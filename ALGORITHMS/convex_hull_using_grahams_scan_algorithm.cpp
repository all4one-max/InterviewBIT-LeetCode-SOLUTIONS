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

struct point {
  int x, y;
};

bool comp(point p1, point p2) {
  return ((p1.x < p2.x) || ((p1.x == p2.x) && (p1.y < p2.y)));
}

int clock_wise(point p1, point p2, point p3) {
  int x1 = (p2.x - p1.x);
  int y1 = (p2.y - p1.y);
  int x2 = (p3.x - p2.x);
  int y2 = (p3.y - p2.y);

  int val = x1 * y2 - x2 * y1;
  if (val < 0) return 1;
  return 0;
}

int counter_clock_wise(point p1, point p2, point p3) {
  int x1 = (p2.x - p1.x);
  int y1 = (p2.y - p1.y);
  int x2 = (p3.x - p2.x);
  int y2 = (p3.y - p2.y);

  int val = x1 * y2 - x2 * y1;

  if (val > 0) return 1;
  else return 0;
}

void convex_hull(point* points) {
  sort(points, points + n, comp);
  point a = points[0], b = points[n - 1];
  vector<point> up, down;
  up.pb(a); down.pb(a);
  fo1(i, n) {
    if (i == (n - 1) || (clock_wise(a, points[i], b))) {
      while (sz(up) >= 2 && !(clock_wise(up[sz(up) - 2], up[sz(up) - 1], points[i]))) {
        up.pop_back();
      }
      up.pb(points[i]);
    }
    if (i == (n - 1) || (counter_clock_wise(a, points[i], b))) {
      while (sz(down) >= 2 && !(counter_clock_wise(down[sz(down) - 2], down[sz(down) - 1], points[i]))) {
        down.pop_back();
      }
      down.pb(points[i]);
    }
  }
  vector<point> final;
  for (int i = 0; i < sz(up); i++) {
    final.pb(up[i]);
  }
  for (int i = (sz(down) - 2); i > 0; i--) {
    final.pb(down[i]);
  }
  for (int i = 0; i < sz(final); i++) {
    cout << final[i].x << " " << final[i].y << endl;
  }
  cout << endl;
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
  point* points = new point[n];
  fo(i, n) {
    cin >> points[i].x >> points[i].y;
  }
  convex_hull(points);
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
