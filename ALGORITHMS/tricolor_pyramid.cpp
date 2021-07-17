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

int n,  m, y, e, t, k, q, u1, u2,  w, v, d, x, ans = 0;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> fact(400005, 1);
vector<int> fact_mod_p(400005, 1);
vector<int> c(400005, 0);

int fme(int a, int b, int mod) {
  int rest = 1;
  while (b) {
    if (b & 1) rest = (rest * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return rest;
}

int modinv(int a, int mod) {return fme(a, mod - 2, mod);}

int binomial(int n, int r, int mod) {
  if (r < 0 || r > n ) return 0;
  if (c[n] - c[r] - c[n - r] >= 1) return 0;
  return (fact_mod_p[n] * modinv(fact_mod_p[r], mod) % mod * modinv(fact_mod_p[n - r], mod) % mod) % mod;
} //ncr

int nfact_mod_p(int n, int p) {
  // n!%p = (n%p)! * ((n/p)!%p)
  int ans = 1;
  while (n) {
    if ((n / p) % 2) {
      ans = p - ans;
    }
    ans = ans * (fact[n % p]);
    n = n / p;
  }
  return ans;
}

int multiplicity_factorial(int n, int p) {
  int count = 0;
  do {
    n /= p;
    count += n;
  } while (n);
  return count;
}

void solve() {
  string s;
  for (int i = 1; i < 3; i++) {
    fact[i] = (fact[i - 1] * i) % 3;
  }
  fo1(i, (400000 + 5)) {
    fact_mod_p[i] = nfact_mod_p(i, 3);
  }

  fo(i, (400000 + 5)) {
    c[i] = multiplicity_factorial(i, 3);
  }

  cin >> n; cin >> s;
  int two = 1;
  fo(i, n - 1) {
    two *= 2;
    two %= 3;
  }
  int ans = 0;
  fo(i, n) {
    // (n-1)Ci
    int val;
    if (s[i] == 'B') val = 0;
    if (s[i] == 'W') val = 1;
    if (s[i] == 'R') val = 2;
    int val2 = binomial(n - 1, i, 3);
    ans += (val2 * val);
    ans %= 3;
  }
  ans = two * ans;
  ans = ans % 3;
  if (ans == 0) cout << "B" << endl;
  else if (ans == 1) cout << "W" << endl;
  else if (ans == 2) cout << "R" << endl;
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
