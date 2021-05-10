### [Colorful Number](https://www.interviewbit.com/problems/colorful-number/)

```cpp
int Solution::colorful(int a) {
    vector<int> v;
    while(a>0) {
        int dg = a%10;
        v.push_back(dg);
        a = a/10;
    }
    if(v.size() >= 10) return 0;
    map<int, int> mp;
    for(int i = 1; i <= v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(j + i - 1 >= v.size()) break;
            int num = 1;
            for(int k = j; k <= (j + i - 1); k++) num *= v[k];
            if(mp[num] == 1) return 0;
            mp[num]++;
        }
    }
    return 1;
}
```

### [Largest Continuous Sequence Zero Sum](https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/)

```cpp
vector<int> Solution::lszero(vector<int> &a) {
    int n = a.size();
    map<int,int> mp;
    int sm = 0, ans = 0, left = -1, right = -1;
    for(int i = 0; i < n; i++) {
        sm += a[i];
        if(sm == 0) {
            if(i + 1 > ans) {
                ans = i + 1;
                left = 0;
                right = i;
            }
        }
        else {
            if(mp[sm] != 0) {
                int last = mp[sm];
                int len = i - last + 1;
                if(len > ans) {
                    left = last;
                    right = i;
                    ans = len;
                }
            }
            else mp[sm] = i + 1;
        }
    }
    vector<int> ret;
    if (left == -1) return {};
    for(int i = left; i <= right; i++) ret.push_back(a[i]);
    return ret;
}
```

### [2 Sum](https://www.interviewbit.com/problems/2-sum/)

```cpp
vector<int> Solution::twoSum(const vector<int> &a, int b) {
    map<int, int> mp;
    for(int i = 0; i < a.size(); i++) {
        if(mp[b - a[i]] != 0) {
            vector<int> v = {mp[b - a[i]], i + 1};
            return v;
        }
        if(mp[a[i]] == 0) mp[a[i]] = i + 1;
    }
    return {};
}
```

### [4 Sum (Star Marked)](https://www.interviewbit.com/problems/4-sum/)

```cpp
// Method 1 (O(n^3) solution using hash map and storing answer in set<vector<int>> to avoid duplicate cases)
vector<vector<int> > Solution::fourSum(vector<int> &a, int b) {
    int n = a.size();
    sort(a.begin(), a.end());
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) mp[a[i]]++;
    set<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        mp[a[i]]--;
        for(int j = i + 1; j < n; j++) {
            mp[a[j]]--;
            for(int k = j + 1; k < n; k++) {
                int sm = a[i] + a[j] + a[k];
                int nm = b - sm;
                mp[a[k]]--;
                if(mp[nm] != 0 && nm >= a[k]) {
                    vector<int> v = {a[i], a[j], a[k], nm};
                    ans.insert(v);
                }
                mp[a[k]]++;
            }
            mp[a[j]]++;
        }
        mp[a[i]]++;
    }
    vector<vector<int>> ret;
    for(auto it : ans) ret.push_back(it);
    return ret;
}

// Method 2 (O(n^3) solution using hash map and using backtracking with index technique so that we do no need
// to use set<vector<int>> to store the answer to avoid duplicate cases)
vector<vector<int> > Solution::fourSum(vector<int> &a, int b) {
    int n = a.size();
    sort(a.begin(), a.end());
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) mp[a[i]]++;
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        mp[a[i]]--;
        for(int j = i + 1; j < n; j++) {
            mp[a[j]]--;
            for(int k = j + 1; k < n; k++) {
                int sm = a[i] + a[j] + a[k];
                int nm = b - sm;
                mp[a[k]]--;
                if(mp[nm] != 0 && nm >= a[k]) {
                    vector<int> v = {a[i], a[j], a[k], nm};
                    ans.push_back(v);
                }
                mp[a[k]]++;
                int ind = k;
                while(ind < n && a[ind] == a[k]) ind++;
                k = ind - 1;
            }
            mp[a[j]]++;
            int ind = j;
            while(ind < n && a[ind] == a[j]) ind++;
            j = ind - 1;
        }
        mp[a[i]]++;
        int ind = i;
        while(ind < n && a[ind] == a[i]) ind++;
        i = ind - 1;
    }
    return ans;
}
```

### [Valid Sudoku](https://www.interviewbit.com/problems/valid-sudoku/)

```cpp
int valid(int i, int j, const vector<string> &a) {
    for(int y = 0; y < 9; y++) {
        if(y == j) continue;
        if(a[i][y] == a[i][j]) return 0;
    }
    for(int x = 0; x < 9; x++) {
        if(x == i) continue;
        if(a[x][j] == a[i][j]) return 0;
    }
    int x = 3 * (i / 3);
    int y = 3 * (j / 3);
    for(int u = x; u < (x + 3); u++) {
        for(int v = y; v < (y + 3); v++) {
            if(u == i && v == j) continue;
            if(a[u][v] == a[i][j]) return 0;
        }
    }
    return 1;
}

int Solution::isValidSudoku(const vector<string> &a) {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(a[i][j] != '.' && !valid(i, j, a)) return 0;
        }
    }
    return 1;
}
```

### [Diffk II](https://www.interviewbit.com/problems/diffk-ii/)

```cpp
int Solution::diffPossible(const vector<int> &a, int b) {
    int n = a.size();
    map<int, int> mp;
    for(auto it : a) {
        if(mp[it + b] != 0 || mp[it - b] != 0) return 1;
        mp[it] = 1;
    }
    return 0;
}
```

### [Anagrams](https://www.interviewbit.com/problems/anagrams/)

```cpp
// Method 1 (Some Stupid use of Map)
vector<vector<int> > Solution::anagrams(const vector<string> &a) {
    int n = a.size();
    vector<vector<int>> ans;
    map<char, int> mp[n];
    for(int i = 0; i < n; i++) {
        for(auto it : a[i]) mp[i][it]++;
    }
    map<int, int> anagram;
    for(int i = 0; i < n; i++) {
        if(anagram[i] == 0) {
            vector<int> v = {i + 1};
            anagram[i] = 1;
            for(int j = i + 1; j < n; j++) {
                if(mp[i] == mp[j]) {
                    anagram[j] = 1;
                    v.push_back(j + 1);
                }
            }
            ans.push_back(v);
        }
    }
    return ans;
}

// Method 2 (Smart Use of Map)
vector<vector<int> > Solution::anagrams(const vector<string> &a) {
    int n = a.size();
    vector<vector<int>> ans;
    map<string, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        string cpy = a[i];
        sort(cpy.begin(), cpy.end());
        mp[cpy].push_back(i + 1);
    }
    for(auto it : mp) ans.push_back(it.second);
    return ans;
}
```
