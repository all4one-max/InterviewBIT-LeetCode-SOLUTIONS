### [Nearest Smaller Element](https://www.interviewbit.com/problems/nearest-smaller-element/)

```cpp
vector<int> Solution::prevSmaller(vector<int> &a) {
    int n = a.size();
    stack<int> st;
    vector<int> ans(n,0);
    ans[0] = -1;
    st.push(a[0]);
    for(int i = 1;i<n;i++) {
        while(!st.empty() && st.top()>=a[i]) {
            st.pop();
        }
        if(!st.empty()) ans[i] = st.top();
        else ans[i] = -1;
        st.push(a[i]);
    }
    return ans;
}
```

### [Largest Rectangle in Histogram (Star Marked)](https://www.interviewbit.com/problems/largest-rectangle-in-histogram/)

```cpp
vector<int> helper(vector<int> &a) {
    int n = a.size();
    vector<int> answer(n, 0);
    stack<pair<int,int>> st;
    st.push({a[0],0});
    answer[0] = a[0];
    for(int i = 1;i<n;i++) {
        while(!st.empty() && st.top().first>=a[i]) st.pop();
        answer[i] = max(answer[i], a[i]);
        if(!st.empty()) answer[i] = max(answer[i], (i - st.top().second)*a[i]);
        else answer[i] = max(answer[i], a[i]*(i + 1));
        st.push({a[i],i});
    }
    return answer;
}

int Solution::largestRectangleArea(vector<int> &a) {
    int n = a.size();
    vector<int> ans1 = helper(a);
    reverse(a.begin(), a.end());
    vector<int> ans2 = helper(a);
    reverse(a.begin(), a.end());
    int ans = a[0];
    for(int i = 0;i<n;i++) {
        ans=max(ans,ans1[i]+ans2[n-i-1]-a[i]);
    }
    return ans;
}
```

### [First non-repeating character in a stream of characters](https://www.interviewbit.com/problems/first-non-repeating-character-in-a-stream-of-characters/)

```cpp
string Solution::solve(string a) {
    int n = a.size();
    vector<int> q[26];
    string b = "";
    for(int i=0;i<n;i++) {
        q[a[i]-'a'].push_back(i);
        int mn = 2*n;
        char note;
        for(int j=0;j<26;j++) {
            if(q[j].size()==1) {
                if(q[j][0]<mn){
                    mn=q[j][0];
                    note='a'+j;
                }
            }
        }
        if(mn!=2*n) b+=note;
        else b+='#';
    }
    return b;
}
```

### [Sliding Window Maximum (Star Marked)](https://www.interviewbit.com/problems/sliding-window-maximum/)

```cpp
vector<int> Solution::slidingMaximum(const vector<int> &a, int b) {
    int n = a.size();
    vector<int> ans;
    deque<int>  q;
    for(int i=0;i<n;i++) {
        while(q.size() && q.back()<a[i]) q.pop_back();
        q.push_back(a[i]);
        if(i-b<-1) continue;
        else if(i-b==-1) ans.push_back(q.front());
        else {
            if(q.front()==a[i-b]) q.pop_front();
            ans.push_back(q.front());
        }
    }
    return ans;
}
```

### [Simplify Directory Path](https://www.interviewbit.com/problems/simplify-directory-path/)

```cpp
string Solution::simplifyPath(string a) {
    deque<string> st;
    int n = a.size();
    int i = 0;
    while(i<n) {
        if(a[i] == '/') {
            i++;
            continue;
        }
        else if (a[i] == '.') {
            if(i+1<n && a[i+1] == '.') {
                if(!st.empty()) st.pop_back();
                i+=2;
            }
            else i++;
        }
        else {
            int j = i;
            string s;
            while(j<n && a[j]!='/') {
                s+=a[j];
                j++;
            }
            i = j;
            st.push_back(s);
        }
    }
    string ans;
    while(!st.empty()) {
        ans+="/";
        ans+=st.front();
        st.pop_front();
    }
    if(ans.empty()) ans+="/";
    return ans;
}
```

### [Redundant Braces](https://www.interviewbit.com/problems/redundant-braces/)

```cpp
int Solution::braces(string a) {
    int n = a.size();
    stack<char> st;
    for(int i=0;i<n;i++) {
        if(a[i]==')') {
            if(st.top()=='(') return 1;
            bool opr = 0;
            while(!st.empty() && st.top()!='(') {
                if(st.top()=='*' || st.top()=='+' || st.top()=='/' || st.top()=='-') opr = 1;
                st.pop();
            }
            if(!opr) return 1;
            st.pop();
        }
        else st.push(a[i]);
    }
    return 0;
}
```

### [Min Stack](https://www.interviewbit.com/problems/min-stack/)

```cpp
stack<pair<int,int>> st;

MinStack::MinStack() {
    while(!st.empty()) st.pop();
}

void MinStack::push(int x) {
    if(st.empty()) st.push({x,x});
    else {
        if(st.top().second>x) st.push({x,x});
        else st.push({x,st.top().second});
    }
}

void MinStack::pop() {
    if(!st.empty()) st.pop();
    return;
}

int MinStack::top() {
    if(st.empty()) return -1;
    return st.top().first;
}

int MinStack::getMin() {
    if(st.empty()) return -1;
    return st.top().second;
}
```

### [Evaluate Expression (Star Marked)](https://www.interviewbit.com/problems/evaluate-expression/)

```cpp
int get_num(string s) {
    int flag = 1;
    int n = s.size();
    if(s[0] == '-') {
        s = s.substr(1);
        flag = -1;
        n--;
    }
    int ans = 0;
    for(int i=0;i<n;i++) ans = ans*10 + (s[i] - '0');
    return flag*ans;
}

int Solution::evalRPN(vector<string> &a) {
    stack<int> st;
    int n = a.size();
    int ans;
    for(int i = 0;i < n;i++) {
        if(a[i] == "*" || a[i] == "/" || a[i] == "+" || a[i] == "-") {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            if (a[i] == "*") st.push(op2*op1);
            else if (a[i] == "/") st.push(op2/op1);
            else if (a[i] == "-") st.push(op2-op1);
            else if (a[i] == "+") st.push(op2+op1);
        }
        else st.push(get_num(a[i]));
    }
    return st.top();
}
```

### [Rain Water Trapped (Star Marked)](https://www.interviewbit.com/problems/rain-water-trapped/)

```cpp
int Solution::trap(const vector<int> &a) {
    int n = a.size(),mx = -1;
    deque<int> q;
    for(int i = n-1;i>=0;i--) {
        if(q.empty()) q.push_front(a[i]);
        else {
            if(a[i]>=q.front()) q.push_front(a[i]);
        }
    }
    int ans = 0;
    for(int i=0;i<n-1;i++) {
        if(a[i] == q.front()) q.pop_front();
        if(mx != -1) {
            int r_max = q.front();
            if(mx>=a[i] && r_max>=a[i]) {
                int mn = min(mx,r_max);
                ans += (mn - a[i]);
            }
        }
        mx = max(mx,a[i]);
    }
    return ans;
}
```

## LeetCode Stack Hard Problems

### [Number of Visible People in a Queue (Star Marked)](https://leetcode.com/problems/number-of-visible-people-in-a-queue/)

```cpp
// O(N * logN solution)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bin(int val, vector<int> &st) {
        int n = st.size();
        int low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(st[mid] >= val) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        if(ans == -1)  return n;
        return n - ans - 1;
    }

    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size(); vector<int> ans(n, 1); ans[n - 1] = 0;
        vector<int> st;
        for(int i = n - 1; i >= 0; i--) {
            auto pos = bin(heights[i], st);
            if(i!=n-1) {
                // cout<<pos<<" "<<st.size()<<endl;
                if(pos != st.size()) ans[i] = max(ans[i], (int)pos + 1);
                else ans[i] = max(ans[i], (int)pos);
            }
            while(!st.empty() && heights[i] >= st.back()) st.pop_back();
            st.push_back(heights[i]);
        }
        return ans;
    }
};
```

### [Check if a Parentheses String Can Be Valid (Star Marked)](https://leetcode.com/contest/biweekly-contest-68/problems/check-if-a-parentheses-string-can-be-valid/)

```cpp
class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        stack<int> st; set<int> free;
        for(int i = 0; i < n; i++) {
            if(!(locked[i] - '0')) free.insert(i);
            else {
                if(s[i] == ')') {
                    if(!st.empty()) st.pop();
                    else {
                        if(free.size()) free.erase(prev(free.end()));
                        else return false;
                    }
                }
                else st.push(i);
            }
        }
        while(!st.empty()) {
            auto it = st.top(); st.pop();
            auto it2 = free.lower_bound(it);
            if(it2 == free.end()) return false;
            free.erase(it2);
        }
        if(free.size() % 2) return false;
        return true;
    }
};
```
