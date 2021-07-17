#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
#include <unordered_map>
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

int n,  m, x, y, e, t, k, len, u1, u2,  w, v, d;
const int mx = 200005, mod = 1000000007, mx2 = 1000005 , mx3 = 100005;

void solve() {
  cin >> n;
  vector<int> a(n), h(n);
  fo(i, n) cin >> a[i];
  vector<int> ones, others;
  vector<pii> answer;
  int nxt = n;
  for (int i = n - 1; i >= 0; i--) {
    int pair_with = -1;
    if (a[i] == 2) {
      if (ones.empty()) {
        cout << -1 << endl;;
        return;
      }
      else {
        pair_with = ones.back();
        ones.pop_back();
      }
    }
    else if (a[i] == 3) {
      if (others.empty()) {
        if (ones.empty()) {
          cout << -1 << endl;;
          return;
        }
        else {
          pair_with = ones.back();
          ones.pop_back();
        }
      }
      else {
        pair_with = others.back();
        others.pop_back();
      }
    }
    if (a[i] == 1) ones.pb(i);
    else if (a[i] == 2 || a[i] == 3) others.pb(i);
    if (a[i] == 1) {
      h[i] = nxt--;
      answer.emplace_back(h[i], i + 1);
    }
    else if (a[i] == 2) {
      h[i] = h[pair_with];
      answer.emplace_back(h[i], i + 1);
    }
    else if (a[i] == 3) {
      h[i] = nxt--;
      answer.emplace_back(h[i], pair_with + 1);
      answer.emplace_back(h[i], i + 1);
    }
  }
  cout << sz(answer) << endl;
  for (auto it : answer) {
    cout << it.fi << " " << it.se << endl;
  }
  //fo(i, n) cout << h[i] << " ";
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
  solve();
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
