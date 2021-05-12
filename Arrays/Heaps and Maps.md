### [K Largest Elements](https://www.interviewbit.com/problems/k-largest-elements/)

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
