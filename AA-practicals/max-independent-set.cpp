#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> g = {
        {1, 5},
        {0, 2, 3},
        {1, 3},
        {1, 2, 4},
        {3},
        {0}
    };
    // set of vertices such that any two vertices in the set do not have a direct edge between them.
    vector<vector<vector<int>>> possibleSets(6);
    int maxInd = INT_MIN;
    for (int i = 0; i < (1 << 6); ++i) {
        int setSize = __builtin_popcount(i);
        // if(maxInd>setSize) continue;
        bool valid = true;
        for (int j = 0; j < g.size() && valid; ++j) {
            for (int k = 0; k < g[j].size(); ++k) {
                if (((1 << g[j][k]) & i) && ((1 << j)&i)) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            vector<int> set;
            for (int j = 0; j <= 5; ++j) {
                if ((1 << j) & i) set.push_back(j);
            }
            possibleSets[setSize].push_back(set);
            maxInd = max(setSize, maxInd);
        }
    }
    cout << "MAX INDEPENDENT SET SIZE " << maxInd << '\n';
    cout << "POSSIBLE SETS ARE... ";
    for (int i = 0; i < possibleSets[maxInd].size(); ++i) {
        cout << "{";
        for (int j = 0; j < maxInd; ++j) {
            if (j != 0)cout << ",";
            cout << possibleSets[maxInd][i][j];
        }
        cout << "} ";
    }
}
