### [Valid BST from Preorder (Star Marked)](https://www.interviewbit.com/problems/valid-bst-from-preorder/)

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

### [2-Sum Binary Tree (Star Marked)](https://www.interviewbit.com/problems/2sum-binary-tree/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
stack<TreeNode*> next_small;
stack<TreeNode*> next_great;

void push_left(TreeNode* root) {
    if(!root) return;
    next_small.push(root);
    push_left(root->left);
}

void push_right(TreeNode* root) {
    if(!root) return;
    next_great.push(root);
    push_right(root->right);
}

int Solution::t2Sum(TreeNode* root, int b) {
    while(!next_small.empty()) next_small.pop();
    while(!next_great.empty()) next_great.pop();
    push_left(root); push_right(root);
    while(!next_small.empty() && !next_great.empty()) {
        if(next_small.top()->val >= next_great.top()->val) break;
        if(next_small.top()->val + next_great.top()->val == b) return 1;
        else if(next_small.top()->val + next_great.top()->val > b) {
            TreeNode* node = next_great.top(); next_great.pop();
            push_right(node->left);
        }
        else if(next_small.top()->val + next_great.top()->val < b) {
            TreeNode* node = next_small.top(); next_small.pop();
            push_left(node->right);
        }
    }
    return 0;
}
```

### [BST Iterator (Star Marked)](https://www.interviewbit.com/problems/bst-iterator/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 stack<TreeNode*> st;

void push_left(TreeNode* root) {
    if(!root) return;
    st.push(root);
    push_left(root->left);
    return;
}

BSTIterator::BSTIterator(TreeNode *root) {
    while(!st.empty()) st.pop();
    push_left(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(st.empty()) return false;
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* node = st.top(); st.pop();
    push_left(node->right);
    return node->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
```

### [Recover Binary Search Tree (Star Marked)](https://www.interviewbit.com/problems/recover-binary-search-tree/)

```cpp
// Method 1 (O(n) space)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void in_order(TreeNode* root, vector<int> &inorder) {
    if(!root) return;
    in_order(root->left, inorder);
    inorder.push_back(root->val);
    in_order(root->right, inorder);
    return;
}

vector<int> Solution::recoverTree(TreeNode* a) {
    vector<int> inorder;
    in_order(a, inorder);
    vector<int> ans;
    int note = -1, ind = -1;
    int n = inorder.size();
    for(int i = inorder.size() - 1; i >= 0; i--) {
        if((i!=0 && inorder[i] < inorder[i - 1]) || (i == 0 && i + 1 < n && inorder[i + 1] < inorder[i])) {
            note = inorder[i];
            ind = i;
            ans.push_back(inorder[i]);
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i != ind) {
            if(inorder[i] >= inorder[ind - 1]) {
                if((ind != n - 1 && inorder[i] <= inorder[ind + 1]) || (ind == n - 1)) {
                    ans.push_back(inorder[i]);
                    break;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// Method 2 (Using Morris Inorder Traversal which uses constant space)
// Morris Inorder Traversal

vector<int> Solution::recoverTree(TreeNode* root) {
    vector<int> inorder;
    TreeNode* cur = root;
    while(cur) {
        if(!cur->left) {
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode* inorder_predecessor = cur->left;
            while(inorder_predecessor->right && inorder_predecessor->right != cur) inorder_predecessor = inorder_predecessor->right;
            if(inorder_predecessor->right == NULL) {
                inorder_predecessor->right = cur;
                cur = cur->left;
            }
            else {
                inorder_predecessor->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }

        }
    }
    if(inorder.size() == 1) return {};
    int ind = -1;
    for(int i = inorder.size() - 1; i >= 0; i--) {
        if((i != 0 && inorder[i] < inorder[i - 1])) {
            ind = i;
            break;
        }
    }
    if(ind == -1) return {};
    vector<int> ans;
    int n = inorder.size();
    ans.push_back(inorder[ind]);
    for(int i = 0; i < n; i++) {
        if(i != ind) {
            if(inorder[i] >= inorder[ind - 1]) {
                if((ind != n - 1 && inorder[i] <= inorder[ind + 1]) || (ind == n - 1)) {
                    ans.push_back(inorder[i]);
                    break;
                }
            }
        }
    }
    if(ans[0] > ans[1]) swap(ans[0], ans[1]);
    return ans;
}
```

### [Path to a Given Node](https://www.interviewbit.com/problems/path-to-given-node/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool dfs(TreeNode* root, vector<int> &ans, int b) {
    if(root->val == b) {
        ans.push_back(b);
        return true;
    }
    if(root->left && dfs(root->left, ans, b)) {
        ans.push_back(root->val);
        return true;
    }
    if(root->right && dfs(root->right, ans, b)) {
        ans.push_back(root->val);
        return true;
    }
    return false;
}

vector<int> Solution::solve(TreeNode* root, int b) {
    vector<int> ans;
    bool path = dfs(root, ans, b);
    reverse(ans.begin(), ans.end());
    return ans;
}
```

### [Remove Half Nodes](https://www.interviewbit.com/problems/remove-half-nodes/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* remove_half_node(TreeNode* root) {
    if(!root) return root;
    TreeNode* lft = NULL; TreeNode* rht = NULL;
    if(root->left) lft = remove_half_node(root->left);
    if(root->right) rht = remove_half_node(root->right);
    if(!root->left && !root->right) return root;
    if(root->left && root->right) {
        root->left = lft;
        root->right = rht;
        return root;
    }
    if(root->left) return lft;
    return rht;
}

TreeNode* Solution::solve(TreeNode* root) {
    TreeNode* root = remove_half_node(root);
    return root;
}
```

### [Balanced Binary Tree](https://www.interviewbit.com/problems/balanced-binary-tree/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
pair<int, int> check(TreeNode* root) {
    if(!root) return {0, 1};
    pair<int, int> p1 = check(root->left); pair<int, int> p2 = check(root->right);
    if(abs(p1.first - p2.first) <= 1 && p1.second && p2.second) return {1 + max(p1.first, p2.first) ,1};
    else return {1 + max(p1.first, p2.first) ,0};
}

int Solution::isBalanced(TreeNode* root) {
    pair<int, int> p = check(root);
    if(p.second) return 1;
    return 0;
}
```

### [Merge 2 Binary Tree](https://www.interviewbit.com/problems/merge-two-binary-tree/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* merge(TreeNode* r1, TreeNode* r2) {
    if(!r1 && !r2) return NULL;
    if(!r1 && r2) return r2;
    if(r1 && !r2) return r1;
    r1->val += r2->val;
    r1->left = merge(r1->left, r2->left);
    r1->right = merge(r1->right, r2->right);
    return r1;
}

TreeNode* Solution::solve(TreeNode* r1, TreeNode* r2) {
    TreeNode* root = merge(r1, r2);
    return root;
}
```

### [Symmetric Binary Tree](https://www.interviewbit.com/problems/symmetric-binary-tree/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int check(TreeNode* r1, TreeNode* r2) {
    if(!r1 && !r2) return 1;;
    if((!r1 && r2) || (r1 && !r2) || (r1->val != r2->val)) return 0;
    if(check(r1->left, r2->right) && check(r1->right, r2->left)) return 1;
    return 0;
}

int Solution::isSymmetric(TreeNode* root) {
    return check(root, root);
}
```

### [Identical Binary Trees](https://www.interviewbit.com/problems/identical-binary-trees/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int check(TreeNode* r1, TreeNode* r2) {
    if(!r1 && !r2) return 1;
    if((!r1 && r2) || (r1 && !r2) || (r1->val != r2->val)) return 0;
    if(check(r1->left, r2->left) && check(r1->right, r2->right)) return 1;
    return 0;
}

int Solution::isSameTree(TreeNode* r1, TreeNode* r2) {
    return check(r1, r2);
}
```

### [Vertical Order traversal of Binary Tree (Star Marked)](https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* root) {
    if(!root) return {};
    vector<int> ans[20001];
    queue<pair<TreeNode*, int>> q; q.push({root, 10001});
    while(!q.empty()) {
        pair<TreeNode*, int> p = q.front(); q.pop();
        ans[p.second].push_back(p.first->val);
        if(p.first->left) q.push({p.first->left, p.second - 1});
        if(p.first->right) q.push({p.first->right, p.second + 1});
    }
    vector<vector<int>> ret;
    for(int i = 0; i < 20001; i++) if(ans[i].size()) ret.push_back(ans[i]);
    return ret;
}
```

### [Inorder Traversal using stacks](https://www.interviewbit.com/problems/inorder-traversal/)

```cpp
vector<int> Solution::inorderTraversal(TreeNode* root) {
    stack<TreeNode*> st; st.push(root);
    while(true) {
        TreeNode* node = st.top();
        if(node->left) st.push(node->left);
        else break;
    }
    vector<int> inorder;
    while(!st.empty()) {
        TreeNode* node = st.top(); st.pop(); inorder.push_back(node->val);
        if(node->right) {
            st.push(node->right);
            while(true) {
                TreeNode* nod = st.top();
                if(nod->left) st.push(nod->left);
                else break;
            }
        }
    }
    return inorder;
}
```

### [PreOrder Traversal using stacks](https://www.interviewbit.com/problems/preorder-traversal/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    st.push(root);
    vector<int> pre_order;
    while(!st.empty()) {
        TreeNode* node = st.top(); st.pop();
        pre_order.push_back(node->val);
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return pre_order;
}
```

### [PostOrder Traversal using stacks](https://www.interviewbit.com/problems/postorder-traversal/)

```cpp
// Method 1 (removing the right subtree after putting the right subtree root in the stack)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* root) {
    stack<TreeNode*> st; st.push(root);
    while(true) {
        TreeNode* node = st.top();
        if(node->left) st.push(node->left);
        else break;
    }
    vector<int> post_order;
    while(!st.empty()) {
        TreeNode* node = st.top();
        if(node->right) {
            TreeNode* right = node->right;
            node->right = NULL;
            st.push(right);
            while(true) {
                TreeNode* nod = st.top();
                if(nod->left) st.push(nod->left);
                else break;
            }
        }
        else {
            post_order.push_back(node->val);
            st.pop();
        }
    }
    return post_order;
}

// Method 2 (without modifying the tree)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::postorderTraversal(TreeNode* root) {
    stack<pair<TreeNode*, int>> st; st.push({root, 0});
    vector<int> post_order;
    while(!st.empty()) {
        pair<TreeNode*, int> p = st.top(); st.pop();
        if(p.second == 1 || (!p.first->left && !p.first->right)) post_order.push_back(p.first->val);
        else {
            st.push({p.first, 1});
            if(p.first->right) st.push({p.first->right, 0});
            if(p.first->left) st.push({p.first->left, 0});
        }
    }
    return post_order;
}
```
