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

int n,  m, y, e, t, k, q, u1, u2,  w, v, c, d, x, ans = 0;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;

void nfact_mod_p(int n, int p) {
  vector<int> fact(p); fact[0] = 1;
  fo1(i, p) {
    fact[i] = (i * fact[i - 1]);
    fact[i] %= p;
  }
  // n!%p = (n%p)! * ((n/p)!%p)
  int ans = 1;
  while (n) {
    if ((n / p) % 2) {
      ans = p - ans;
    }
    ans = ans * (fact[n % p]);
    n = n / p;
  }
  cout << ans << endl;
  return;
}

void multiplicity_factorial(int n, int p) {
  int count = 0;
  do {
    n /= p;
    count += n;
  } while (n);
  cout << count << endl;
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
  nfact_mod_p(12, 3);
  multiplicity_factorial(12, 3);
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
