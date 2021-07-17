#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int            long long
#define fo(i,n)        for(int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair

int n, x, m, y, e, t, k, len, u1, u2,  f;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
vector<int> tre(mx, 0);
vector<int> a(mx, 0);

void buildTree(int tl, int tr, int treeNode) {
    if (tl == tr) {tre[treeNode] = a[tl]; return;}
    int tm = (tl + tr) / 2;
    buildTree(tl, tm, 2 * treeNode);
    buildTree((tm + 1), tr, 2 * treeNode + 1);
    tre[treeNode] = tre[2 * treeNode] + tre[2 * treeNode + 1];
    return;
}

void updateTree(int tl, int tr, int treeNode, int idx, int value) {
    if (tl == tr) {
        a[idx] = value;
        tre[treeNode] = value;
        return;
    }
    int tm = (tl + tr) / 2;
    if (idx > tm) updateTree(tm + 1, tr, 2 * treeNode + 1, idx, value);
    else updateTree(tl, tm, 2 * treeNode, idx, value);
    tre[treeNode] = tre[2 * treeNode] + tre[2 * treeNode + 1];
    return;
}

int query(int tl, int tr, int treeNode, int left, int right) {
    if (left > right) return 0;
    if (left == tl && right == tr) return tre[treeNode];
    int tm = (tl + tr) / 2;
    int ans1 = query(tl, tm, 2 * treeNode, left, min(right, tm));
    int ans2 = query(tm + 1, tr, 2 * treeNode + 1, max(left, tm + 1), right);
    return ans1 + ans2;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
# endif
    cin >> n;
    fo(i, n) cin >> a[i];
    buildTree(0, n - 1, 1);
    for (auto it = (tre.begin() + 1); it != (tre.begin() + 2 * n + 1); it++) {
        cout << *it << " ";
    }
    cout << endl;
    updateTree(0, n - 1, 1, 2, 10);
    for (auto it = (tre.begin() + 1); it != (tre.begin() + 2 * n + 1); it++) {
        cout << *it << " ";
    }
    cout << endl;
    int ans = query(0, n - 1, 1, 2, 4);
    cout << "sum is " << ans << endl;
    cout.flush();
    return 0;
}

/*
    #######
   #
  #
 #######   #     #  # ####   # #     #
       #  # #   #  # #   #  # # #   #
      #  ####  #  # ####   ####  # #
######  #   # #### #    # #   #   #
*/
