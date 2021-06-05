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

### [Level Order](https://www.interviewbit.com/problems/level-order/)

```cpp
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* a) {
    queue<TreeNode*> q; q.push(a);
    vector<vector<int>> ans = {{a->val}};
    while(!q.empty()) {
        int sz = q.size();
        vector<int> lvl;
        for(int i = 0; i < sz; i++) {
            auto node = q.front(); q.pop();
            if(node->left) {
                q.push(node->left);
                lvl.push_back(node->left->val);
            }
            if(node->right) {
                q.push(node->right);
                lvl.push_back(node->right->val);
            }
        }
        if(lvl.size()) ans.push_back(lvl);
    }
    return ans;
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

### [Commutable Islands](https://www.interviewbit.com/problems/commutable-islands/)

```cpp
// Method 1 (O(V*V) kruskal DSU with no optimisation)
bool comp(vector<int> &v1, vector<int> &v2) {
    if(v1[2] < v2[2]) return true;
    return false;
}

int getP(int v, vector<int> &parent) {
    while(parent[v] != v) v = parent[v];
    return v;
}

int slow_kruskal(int v, vector<vector<int>> &b) {
    int e = b.size();
    vector<int> parent(v + 1, 0);
    for(int i = 0; i <= v; i++) parent[i] = i;
    int count = 0, i = 0;
    int ans = 0;
    while(count < (v - 1)) {
        int x = b[i][0], y = b[i][1], w = b[i][2];
        int p1 = getP(x, parent), p2 = getP(y, parent);
        if(p1 != p2) {
            parent[p1] = p2;
            ans += w;
            count++;
        }
        i++;
    }
    return ans;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    sort(b.begin(), b.end(), comp);
    return slow_kruskal(a, b);
}

// Method 2 (O(V*logv) Kruskal DSU by rank and parent)
bool comp(vector<int> &v1, vector<int> &v2) {
    if(v1[2] < v2[2]) return true;
    return false;
}

int findP_and_C(int v, vector<int> &parent) {
    if(parent[v] != v) parent[v] = findP_and_C(parent[v], parent);
    return parent[v];
}

void union_sets(int p1, int p2, vector<int> &rank, vector<int> &parent) {
    if(rank[p1] > rank[p2]) parent[p2] = p1;
    else if(rank[p1] < rank[p2]) parent[p1] = p2;
    else {
        parent[p2] = p1;
        rank[p1]++;
    }
    return;
}

int fast_kruskal(int v, vector<vector<int>> &b) {
    int e = b.size();
    vector<int> rank(v + 1, 0); vector<int> parent(v + 1, 0);
    for(int i = 0; i <= v; i++) parent[i] = i;
    int count = 0, i = 0;
    int ans = 0;
    while(count < (v - 1)) {
        int x = b[i][0], y = b[i][1], w = b[i][2];
        int p1 = findP_and_C(x, parent), p2 = findP_and_C(y, parent);
        if(p1 != p2) {
            union_sets(p1, p2, rank, parent);
            ans += w;
            count++;
        }
        i++;
    }
    return ans;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    sort(b.begin(), b.end(), comp);
    return fast_kruskal(a, b);
}
```

### [Possibility of finishing all courses given pre-requisites](https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/)

```cpp
int cycle;

void dfs(int v, vector<int> &visited, vector<int> &rec_stack, array<vector<int>, 60010> &adj) {
    rec_stack[v] = 1;
    visited[v] = 1;
    for(auto it : adj[v]) {
        if(!visited[it]) {
            dfs(it, visited, rec_stack, adj);
            if(cycle) return;
        }
        else {
            if(rec_stack[it]) {
                cycle = 1;
                return;
            }
        }
    }
    rec_stack[v] = 0;
    return;
}

int Solution::solve(int a, vector<int> &b, vector<int> &c) {
    array<vector<int>, 60010> adj;
    int n = b.size();
    for(int i = 0; i < n; i++) adj[b[i]].push_back(c[i]);
    vector<int> visited(a + 5);
    vector<int> rec_stack(a + 5);
    for(int i = 1; i <= a; i++) {
        if(!visited[i]) {
            cycle = 0;
            dfs(i, visited, rec_stack, adj);
            if(cycle) return 0;
        }
    }
    return 1;
}
```

### [Black Shapes](https://www.interviewbit.com/problems/black-shapes/)

```cpp
vector<array<int, 2>> mov = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
void dfs(int x, int y, vector<vector<int>> &vis, vector<string> &a) {
    int n = a.size(), m = a[0].size();
    vis[x][y] = 1;
    for(auto it : mov) {
        int nx = x + it[0], ny = y + it[1];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && a[nx][ny] == 'X') dfs(nx, ny, vis, a);
    }
    return;
}

int Solution::black(vector<string> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> vis(n + 5, vector<int> (m + 5, 0));
    int comp = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && a[i][j] == 'X') {
                dfs(i, j, vis, a);
                comp++;
            }
        }
    }
    return comp;
}
```

### [Largest Distance between nodes of a Tree](https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/)

```cpp
pair<int, int> dfs(array<vector<int>, 40005> &adj, int v, int p) {
    int leaf = 1;
    int ans = 0, h1 = 0, h2 = 0;
    for(auto it : adj[v]) {
        if(it != p) {
            auto ret = dfs(adj, it, v);
            ans = max(ans, ret.second);
            if(ret.first + 1 > h1) {
                h2 = h1;
                h1 = ret.first + 1;
            }
            else if(ret.first + 1 > h2) {
                h2 = ret.first + 1;
            }
            leaf = 0;
        }
    }
    if(leaf) return {0, 0};
    else {
        return {max(h1, h2), max(ans, h1 + h2)};
    }
}

int Solution::solve(vector<int> &a) {
    int n = a.size(); array<vector<int>, 40005> adj;
    for(int i = 0; i < n; i++) {
        if(a[i] == -1) continue;
        adj[i + 1].push_back(a[i] + 1);
        adj[a[i] + 1].push_back(i + 1);
    }
    auto ret = dfs(adj, 1, -1);
    return ret.second;
}
```

### [Cycle in Directed Graph](https://www.interviewbit.com/problems/cycle-in-directed-graph/)

```cpp
int cycle;
void dfs(int v, array<vector<int>, 100005> &adj, vector<int> &vis, vector<int> &rec_stack) {
    vis[v] = 1;
    rec_stack[v] = 1;
    for(auto it : adj[v]) {
        if(!vis[it]) {
            dfs(it, adj, vis, rec_stack);
            if(cycle) return;
        }
        else {
            if(rec_stack[it]) {
                cycle = 1;
                return;
            }
        }
    }
    rec_stack[v] = 0;
    return;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    array<vector<int>, 100005> adj;
    cycle = 0;
    for(int i = 0; i < b.size(); i++) adj[b[i][0]].push_back(b[i][1]);
    vector<int> vis(100005, 0);
    vector<int> rec_stack(100005, 0);
    for(int i = 1; i <= a; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, rec_stack);
            if(cycle) return 1;
        }
    }
    return 0;
}
```

### [Delete Edge!](https://www.interviewbit.com/problems/delete-edge/)

```cpp
long long ans, sum;

int dfs(int v, int p, array<vector<int>, 100005> &adj, vector<int> &a) {
    int cur_sm = a[v - 1];
    for(auto it : adj[v]) {
        if(it != p) {
            cur_sm += dfs(it, v, adj, a);
            cur_sm %= 1000000007;
        }
    }
    int rest = (sum - cur_sm + 1000000007) % 1000000007;
    ans = max(ans, ((long long)cur_sm * rest) % 1000000007);
    return cur_sm;
}

int Solution::deleteEdge(vector<int> &a, vector<vector<int> > &b) {
    sum = 0; for(int i = 0; i < a.size(); i++) sum += a[i];
    array<vector<int>, 100005> adj;
    for(int i = 0; i < b.size(); i++) {
        adj[b[i][0]].push_back(b[i][1]);
        adj[b[i][1]].push_back(b[i][0]);
    }
    ans = 0;
    dfs(1, -1, adj, a);
    ans %= 1000000007;
    ans = (int)ans;
    return ans;
}
```

### [Two teams?](https://www.interviewbit.com/problems/two-teams/)

```cpp
int dfs(int v, array<vector<int>, 100005> &adj, vector<int> &color) {
    for(auto it : adj[v]) {
        if(!color[it]) {
            color[it] = 3 - color[v];
            if(dfs(it, adj, color)) return 1;
        }
        else {
            if(color[v] == color[it]) return 1;
        }
    }
    return 0;
}

int Solution::solve(int a, vector<vector<int> > &b) {
    array<vector<int>, 100005> adj;
    for(int i = 0; i < b.size(); i++) {
        adj[b[i][0]].push_back(b[i][1]);
        adj[b[i][1]].push_back(b[i][0]);
    }
    vector<int> color(100005, 0);

    for(int i = 1; i <= a; i++) {
        if(color[i] == 0) {
            color[i] = 1;
            if(dfs(i, adj, color)) return 0;
        }
    }
    return 1;
}
```

### [Stepping Numbers](https://www.interviewbit.com/problems/stepping-numbers/)

```cpp
// Method 1 (Did not use Graph)
int step(int i) {
    int dg = i % 10;
    i = i/10;
    while(i) {
        int dig = i % 10;
        if(abs(dg - dig) != 1) return 0;
        dg = dig;
        i = i/10;
    }
    return 1;
}

vector<int> Solution::stepnum(int a, int b) {
    vector<int> ans;
    for(int i = a; i <= b; i++) {
        if(step(i)) ans.push_back(i);
    }
    return ans;
}

// Method 2 (Use Graph)
void dfs(int num, int last_dig, int cur, int a, int b, vector<int> &ans) {
    if(num >= a && num <= b) ans.push_back(num);
    if(cur == 7) return;
    if (last_dig == -1) {
        for(int i = 1; i <= 9; i++) dfs(i, i, cur + 1, a, b, ans);
    }
    else {
        if(last_dig + 1 <= 9) dfs(num*10 + last_dig + 1, last_dig + 1, cur + 1, a, b, ans);
        if(last_dig - 1 >= 0) dfs(num*10 + last_dig - 1, last_dig - 1, cur + 1, a, b, ans);
    }
    return;
}

vector<int> Solution::stepnum(int a, int b) {
    vector<int> ans;
    dfs(0, -1, 0, a, b, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
```

### [Capture Regions on Board](https://www.interviewbit.com/problems/capture-regions-on-board/)

```cpp
vector<array<int, 2>> mov = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
void dfs(int i, int j, vector<vector<int>> &visited, vector<vector<char> > &a) {
    int n = a.size(), m = a[0].size();
    visited[i][j] = 1;
    a[i][j] = 'Y';
    for(auto it : mov) {
        int nx = i + it[0], ny = j + it[1];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m) {
            if(!visited[nx][ny] && a[nx][ny] == 'O') dfs(nx, ny, visited, a);
        }
    }
    return;
}

void Solution::solve(vector<vector<char> > &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> visited(n + 5, vector<int> (m + 5, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && a[i][j] == 'O' && !visited[i][j]) dfs(i, j, visited, a);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'O') a[i][j] = 'X';
            if(a[i][j] == 'Y') a[i][j] = 'O';
        }
    }
}
```

### [Word Search Board](https://www.interviewbit.com/problems/word-search-board/)

```cpp
vector<array<int, 2>> mov = {{0, - 1}, {1, 0}, {0, 1}, {-1, 0}};

int dfs(int x, int y, int cur, string &b, int n, vector<string> &a) {
    int m = a.size(), k = a[0].size();
    if(cur == n) return 1;
    for(auto it : mov) {
        int nx = x + it[0], ny = y + it[1];
        if(nx >= 0 && nx < m && ny >= 0 && ny < k) {
            if(a[nx][ny] == b[cur]) {
                int ret = dfs(nx, ny, cur + 1, b, n, a);
                if(ret) return 1;
            }
        }
    }
    return 0;
}

int Solution::exist(vector<string> &a, string b) {
    int n = b.size();
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[0].size(); j++) {
            if(a[i][j] == b[0]) {
                if(n == 1) return 1;
                if(dfs(i, j, 1, b, n, a)) return 1;
            }
        }
    }
    return 0;
}
```

### [Knight On Chess Board](https://www.interviewbit.com/problems/knight-on-chess-board/)

```cpp
int Solution::knight(int a, int b, int c, int d, int e, int f) {
    c--; d--; e--; f--;
    vector<array<int, 2>> mov = {{ -2, -1}, { -2, 1}, { -1, -2}, {1, -2}, {2, -1}, {2, 1}, {1, 2}, { -1, 2}};
    queue<pair<int, pair<int, int>>> q; q.push({0, {c, d}});
    vector<vector<int>> visited(a + 1, vector<int> (b + 1, 0));
    visited[c][d] = 1;
    while(!q.empty()) {
        auto [cost, pos] = q.front(); q.pop(); int x = pos.first, y = pos.second;
        if(x == e && y == f) return cost;
        for(auto it : mov) {
            int nx = x + it[0], ny = y + it[1];
            if(nx >= 0 && nx < a && ny >= 0 && ny < b && !visited[nx][ny]) {
                q.push({cost + 1, {nx, ny}});
                visited[nx][ny] = 1;
            }
        }
    }
    return -1;
}
```

### [Word Ladder I (Star Marked)](https://www.interviewbit.com/problems/word-ladder-i/)

```cpp
// Method 1 (O(N*N*25) / O(5000*5000*25) BFS)
int check(string a, string b) {
    if(a.size() != b.size()) return 0;
    int n = a.size(); int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) cnt++;
    }
    if(cnt + 1 == n) return 1;
    return 0;
}

int Solution::solve(string a, string b, vector<string> &c) {
    int n = c.size();
    queue<pair<int, string>> q; q.push({0, a});
    vector<int> visited(n + 5, 0);
    while(!q.empty()) {
        auto [cost, v] = q.front(); q.pop();
        if(v == b) return cost + 1;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                if(c[i] == v) {
                    visited[i] = 1;
                    continue;
                }
                if(check(v, c[i])) {
                    visited[i] = 1;
                    q.push({cost + 1, c[i]});
                }
            }
        }
    }
}

// Method 2 (O(N*25*26) / O(5000*25*26) BFS)
int Solution::solve(string a, string b, vector<string> &c) {
    int n = c.size();
    queue<pair<int, string>> q; q.push({0, a});
    vector<int> visited(n + 5, 0);
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++) mp[c[i]] = i + 1;
    if(mp.find(a) != mp.end()) visited[mp[a]] = 1;
    while(!q.empty()) {
        auto [cost, v] = q.front(); q.pop();
        if(v == b) return cost + 1;
        for(int i = 0; i < v.size(); i++) {
            string cpy(v);
            for(int j = 0; j < 26; j++) {
                cpy[i] = 'a' + j;
                if(mp.find(cpy) != mp.end() && !visited[mp[cpy]]) {
                    visited[mp[cpy]] = 1;
                    q.push({cost + 1, cpy});
                }
            }
        }
    }
}
```

### [Word Ladder II (Star Marked)](https://www.interviewbit.com/problems/word-ladder-ii/)

```cpp
void getAns(string a, string cur, vector<vector<string>> &ans, vector<string> &temp, unordered_map<string, vector<string>> &parent) {
    if(cur == a) {
        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        reverse(temp.begin(), temp.end());
        return;
    }
    for(auto it : parent[cur]) {
        temp.push_back(it);
        getAns(a, it, ans, temp, parent);
        temp.pop_back();
    }
    return;
}

vector<vector<string> > Solution::findLadders(string a, string b, vector<string> &c) {
    int n = c.size();
    queue<string> q; q.push(a);
    vector<int> visited(n + 5, 0);
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++) mp[c[i]] = i + 1;
    if(mp.find(a) != mp.end()) visited[mp[a]] = 1;
    if(mp.find(b) == mp.end()) mp[b] = n + 1;
    unordered_map<string, vector<string>> parent;
    unordered_map<string, int> distance; distance[a] = 0;
    while(!q.empty()) {
        auto v = q.front(); q.pop();
        if(v == b) break;
        for(int i = 0; i < v.size(); i++) {
            string cpy(v);
            for(int j = 0; j < 26; j++) {
                cpy[i] = 'a' + j;
                if(cpy != v && mp.find(cpy) != mp.end()) {
                    if(!visited[mp[cpy]]) {
                        visited[mp[cpy]] = 1;
                        q.push(cpy);
                        parent[cpy].push_back(v);
                        distance[cpy] = distance[v] + 1;
                    }
                    else {
                        if(distance[v] + 1 == distance[cpy]) parent[cpy].push_back(v);
                    }
                }
            }
        }
    }
    vector<vector<string>> ans;
    vector<string> temp = {b};
    getAns(a, b, ans, temp, parent);
    return ans;
}
```

### [Clone Graph (Star Marked)](https://www.interviewbit.com/problems/clone-graph/)

```cpp
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
void dfs(UndirectedGraphNode* root, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &cpy, unordered_map<UndirectedGraphNode*, int> &visited) {
    UndirectedGraphNode* node = new UndirectedGraphNode(root->label);
    cpy[root] = node; visited[root] = 1;
    for(auto it : root->neighbors) {
        if(!visited[it]) dfs(it, cpy, visited);
    }
    return;
}

void dfs2(UndirectedGraphNode* root, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &cpy, unordered_map<UndirectedGraphNode*, int> &vis) {
    UndirectedGraphNode* node = cpy[root]; vis[root] = 1;
    for(auto it : root->neighbors) {
        node->neighbors.push_back(cpy[it]);
        if(!vis[it]) dfs2(it, cpy, vis);
    }
    return;
}

UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cpy;
    unordered_map<UndirectedGraphNode*, int> visited;
    dfs(node, cpy, visited); unordered_map<UndirectedGraphNode*, int> vis;
    dfs2(node, cpy, vis);
    return cpy[node];
}
```
