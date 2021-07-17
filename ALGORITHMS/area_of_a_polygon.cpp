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
#define pii            pair<int, int>

int n,  m, y, e, t, k, len, u1, u2,  w, v;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000;

class point {
public:
  int x, y;
};

class polygon {
public:
  point* points;
  polygon(int n) {
    points = new point[n];
  }
};

void area(polygon p) {
  int ar = 0;
  for (int i = 1; i < (n - 1); i++) {
    int x1 = (p.points[i].x - p.points[0].x);
    int y1 = (p.points[i].y - p.points[0].y);
    int x2 = (p.points[i + 1].x - p.points[0].x);
    int y2 = (p.points[i + 1].y - p.points[0].y);
    ar += (x1 * y2 - y1 * x2);
  }
  cout << abs(ar / 2) << endl;
  return;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  cin >> n;
  polygon p(n);
  fo(i, n) {
    cin >> p.points[i].x >> p.points[i].y;
  }
  area(p);
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
