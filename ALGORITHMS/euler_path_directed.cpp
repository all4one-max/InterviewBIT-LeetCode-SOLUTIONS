#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int            long long
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define sz(v)          v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, q, u1, u2,  w, v, c, d, x;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> adj[mx2];
vector<int> indegree(mx2, 0), outdegree(mx2, 0);
map<pii, int> mpp;

void solve() {
    cin >> n >> m;
    fo(i, m) {
        cin >> u1 >> u2;
        adj[u1].pb(u2);
        mpp[ {u1, u2}]++;
        indegree[u2]++;
        outdegree[u1]++;
    }

    int v1 = -1, v2 = -1;
    fo1(i, n + 1) {
        if (outdegree[i] - indegree[i] > 1) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        if (indegree[i] - outdegree[i] > 1) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        if (outdegree[i] - indegree[i] == 1) {
            if (v1 == -1) v1 = i;
            else {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
        if (indegree[i] - outdegree[i] == 1) {
            if (v2 == -1) v2 = i;
            else {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    if (v1 == -1 || v2 == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    stack<int> st;
    st.push(v1);
    vector<int> res;
    while (!st.empty()) {
        int v = st.top();
        if (outdegree[v] == 0) {
            res.pb(v);
            st.pop();
        }
        else {
            for (auto it : adj[v]) {
                if (mpp[ {v, it}] > 0) {
                    mpp[ {v, it}]--;
                    outdegree[v]--;
                    st.push(it);
                    break;
                }
            }
        }
    }

    fo(i, n + 1) {
        if (outdegree[i]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }

    reverse(all(res));
    for (auto it : res) cout << it << " ";
    cout << endl;
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
# endif
    t = 1;
    fo(i, t) solve();
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
