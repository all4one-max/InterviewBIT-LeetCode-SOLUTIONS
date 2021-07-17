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

// The Z-function for a string is an array of length n where the i-th element
// is equal to the greatest number of characters starting from the position i
// that coincide with the first characters of s.

// In other words, z[i] is the length of the longest common prefix
// between s and the suffix of s starting at i.

// Note. In this article, to avoid ambiguity, we assume 0-based indexes;
// that is: the first character of s has index 0 and the last one has index n−1.

// The first element of Z-function, z[0], is generally not well defined.
// In this article we will assume it is zero (although it doesn't change anything
// in the algorithm implementation).

// O(N) time and space

int n,  m, y, e, t, k, q, u1, u2,  w, v, c, d, x, ans = 0;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
string s;

void solve() {
  cin >> s; n = sz(s); vector<int> z(n + 1, 0); int l = 0, r = 0;
  fo1(i, n) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  fo(i, n) cout << z[i] << " "; cout << endl;
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
