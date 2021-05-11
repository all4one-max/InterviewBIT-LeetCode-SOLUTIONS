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

### [Equal](https://www.interviewbit.com/problems/equal/)

```cpp
vector<int> Solution::equal(vector<int> &a) {
    int n = a.size();
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(mp[a[i] + a[j]].size() == 0) {
                mp[a[i] + a[j]].push_back(i);
                mp[a[i] + a[j]].push_back(j);
            }
        }
    }
    vector<int> ans = {};
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(mp[a[i] + a[j]].size()) {
                if(mp[a[i] + a[j]][0] < i && mp[a[i] + a[j]][1] != i && mp[a[i] + a[j]][1] != j) {
                    if(ans.size() == 0) {
                        ans = mp[a[i] + a[j]];
                        ans.push_back(i);
                        ans.push_back(j);
                    }
                    else{
                        int a1 = mp[a[i] + a[j]][0], b1 = mp[a[i] + a[j]][1];
                        int c1 = i, d1 = j;
                        if(a1 < ans[0]) ans = {a1, b1, c1, d1};
                        else if (a1 == ans[0] && b1 < ans[1]) ans = {a1, b1, c1, d1};
                        else if (a1 == ans[0] && b1 == ans[1] && c1 < ans[2]) ans = {a1, b1, c1, d1};
                        else if (a1 == ans[0] && b1 == ans[1] && c1 == ans[2] && d1 < ans[3]) ans = {a1, b1, c1, d1};
                    }
                }
            }
        }
    }
    return ans;
}
```

### [Copy List (Star Marked)](https://www.interviewbit.com/problems/copy-list/)

```cpp
/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* head) {

    RandomListNode* origCur =NULL;
    RandomListNode* cloneCur =NULL;

    unordered_map <RandomListNode*,RandomListNode*> map;

    origCur = head;
    while(origCur)
    {
        cloneCur = new RandomListNode(origCur->label);
        map[origCur] = cloneCur;
        origCur = origCur->next;
    }

    origCur = head;

    while(origCur)
    {
        map[origCur]->next = map[origCur->next];
        map[origCur]->random = map[origCur->random];
        origCur = origCur->next;
    }

    return map[head];
}
```

### [Window String (Star Marked)](https://www.interviewbit.com/problems/window-string/)

```cpp
#define fi             first
#define se             second

string Solution::minWindow(string s, string t) {
    unordered_map<char, int> mt;
    for(auto it : t) mt[it]++;
    unordered_map<char, int> ms;
    int n = s.size();
    int i = 0, j = 0;
    int cnt = 0, val = mt.size();
    ms[s[0]]++; if(mt[s[0]] == 1) cnt++;
    int ans = 1e9, left = -1, right = -1;
    while(i < n && j < n) {
        if(cnt == val) {
            int len = (j - i + 1);
            if(ans > len) {
                ans = len;
                left = i;
                right = j;
            }
            if(i == j) {
                j++;
                if(j < n && mt[s[j]]) {
                    if(ms[s[j]] + 1 == mt[s[j]]) cnt++;
                    ms[s[j]]++;
                }
            }
            else {
                if(mt[s[i]]) {
                    if(ms[s[i]] == mt[s[i]]) cnt--;
                    ms[s[i]]--;
                }
                i++;
            }
        }
        else {
            j++;
            if(j < n && mt[s[j]]) {
                if(ms[s[j]] + 1 == mt[s[j]]) cnt++;
                ms[s[j]]++;
            }
        }
    }
    if(left == -1) return "";
    return s.substr(left, ans);
}
```

### [Longest Substring Without Repeat](https://www.interviewbit.com/problems/longest-substring-without-repeat/)

```cpp
int Solution::lengthOfLongestSubstring(string a) {
    int n = a.size();
    unordered_map<char, int> mp;
    int i = 0, j = 0;
    int len = 1, ans = 1;
    mp[a[0]] = 1;
    while(i < n && j < n) {
        j++;
        if(j < n) {
            if(mp[a[j]] == 1) {
                while(i<n && a[i] != a[j]) {
                    len--;
                    mp[a[i]]--;
                    i++;
                }
                i++;
                len = (j - i + 1);
                ans = max(ans, len);
            }
            else {
                len++;
                ans = max(ans, len);
                mp[a[j]] = 1;
            }
        }
    }
    return ans;
}
```

### [Fraction (Star Marked)](https://www.interviewbit.com/problems/fraction/)

```cpp
string Solution::fractionToDecimal(int x, int y) {
    long long a = (long long) x; long long b = (long long) y;
    int flag = 0;
    if((a>0 && b<0) || (a<0 && b>0)) flag = 1;
    a = abs(a); b = abs(b);
    long long integer_part = a/b;
    string s = to_string(integer_part);
    if(flag) s = "-" + s;
    long long rem = a%b;
    if(rem == 0) return s;
    s = s + ".";
    long long pos = s.size();
    map<long long, long long> mp;
    while(true) {
        if(mp[rem] != 0) {
            long long rep = mp[rem];
            string pre = s.substr(0, rep);
            string rest = s.substr(rep);
            string ret = pre + "(" + rest + ")";
            return ret;
        }
        mp[rem] = pos;
        rem *= 10;
        long long vl = rem/b;
        rem = rem%b;
        string add = to_string(vl);
        s += add;
        pos += add.size();
        if(rem == 0) break;
    }
    return s;
}
```

### [Points on the Straight Line](https://www.interviewbit.com/problems/points-on-the-straight-line/)

```cpp
int Solution::maxPoints(vector<int> &x, vector<int> &y) {
    int n = x.size();
    if(n == 0) return 0;
    if(n == 1) return 1;
    int ans = 2;
    for(int i = 0; i < n; i++) {
        map<double, int> mp;
        int cur_max = 0, same_points = 0;
        for(int j = i + 1; j < n; j++) {
            double num = (y[j] - y[i]);
            double den = (x[j] - x[i]);
            if(num == 0 && den == 0) {
                same_points++;
                continue;
            }
            double slope;
            if(den != 0) slope = ((double) num/den);
            else slope = 1e12;
            mp[slope]++;
            cur_max = max(cur_max, mp[slope]);
        }
        ans = max(ans, cur_max + same_points + 1);
    }
    return ans;
}
```

### [Substring Concatenation (Star Marked)](https://www.interviewbit.com/problems/substring-concatenation/)

```cpp
// Do refere the leetcode for constraints
vector<int> Solution::findSubstring(string s, const vector<string> &b) {
    int word_len = b[0].size(), num_words = b.size();
    unordered_map<string, int> mpb;
    for(auto it : b) mpb[it]++;
    int i = 0, j = 0, count = 0;
    int n = mpb.size();
    int m = s.size();
    vector<int> ans;
    for(int i = 0; i < m; i++) {
        if(i + word_len * num_words > m) break;
        unordered_map<string, int> mpa;
        int count = 0;
        for(int j = i; j < (i + word_len * num_words); j+=word_len) {
            string word = s.substr(j, word_len);
            mpa[word]++;
            if(mpb[word] && mpa[word] == mpb[word]) count++;
            if(!mpb[word]) break;
        }
        if(count == n) ans.push_back(i);
    }
    return ans;
}
```
