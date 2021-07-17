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

int n, x, m, y, e, t, k, len, u1, u2,  f, q, lg, curr = 0;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
vector<int> arr(mx2, 0);
vector<int> logg(mx2, 0);
vector<int> adj[mx2];
vector<int> height(mx2, 0);
vector<int> tre(mx2, 0);
vector<int> euler(mx, 0);
map<int, int> first;

void buildTree(int start, int end, int treeNode) {
    if (start == end) {tre[treeNode] = start; return;}
    int mid = (start + end) / 2;
    buildTree(start, mid, 2 * treeNode);
    buildTree((mid + 1), end, 2 * treeNode + 1);
    int left = tre[2 * treeNode], right = tre[2 * treeNode + 1];
    if (height[euler[left]] < height[euler[right]]) tre[treeNode] = left;
    else tre[treeNode] = right;
}

int RMQ_query(int start, int end, int treeNode, int left, int right) {
    //completely outside
    if (start > right || left > end) return -1;
    //completely inside
    if (left <= start && right >= end) return tre[treeNode];
    //partially inside and partially outside
    int mid = (start + end) / 2;
    int ans1 = RMQ_query(start, mid, 2 * treeNode, left, right);
    int ans2 = RMQ_query(mid + 1, end, 2 * treeNode + 1, left, right);

    if (ans1 != -1 && ans2 != -1) {
        if (height[euler[ans1]] < height[euler[ans2]]) return ans1;
        else return ans2;
    }
    else if (ans1 != -1) return ans1;
    else return ans2;
}

void eulr(int v, int p) {
    euler[curr++] = v;
    for (auto it : adj[v]) {
        if (it != p) {
            if (first[it] == 0) first[it] = curr;
            height[it] = height[v] + 1;
            eulr(it, v);
            euler[curr++] = v;
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
# endif
    cin >> n >> e;
    fo(i, e) {
        cin >> u1 >> u2;
        adj[u1].pb(u2);
        adj[u2].pb(u1);
    }
    eulr(1, -1);
    buildTree(0, curr - 1, 1);
    cin >> q;
    fo(i, q) {
        cin >> u1 >> u2;
        if (first[u1] > first[u2]) swap(u1, u2);
        cout << euler[RMQ_query(0, curr - 1, 1, first[u1], first[u2])] << endl;
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
