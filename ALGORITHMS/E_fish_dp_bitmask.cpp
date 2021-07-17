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

int n,  m, y, e, t, k, q, u1, u2,  w, v, d;
const int mx = 300005, mod = 998244353, mx2 = 1000005 , mx3 = 200005, INF = 10000000000000000;
vector<vector<float>> prob(20, vector<float>(20, 0));
vector<float> dp(mx2, -1);

float move(int mask, int fish_lose) {
  int alive = __builtin_popcount(mask);
  float den = (alive * (alive - 1)) / 2;
  float cur_ans = 0;
  fo(fish, n) {
    if ((1 << fish)&mask) {
      cur_ans += prob[fish][fish_lose];
    }
  }
  return cur_ans / (1.0 * den);
}

float fish_win(int mask) {
  int alive = __builtin_popcount(mask);
  if (alive == n) return 1;
  if (dp[mask] != -1) return dp[mask];
  float ans = 0;
  fo(fish, n) {
    if (!(mask & (1 << fish))) {
      int prev_bitMask = mask ^ (1 << fish);
      float prev_mask_ans = fish_win(prev_bitMask);
      float prev_cur_ans = move(prev_bitMask, fish);
      ans += prev_cur_ans * prev_mask_ans;
    }
  }
  return dp[mask] = ans;
}

//dp[mask] is nothing but the probabily of that set of fish which are alive in the mask
// 1 means alive, 0 means dead

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  cin >> n;
  fo(i, n) {
    fo(j, n) cin >> prob[i][j];
  }
  fo(i, n) {
    cout << fixed << setprecision(7) << fish_win(1 << i) << " ";
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
