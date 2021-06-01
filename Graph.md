### [Valid Path](https://www.interviewbit.com/problems/valid-path/)

```cpp
string Solution::solve(int a, int b, int n, int r, vector<int> &e, vector<int> &f) {
    if(a == 0 || b == 0) {
        if(n) return "NO";
        else return "YES";
    }

    vector<vector<int>> blcok(a + 1, vector<int> (b + 1, 0));
    for(int i = 0; i < n; i++) {
        int x = e[i], y = f[i];
        int left = max(0, y - r), right = min(b, y + r);
        for(int j = left; j <= right; j++) {
            for(int up = x; up <= a; up++) {
                int rad = abs(up - x)*abs(up - x) + abs(y - j)*abs(y - j);
                if(rad <= r*r) blcok[up][j] = 1;
                else break;
            }
            for(int down = x; down >= 0; down--) {
                int rad = abs(down - x)*abs(down - x) + abs(y - j)*abs(y - j);
                if(rad <= r*r) blcok[down][j] = 1;
                else break;
            }
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    if(blcok[0][0]) return "NO";
    vector<vector<int>> visited(105, vector<int> (105, 0)); visited[0][0] = 1;
    vector<array<int, 2>> mov = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if(x == a && y == b) return "YES";
        for(auto it : mov) {
            int nx = x + it[0], ny = y + it[1];
            if(nx >= 0 && nx <= a && ny >= 0 && ny <= b) {
                if(!visited[nx][ny] && !blcok[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return "NO";
}
```

### [Snake Ladder Problem!](https://www.interviewbit.com/problems/snake-ladder-problem/)

```cpp
int Solution::snakeLadder(vector<vector<int> > &a, vector<vector<int> > &b) {
    int n = a.size(), m = b.size();
    unordered_map<int, int> ladder, snake;
    for(int i = 0; i < n; i++) ladder[a[i][0]] = a[i][1];
    for(int i = 0; i < m; i++) snake[b[i][0]] = b[i][1];
    vector<int> visited(110, 0);
    queue<pair<int, int>> q; q.push({1, 0});
    while(!q.empty()) {
        auto [x, mov] = q.front(); q.pop();
        if(x == 100) return mov;
        for(int i = 1; i <= 6; i++) {
            if(!visited[x + i]) {
                visited[x + i] = 1;
                if(ladder[x + i] != 0) {
                    if(!visited[ladder[x + i]]) {
                        q.push({ladder[x + i], mov + 1});
                        visited[ladder[x + i]] = 1;
                    }
                }
                else if(snake[x + i] != 0) {
                    if(!visited[snake[x + i]]) {
                        q.push({snake[x + i], mov + 1});
                        visited[snake[x + i]] = 1;
                    }
                }
                else q.push({x + i, mov + 1});
            }
        }
    }
    return -1;
}
```

### [Smallest Multiple With 0 and 1 (Star Marked)](https://www.interviewbit.com/problems/smallest-multiple-with-0-and-1/)

```cpp
string Solution::multiple(int a) {
    if(a == 1) return "1";
    queue<pair<int, int>> q; q.push({1, 1});
    vector<int> visited(a + 1, 0); visited[1] = 1;
    vector<pair<int, int>> parent(a + 1, {0, 0}); parent[1] = {-1, 1};
    while(!q.empty()) {
        auto [rem, state] = q.front(); q.pop();
        if(rem == 0) {
            string s; s.push_back(state + '0');
            while(true) {
                int p = parent[rem].first;
                s.push_back(parent[p].second + '0');
                rem = p;
                if(rem == 1) break;
            }
            reverse(s.begin(), s.end());
            return s;
        }
        for(auto r : {0, 1}) {
            int rr = (10*rem + r)%a;
            if(!visited[rr]) {
                q.push({rr, r});
                visited[rr] = 1;
                parent[rr] = {rem, r};
            }
        }
    }
}
```

### [Min Cost Path (Star Marked)](https://www.interviewbit.com/problems/min-cost-path/)

```cpp
int Solution::solve(int a, int b, vector<string> &c) {
    deque<pair<int, pair<int, int>>> q; q.push_front({0, {0, 0}});
    vector<vector<int>> visited(a + 1, vector<int> (b + 1, 0));
    vector<pair<int, int>> mov = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};
    map<pair<int, int>, char> mp;
    mp[{-1, 0}] = 'U'; mp[{0, 1}] = 'R'; mp[{1, 0}] = 'D'; mp[{0, -1}] = 'L';
    while(!q.empty()) {
        auto it = q.front(); q.pop_front();
        int cost = it.first, x = it.second.first, y = it.second.second;
        if(x == a - 1 && y == b - 1) return cost;
        if(visited[x][y]) continue;
        visited[x][y] = 1;
        for(auto it2 : mov) {
            int nx = x + it2.first, ny = y + it2.second;
            if(nx >= 0 && nx < a && ny >= 0 && ny < b) {
                if(mp[it2] == c[x][y]) q.push_front({cost, {nx, ny}});
                else q.push_back({cost + 1, {nx, ny}});
            }
        }
    }
}
```

### [Permutation Swaps!](https://www.interviewbit.com/problems/permutation-swaps/)

```cpp
void dfs(int v, vector<int> adj[], vector<int> &visited, vector<int> &components, int comp) {
    visited[v] = 1;
    components[v] = comp;
    for(auto it : adj[v]) {
        if(!visited[it]) {
            visited[it] = 1;
            dfs(it, adj, visited, components, comp);
        }
    }
    return;
}

int Solution::solve(vector<int> &a, vector<int> &b, vector<vector<int> > &c) {
    int n = a.size();
    vector<int> adj[n + 5];
    for(int i = 0; i < c.size(); i++) {
        int x = c[i][0], y = c[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    unordered_map<int, int> mp; for(int i = 0; i < n; i++) mp[a[i]] = i + 1;
    vector<int> components(n + 5, 0); int comp = 1;
    vector<int> visited(n + 5, 0);
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited, components, comp);
            comp++;
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            if (components[i + 1] != components[mp[b[i]]]) return 0;
        }
    }
    return 1;
}
```
