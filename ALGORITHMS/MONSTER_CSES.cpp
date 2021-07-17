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

int n,  m, y, e, t, k, len, u1, u2,  w, v, d;
vector<vector<char>> store(1005, vector<char> (1005, 0));
vector<vector<int>> visited(1001, vector<int> (1001, 0));
vector<array<int, 2>> mov = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<pii>> parent(1001, vector<pii> (1001, { -1, -1}));
vector<vector<int>> distanc(1001, vector<int> (1001, 1e9));
queue<pii> q;

void bfs() {
  if (q.empty()) return;
  auto it = q.front();
  int x = it.fi, y = it.se;
  vector<vector<int>> visited(1001, vector<int>(1001, 0));
  visited[x][y] = 1;
  vector<vector<int>> dist(1001, vector<int>(1001, 0));
  while (!q.empty()) {
    auto it = q.front();
    int x = it.fi, y = it.se;
    q.pop();
    for (auto mv : mov) {
      int nx = x + mv[0], ny = y + mv[1];
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && store[nx][ny] != '#') {
        if (visited[nx][ny] == 0 && store[nx][ny] != 'M') {
          q.push({nx, ny});
          visited[nx][ny] = 1;
          dist[nx][ny] = dist[x][y] + 1;
          distanc[nx][ny] = min(distanc[nx][ny], dist[nx][ny]);
        }
        else {
          distanc[nx][ny] = min(distanc[nx][ny], dist[x][y] + 1);
        }
      }
    }
  }
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
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "YES" << endl;
    cout << 0 << endl;
  }
  else {
    fo(i, n) fo(j, m) cin >> store[i][j];
    int x, y;
    fo(i, n) {
      fo(j, m) {
        if (store[i][j] == 'M') {
          q.push({i, j});
          visited[i][j] = 1;
        }
        else if (store[i][j] == 'A') {x = i, y = j;}
      }
    }
    auto it = q.front();
    bfs();
    vector<vector<int>> visited(1001, vector<int>(1001, 0));
    visited[x][y] = 1;
    queue<pii> q;
    vector<vector<int>> dist(1001, vector<int>(1001, 0));
    vector<vector<array<int, 2>>> parent(1001, vector<array<int, 2>>(1001, {0, 0}));
    parent[x][y] = { -1, -1};
    q.push({x, y});
    array<int, 2> note;
    bool not_found = true;
    while (!q.empty()) {
      auto it = q.front();
      int x = it.fi, y = it.se;
      q.pop();
      if (x == (n - 1) || (y == (m - 1)) || (x == 0) || (y == 0)) {
        //cout << "ok" << endl;
        not_found = false;
        note = {x, y};
        break;
      }
      for (auto mv : mov) {
        int nx = x + mv[0], ny = y + mv[1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited[nx][ny] == 0 && store[nx][ny] != '#') {
          parent[nx][ny] = {x, y};
          dist[nx][ny] = dist[x][y] + 1;
          if (dist[nx][ny] < distanc[nx][ny]) {
            q.push({nx, ny});
            visited[nx][ny] = 1;
          }
        }
      }
    }
    if (not_found) cout << "NO" << endl;
    else {
      vector<pii> ans = {{note[0], note[1]}};
      x = note[0], y = note[1];
      string s = "";
      while (true) {
        auto it = parent[x][y];
        if (it[0] == -1) break;
        ans.pb({it[0], it[1]});
        if (it[0] > x) s += 'U';
        else if (it[0] < x) s += 'D';
        else if (it[1] > y) s += 'L';
        else s += 'R';
        x = it[0], y = it[1];
      }
      cout << "YES" << endl;
      cout << sz(s) << endl;
      reverse(all(s));
      cout << s << endl;
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
######  #   # #### #    # #   #   #w
*/
