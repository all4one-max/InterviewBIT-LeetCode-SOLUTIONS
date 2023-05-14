#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> parent;
int n, m;
int findParent(int u) {
	return (parent[u] != u ? parent[u] = findParent(parent[u]) : u);
}
void solve() {
	// will consist of two types of queries.
	// query 1: check if given two edges are connected or not.
	// query 2: Add an edge bw u,v.
	int tq;
	cin >> tq;
	// Step 1: first form a dsu type structure for graph.
	parent = vector<int>(n);
	iota(parent.begin(), parent.end(), 0);
	vector<int> rank(n);
	int total_connected = n;
	for (int i = 0; i < g.size(); ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			int u = i, v = g[i][j];
			int p1 = findParent(u), p2 = findParent(v);
			if (p1 != p2) {
				if (rank[p1] < rank[p2]) {
					swap(p1, p2);
				}
				parent[p1] = p2;
				rank[p1] += rank[p2];
				total_connected--;
			}
		}
	}
	cout << total_connected << '\n';
	for (int i = 0; i < tq; ++i) {
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 1) {
			cout << (findParent(u) == findParent(v) ? "YES\n" : "NO\n");
		}
		else {
			int p1 = findParent(u), p2 = findParent(v);
			if (p1 != p2) {
				if (rank[p1] < rank[p2]) {
					swap(p1, p2);
				}
				parent[p1] = p2;
				rank[p1] += rank[p2];
				total_connected--;
			}
		}
	}
}
int main() {
	// incremental dynamic connectivity
	// Step 1: Create a sample graph
	cin >> n >> m;
	g = vector<vector<int>>(n + 1); // will store edges
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	// Graph is formed.
	solve();
}
