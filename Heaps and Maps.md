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
// Method 1(Using heap O(nlogn) to build the heap and O(klogn) to get the k largest elements)
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

## LeetCode Heaps Hard Problems

### [Find the Kth Smallest Sum of a Matrix With Sorted Rows (Star Marked)](https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/)

```cpp
// O(k * N * logN) assuming dimension of matrix is N X M
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        // store minimum sum between any two arrays in the matrix in a priority queue
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> temp; int sum = 0; temp.push_back(sum);
        for(int i = 0; i < mat.size(); i++) {
            sum += mat[i][0];
            temp.push_back(0);
        }
        temp[0] = sum; pq.push(temp); set<vector<int>> st; st.insert(temp);
        while(k) {
            auto v = pq.top(); pq.pop(); int ans = 1e9, pos = -1, save = v[0];
            k--; if(k == 0) return v[0];
            for(int i = 1; i < v.size(); i++) {
                if(v[i] + 1 < mat[i - 1].size()) {
                    int sum = v[0] - mat[i - 1][v[i]] + mat[i - 1][v[i] + 1];
                    v[0] = sum; v[i]++;
                    if(st.find(v) == st.end()) {
                        pq.push(v);
                        st.insert(v);
                    }
                    v[i]--; v[0] = save;
                }
            }
        }
        return -1;
    }
};

// this is the same thing as the above but here we have used out own comperator
// Now you can think of priority queue as a vector and it pops element from the
// end of the vector. so when we want priority queue to pop out minimum element
// we actually want this vector to be sorted in descending order and that's
// why our compertor returns true when v1[0] > v2[0]
class comp {
    public:
        bool operator()(vector<int> v1, vector<int> v2) {
            return v1[0] > v2[0];
        }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        // store minimum sum between any two arrays in the matrix in a priority queue
        priority_queue<vector<int>, vector<vector<int>>, comp> pq;
        vector<int> temp; int sum = 0; temp.push_back(sum);
        for(int i = 0; i < mat.size(); i++) {
            sum += mat[i][0];
            temp.push_back(0);
        }
        temp[0] = sum; pq.push(temp); set<vector<int>> st; st.insert(temp);
        while(k) {
            auto v = pq.top(); pq.pop(); int ans = 1e9, pos = -1, save = v[0];
            k--; if(k == 0) return v[0];
            for(int i = 1; i < v.size(); i++) {
                if(v[i] + 1 < mat[i - 1].size()) {
                    int sum = v[0] - mat[i - 1][v[i]] + mat[i - 1][v[i] + 1];
                    v[0] = sum; v[i]++;
                    if(st.find(v) == st.end()) {
                        pq.push(v);
                        st.insert(v);
                    }
                    v[i]--; v[0] = save;
                }
            }
        }
        return -1;
    }
};
```

### [Minimum Cost to Hire K Workers (Star Marked)](https://leetcode.com/problems/minimum-cost-to-hire-k-workers/)

```cpp
// Method 1 (using binary on answer O(N * N * logN) time) gives TLE
class Solution {
public:
    static bool comp(vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0];
    }

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size(); vector<vector<int>> store;
        for(int i = 0; i < n; i++) store.push_back({quality[i], wage[i]});
        sort(store.begin(), store.end(), comp);
        double ans = 1e18;
        for(int i = 0; i < n; i++) {
            int low = store[i][1], high = 1e9;
            while(low <= high) {
                int mid = (low + high)/2; double cur_ans = mid; int cnt = 1;
                for(int j = 0; j < n; j++) {
                    if(j == i) continue;
                    if(cnt == k) break;
                    double cur_price = ((double)store[j][0]/store[i][0])*mid;
                    if(cur_price >= store[j][1]) {
                        cur_ans = (double) cur_ans + cur_price;
                        cnt++;
                    }
                }
                if(cnt == k) {
                    high = mid - 1;
                    ans = min(ans, cur_ans);
                }
                else low = mid + 1;
            }
        }
        return ans;
    }
};

// Method 2 (O(N * logN) time)
// this solution will be very easy to solve once you realize that in the optimal set
// there would be at least one worker which will receive the minimum wage.
// now to figure this out, here are some useful pointers.
// 1. assume that each worker receives x wage per quality
// 2. then the wage a worker receives should be q_i * x
// 3. Condition : q_i * x >= w_i
class Solution {
public:
    static bool comp(vector<int> v1, vector<int> v2) {
        double val1 = (double)v1[1]/v1[0];
        double val2 = (double)v2[1]/v2[0];
        return val1 < val2;
    }

    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size(); vector<vector<int>> store;
        for(int i = 0; i < n; i++) store.push_back({quality[i], wage[i]});
        sort(store.begin(), store.end(), comp);
        priority_queue<double> pq; int sm = 0;
        for(int i = 0; i < k - 1; i++) {
            pq.push(store[i][0]);
            sm += store[i][0];
        }
        double ans = 1e18;
        for(int i = k - 1; i < n; i++) {
            double cur_ans = ((double)(sm + store[i][0]) * store[i][1])/store[i][0];
            ans = min(ans, cur_ans);
            if(pq.size() && pq.top() > store[i][0]) {
                int get = pq.top(); pq.pop();
                pq.push(store[i][0]);
                sm -= get; sm += store[i][0];
            }
        }
        return ans;
    }
};
```

### [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)

```cpp
// Method 1 (Using ordered set, O(logn) insertion and O(logn) for finding median)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set    tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update>

class MedianFinder {
private:
    ordered_set o_set; int sz = 0;
public:

    void addNum(int num) {
        o_set.insert({num, sz}); sz++;
        return;
    }

    double findMedian() {
        if(sz%2) {
            auto num = *(o_set.find_by_order((sz/2)));
            return num.first;
        }
        else {
            auto num1 = *(o_set.find_by_order((sz/2)));
            auto num2 = *(o_set.find_by_order((sz/2) - 1));
            double ans = ((double)num1.first + num2.first)/2;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// Method 2 (Using Priority Queue O(logn) insertion and O(1) finding median)
 class MedianFinder {
private:
    priority_queue<int> mx; priority_queue<int, vector<int>, greater<int>> mn;
    int sz_mx = 0, sz_mn = 0;
public:

    void addNum(int num) {
        if(!sz_mn && !sz_mx) {
            mx.push(-1e9); mn.push(1e9);
            sz_mx = 1, sz_mn = 1;
        }
        if(sz_mn == sz_mx) {
            if(num <= mx.top()) mx.push(num);
            else {
                if(num <= mn.top()) mx.push(num);
                else {
                    int num1 = mn.top(); mn.pop(); mx.push(num1);
                    mn.push(num);
                }
            }
            sz_mx++;
        }
        else {
            if(num > mx.top()) mn.push(num);
            else {
                int num1 = mx.top(); mx.pop(); mn.push(num1);
                mx.push(num);
            }
            sz_mn++;
        }
        return;
    }

    double findMedian() {
        if(sz_mx > sz_mn) return mx.top();
        else {
            int mx_num = mx.top();
            int mn_num = mn.top();
            double ans = ((double)mx_num + mn_num)/2;
            return ans;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

### [Minimize Deviation in Array (Star Marked)](https://leetcode.com/problems/minimize-deviation-in-array/)

```cpp
/*
i couldn't solve this question so i read the solution in the discussion forum. basically what they say is let's just eliminate one type of operation. and the way we do it is multiplying every odd number by 2. so now we can only perform one type of operation to minimize the deviation, i.e division by 2. now they have said that we can just maintain the maximum and the minimum number and if the maximum number is odd we will terminate our program, otherwise we will divide the maximum number by 2.
*/
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();  priority_queue<int> pq; int mn = 1e9;
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2) nums[i] *= 2;
            mn = min(mn, nums[i]);
            pq.push(nums[i]);
        }
        int ans = 1e9;
        while(true) {
            int get = pq.top(); pq.pop();
            ans = min(ans, get - mn);
            if(get % 2) break;
            else {
                get /= 2; mn = min(mn, get);
                pq.push(get);
            }
        }
        return ans;
    }
};
```

### [Trapping Rain Water II (Star Marked)](https://leetcode.com/problems/trapping-rain-water-ii/)

```cpp
// took 3 days to solve
// In trapping rain water 1 we were for a particular column we were filling water upto the min(max_on_left, max_on_right)
// but in this question instead of only left and right columns we have to think about an enclosed region

// so given a current enclosed region it is possible to fill water upto the minimum height boundary of this region in all
// the cells within the region. Now everytime you will pop this minimum height boundary and add its neighbour into the
// the queue.

class Solution {
public:
    int trapRainWater(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 || j == m - 1 || i == n - 1 || j == 0) {
                    pq.push({mat[i][j], i, j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<array<int, 2>> mov = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int ans = 0; int min_height_boundary = INT_MIN;
        while(!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int h = it[0], x = it[1], y = it[2];
            min_height_boundary = max(min_height_boundary, h);
            for(auto mv : mov) {
                int nx = x + mv[0], ny = y + mv[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    if(mat[nx][ny] <= min_height_boundary) ans += (min_height_boundary - mat[nx][ny]);
                    vis[nx][ny] = 1;
                    pq.push({mat[nx][ny], nx, ny});
                }
            }
        }
        return ans;
    }
};
```

### [Pizza With 3n Slices (Star Marked)](https://leetcode.com/problems/pizza-with-3n-slices/)

```cpp
// very very very hard problem

// this is a very question, doing house robber II will help in solving this question.
// So basically given this circular array, the observations are:
// 1. the main obervation is given an array of size n if we choose atmost n/3 slices which are not adjacent
//    there would be a way to actually eat these slices according to the the conditions given. Therefore this question
//    actually reduces to finding out the maximum sum of n/3 slice which are not consecutive.
// 2. we can't choose a[0] and a[n - 1] slice at the same time, therefore we can operate separately on
//    the array arr[0:n - 2] and arr[1:n - 1].

// made 2 dps
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < n; i++) dp[i][1] = slices[i];
        for(int i = 1; i < n - 1; i++) {
            dp[i][1] = max(dp[i][1], dp[i - 1][1]);
            for(int j = 2; j <= n; j++) {
                if(i - 2 >= 0) dp[i][j] = (slices[i] + dp[i - 2][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        int ans = dp[n - 2][n/3];
        vector<vector<int>> dp2(n + 1, vector<int> (n + 1, 0));
        for(int i = 1; i < n; i++) dp2[i][1] = slices[i];
        for(int i = 1; i < n; i++) {
            dp2[i][1] = max(dp2[i][1], dp2[i - 1][1]);
            for(int j = 2; j <= n; j++) {
                if(i - 2 >= 0) dp2[i][j] = (slices[i] + dp2[i - 2][j - 1]);
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j]);
            }
        }
        ans = max(ans, dp2[n - 1][n/3]);
        return ans;
    }
};

// made 1 dp
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < n; i++) dp[i][1] = slices[i];
        for(int i = 1; i < n - 1; i++) {
            dp[i][1] = max(dp[i][1], dp[i - 1][1]);
            for(int j = 2; j <= n; j++) {
                if(i - 2 >= 0) dp[i][j] = (slices[i] + dp[i - 2][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        int ans = dp[n - 2][n/3]; dp[0][1] = 0;
        for(int i = 1; i < n; i++) dp[i][1] = slices[i];
        for(int i = 1; i < n; i++) {
            dp[i][1] = max(dp[i][1], dp[i - 1][1]);
            for(int j = 2; j <= n; j++) {
                if(i - 2 >= 0) dp[i][j] = (slices[i] + dp[i - 2][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
        ans = max(ans, dp[n - 1][n/3]);
        return ans;
    }
};
```

### [Minimum Difference in Sums After Removal of Elements (Star Marked)](https://leetcode.com/contest/biweekly-contest-71/problems/minimum-difference-in-sums-after-removal-of-elements/)

```cpp
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = (nums.size())/3;
        vector<long long> pref(3*n, 0), suf(3*n, 0);
        priority_queue<int> pq1;
        for(int i = 0; i < 3*n; i++) {
            pref[i] = (i?pref[i - 1]:0);
            if(pq1.size() == n) {
                if(pq1.top() > nums[i]) {
                    pref[i] -= pq1.top();
                    pq1.pop();
                    pq1.push(nums[i]);
                    pref[i] += nums[i];
                }
            }
            else {
                pq1.push(nums[i]);
                pref[i] += nums[i];
            }
        }
        priority_queue<int, vector<int>, greater<int>> pq2;
        for(int i = (3*n) - 1; i >= 0; i--) {
            suf[i] = (((i + 1) < 3*n)?suf[i + 1]:0);
            if(pq2.size() == n) {
                if(pq2.top() < nums[i]) {
                    suf[i] -= pq2.top();
                    pq2.pop();
                    pq2.push(nums[i]);
                    suf[i] += nums[i];
                }
            }
            else {
                pq2.push(nums[i]);
                suf[i] += nums[i];
            }
        }
        long long ans = 1e18;
        for(int i = n - 1; i < 2*n; i++) ans = min(ans, pref[i] - suf[i + 1]);
        return ans;
    }
};
```

### [Smallest Sufficient Team (Star Marked)](https://leetcode.com/problems/smallest-sufficient-team/)

```cpp
vector<long long> dp;
class Solution {
public:
    long long dpMask(int mask, vector<string>& req_skills, vector<int>& people, vector<int> &avail) {
        int n = req_skills.size(), m = people.size();
        if(mask == ((1<<n) - 1)) return 0;
        if(dp[mask] != -1) return dp[mask];
        int ans = 1e9; long long vans = 0;
        for(int i = 0; i < m; i++) {
            if(avail[i]) {
                int curMask = mask|people[i];
                avail[i] = 0;
                auto ret = dpMask(curMask, req_skills, people, avail);
                ret|=(1LL<<i);
                auto cnt = __builtin_popcountll(ret);
                if(ans > cnt) {
                    ans = cnt;
                    vans = ret;
                }
                avail[i] = 1;
            }
        }
        return dp[mask] = vans;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        dp = vector<long long> (100000, -1LL);
        int n = people.size(), m = req_skills.size();
        map<string, int> mpp;
        int ind = 0; for(auto it : req_skills) mpp[it] = ind++;
        vector<int> preMask;
        for(auto v : people) {
            int curMask = 0;
            for(auto u : v) curMask+=(1<<mpp[u]);
            preMask.push_back(curMask);
        }
        vector<int> avail(n, 1);
        long long ans =  dpMask(0, req_skills, preMask, avail);
        vector<int> ret;
        for(int i = 0; i < n; i++) {
            if((ans>>i)&1) ret.push_back(i);
        }
        return ret;
    }
};
```
