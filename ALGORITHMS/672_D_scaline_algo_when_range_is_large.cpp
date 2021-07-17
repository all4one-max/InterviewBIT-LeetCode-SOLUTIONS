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

int n,  m, y, e, t, k, len, u1, u2,  f, sm = 0, cnt = 0, x, q, a, b;
const int mx = 300005, mod = 998244353, mx2 = 1000005 , mx3 = 100000;
vector<pii> v;
vector<int> fact(mx, 1);

int fme(int a, int b) {
  int rest = 1;
  while (b) {
    if (b & 1) rest = (rest * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return rest;
}

bool comp(pair<int, int>p1, pair<int, int>p2) {
  if (p1.fi < p2.fi) return true;
  else if (p1.fi == p2.fi) {
    if (p1.se < p2.se) return true;
  }
  return false;
}

int modinv(int a) {return fme(a, mod - 2);}

int binomial(int n, int r) {return (fact[n] * modinv(fact[r]) % mod * modinv(fact[n - r]) % mod) % mod;} //ncr

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  for (int i = 1; i < (mx + 1); i++) {
    fact[i] = (fact[i - 1] * i) % mod;
  }
  cin >> n >> k;
  fo(i, n) {
    cin >> a >> b;
    v.pb({a, 1});
    v.pb({b + 1, -1});
  }
  sort(v.begin(), v.end(), comp);
  int on_so_far = 0, ans = 0;
  for (auto it : v) {
    if (it.se == 1) {
      if ((on_so_far) >= (k - 1)) {
        ans += (binomial(on_so_far, k - 1));
        ans %= mod;
      }
      on_so_far += 1;
    }
    else on_so_far -= 1;
  }
  cout << ans << endl;
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
