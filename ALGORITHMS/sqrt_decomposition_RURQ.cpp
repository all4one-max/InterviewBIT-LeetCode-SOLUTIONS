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
const int mx = 200005, mod = 1000000007, mx2 = 1000001, mx3 = 10000, blk_size = 100;
vector<int> arr(mx, 0);
vector<int> blocks_b(blk_size, 0);
vector<int> blocks_c(blk_size, 0);

void pre_process() {
    int sq = floor(sqrt(n));
    int cur_blk = -1;
    fo(i, n) {
        if (i % sq == 0) cur_blk += 1;
        blocks_b[cur_blk] += arr[i];
    }
    return;
}

int query(int l, int r) {
    int sq = floor(sqrt(n));
    int ans = 0;
    while (l % sq != 0 and l < r) {
        ans += (arr[l] + blocks_c[l / sq]);
        l++;
    }
    while (l + sq - 1 <= r) {
        ans += blocks_b[l / sq];
        l += sq;
    }
    while (l <= r) {
        ans += (arr[l] + blocks_c[l / sq]);
        l++;
    }
    return ans;
}

void update(int l, int r, int value) {
    int sq = floor(sqrt(n));
    int ans = 0;
    while (l % sq != 0 and l < r) {
        arr[l] += value;
        blocks_b[l / sq] += (value * (sq - (l / sq)));
        l++;
    }
    while (l + sq - 1 <= r) {
        ans += blocks_b[l / sq];
        blocks_b[l / sq] += (value * sq);
        blocks_c[l / sq] += value;
        l += sq;
    }
    while (l <= r) {
        arr[l] += value;
        blocks_b[l / sq] += (value * (sq - (l / sq)));
        l++;
    }
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
# endif
    cin >> n >> q;
    fo(i, n) cin >> arr[i];
    pre_process();
    fo(i, q) {
        cin >> u1 >> u2;
        cout << query(u1 - 1, u2 - 1) << endl;
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
