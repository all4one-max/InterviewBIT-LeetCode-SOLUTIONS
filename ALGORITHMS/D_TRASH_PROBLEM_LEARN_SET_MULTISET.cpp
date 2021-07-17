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

int n,  m, y, e, t, k, len, u1, u2,  f, sm = 0, cnt = 0, a, b, x, q;
const int mx = 200005, mod = 1000000009, mx2 = 1000005 , mx3 = 1000001;
set<int> st;
multiset<int> mst;

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  cin >> n >> q;
  fo(i, n) {cin >> x; st.insert(x);}
  auto it = st.begin(); x = *(it);
  auto nxt = it++, pre = it--;
  for (auto it = ++st.begin(); it != st.end(); it++) {mst.insert(*(it) - x); x = *it;}
  if (st.size() <= 1) cout << 0 << endl;
  else {
    int mxx = *(mst.rbegin());
    int start = *(st.begin()), end = *(st.rbegin());
    cout << (end - start - mxx) << endl;
  }
  fo(i, q) {
    cin >> u1 >> u2;
    if (u1 == 1) {
      st.insert(u2);
      it = st.find(u2);
      nxt = next(it);
      pre = prev(it);
      if (it != st.begin() && nxt != st.end()) mst.erase(mst.find(*nxt - *pre));
      if (nxt != st.end()) mst.insert(*nxt - *it);
      if (it != st.begin()) mst.insert(*it - *pre);
    }
    else {
      it = st.find(u2);
      nxt = next(it);
      pre = prev(it);
      if (nxt != st.end()) mst.erase(mst.find(*nxt - *it));
      if (it != st.begin()) mst.erase(mst.find(*it - *pre));
      if (it != st.begin() && nxt != st.end()) mst.insert(*nxt - *pre);
      st.erase(u2);
    }
    if (st.size() <= 1) cout << 0 << endl;
    else {
      int mxx = *(mst.rbegin());
      int start = *(st.begin()), end = *(st.rbegin());
      cout << (end - start - mxx) << endl;
    }
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
