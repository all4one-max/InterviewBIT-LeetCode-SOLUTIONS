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
vector<int> BIT(mx, 0);
vector<int> arr(mx, 0);

void update(int index,  int val) {
    while (index <= n) {
        BIT[index] += val;
        index += (index & (-index));
    }
    return;
}

int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= (index & (-index));
    }
    return sum;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
# endif
    cin >> n;
    fo1(i, n + 1) {
        cin >> arr[i];
        update(i, arr[i]);
    }
    cout << "SUM OF FIRST 5 " << query(5) << endl;
    cout << "SUM B/W 2 AND 6 " << query(6) - query(1) << endl;
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
