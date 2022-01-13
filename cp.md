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
