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

int n, x, m, y, e, t, k, len, u1, u2, q, f;
const int mx = 800005, mod = 1000000007, mx2 = 200005 , mx3 = 2000005, INF = 1000000000000000000;
vector<int> tre(mx, 0);
vector<int> marked(mx, 0);
vector<int> a(mx2, 0);

void buildTree(int tl, int tr, int treeNode) {
    if (tl == tr) {tre[treeNode] = a[tl]; return;}
    int tm = (tl + tr) / 2;
    buildTree(tl, tm, 2 * treeNode);
    buildTree((tm + 1), tr, 2 * treeNode + 1);
    tre[treeNode] = 0;
    return;
}

void push(int treeNode) {
    if (marked[treeNode]) {
        tre[treeNode * 2] = tre[treeNode * 2 + 1] = tre[treeNode];
        marked[treeNode * 2] = marked[treeNode * 2 + 1] = true;
        marked[treeNode] = false;
    }
}

void updateTree(int tl, int tr, int treeNode, int l, int r, int new_value) {
    if (l > r) return;
    if (tl == l && tr == r) {
        tre[treeNode] = new_value;
        marked[treeNode] = 1;
        return;
    }
    push(treeNode);
    int tm = (tl + tr) / 2;
    updateTree(tl, tm, 2 * treeNode, l, min(tm, r), new_value);
    updateTree(tm + 1, tr, 2 * treeNode + 1, max(tm + 1, l), r, new_value);
    return;
}

int query(int tl, int tr, int treeNode, int pos) {
    if (tl == tr) return tre[treeNode];
    push(treeNode);
    int tm = (tl + tr) / 2;
    if (pos <= tm) return query(tl, tm, 2 * treeNode, pos);
    else return query(tm + 1, tr, 2 * treeNode + 1, pos);
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
# endif
    cin >> n >> q;
    fo(i, n) cin >> a[i];
    buildTree(0, n - 1, 1);
    fo(i, q) {
        cin >> x;
        if (x == 1) {
            cin >> u1 >> u2 >> k;
            u1--; u2--;
            updateTree(0, n - 1, 1, u1, u2, k);
        }
        else {
            cin >> u1;
            u1--;
            cout << query(0, n - 1, 1, u1) << endl;
        }
    }
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
