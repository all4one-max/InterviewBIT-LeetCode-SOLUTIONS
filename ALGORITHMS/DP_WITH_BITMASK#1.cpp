/*
Problem Statement

Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary
depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job
and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

Input Format
Number of workers and job: N
Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

Sample Input
4

[
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4
]

Sample Output
13

Constraints
N <= 20
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
#include <unordered_map>
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

// TIME COMPLEXITY : O(2^n*(n**2))

int n,  m, e, t, k, len, u1, u2,  w, v, d;
const int mx = 200005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000, INF = 10000000000000000;
vector<vector<int>> arr(21, vector<int>(21, 0));

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
# endif
    cin >> n;
    fo(i, n) fo(j, n) cin >> arr[i][j];
    vector<vector<int>> dp(n + 1, vector<int>(1 << 20, 1000));
    fo(i, 1 << 20) dp[n][i] = 0;
    for (int i = (n - 1); i >= 0; i--) {
        for (int mask = ((1 << n) - 1); mask >= 0; mask--) {
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) {
                    dp[i][mask] = min(dp[i][mask], arr[j][i] + dp[i + 1][mask ^ (1 << j)]);
                }
            }
        }
    }
    cout << dp[0][(1 << n) - 1] << endl;
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

