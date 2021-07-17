#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
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

int n,  m, y, e, t, k, q, u1, u2,  w, v, x;
const int mx = 400005, mod = 1LL << 32, mx2 = 200005 , mx3 = 100005, INF = 10000000000000000;

/*
PROBLEM STATEMENT:
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than
 ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

algo logic : https://www.youtube.com/watch?v=AoX3BPWNnoE&ab_channel=takeUforward
*/

/*
LOGIC OF THE ALGORITHM
TEST CASE : [ 7 7 5 7 5 1 | 5 7 | 5 5 7 7 | ] 5 5 5 5
wherever above there is this '|' symbol it means that the count was 0 over there
also the elemetns enclosed in [] forms the prefix. now, do note that in question it says
there is a majority elements that is there is a number that repeats more than  ⌊n / 2⌋ times.
the intuition is that the majority element will be the majority element in the suffix.
therefore, let us make an assumption that the majority elemnt is in the prefix and not in the
suffix. so if the majority element was in the prefix than in the best case it can have
its frequency as ⌊(length of prefix) / 2⌋ as before the start of suffix the count will
be 0 now n  = (len of prefix + len of suffix) , therefore
⌊n / 2⌋ = ⌊(len of prefix) / 2⌋ + ⌊(len of suffix) / 2⌋ and hence our assumption is wrong
as the frequency of the majority element is in the prefix and not in the suffix is less than
what we require. therefore by contradiction the majority element will be there in the suffix.
Counter Test Case : [ 7 7 5 7 5 1 | 5 7 | 5 5 7 7 | ] 1 1 1 1 (This is when if we are not
given there is a majority element present)
*/

void solve() {
  cin >> n;
  int count = 0, ele;
  fo(i, n) {
    cin >> x;
    if (count == 0) {
      count = 1;
      ele = x;
    }
    else {
      if (x == ele) count++;
      else count--;
    }
  }
  cout << ele << endl;
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
