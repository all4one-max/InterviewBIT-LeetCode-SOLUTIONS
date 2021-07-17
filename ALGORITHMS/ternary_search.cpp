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

int n, x, m, y, e, t, k, len, u1, u2,  f, q;
const int mx = 200005, mod = 1000000007, mx2 = 1000001, mx3 = 10000, blk_size = 100 ;
vector<int> arr(mx, 0);
vector<int> blocks(blk_size, 0);

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
# endif
    cin >> n >> x;
    fo(i, n) cin >> arr[i];
    int eps = 3; //set the error limit here
    // double eps = 1e-9;
    int l = 0, r = n - 1;
    while (r - l > eps) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int f1 = arr[m1];      //evaluates the function at m1
        int f2 = arr[m2];      //evaluates the function at m2
        if (f1 == x) {cout << "FOUND AT " << f1 << endl; found = truel}
        else if (f2 == x) {cout << "FOUND AT " << f2 << endl; found = truel}
        if (f1 < f2)
            l = m1;
        else
            r = m2;
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
