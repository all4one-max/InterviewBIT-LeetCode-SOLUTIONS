#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll             long long
#define fo(i,n)        for(int i=0;i<n;i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define MOD 1000000007
#define pb             push_back
#define mp             make_pair

void help_topo_sort(vector<int> adj[], stack<int> &st, int n, vector<bool> &visited, int v) {
  visited[v] = 1;
  for (int it : adj[v]) {
    if (visited[it] == 0) {
      help_topo_sort(adj, st, n, visited, it);
    }
  }
  st.push(v);
  return;
}

void topo_sort(vector<int> adj[], int n) {
  stack<int> st;
  vector<bool> visited(n + 1, 0);
  visited[0] = 1;
  fo(i, n + 1) {
    if (visited[i] == 0) {
      help_topo_sort(adj, st, n, visited, i);
    }
  }
  while (st.empty() == false) {
    cout << st.top() << " ";
    st.pop();
  }
  return;
}

int main() {
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  int t = 1;
  while (t--) {
    int n, e, x, y;
    cin >> n >> e;
    vector<int> adj[n + 1]; //directed edges only
    fo(i, e) {
      cin >> x >> y;
      adj[x].pb(y);
    }
    topo_sort(adj, n);
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
