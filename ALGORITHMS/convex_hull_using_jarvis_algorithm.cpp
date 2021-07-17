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

bool change(point p, point q, point r) {
  int x1 = q.x - p.x;
  int y1 = q.y - p.y;
  int x2 = r.x - q.x;
  int y2 = r.y - q.y;

  int val = (x1 * y2 - y1 * x2);

  if (val <= 0) return 0;
  else return 1;
}

void convex_hull(point* points) {
  vector<point> hull;
  // find leftmost point
  int left = 0;
  fo1(i, n) {
    if (points[i].x < points[left].x) left = i;
  }
  int p = left;

  do {
    hull.pb(points[p]);
    int q = (p + 1) % n;
    fo(r, n) {
      if (change(points[p], points[q], points[r])) {
        q = r; // q will be updated when pq X qr is clockwise i.e positive
      }
    }
    p = q;
  } while (p != left);

  for (int i = 0; i < sz(hull); i++) {
    cout << hull[i].x << " " << hull[i].y << endl;
  }
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
