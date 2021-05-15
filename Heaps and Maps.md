### [Ways to form Max Heap (Star Marked)](https://www.interviewbit.com/problems/ways-to-form-max-heap/)

```cpp
long long ncr(int n, int r){
    vector<long long> c(n + 1, 0); c[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j >= 1; j--) {
            c[j] = c[j] + c[j - 1]; // ncr = n-1cr-1 + n-1cr
            c[j] %= 1000000007;
        }
    }
    return c[r];
}

int func(int a) {
    if(a == 1 || a == 2) return 1;
    if(a == 3) return 2;
    int h = log2(a);
    if((1<<h) - 1 != a) h += 1;
    int alast = a - ((1<<(h - 1)) - 1); int mlast = 1<<(h - 1);
    int last;
    if(alast*2 >= mlast) last = 1<<(h - 2);
    else last = alast;
    int pre = (1<<(h - 2)) - 1;
    int l = pre + last;
    int ans1 = func(l);
    int ans2 = func(a - l - 1);
    long long fct = ncr(a - 1, l);
    long long ans = 1LL*fct * ((1LL*ans1 * ans2)%1000000007); ans %= 1000000007;
    int ret = (int)ans;
    return ret;
}

int Solution::solve(int a) {
    return func(a);
}
```

### [N max pair combinations](https://www.interviewbit.com/problems/n-max-pair-combinations/)

```cpp
vector<int> Solution::solve(vector<int> &a, vector<int> &b) {
    int n = a.size();
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    priority_queue<vector<int>> pq; pq.push({a[n - 1] + b[n - 1], n - 1, n - 1});
    set<pair<int, int>> st; vector<int> ans;
    int c = n;
    while(c) {
        vector<int> val = pq.top(); pq.pop(); ans.push_back(val[0]);
        if(val[1] - 1 >= 0) {
            if(st.find({val[1] - 1, val[2]}) == st.end()) {
                pq.push({a[val[1] - 1] + b[val[2]], val[1] - 1, val[2]});
                st.insert({val[1] - 1, val[2]});
            }
        }
        if(val[2] - 1 >= 0) {
            if(st.find({val[1], val[2] - 1}) == st.end()) {
                pq.push({a[val[1]] + b[val[2] - 1], val[1], val[2] - 1});
                st.insert({val[1], val[2] - 1});
            }
        }
        c--;
    }
    return ans;
}
```

### [K Largest Elements (Star Marked)](https://www.interviewbit.com/problems/k-largest-elements/)

```cpp
// Method 1(Using heap O(n) to build the heap and O(klogn) to get the k largest elements)
vector<int> Solution::solve(vector<int> &a, int b) {
    priority_queue<int>pq;
    for(auto it : a) pq.push(it);
    vector<int> ans;
    while(b) {
        ans.push_back(pq.top());
        pq.pop(); b--;
    }
    return ans;
}

// Method 2(Using order statistics O(n) on average)
int partition(vector<int> &a, int l, int r) {
    int pivot = a[r];
    int j = l;
    for(int i = l; i < r; i++) {
        if(a[i] <= pivot) {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[r], a[j]);
    return j;
}

void kthsmallest(vector<int> &a, int ind, int l, int r) {
    int pivot = partition(a, l, r);

    if(pivot < ind) return kthsmallest(a, ind, pivot + 1, r);
    else if (pivot > ind) return kthsmallest(a, ind, l, pivot - 1);
    return;
}

vector<int> Solution::solve(vector<int> &a, int b) {
    int n = a.size();
    if(b == n) return a;
    kthsmallest(a, n - b - 1, 0, n - 1);
    vector<int> ans;
    for(int i = n - b; i < n; i++) ans.push_back(a[i]);
    return ans;
}
```

### [Magician and Chocolates](https://www.interviewbit.com/problems/magician-and-chocolates/)

```cpp
int Solution::nchoc(int a, vector<int> &b) {
    int n = b.size();
    priority_queue<int> pq;
    for(auto it : b) pq.push(it);
    long long ans = 0;
    for(int i = 1; i <= a; i++) {
        int val = pq.top();
        pq.pop();
        ans += val;
        ans %= 1000000007;
        pq.push(val/2);
    }
    return (int)ans;
}
```

### [Maximum Sum Combination (Star Marked)](https://www.interviewbit.com/problems/maximum-sum-combinations/)

```cpp
vector<int> Solution::solve(vector<int> &a, vector<int> &b, int c) {
    int n = a.size();
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    priority_queue<vector<int>> pq; pq.push({a[n - 1] + b[n - 1], n - 1, n - 1});
    set<pair<int, int>> st; vector<int> ans;
    while(c) {
        vector<int> val = pq.top(); pq.pop(); ans.push_back(val[0]);
        if(val[1] - 1 >= 0) {
            if(st.find({val[1] - 1, val[2]}) == st.end()) {
                pq.push({a[val[1] - 1] + b[val[2]], val[1] - 1, val[2]});
                st.insert({val[1] - 1, val[2]});
            }
        }
        if(val[2] - 1 >= 0) {
            if(st.find({val[1], val[2] - 1}) == st.end()) {
                pq.push({a[val[1]] + b[val[2] - 1], val[1], val[2] - 1});
                st.insert({val[1], val[2] - 1});
            }
        }
        c--;
    }
    return ans;
}
```

### [Merge K Sorted Lists](https://www.interviewbit.com/problems/merge-k-sorted-lists/)

```cpp
// Method 1 (by adding elements of the list individually to the priority queue)
ListNode* Solution::mergeKLists(vector<ListNode*> &a) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto head : a) {
        while(head) {
            pq.push(head->val);
            head = head->next;
        }
    }
    if(pq.empty()) return NULL;
    ListNode dummy(0);
    ListNode* head = &dummy;
    while(!pq.empty()) {
        ListNode* node = new ListNode(pq.top()); pq.pop();
        head->next = node;
        head = head->next;
    }
    return dummy.next;
}

// Method 2 (smart way of solving or say not so intuitive way of solving)
// Also no extra space required
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class comp{
    public:
        bool operator()(ListNode *l1,ListNode *l2){
            return l1->val > l2->val;
        }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &a) {
    priority_queue<ListNode*, vector<ListNode*>, comp> pq;
    for(auto v : a) pq.push(v);
    ListNode dummy(0); ListNode* head = &dummy;
    while(!pq.empty()) {
        ListNode* node = pq.top(); pq.pop();
        head->next = node; head = head->next;
        if(node->next) pq.push(node->next);
    }
    return dummy.next;
}
```

### [Distinct Numbers in Window](https://www.interviewbit.com/problems/distinct-numbers-in-window/)

```cpp
vector<int> Solution::dNums(vector<int> &a, int b) {
    int n = a.size();
    if(b > n) return {};
    unordered_map<int, int> mp;
    int distinct = 0;
    vector<int> ans(n - b + 1, 0);
    for(int i = n - 1; i >=0; i--) {
        if(i < n - b) {
            mp[a[i]]++;
            if(mp[a[i]] == 1) distinct++;
            if(mp[a[i + b]] == 1) distinct--;
            mp[a[i + b]]--;
            ans[i] = distinct;
        }
        else {
            mp[a[i]]++;
            if(mp[a[i]] == 1) distinct++;
            if(i == n - b) ans[i] = distinct;
        }
    }
    return ans;
}
```

### [LRU Cache (Star Marked)](https://www.interviewbit.com/problems/lru-cache/)

```cpp
struct LstNode {
    int val;
    LstNode* next;
    LstNode* prev;
    LstNode(int x) : val(x), next(NULL), prev(NULL) {}
};

map<int, LstNode*> mp1;
map<int, int> mp2;
LstNode* head;
LstNode* tail;
int sze, capacity;

LRUCache::LRUCache(int cpacity) {
    mp1.clear(); mp2.clear();
    head = NULL; tail = NULL;
    sze = 0; capacity = cpacity;
}

int LRUCache::get(int key) {
    if(mp2[key] != 0) {
        set(key, mp2[key]);
        return mp2[key];
    }
    return -1;
}

void LRUCache::set(int key, int value) {
    if(mp2[key] != 0) {
        LstNode* node = mp1[key];
        if(node == tail) tail = tail->prev;
        if(node->prev) {
            node->prev->next = node->next;
            if(node->next) node->next->prev = node->prev;
            node->next = head;
            head->prev = node;
            node->prev = NULL;
            head = node;
        }
        if(tail) tail->next = NULL;
        else tail = head;
    }
    else {
        if(sze == capacity) {
            mp2[tail->val] = 0;
            mp1[tail->val] = NULL;
            tail = tail->prev;
            if(tail) tail->next = NULL;
            LstNode* new_node = new LstNode(key);
            if(capacity == 1) {
                head = new_node;
                tail = head;
            }
            else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
        else {
            LstNode* new_node = new LstNode(key);
            if(!head) {
                head = new_node;
                tail = new_node;
            }
            else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
            sze++;
        }
    }
    mp1[key] = head;
    mp2[key] = value;
    return;
}
```
