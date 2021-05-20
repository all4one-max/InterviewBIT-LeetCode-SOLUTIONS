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

### [Diagonal Traversal (Star Marked)](https://www.interviewbit.com/problems/diagonal-traversal/)

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
vector<int> ans[100005];
void preorder(TreeNode* root, int ind) {
    if(!root) return;
    ans[ind].push_back(root->val);
    preorder(root->left, ind - 1);
    preorder(root->right, ind);
    return;
}

vector<int> Solution::solve(TreeNode* root) {
    for(int i = 0; i < 100005; i++) ans[i].clear();
    preorder(root, 100000);
    vector<int> ret;
    for(int i = 100004; i >= 0; i--) {
        auto it = ans[i];
        if(it.size()) for(auto it2 : it) ret.push_back(it2);
    }
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

### [Right view of Binary tree](https://www.interviewbit.com/problems/right-view-of-binary-tree/)

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
vector<int> Solution::solve(TreeNode* root) {
    // he asks for the last node of each level
    deque<TreeNode*> q; q.push_back(root);
    vector<int> ans;
    while(true) {
        deque<TreeNode*> q2;
        ans.push_back(q.back()->val);
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop_front();
            if(node->left) q2.push_back(node->left);
            if(node->right) q2.push_back(node->right);
        }
        q = q2;
        if(q.empty()) break;
    }
    return ans;
}
```

### [Cousins in Binary Tree](https://www.interviewbit.com/problems/cousins-in-binary-tree/)

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
vector<int> Solution::solve(TreeNode* root, int b) {
    if(b == root->val) return {};
    vector<int> parent(100005, -1);
    queue<TreeNode*> q; q.push(root);
    vector<int> ans;
    int found = 0;
    while(true) {
        queue<TreeNode*> q2;
        while(!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if(node->left) {
                parent[node->left->val] = node->val;
                if(node->left->val == b) found = 1;
                q2.push(node->left);
            }
            if(node->right) {
                parent[node->right->val] = node->val;
                if(node->right->val == b) found = 1;
                q2.push(node->right);
            }
        }
        while(!q2.empty()) {
            TreeNode* node = q2.front(); q2.pop();
            if(found && parent[node->val] != parent[b]) ans.push_back(node->val);
            q.push(node);
        }
        if(found) return ans;
        if(q.empty()) break;

    }
}
```

### [ZigZag Level Order Traversal BT](https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/)

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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q; q.push(root); int cur = 0;
    while(!q.empty()) {
        int n = q.size();
        vector<int> lvl_ans;
        while(n) {
            TreeNode* node = q.front(); q.pop();
            lvl_ans.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            n--;
        }
        if(cur) reverse(lvl_ans.begin(), lvl_ans.end());
        cur = 1 - cur;
        ans.push_back(lvl_ans);
    }
    return ans;
}
```

### [Populate Next Right Pointers Tree (Star Marked)](https://www.interviewbit.com/problems/populate-next-right-pointers-tree/)

```cpp
// Method 1 (using level order traversal and not constant space solution)
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* root) {
    deque<TreeLinkNode*> q; q.push_back(root);
    while(true) {
        int n = q.size(); deque<TreeLinkNode*> q2;
        TreeLinkNode* last = NULL;
        while(!q.empty()) {
            TreeLinkNode* node = q.back(); q.pop_back();
            node->next = last; last = node;
            if(node->right) q2.push_front(node->right);
            if(node->left) q2.push_front(node->left);
        }
        q = q2;
        if(q.empty()) break;
    }
    return;
}

// Method 2 (using constant space)
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* root) {
    TreeLinkNode* cur = root;
    TreeLinkNode* prev = NULL;
    TreeLinkNode* next_lvl_node = NULL;
    while(cur) {
        if(prev) {
            if(cur->left) prev->next = cur->left;
            else if(cur->right) prev->next = cur->right;
        }
        if(cur->left && cur->right) {
            if(!next_lvl_node) next_lvl_node = cur->left;
            cur->left->next = cur->right;
            prev = cur->right;
        }
        else if(cur->left) {
            if(!next_lvl_node) next_lvl_node = cur->left;
            prev = cur->left;
        }
        else if(cur->right) {
            if(!next_lvl_node) next_lvl_node = cur->right;
            prev = cur->right;
        }
        if(cur->next) cur = cur->next;
        else {
            if(prev) prev->next = NULL;
            if(next_lvl_node) {
                cur = next_lvl_node;
                prev = NULL; next_lvl_node = NULL;
            }
            else break;
        }
    }
    return;
}
```

### [Hotel Reviews (Star Marked)](https://www.interviewbit.com/problems/hotel-reviews/)

```cpp
// using trie
struct trie_node {
    unordered_map<char, trie_node*> m;
    char c;
    bool terminal; // we have added this because if abb and abba are both present
    // as words then how will we know whether we have a particular word or not
    trie_node(char x) {
        c = x;
        terminal = false;
    }
};

void insert(string s, trie_node* head) {
    if(s.size() == 0) {
        head->terminal = true;
        return;
    }
    if(!head->m[s[0]]) {
        trie_node* new_node = new trie_node(s[0]);
        head->m[s[0]] = new_node;
    }
    insert(s.substr(1), head->m[s[0]]);
    return;
}

int check(string s, trie_node* head) {
    if(s.size() == 0) {
        if(head->terminal) return 1;
        return 0;
    }
    if(!head->m[s[0]]) return 0;
    if (check(s.substr(1), head->m[s[0]])) return 1;
    return 0;
}

vector<int> Solution::solve(string a, vector<string> &b) {
    int n = a.size();
    string s;
    trie_node* head = new trie_node('?');
    for(int i = 0; i < n; i++) {
        if(a[i] == '_' || (i == n - 1)) {
            if(i == n - 1) s.push_back(a[i]);
            insert(s, head);
            s = "";
        }
        else s.push_back(a[i]);
    }
    map<int, vector<int>> mp;
    for(int i = 0; i < b.size(); i++) {
        string s;
        int count = 0;
        for(int j = 0; j < b[i].size(); j++) {
            if(b[i][j] == '_' || (j == b[i].size() - 1)) {
                if((j == b[i].size() - 1)) s.push_back(b[i][j]);
                if(check(s, head)) count++;
                s = "";
            }
            else s.push_back(b[i][j]);
        }
        mp[count].push_back(i);
    }
    vector<int> ans;
    for(auto it = mp.rbegin(); it != mp.rend(); it++) {
        for(auto ind : it->second) ans.push_back(ind);
    }
    return ans;
}
```

### [Shortest Unique Prefix](https://www.interviewbit.com/problems/shortest-unique-prefix/)

```cpp
// using trie
struct trie_node {
    unordered_map<char, trie_node*> m;
    char c;
    int count;
    trie_node(char x) {
        c = x;
        count = 1;
    }
};

void insert(string word, trie_node* head) {
    for(int i = 0; i < word.size(); i++) {
        if(!head->m[word[i]]) {
            trie_node* new_node = new trie_node(word[i]);
            head->m[word[i]] = new_node;
        }
        else head->m[word[i]]->count++;
        head = head->m[word[i]];
    }
    return;
}

string get_pref(string word, trie_node* head) {
    string pref;
    for(int i = 0; i < word.size(); i++) {
        pref.push_back(word[i]);
        if(head->m[word[i]]->count == 1) return pref;
        else head = head->m[word[i]];
    }
}

vector<string> Solution::prefix(vector<string> &a) {
    trie_node* head = new trie_node('?');
    for(auto word : a) insert(word, head);
    vector<string> ans;
    for(auto word : a) ans.push_back(get_pref(word, head));
    return ans;
}
```

### [Inorder Traversal of Cartesian Tree](https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/)

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
TreeNode* recur(vector<int> &a ,int i, int n) {
    if(n - i < 0) return NULL;
    int mx = -1, note = -1;
    for(int j = i; j <= n; j++) {
        if(a[j] > mx) {
            mx = a[j];
            note = j;
        }
    }
    TreeNode* root = new TreeNode(mx);
    root->left = recur(a, i, note - 1);
    root->right = recur(a, note + 1, n);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &a) {
    int n = a.size();
    return recur(a, 0, n - 1);
}
```

### [Inorder Traversal of Cartesian Tree](https://www.interviewbit.com/problems/inorder-traversal-of-cartesian-tree/)

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
TreeNode* balanceBST(const vector<int> &a, int i, int n) {
    if(n - i < 0) return NULL;
    int mid = (i + n)/2;

    TreeNode* root = new TreeNode(a[mid]);
    root->left = balanceBST(a, i, mid - 1);
    root->right = balanceBST(a, mid + 1, n);

    return root;
}

TreeNode* Solution::sortedArrayToBST(const vector<int> &a) {
    int n = a.size();
    return balanceBST(a, 0, n - 1);
}
```

### [Construct Binary Tree From Inorder And Preorder (Star Marked)](https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/)

```cpp
// Method 1 (Using Recursion)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(int pi, int pn, int ii, int in, vector<int> &a, vector<int> &b) {
    if(pn - pi < 0) return NULL;
    int pos = -1;
    for(int i = ii; i <= in; i++) {
        if(a[pi] == b[i]) {
            pos = i;
            break;
        }
    }
    int on_the_left = pos - ii;
    int on_the_right = in - pos;

    TreeNode* root = new TreeNode(a[pi]);
    root->left = solve(pi + 1, pi + on_the_left, pos - on_the_left, pos - 1, a, b);
    root->right = solve(pi + on_the_left + 1, pn, pos + 1, pn, a, b);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &a, vector<int> &b) {
    int n = a.size();
    return solve(0, n - 1, 0, n - 1, a, b);
}

// Method 2 (iterative method, logic was easy to think but implementation was tough)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &a, vector<int> &b) {
    int n = a.size();
    int i = 0, inorder_next = 0; TreeNode* root = NULL;
    stack<TreeNode*> st; unordered_map<int, int> mp; TreeNode* last = NULL;
    while(inorder_next < n) {
        while(i < n) {
            TreeNode* node = new TreeNode(a[i]);
            if(!last && !st.empty()) st.top()->left = node;
            else if(last) {
                last->right = node;
                last = NULL;
            }
            if(!root) root = node;
            st.push(node); mp[node->val] = 1;
            if(a[i] == b[inorder_next]) {i++; break;}
            i++;
        }
        while(inorder_next < n && mp[b[inorder_next]]) {
            mp[b[inorder_next]] = 0;
            last = st.top(); st.pop();
            inorder_next++;
        }
    }
    return root;
}
```

### [Binary Tree From Inorder And Postorder](https://www.interviewbit.com/problems/binary-tree-from-inorder-and-postorder/)

```cpp
// Method 1 (Using Recursion)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(int ii, int in, int pi, int pn, vector<int> &a, vector<int> &b) {
    if(in - ii < 0) return NULL; int pos = -1;
    for(int i = in; i >= ii; i--) {
        if(a[i] == b[pn]) {
            pos = i;
            break;
        }
    }
    TreeNode* root = new TreeNode(b[pn]);
    int on_the_left = pos - ii;
    root->left = solve(ii, pos - 1, pi, pi + on_the_left - 1, a, b);
    root->right = solve(pos + 1, in, pi + on_the_left, pn - 1, a, b);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &a, vector<int> &b) {
    int n = a.size();
    return  solve(0, n - 1, 0, n - 1, a, b);
}

//  Method 2 (iteratively)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::buildTree(vector<int> &a, vector<int> &b) {
    int n = a.size();
    stack<TreeNode*> st; unordered_map<int, int> mp;
    int i = n - 1, inorder_next = n - 1; TreeNode* root = NULL; TreeNode* last = NULL;
    while(inorder_next >= 0) {
        while(i >= 0) {
            TreeNode* node = new TreeNode(b[i]);
            if(!last && !st.empty()) st.top()->right = node;
            if(last) {
                last->left = node;
                last = NULL;
            }
            if(!root) root = node;
            st.push(node); mp[node->val] = 1;
            if(b[i] == a[inorder_next]) {
                i--;
                break;
            }
            i--;
        }
        while(inorder_next >= 0 && mp[a[inorder_next]]) {
            last = st.top(); st.pop();
            mp[a[inorder_next]] = 0;
            inorder_next--;
        }
    }
    return root;
}
```

### [Invert the Binary Tree](https://www.interviewbit.com/problems/invert-the-binary-tree/)

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
TreeNode* Invert(TreeNode* root) {
    if(!root) return NULL;
    if(!root->left && !root->right) return root;
    TreeNode* temp = root->left;
    if(root->right) root->left = Invert(root->right);
    else root->left = NULL;
    if(temp) root->right = Invert(temp);
    else root->right = NULL;
    return root;
}

TreeNode* Solution::invertTree(TreeNode* root) {
    return Invert(root);
}
```

### [Max Depth of Binary Tree](https://www.interviewbit.com/problems/max-depth-of-binary-tree/)

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
int solve(TreeNode* root) {
    if(!root) return 0;
    int ans = 1;
    int left = solve(root->left); int right = solve(root->right);
    ans = max(ans + left, ans + right);
    return ans;
}

int Solution::maxDepth(TreeNode* root) {
    return solve(root);
}
```

### [Sum Root to Leaf Numbers](https://www.interviewbit.com/problems/max-depth-of-binary-tree/)

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
int sum = 0;
void solve(TreeNode* root, int num) {
    if(!root) return;
    if(!root->left && !root->right) {
        int ans = num + root->val;
        ans %= 1003; sum = sum + ans; sum %= 1003;
    }
    solve(root->left, ((num + root->val)*10)%1003);
    solve(root->right, ((num + root->val)*10)%1003);
    return;
}

int Solution::sumNumbers(TreeNode* a) {
    if(!a) return 0;
    if(!a->left && !a->right) return a->val;
    sum = 0;
    solve(a, 0);
    return sum;
}
```

### [Path Sum](https://www.interviewbit.com/problems/max-depth-of-binary-tree/)

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
int solve(TreeNode* root, int cur_sm, int sm) {
    if(!root) return 0;
    if(!root->left && !root->right) {
        if((cur_sm + root->val) == sm) return 1;
        return 0;
    }
    if(solve(root->left, (cur_sm + root->val), sm)) return 1;
    if(solve(root->right, (cur_sm + root->val), sm)) return 1;
    return 0;
}

int Solution::hasPathSum(TreeNode* a, int b) {
    return solve(a, 0, b);
}
```

### [Min Depth of Binary Tree](https://www.interviewbit.com/problems/min-depth-of-binary-tree/)

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
int mn = 1e9;
void solve(TreeNode* root, int lvl) {
    if(!root) return;
    if(!root->left && !root->right) mn = min(mn, lvl + 1);
    if(root->left) solve(root->left, lvl + 1);
    if(root->right) solve(root->right, lvl + 1);
    return;
}

int Solution::minDepth(TreeNode* root) {
    mn = 1e9;
    solve(root, 0);
    return mn;
}
```

### [Root to Leaf Paths With Sum](https://www.interviewbit.com/problems/root-to-leaf-paths-with-sum/)

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
void solve(TreeNode* root, int cur_sm, int sm, vector<int> &temp, vector<vector<int>> &ans) {
    if(!root) return;
    temp.push_back(root->val);
    if(!root->left && !root->right) {
        if(cur_sm + root->val == sm) ans.push_back(temp);
    }
    if(root->left) solve(root->left, cur_sm + root->val, sm, temp, ans);
    if(root->right) solve(root->right, cur_sm + root->val, sm, temp, ans);
    temp.pop_back();
    return;
}

vector<vector<int> > Solution::pathSum(TreeNode* a, int b) {
    vector<vector<int>> ans;
    vector<int> temp;
    solve(a, 0, b, temp, ans);
    return ans;
}
```

### [Least Common Ancestor](https://www.interviewbit.com/problems/least-common-ancestor/)

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
bool solve(TreeNode* root, int vl, vector<int> &path) {
    if(!root) return false;
    if(root->val == vl) {
        path.push_back(root->val);
        return true;
    }
    path.push_back(root->val);
    if(solve(root->left, vl, path)) return true;
    if(solve(root->right, vl, path)) return true;
    path.pop_back();
    return false;
}

int Solution::lca(TreeNode* root, int b, int c) {
    vector<int> path_to_b, path_to_c;
    bool grb = solve(root, b, path_to_b); bool grb2 = solve(root, c, path_to_c);
    if(!grb || !grb2) return -1;
    int n = path_to_b.size(), m = path_to_c.size();
    int mn = min(n, m);
    int ans, i = 0;
    while(i < mn) {
        if(path_to_b[i] == path_to_c[i]) ans = path_to_b[i];
        else break;
        i++;
    }
    return ans;
}
```

### [Flatten Binary Tree to Linked List (Star Marked)](https://www.interviewbit.com/problems/flatten-binary-tree-to-linked-list/)

```cpp
// Method 1 (Using Recursion)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* solve(TreeNode* root) {
    if(!root) return NULL;
    if(!root->left && !root->right) return root;
    TreeNode* rec_left = solve(root->left);
    root->left = NULL;
    TreeNode* save = root->right;
    root->right = rec_left;
    TreeNode* save_root = root;
    TreeNode* rec_right = solve(save);
    while(root->right) root = root->right;
    root->right = rec_right;
    return save_root;
}

TreeNode* Solution::flatten(TreeNode* root) {
    solve(root);
    return root;
}

// Method 2 (Using Iterative Solution)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::flatten(TreeNode* node) {
    TreeNode* root = node;
    while(root) {
        if(root->left) {
            TreeNode* temp = root->left;
            while(temp->right) temp = temp->right;
            temp->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }
        else root = root->right;
    }
    return node;
}
```

### [Order of People Heights (Star Marked)](https://www.interviewbit.com/problems/order-of-people-heights/)

```cpp
// Method 1 (O(n**2) solution)
vector<int> Solution::order(vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<int> ans(n, 0);
    vector<int> avail(n, 1);
    for(int i = 0; i < n; i++) {
        int mn = 1e9, pos = -1;
        for(int j = 0; j < n; j++) {
            if(avail[j] && b[j] == 0 && mn > a[j]) {
                pos = j;
                mn = a[j];
            }
        }
        for(int j = 0; j < n; j++) {
            if(avail[j] && mn > a[j]) b[j]--;
        }
        avail[pos] = 0;
        ans[i] = mn;
    }
    return ans;
}

// Method 2 (Using Segment Tree)
bool comp(array<int, 2> a1, array<int, 2> a2) {
    if(a1[0] <= a2[0]) return true;
    return false;
}

void buildTree(vector<int> &tree, int idx, int tl, int tr) {
    if(tl == tr) {
        tree[idx] = 1;
        return;
    }
    int tm = (tl + tr)/2;
    buildTree(tree, 2*idx, tl, tm);
    buildTree(tree, 2*idx + 1, tm + 1, tr);
    tree[idx] = tree[2*idx] + tree[2*idx + 1];
    return;
}

int query(vector<int> &tree, int count, int idx, int tl, int tr) {
    if(tl == tr) return tl;
    int tm = (tl + tr)/2;
    if(count > tree[2*idx]) return query(tree, count - tree[2*idx], 2*idx + 1, tm + 1, tr);
    else return query(tree, count, 2*idx, tl, tm);
}

void update(vector<int> &tree, int pos, int idx, int tl, int tr) {
    if(tl == tr) {
        tree[idx] = 0;
        return;
    }
    int tm = (tl + tr)/2;
    if(pos > tm) update(tree, pos, 2*idx + 1, tm + 1, tr);
    else update(tree, pos, 2*idx, tl, tm);
    tree[idx] = tree[2*idx] + tree[2*idx + 1];
    return;
}

vector<int> Solution::order(vector<int> &a, vector<int> &b) {
    int n = a.size();
    vector<array<int, 2>> arr;
    for(int i = 0; i < n; i++) arr.push_back({a[i], b[i] + 1});
    sort(arr.begin(), arr.end(), comp);
    vector<int> ans(n, 0);
    vector<int> tree(4*n, 0);
    buildTree(tree, 1, 0, n - 1);
    for(int i = 0; i < n; i++) {
        int pos = query(tree, arr[i][1], 1, 0, n - 1);
        ans[pos] = arr[i][0];
        update(tree, pos, 1, 0, n - 1);
    }
    return ans;
}
```
