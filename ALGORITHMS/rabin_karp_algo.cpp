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

int n,  m, y, e, t, k, q, u1, u2,  w, v, c, d, x, ans = 0;
const int mx = 400005, mod = 1LL << 32, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
string pattern, text;
vector<int> occurences;

void rabin_karp() {
    const int p = 31;
    const int m = 1e9 + 9;
    int S = pattern.size(), T = text.size();

    vector<int> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    vector<int> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % m;
    int h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (pattern[i] - 'a' + 1) * p_pow[i]) % m;

    for (int i = 0; i + S - 1 < T; i++) {
        int cur_h = (h[i + S] + m - h[i]) % m; // = hash[i....j] * p_pow[i]
        if (cur_h == (h_s * p_pow[i] % m)) occurences.push_back(i);
    }
    return;
}

void solve() {
    cin >> pattern >> text;
    rabin_karp();
    for (auto it : occurences) cout << it << " ";
    cout << endl;
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
    cin >> t;
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
