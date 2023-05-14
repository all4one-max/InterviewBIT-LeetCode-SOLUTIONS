#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> edges;
    for (int i = 0; i < e; ++i) {
        int u1, v1;
        cin >> u1 >> v1;
        edges.push_back({u1, v1});
    }
    int minVertexCover = INT_MAX;
    vector<vector<vector<int>>> vertexSet(v + 1);
    for (int i = 0; i < (1 << v); ++i) {
        int num = i;
        bool valid = 1;
        int vertexCover = __builtin_popcount(num);
        if (vertexCover > minVertexCover) continue;
        for (int j = 0; j < e; ++j) {
            if ((num & (1 << edges[j].first)) or (num & (1 << edges[j].second))) {
                // Found atleast one vertex
            }
            else {
                valid = 0;
                break;
            }
        }
        if (valid) {
            vector<int> set;
            for (int j = 0; j < v; ++j) {
                if (num & (1 << j)) set.push_back(j);
            }
            vertexSet[vertexCover].push_back(set);
            minVertexCover = vertexCover;
        }
    }
    cout << "vertex set found.. " << minVertexCover << "\n";
    for (int i = 0; i < vertexSet[minVertexCover].size(); ++i) {
        cout << "{ ";
        for (int j = 0; j < minVertexCover; ++j) {
            if (j != 0) cout << ",";
            cout << vertexSet[minVertexCover][i][j];
        }
        cout << " }\n";
    }
}
