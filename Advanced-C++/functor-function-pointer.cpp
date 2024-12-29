#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#include <bits/stdc++.h>

enum Function_CALL_FORMAT {
  LAMBDA = 0,
  FUNCTOR,
  FUNCTION_POINTER
};

struct CustomComparator {
public:
    bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
        if(p1.first < p2.first) return true;
        if(p1.second < p2.second) return true;
        return false;
    }
};
        
bool comp_func(pair<int,int>& p1, pair<int,int>& p2) {
    if(p1.first < p2.first) return true;
    if(p1.second < p2.second) return true;
    return false;
};

int main() {
    Function_CALL_FORMAT funcation_call_format = FUNCTION_POINTER;
    
    if (funcation_call_format == FUNCTOR) {
        cout<<"Functor comparator priority queue"<<endl;
        std::priority_queue<pair<int,int>, std::vector<pair<int,int>>, CustomComparator> pq;
        
        pq.push({1,3});
        pq.push({1, 1});
        
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
    }
    else if(funcation_call_format == LAMBDA) {
        cout<<"Lambda comparator priority queue"<<endl;
        auto comp = [&](pair<int,int>& p1, pair<int,int>& p2) -> bool {
            if(p1.first < p2.first) return true;
            if(p1.second > p2.second) return true;
            return false;
        };
        // priority_queue<pair<int,int>,  vector<pair<int,int>>, function<bool(pair<int, int>&, pair<int, int>&)>> pq(comp);
        priority_queue<pair<int,int>,  vector<pair<int,int>>, decltype(comp)> pq(comp);
        
        pq.push({1,3});
        pq.push({1, 1});
        
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
    }
    else if(funcation_call_format == FUNCTION_POINTER) {
        cout<<"function pointer comparator priority queue"<<endl;
        bool (*comp_func_ptr)(pair<int,int>&, pair<int,int>&){ &comp_func };
        priority_queue<pair<int,int>,  vector<pair<int,int>>, bool (*)(pair<int,int>&, pair<int,int>&)> pq(comp_func_ptr);
        
        pq.push({1,3});
        pq.push({1, 1});
        
        cout<<pq.top().first<<" "<<pq.top().second<<endl;
    }

    return 0;
}
