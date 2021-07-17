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

int n, x, m, y, e, t, k, len, u1, u2, r;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
vector<int> BIT(mx, 0);
vector<int> arr(mx, 0);

int setBit(int n) {
  int count = 0;
  while (n) {n = n & (n - 1); count += 1;}
  return count;
}

int fme(int a, int b) {
  int rest = 1;
  while (b) {
    if (b & 1) rest = (rest * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return rest;
}

int btod(string s) {
  int len = s.length(), cur = 0, ind = 0;
  for (int i = (len - 1); i >= 0; i--) {
    if (s[i] == '1') cur += pow(2, ind);
    ind++;
  }
  return cur;
}

bool comp(int a, int b)
{
  return (a >= b);
}

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
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  string s;
  cin >> n >> s;
  string rs = s; reverse(all(rs));
  set<int> posr[26];
  fo(i, n) posr[rs[i] - 'a'].insert(i);
  vector<int> cor_pos;
  fo(i, n) {
    cor_pos.pb(*(posr[s[i] - 'a'].begin()) + 1);
    posr[s[i] - 'a'].erase(posr[s[i] - 'a'].begin());
  }
  int invcnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    invcnt += (query(cor_pos[i] - 1));
    update(cor_pos[i], 1);
  }
  cout << invcnt << endl;
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
