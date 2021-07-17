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

int n,  m, y, e, t, k, len, u1, u2,  f, sm = 0, cnt = 0, x, q;
const int mx = 200005, mod = 1000000009, mx2 = 1000005 , mx3 = 1000001;
vector<int> a(5, 0);
vector<int> b(5, 0);

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  cin >> n;
  fo(i, 3) cin >> a[i];
  fo(i, 3) cin >> b[i];
  vector<pair<int, int>> not_win = {{0, 0}, {0, 2}, {1, 0}, {1, 1}, {2, 1}, {2, 2}};
  int mn = 1e10;
  do {
    vector<int> cpy_a = a, cpy_b = b;
    for (int i = 0; i < sz(not_win); i++) {
      if (cpy_a[not_win[i].fi] > cpy_b[not_win[i].se]) {
        cpy_a[not_win[i].fi] -= cpy_b[not_win[i].se];
        cpy_b[not_win[i].se] = 0;
      }
      else {
        cpy_b[not_win[i].se] -= cpy_a[not_win[i].fi];
        cpy_a[not_win[i].fi] = 0;
      }
    }
    int cur_ans = min(cpy_a[0], cpy_b[1]) + min(cpy_a[1], cpy_b[2]) + min(cpy_a[2], cpy_b[0]);
    mn = min(mn, cur_ans);
  } while (next_permutation(all(not_win)));
  int mx = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
  cout << mn << " " << mx << endl;
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
