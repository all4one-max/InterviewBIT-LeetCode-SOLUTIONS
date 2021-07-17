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

int n, x, m, y, e, t, k, len, u1, u2,  f, q, lg, curr = 0;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
vector<int> arr(mx, 0);
vector<int> adj[mx];
int up[mx][20];

void binary_lift(int v, int p) {
    up[v][0] = p;
    for (int i = 1; i < 20; i++) {
        if (up[v][i - 1] != -1) {
            up[v][i] = up[up[v][i - 1]][i - 1];
        } else up[v][i] = -1;
    }
    for (auto it : adj[v]) {
        if (it != p) {
            binary_lift(it, v);
        }
    }
    return;
}

int query(int u1, int k) {
    int i = 0;
    while (k > 0) {
        if (k & 1) {
            u1 = up[u1][i];
            if (u1 == -1) return -1;
        }
        k = k >> 1;
        i += 1;
    }
    return u1;
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
    fo(i, n - 1) {
        cin >> u1;
        adj[i + 2].pb(u1);
        adj[u1].pb(i + 2);
    }
    binary_lift(1, -1);
    fo(i, q) {
        cin >> u1 >> u2;
        cout << query(u1, u2) << endl;
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
