#include<bits/stdc++.h>

using namespace std;
struct TreeNode {
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode(): val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode * left, TreeNode * right): val(x), left(left), right(right) {}
};
int preInd = 0;
TreeNode * createTree(vector < int > & preorder, vector < int > & inorder, int start, int end) {
  if (start > end) {
    return NULL;
  }
  TreeNode * node = new TreeNode(preorder[preInd++]);
  int pos;
  for (int i = start; i <= end; i++) {
    if (inorder[i] == node -> val) {
      pos = i;
      break;
    }
  }
  node -> left = createTree(preorder, inorder, start, pos - 1);
  node -> right = createTree(preorder, inorder, pos + 1, end);
  return node;
}
int maxDist = 0;
int findMaxDistance(TreeNode * root) {
  if (root == NULL) return 0;
  int left = findMaxDistance(root -> left);
  int right = findMaxDistance(root -> right);
  int tt = left + right;
  maxDist = max(maxDist, tt);
  return max(left, right) + 1;
}
int main() {
  int tnodes;
  cin >> tnodes;
  vector < int > preorder(tnodes), inorder(tnodes);
  for (int i = 0; i < tnodes; ++i) cin >> preorder[i];
  for (int i = 0; i < tnodes; ++i) cin >> inorder[i];
  TreeNode * root = createTree(preorder, inorder, 0, inorder.size() - 1);
  findMaxDistance(root);
  cout << "Max Distance bw any two nodes in given tree is " << maxDist;
}

