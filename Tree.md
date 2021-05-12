### [Valid BST from Preorder](https://www.interviewbit.com/problems/valid-bst-from-preorder/)

```cpp
// Method 1 (O(n^2) using recursion)
int check(vector<int> &a, int i, int n) {
    if(n - i == 1) return 1;
    int note = -1;
    for(int j = i; j < n; j++) {
        if(a[j] > a[i]) {
            note = j;
            break;
        }
    }
    if(note != -1) {
        for(int j = note; j < n; j++) {
            if(a[j] <= a[i]) return 0;
        }
    }

    if(note == -1 || note == i + 1) return check(a, i + 1, n);
    int ans1 = check(a, i + 1, note);
    int ans2 = check(a, note, n);
    return (ans1 & ans2);
}

int Solution::solve(vector<int> &a) {
    int n = a.size();
    return check(a, 0, n);
}

// Method 2 (O(n) using stack)
int Solution::solve(vector<int> &A) {
    stack<int> s;
    int root = INT_MIN;
    for(int i = 0;i < A.size(); i++){
        if(A[i] < root)   return false;
        while(!s.empty() && A[i] > s.top()){
            root = s.top();
            s.pop();
        }
        s.push(A[i]);
    }
    return true;
}
```

### [Kth Smallest Element In Tree](https://www.interviewbit.com/problems/kth-smallest-element-in-tree/)

```cpp
// Method 1 (storing the in-order traversal itself)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void in_order(TreeNode* a, vector<int> &v) {
     if(a == NULL) return;
     if(!a->left && !a->right) {
         v.push_back(a->val);
         return;
     }
     in_order(a->left, v);
     v.push_back(a->val);
     in_order(a->right, v);
     return;
 }

int Solution::kthsmallest(TreeNode* a, int b) {
    vector<int> v;
    in_order(a, v);
    return v[b - 1];
}

// Method 2 (passing the value of k)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int in_order(TreeNode* a, int b, int &ans) {
     if(a == NULL) return 0;
     int ret = in_order(a->left, b, ans);
     if(ret + 1 == b) ans = a->val;
     int garbage = in_order(a->right, b - ret - 1, ans);
     return ret + 1 + garbage;
 }

int Solution::kthsmallest(TreeNode* a, int b) {
    int ans;
    int num = in_order(a, b, ans);
    return ans;
}
```

### [Kth Smallest Element In Tree](https://www.interviewbit.com/problems/kth-smallest-element-in-tree/)

```cpp
// Method 1 (storing the in-order traversal itself)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void in_order(TreeNode* a, vector<int> &v) {
     if(a == NULL) return;
     if(!a->left && !a->right) {
         v.push_back(a->val);
         return;
     }
     in_order(a->left, v);
     v.push_back(a->val);
     in_order(a->right, v);
     return;
 }

int Solution::kthsmallest(TreeNode* a, int b) {
    vector<int> v;
    in_order(a, v);
    return v[b - 1];
}
```
