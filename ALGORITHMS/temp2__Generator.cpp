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

signed main()
{ tezi
// # ifndef ONLINE_JUDGE
//   // for getting input from input.txt
//   freopen("input.txt", "r", stdin);
//   // for getting input from output.txt
//   freopen("output.txt", "w", stdout);
// # endif
  srand(time(0));
  int t = 5;
  cout << t << endl;
  fo(i, t) {
    int n = 6;
    vector<int> arr;
    fo(i, n) {
      int num = rand() % 100;
      arr.pb(num);
    }
    int x = rand() % 50 + 1;
    vector<int> ad, bd;
    fo(i, 1 << n) {
      int ans = x, ans2 = x + 3;
      fo(j, n) {
        if ((i >> j) & 1) {
          ans ^= arr[j];
          ans2 ^= arr[j];
        }
        else {
          ans += arr[j];
          ans2 += arr[j];
        }
      }
      ad.pb(ans);
      bd.pb(ans2);
    }
    int st = rand() % 2, y;
    if (st) {
      int ind = rand() % (sz(ad));
      y = ad[ind];
    }
    else {
      int ind = rand() % (sz(bd));
      y = bd[ind];
    }
    cout << n << " " << x << " " << y << endl;
    fo(i, n) cout << arr[i] << " ";
    cout << endl;
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
