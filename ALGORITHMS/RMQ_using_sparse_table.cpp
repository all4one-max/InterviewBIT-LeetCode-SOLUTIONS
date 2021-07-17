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

int n, x, m, y, e, t, k, len, u1, u2,  f, q, lg;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
vector<int> arr(mx2, 0);
vector<int> logg(mx2, 0);

void RMQ_build (vector<vector<int>> &mm) {
    fo(i, n) mm[i][0] = arr[i];
    int k = (logg[n] + 1);

    for (int j = 1; j <= k; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            mm[i][j] = min(mm[i][j - 1], mm[i + (1 << (j - 1))][j - 1]);
        }
    }
    return;
}

int RMQ_query(int i, int j, vector<vector<int>> &mm) { // SPARSE TABLE
    int len = logg[j - i + 1];
    return min(mm[i][len], mm[j - (1 << len) + 1][len]);
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
# endif
    logg[1] = 0;
    for (int i = 2; i < mx2; i++) {
        logg[i] = logg[i / 2] + 1;
    }
    cin >> n >> q;
    fo(i, n) cin >> arr[i];
    lg = (logg[mx2 - 1] + 1);
    vector<vector<int>> mm(mx2, vector<int> (lg, 1e9));
    RMQ_build(mm);
    fo(i, q) {
        cin >> u1 >> u2;
        cout << RMQ_query(u1 - 1, u2 - 1, mm) << endl;
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
