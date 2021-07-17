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

// This algorithm find all the substrings which is a palindrome in O(N)

int n,  m, y, e, t, k, q, u1, u2,  w, v, c, d, x, ans = 0;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
string s;
vector<int> d1(mx2, 0);
vector<int> d2(mx2, 0);

void manachers_algo() {
  n = sz(s);
  int l = 0, r = - 1;
  fo(i, n) {
    // k here is the number of palindromes i can have with index i as centre
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while ((i + k) < n && (i - k) >= 0 && s[i + k] == s[i - k]) {
      k++;
    }
    d1[i] = k;
    if ((i + k - 1) > r) {
      l = (i - k + 1);
      r = (i + k - 1);
    }
  }
  l = 0, r = -1;
  // in case of palindrome of even length, i signifies the latter of the
  // two center indices
  fo1(i, n) {
    // k here is the number of palindromes i can have with index i as centre
    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
    while ((i + k) < n && (i - k - 1) >= 0 && s[i + k] == s[i - k - 1]) {
      k++;
    }
    d2[i] = k;
    if ((i + k - 1) > r) {
      l = i - k;
      r = (i + k - 1);
    }
  }
}

void solve() {
  cin >> s;
  manachers_algo();
  int ans = max(*max_element(d1.begin(), d1.end()), *max_element(d2.begin(), d2.end()));
  string palindrome = "";
  fo(i, n) {
    if (d2[i] == ans) {
      for (int j = i - d2[i]; j < i + d2[i]; j++) {
        palindrome += s[j];
      }
      cout << palindrome << endl;
      return;
    }
  }
  fo(i, n) {
    if (d1[i] == ans) {
      for (int j = i - d1[i] + 1; j < i + d1[i]; j++) {
        palindrome += s[j];
      }
      cout << palindrome << endl;
      return;
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
