### [E. LEQ (Star Marked)](https://atcoder.jp/contests/abc221/tasks/abc221_e)

```cpp
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
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, v, c, d, x, a, b;
const int mx = 400005, mod = 998244353, mx2 = 300005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> BIT(mx, 0);
vector<int> fact(mx, 1);

int fme(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res % mod;
}

int modinv(int a) {return fme(a, mod - 2);}

void update(int index,  int val) {
    while (index <= mx) {
        BIT[index] += val;
        BIT[index] %= mod;
        index += (index & (-index));
    }
    return;
}

int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        sum %= mod;
        index -= (index & (-index));
    }
    return sum;
}

void solve() {
    cin >> n;
    vector<int> v(n, 0);
    vector<int> arr(n, 0);
    fo(i, n) {
        cin >> v[i];
        arr[i] = v[i];
    }
    vector<int> pow_of_2(n + 5, 0); pow_of_2[0] = 1;
    fo1(i, n + 5) {
        pow_of_2[i] = pow_of_2[i - 1] * 2;
        pow_of_2[i] %= mod;
    }
    sort(all(v));
    uniq(v);
    fo(i, n) arr[i] = lower_bound(all(v), arr[i]) - v.begin() + 2;
    int tot = 0, ans = 0;
    fo(i, n) {
        int get = query(arr[i]);
        // cout << i << " " << get << endl;
        int val = (pow_of_2[i] * get) % mod;
        ans = (ans + val) % mod;
        int upd = modinv(pow_of_2[i + 1]); upd %= mod;
        update(arr[i], upd);
    }
    cout << ans << endl;
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    t = 1;
    for (int i = 1; i < mx; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    fo(i, t) solve();
    return 0;
}
```

### [E. Lexicographically Small Enough (Star Marked)](https://codeforces.com/contest/1616/problem/E)

```cpp
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int             long long
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
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, cycle = 0;
const int mx = 400005, mod = 998244353  , mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;

void solve() {
    cin >> n; string s, t; cin >> s >> t;
    vector<int> arrs(n, 0), arrt(n, 0);
    fo(i, n) {
        arrs[i] = s[i] - 'a';
        arrt[i] = t[i] - 'a';
    }
    vector<int> used(26, 0);
    vector<vector<int>> pre(n, vector<int> (26, 0));
    fo(i, n) {
        fo(j, 26) {
            pre[i][j] = ((i > 0) ? pre[i - 1][j] : 0);
            if (arrs[i] == j) pre[i][j] += 1;
        }
    }
    vector<int> pos[26];
    fo(i, n) pos[arrs[i]].pb(i);
    int ans = INF, sm = 0;
    fo(i, n) {
        fo(j, 26) {
            if (j < arrt[i]) {
                if (sz(pos[j]) != used[j]) {
                    int unused_pos_j = pos[j][used[j]];
                    int moved = 0;
                    fo(k, 26) {
                        if (used[k] > pre[unused_pos_j][k]) moved += (used[k] - pre[unused_pos_j][k]);
                    }
                    int cor_pos = unused_pos_j + moved;
                    ans = min(ans, sm + cor_pos - i);
                }
            }
            else break;
        }
        if (sz(pos[arrt[i]]) == used[arrt[i]]) break;
        int unused_pos_j = pos[arrt[i]][used[arrt[i]]];
        int moved = 0;
        fo(k, 26) {
            if (used[k] > pre[unused_pos_j][k]) moved += (used[k] - pre[unused_pos_j][k]);
        }
        int cor_pos = unused_pos_j + moved;
        used[arrt[i]]++;
        sm += (cor_pos - i);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    cin >> t;
    fo(i, t) solve();
    return 0;
}
```

### [D. Keep the Average High (Star Marked)](https://codeforces.com/contest/1616/problem/D)

```cpp
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int             long long
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
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;

void solve() {
    cin >> n; vector<int> arr(n, 0); fo(i, n) cin >> arr[i];
    cin >> x;
    fo(i, n) arr[i] -= x;
    vector<int> cpy(arr);
    fo1(i, n) arr[i] += arr[i - 1];
    stack<int> st; st.push(0); multiset<int> mst; mst.insert(0);
    int ans = n;
    fo1(i, n) {
        int rem = 0;
        if (mst.lower_bound(arr[i]) == mst.end()) {
            // nothing
        }
        else {
            auto it = mst.lower_bound(arr[i]);
            int num = *(it);
            if (num == arr[i]) it++;
            if (it != mst.end()) rem = 1;
        }
        if (rem) {
            ans--;
            while (!st.empty()) {
                mst.erase(mst.find(st.top()));
                st.pop();
            }
        }
        else {
            while (!st.empty() && arr[i - 1] >= st.top()) {
                mst.erase(mst.find(st.top()));
                st.pop();
            }
            st.push(arr[i - 1]);
            mst.insert(arr[i - 1]);
        }
    }
    cout << ans << endl;
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    cin >> t;
    fo(i, t) solve();
    return 0;
}
```

### [E. Average and Median (Star Marked)](https://atcoder.jp/contests/abc236/tasks/abc236_e)

```cpp
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int             long long
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
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, mx_ind;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> arr(mx2, 0);
vector<int> arr2(mx2, 0);

void solve_avg() {
  long double low = (long double)0, high = (long double) * max_element(all(arr)), ans = (long double)0;
  while (low <= high) {
    long double mid = (low + high) / 2;
    vector<int> cpy(n + 1, 0);
    fo1(i, n + 1) cpy[i] = arr[i - 1] - mid;
    vector<array<int, 2>> dp(n + 1, {0, 0});
    fo1(i, n + 1) {
      dp[i][1] = cpy[i] + (int)max(dp[i - 1][1], dp[i - 1][0]);
      dp[i][0] = dp[i - 1][1];
    }
    if (max(dp[n][1], dp[n][0]) >= 0LL) {
      low = mid + 1;
      ans = max(ans, mid);
    }
    else high = mid - 1;
  }
  cout << fixed << setprecision(9) << (ans / (long double)10000) << endl;
  return;
}

void solve_median() {
  int lw = 1, hgh = *max_element(all(arr2)); int median = 1;
  while (lw <= hgh) {
    int mid = (lw + hgh) / 2;
    vector<int> cpy(n + 1, 0);
    fo1(i, n + 1) {
      if (arr2[i - 1] >= mid) cpy[i] = 1;
      else cpy[i] = -1;
    }
    vector<array<int, 2>> dp(n + 1, {0, 0});
    fo1(i, n + 1) {
      dp[i][1] = cpy[i] + (int)max(dp[i - 1][1], dp[i - 1][0]);
      dp[i][0] = dp[i - 1][1];
    }
    if (max(dp[n][1], dp[n][0]) > 0LL) {
      lw = mid + 1;
      median = max(median, mid);
    }
    else hgh = mid - 1;
  }
  cout << median << endl;
  return;
}

void solve() {
  cin >> n;
  fo(i, n) {
    cin >> arr[i];
    arr2[i] = arr[i];
    arr[i] *= (int)10000;
  }
  solve_avg();
  solve_median();
  return;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
  // for printing erros
  freopen("Errors.txt", "w", stderr);
# endif
  t = 1;
  fo(i, t) solve();
  return 0;
}
```

### [D. Shuffle (Star Marked)](https://codeforces.com/contest/1622/problem/D)

```cpp
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int             long long
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
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, cycle = 0;
const int mx = 400005, mod = 998244353  , mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> fact(mx, 1);

int fme(int a, int b) {
    int rest = 1;
    while (b) {
        if (b & 1) rest = ((int)1 * rest * a + mod) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return rest;
}

int modinv(int a) {return fme(a, mod - 2);}

int binomial(int n, int r) {return (fact[n] * modinv(fact[r]) % mod * modinv(fact[n - r]) % mod) % mod;} //ncr

void solve() {
    cin >> n >> k;
    for (int i = 1; i < mx; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    vector<int> dp(n, 0); string s; cin >> s;
    dp[0] = 1;
    int found = 0;
    fo1(i, n) {
        int len = 0, cnt = 0;
        for (int j = i; j >= 0; j--) {
            len++;
            if (s[j] == '1') {
                if (cnt == k) {
                    len--;
                    break;
                }
                cnt++;
            }
        }
        if (cnt < k) {
            dp[i] = dp[i - 1];
            continue;
        }
        if (!found) {
            dp[i] = (binomial(len, k)) % mod;
        }
        else {
            if (s[i] == '1') dp[i] = (dp[i - 1] + (((len - 1) >= cnt && cnt == k) ? binomial(len - 1, cnt) : 0)) % mod;
            else dp[i] = (dp[i - 1] + ((len >= cnt && cnt == k) ? binomial(len - 1, cnt - 1) : 0)) % mod;
        }
        found = 1;
    }
    cout << dp[n - 1] << endl;
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    t = 1;
    fo(i, t) solve();
    return 0;
}
```

### [F. Reordering (Star Marked)](https://atcoder.jp/contests/abc234/tasks/abc234_f)

```cpp
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int             long long
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
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, cycle = 0;
const int mx = 400005, mod = 998244353  , mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> fact(mx, 1);
vector<int> mod_inv(mx, 0);

int fme(int a, int b) {
    int rest = 1;
    while (b) {
        if (b & 1) rest = ((int)1 * rest * a + mod) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return rest;
}

int modinv(int a) {return fme(a, mod - 2);}

int binomial(int n, int r) {return (fact[n] * mod_inv[r] % mod * mod_inv[n - r] % mod) % mod;} //ncr

void solve() {
    string s; cin >> s; n = sz(s);
    for (int i = 1; i < 5005; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    fo(i, 5005) {
        int fct = fact[i];
        mod_inv[i] = modinv(fct);
    }
    vector<int> cnt(26, 0); fo(i, n) cnt[s[i] - 'a']++;
    vector<vector<int>> dp(26, vector<int> (n + 1, 0));
    // dp[i][len] = #different strings formed from using first i alphabets having
    //              length len
    fo(i, cnt[0] + 1) dp[0][i] = 1;
    fo(i, 26) dp[i][0] = 1;
    fo1(i, 26) {
        fo1(len, n + 1) {
            fo(freq, cnt[i] + 1) {
                if (freq > len) break;
                dp[i][len] = (dp[i][len] + (dp[i - 1][len - freq] * binomial(len, freq)) % mod) % mod;
            }
        }
    }
    int ans = 0;
    fo1(len, n + 1) ans = (ans + dp[25][len]) % mod;
    cout << ans << endl;
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    t = 1;
    fo(i, t) solve();
    return 0;
}
```

### [C. Road Optimization (Star Marked)](https://codeforces.com/contest/1625/problem/C)

```cpp
// it is fairly possible that reaching the ith stop in a suboptimal time
// might lead to way that makes reaching the last stop optimally

#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int             long long
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
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, cycle = 0;
const int mx = 400005, mod = 998244353  , mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;

void solve() {
    int l;
    cin >> n >> l >> k;
    vector<int> dist(n + 1, l); fo(i, n) cin >> dist[i];
    vector<int> speed(n, 0); fo(i, n) cin >> speed[i];
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, INF));
    int time = 0;
    fo(i, n + 1) {
        dp[i][0] = time;
        if (i + 1 <= n) time += (speed[i] * (dist[i + 1] - dist[i]));
    }
    fo(i, k + 1) dp[0][i] = 0;
    fo1(i, k + 1)  {
        fo1(j, n + 1) {
            dp[j][i] = min(dp[j][i], dp[j][i - 1]);
            int rem = 0;
            for (int l = j - 1; l >= 0; l--) {
                if (i - rem < 0) continue;
                time = dp[l][i - rem] + speed[l] * (dist[j] - dist[l]);
                rem++;
                dp[j][i] = min(dp[j][i], time);
            }
        }
    }
    cout << dp[n][k] << endl;
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    t = 1;
    fo(i, t) solve();
    return 0;
}
```

### [D. 388535 (HARD VERSION) (Star Marked)](https://codeforces.com/contest/1658/problem/D2)

```cpp
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<pair<long long, long long>, null_type,less<pair<long long, long long>>, rb_tree_tag,tree_order_statistics_node_update>
#define int            long long
#define ld             long double
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define nl             "\n"
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, ans;
const int mx = 400005, mod = 998244353, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;

struct trie_node {
    char c;
    int count;
    trie_node* left;
    trie_node* right;
    trie_node(char x) {
        c = x;
        count = 0;
        left = right = NULL;
    }
};

void insert(trie_node* root, int num) {
    trie_node* dummy = root;
    for (int i = 19; i >= 0; i--) {
        dummy->count++;
        if ((num >> i) & 1) {
            if (!dummy->right) dummy->right = new trie_node('?');
            dummy = dummy->right;
        }
        else {
            if (!dummy->left) dummy->left = new trie_node('?');
            dummy = dummy->left;
        }
    }
    dummy->count++;
    return;
}

int lessX(trie_node* root, int num, int lim) {
    int ans = 0;
    trie_node* dummy = root;
    for (int i = 19; i >= 0; i--) {
        if ((num >> i) & 1) {
            if ((lim >> i) & 1) {
                if (dummy->right) ans += (dummy->right->count);
                if (!dummy->left) break;
                dummy = dummy->left;
            }
            else {
                if (!dummy->right) break;
                dummy = dummy->right;
            }
        }
        else {
            if ((lim >> i) & 1) {
                if (dummy->left) ans += (dummy->left->count);
                if (!dummy->right) break;
                dummy = dummy->right;
            }
            else {
                if (!dummy->left) break;
                dummy = dummy->left;
            }
        }
    }
    return ans;
}

void solve() {
    int l, r; cin >> l >> r;
    vector<int> arr(r - l + 1, 0);
    fo(i, r - l + 1) cin >> arr[i];
    trie_node* root = new trie_node('?');
    fo(i, r - l + 1) insert(root, arr[i]);
    for (auto it : arr) {
        int x = (it ^ l);
        int cnt2 = lessX(root, x, r + 1), cnt1 = lessX(root, x, l);
        int cnt =  cnt2 - cnt1;
        if (cnt == (r - l + 1)) {
            cout << x << nl;
            return;
        }
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
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    cin >> t;
    // t = 1;
    fo(i, t) solve();
    return 0;
}
```

### [C. Tokitsukaze and Strange Inequality (Star Marked)](https://codeforces.com/contest/1678/problem/C)

```cpp
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<pair<long long, long long>, null_type,less<pair<long long, long long>>, rb_tree_tag,tree_order_statistics_node_update>
#define int            long long
#define ld             long double
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i=1;i<n;i++)
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define nl             "\n"
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, ans;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;

void solve() {
  cin >> n; vector<int> arr(n, 0);
  fo(i, n) cin >> arr[i];
  vector<int> bd(n, 0);
  fo1(i, n) {
    for (int j = i + 2; j < n; j++) {
      if (arr[i] > arr[j]) bd[i]++;
    }
  }
  vector<int> pref(bd);
  fo1(i, n) pref[i] += pref[i - 1];
  debug(bd) debug(pref)
  int ans = 0;
  for (int c = 2; c < n - 1; c++) {
    for (int a = c - 2; a >= 0; a--) {
      if (arr[a] > arr[c]) bd[a]--;
    }
    for (int a = 1; a <= c; a++) pref[a] = (bd[a] + pref[a - 1]);
    for (int a = 0; a < c - 1; a++) {
      if (arr[a] < arr[c]) ans += (pref[c - 1] - pref[a]);
    }
  }
  cout << ans << nl;
  return;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
  // for printing erros
  freopen("Errors.txt", "w", stderr);
# endif
  cin >> t;
  // t = 1;
  fo(i, t) solve();
  return 0;
}
```
