// QUESTION D AT CODER - WIZARD IN MAZE ROUND 176
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
#define all(v)         v.begin(), v.end()
#define sz(v)          v.size()
#define pii            pair<int, int>

int n, x, m, y, e, t, k, len, u1, u2,  h, w;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
vector<vector<int>> dist(1001, vector<int> (1001, mod));
vector<vector<int>> adj(1001, vector<int> (1001, -1));
vector<vector<char>> board(1005, vector<char> (1005, 0));

void bfs_0_1() {
  deque<pair<int, int>> dq;
  vector<pair<int, int>> mov_a = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};
  dq.push_back({u1 - 1, u2 - 1});
  dist[u1 - 1][u2 - 1] = 0;
  while (!dq.empty()) {
    int i = dq.begin()->fi, j = dq.begin()->se;
    dq.pop_front();
    for (auto it : mov_a) {
      int nx = (i + it.fi), ny = (j + it.se);
      if (nx >= 0 && nx < h && ny >= 0 && ny < w && board[nx][ny] == '.' && (dist[nx][ny] > dist[i][j])) {
        dist[nx][ny] = dist[i][j];
        dq.push_front({nx, ny});
      }
    }
    for (int k = -2; k < 3; k++) {
      for (int l = -2; l < 3; l++) {
        int nx = (i + k), ny = (j + l);
        if (nx >= 0 && nx < h && ny >= 0 && ny < w && board[nx][ny] == '.' && (dist[nx][ny] > (dist[i][j] + 1))) {
          dist[nx][ny] = (dist[i][j] + 1);
          dq.push_back({nx, ny});
        }
      }
    }
  }
  if (dist[x - 1][y - 1] == mod) cout << -1 << endl;
  else cout << dist[x - 1][y - 1] << endl;
  return;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  cin >> h >> w;
  cin >> u1 >> u2;
  cin >> x >> y;
  fo(i, h) {
    fo(j, w) cin >> board[i][j];
  }
  bfs_0_1();
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
