#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>> &rGraph, int source, int sink, vector<int> &parent) {
    int n = rGraph.size();
    vector<bool> visited(n, 0);
    queue<int> qu;
    qu.push(source);
    visited[source] = 1;
    parent[source] = -1;
    while (qu.size() > 0) {
        int crNode = qu.front();
        qu.pop();
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && rGraph[crNode][i] > 0) {
                if (i == sink) {
                    parent[i] = crNode;
                    return true;// Found a augmenting path
                }
                qu.push(i);
                parent[i] = crNode;
                visited[i] = true;
            }
        }
    }
    return false;
}
int fordFulkerson(vector<vector<int>> &graph, int source, int sink) {
    int n = graph.size();
    vector<vector<int>> rGraph(n, vector<int>(n)); //residual graph
    rGraph = graph;
    vector<int> parent(n);
    int maxFlow = 0;// initally
    // Step 1: Find an augmenting path.
    while (bfs(rGraph, source, sink, parent)) {
        int pathFlow = INT_MAX;
        int crNode = sink;
        while (parent[crNode] != -1) {
            pathFlow = min(pathFlow, rGraph[parent[crNode]][crNode]);
            crNode = parent[crNode];
        }
        crNode = sink;
        while (parent[crNode] != -1) {
            int par = parent[crNode];
            rGraph[par][crNode] -= pathFlow;
            rGraph[crNode][par] += pathFlow;
            crNode = par;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    vector<vector<int>> graph = { { 0, 16, 13, 0, 0, 0 }, { 0, 0, 10, 12, 0, 0 },
        { 0, 4, 0, 0, 14, 0 },  { 0, 0, 9, 0, 0, 20 },
        { 0, 0, 0, 7, 0, 4 },   { 0, 0, 0, 0, 0, 0 }
    };
    int source = 0, sink = 5;
    cout << "Max Flow possible is " << fordFulkerson(graph, source, sink);
    return 0;
}
