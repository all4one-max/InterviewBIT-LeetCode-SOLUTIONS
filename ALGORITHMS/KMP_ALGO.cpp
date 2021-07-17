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

int n, x, m, y, e, t, k, len, u1, u2,  f;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
string text;
string pattern;
vector<int> lps(mx2, 0);

void gen_lps() {
  int i = 1, pre_match = 0, m = pattern.size();
  while (i < m) {
    if (pattern[i] == pattern[pre_match]) {
      pre_match += 1;
      lps[i] = pre_match;
      i++;
    }
    else {
      if (pre_match == 0) {lps[i] = 0; i++;}
      else pre_match = lps[pre_match - 1];
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
  cin >> text;
  cin >> pattern;
  gen_lps();
  int n = text.size(), m = pattern.size(), i = 0, j = 0;
  bool found = false;
  while (i < n) {
    if (j == m) {
      found = true;
      break;
    }
    if (text[i] == pattern[j]) {
      i++; j++;
      if (j == m && i == n) {
        found = true;
        break;
      }
    }
    else {
      if (j == 0) i++;
      else j = lps[j - 1];
    }
  }
  if (found) cout << "FOUND" << endl;
  else cout << "NOT FOUND" << endl;
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
