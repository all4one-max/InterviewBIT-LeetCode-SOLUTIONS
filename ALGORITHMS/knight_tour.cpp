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

int n,  m, y, e, t, q, u1, u2,  w, v, c, d, x, cur = 1;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 2000005, INF = 1000000000000000000;
vector<vector<int>> board(10, vector<int>(10, 0));
vector<vector<int>> visited(10, vector<int>(10, 0));
vector<array<int, 2>> mov = {{ -2, -1}, { -2, 1}, { -1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, { -1, 2}};
// Warnsdorff's rule

bool ok(int x, int y) {
    return ((x >= 1 && x <= 8) && (y >= 1 && y <= 8));
}

int get_dig(int x, int y) {
    int dig = 0;
    for (auto it : mov) {
        int nx = x + it[0], ny = y + it[1];
        if (ok(nx, ny) && !visited[nx][ny]) {
            dig++;
        }
    }
    return dig;
}

bool fill(int x, int y, int cur) {
    board[x][y] = cur;
    visited[x][y] = 1;
    if (cur == 64) return true;
    vector<array<int, 3>> pos_moves;
    for (auto it : mov) {
        int nx = x + it[0], ny = y + it[1];
        if (ok(nx, ny) && !visited[nx][ny]) {
            int dig = get_dig(nx, ny);
            pos_moves.pb({dig, nx, ny});
        }
    }
    sort(all(pos_moves));
    for (auto it : pos_moves) {
        if (!visited[it[1]][it[2]] && fill(it[1], it[2], cur + 1)) return true;
    }
    board[x][y] = 0;
    visited[x][y] = 0;
    return false;
}

void solve() {
    cin >> n >> m;
    swap(n, m);
    int cur = 1;
    bool ret = fill(n, m, cur);
    fo1(i, 9 ) {
        fo1(j, 9) cout << board[i][j] << " ";
        cout << endl;
    }
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
