### [Longest Common Subsequence](https://www.interviewbit.com/problems/longest-common-subsequence/)

```cpp
int Solution::solve(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(a[i] == b[j]) dp[i][j] = max({dp[i + 1][j], dp[i][j + 1], (1 + dp[i + 1][j + 1])});
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}
```

### [Longest Palindromic Subsequence](https://www.interviewbit.com/problems/longest-palindromic-subsequence/)

```cpp
int Solution::solve(string a) {
    int n = a.size(); vector<vector<int>> dp(n + 1, vector<int> (n +1, 1));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                if(j - i == 1) dp[i][j] = 2;
                else dp[i][j] = (2 + dp[i + 1][j - 1]);
            }
            dp[i][j] = max({dp[i][j], dp[i][j - 1], dp[i + 1][j]});
        }
    }
    int ans = *max_element(dp[0].begin(), dp[0].end());
    return ans;
}
```

### [Edit Distance (Star Marked)](https://www.interviewbit.com/problems/edit-distance/)

```cpp
int Solution::minDistance(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(a[i] == b[j]) {
                if(i == n - 1) dp[i][j] = m - j - 1;
                else if(j == m - 1) dp[i][j] = n - i - 1;
                else dp[i][j] = dp[i + 1][j + 1];
            }
            else {
                if(i == n - 1) dp[i][j] = 1 + min({m - j - 1, dp[i][j + 1]});
                else if(j == m - 1) dp[i][j] = 1 + min({n - i - 1, dp[i + 1][j]});
                else dp[i][j] = 1 + min({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]});
            }
        }
    }
    return dp[0][0];
}
```

### [Repeating Sub-Sequence](https://www.interviewbit.com/problems/repeating-subsequence/)

```cpp
int Solution::anytwo(string a) {
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(a[i] == a[j] && i != j) dp[i][j] = (1 + dp[i + 1][j + 1]);
            else dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    if(dp[0][0] >= 2) return 1;
    return 0;
}
```

### [Distinct Subsequences (Star Marked)](https://www.interviewbit.com/problems/distinct-subsequences/)

```cpp
int Solution::numDistinct(string a, string b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
    for(int i = 0; i <= m; i++) dp[n][i] = 0;
    for(int i = 0; i <= n; i++) dp[i][m] = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if((n - i) >= (m - j)) {
                if(a[i] == b[j]) {
                    if(dp[i + 1][j + 1] != -1) dp[i][j] = dp[i + 1][j + 1];
                    if(dp[i + 1][j] != -1) dp[i][j] += dp[i + 1][j];
                }
                else {
                    if(dp[i + 1][j] != -1) dp[i][j] = dp[i + 1][j];
                }
            }
        }
    }
    if(dp[0][0] == -1) return 0;
    return dp[0][0];
}
```

### [Scramble String (Star Marked)](https://www.interviewbit.com/problems/scramble-string/)

```cpp
int recur(string a, string b, map<pair<string, string>, int> &mp) {
    int n = a.size() - 1;
    if(n == 0) {
        if(a == b) mp[{a, b}] = 1;
        else mp[{a, b}] = 0;
        return mp[{a, b}];
    }
    for(int k = 0; k < n; k++) {
        string s1 = a.substr(0, k + 1), s2 = a.substr(k + 1);
        if(s2 + s1 == b) {
            mp[{a, b}] = 1;
            return 1;
        }
    }
    for(int k = 0; k < n; k++) {
        string a1 = a.substr(0, k + 1), a2 = a.substr(k + 1);
        string b1 = b.substr(0, k + 1), b2 = b.substr(k + 1);
        string b3 = b.substr(n - k), b4 = b.substr(0, n - k);
        if(mp.find({a1, b1}) == mp.end()) mp[{a1, b1}] = recur(a1, b1, mp);
        if(mp.find({a2, b2}) == mp.end()) mp[{a2, b2}] = recur(a2, b2, mp);
        if(mp[{a1, b1}] && mp[{a2, b2}]) {
            mp[{a, b}] = 1;
            return 1;
        }
        if(mp.find({a1, b3}) == mp.end()) mp[{a1, b3}] = recur(a1, b3, mp);
        if(mp.find({a2, b4}) == mp.end()) mp[{a2, b4}] = recur(a2, b4, mp);
        if(mp[{a1, b3}] && mp[{a2, b4}]) {
            mp[{a, b}] = 1;
            return 1;
        }
    }
    mp[{a, b}] = 0;
    return 0;
}

int Solution::isScramble(const string a, const string b) {
    int n = a.size(), m = b.size();
    if(n != m) return 0;
    map<pair<string, string>, int> mp;
    return recur(a, b, mp);
}
```

### [Regular Expression Match (Star Marked)](https://www.interviewbit.com/problems/regular-expression-match/)

```cpp
// Method 1 (O(n*m) space and time)
int Solution::isMatch(const string a, const string b) {
    int n = a.size(), m = b.size(); vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    dp[n][m] = 1;
    for(int j = m - 1; j >= 0; j--) {
        if(b[j] == '*') dp[n][j] = 1;
        else break;
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(a[i] == b[j]) dp[i][j] = dp[i + 1][j + 1];
            else {
                if(b[j] == '?') dp[i][j] = dp[i + 1][j + 1];
                else if(b[j] == '*') dp[i][j] = (dp[i + 1][j] || dp[i + 1][j + 1] || dp[i][j + 1]);
            }
        }
    }
    return dp[0][0];
}

// Method 2 (O(n*m) time and O(m) space)
int Solution::isMatch(const string a, const string b) {
    int n = a.size(), m = b.size(); vector<int> dplast(m + 1, 0); dplast[m] = 1;
    vector<int> dpcur(m + 1, 0);
    for(int j = m - 1; j >= 0; j--) {
        if(b[j] == '*') dplast[j] = 1;
        else break;
    }
    for(int i = n - 1; i >= 0; i--) {
        fill(dpcur.begin(), dpcur.end(), 0);
        for(int j = m - 1; j >= 0; j--) {
            if(a[i] == b[j]) dpcur[j] = dplast[j + 1];
            else {
                if(b[j] == '?') dpcur[j] = dplast[j + 1];
                else if(b[j] == '*') dpcur[j] = (dplast[j] || dplast[j + 1] || dpcur[j + 1]);
            }
        }
        dplast = dpcur;
    }
    return dpcur[0];
}
```

### [Regular Expression II (Star Marked)](https://www.interviewbit.com/problems/regular-expression-ii/)

```cpp
int Solution::isMatch(const string a, const string b) {
    int n = a.size(), m = b.size(); vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    dp[n][m] = 1;
    for(int i = m - 1; i >= 0; i--) {
        if(b[i] == '*') dp[n][i] = 1;
        else break;
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(a[i] == b[j]) {
                if(j + 1 < m) {
                    if(b[j + 1] == '*') dp[i][j] = (dp[i + 1][j + 1] || dp[i + 1][j] || dp[i][j + 1]);
                    else dp[i][j] = dp[i + 1][j + 1];
                }
                else dp[i][j] = dp[i + 1][j + 1];
            }
            else {
                if(b[j] == '*') dp[i][j] = dp[i][j + 1];
                else if(b[j] == '.') {
                    dp[i][j] = dp[i + 1][j + 1];
                    if(j + 1 < m  && b[j + 1] == '*') dp[i][j] = (dp[i][j] || dp[i + 1][j]);
                }
                else {
                    if(j + 1 < m && b[j + 1] == '*') dp[i][j] = dp[i][j + 1];
                }
            }
        }
    }
    return dp[0][0];
}
```

### [Interleaving Strings](https://www.interviewbit.com/problems/interleaving-strings/)

```cpp
int Solution::isInterleave(string a, string b, string c) {
    int n = a.size(), m = b.size(), o = c.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (o + 1, 0)));
    if(a[n - 1] == c[o - 1]) dp[n - 1][m][o - 1] = 1;
    if(b[m - 1] == c[o - 1]) dp[n][m - 1][o - 1] = 1;
    dp[n][m][o] = 1;
    for(int i = n; i >= 0; i--) {
        for(int j = m; j >= 0; j--) {
            for(int k = o - 1; k >= 0; k--) {
                if(i == n) {
                    if(b[j] == c[k]) dp[i][j][k] = dp[i][j + 1][k + 1];
                }
                else if (j == m) {
                    if(a[i] == c[k]) dp[i][j][k] = dp[i + 1][j][k + 1];
                }
                else if(i != n && j != m && (n - i) + (m - j) == (o - k)) {
                    if(a[i] == c[k]) {
                        dp[i][j][k] = dp[i + 1][j][k + 1];
                    }
                    if(b[j] == c[k]) dp[i][j][k] = (dp[i][j][k] || dp[i][j + 1][k + 1]);
                }
            }
        }
    }
    return dp[0][0][0];
}
```

### [Length of Longest Subsequence](https://www.interviewbit.com/problems/length-of-longest-subsequence/)

```cpp
int Solution::longestSubsequenceLength(const vector<int> &a) {
    int n = a.size(); vector<int> dp(n + 1, 1);
    if(n == 0) return 0;
    vector<int> dp2(n + 1, 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] > a[j]) dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j > i; j--) {
            if(a[i] > a[j]) dp2[i] = max(dp2[i], 1 + dp2[j]);
        }
    }
    int ans = 1;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i] + dp2[i] - 1);
    return ans;
}
```

### [Smallest sequence with given Primes (Star Marked)](https://www.interviewbit.com/problems/smallest-sequence-with-given-primes/)

```cpp
// Method 1 (using priority queue O(DlogD))
vector<int> Solution::solve(int A, int B, int C, int D) {
    //min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(A); pq.push(B); pq.push(C);
    unordered_map<int, int> mp; // used to check if element exists or not
    vector<int> res;

    while(D > 0){
        if(mp[pq.top()]){ // if ele already exists, no use so kick it and continue
            pq.pop();
            continue;
        }
        // top of pq always has min ele of all, so try combinations with it
        // and then kick it out
        if(!mp[pq.top()*A]) pq.push(pq.top()*A);

        if(!mp[pq.top()*B]) pq.push(pq.top()*B);

        if(!mp[pq.top()*C]) pq.push(pq.top()*C);

        D--;
        mp[pq.top()]++;
        res.push_back(pq.top());
        pq.pop();
    }
    return res; // will already be in sorted order as we used reverse priorityQ (minHeap)
}

// Mehotd 2 (O(D) solution)
vector<int> Solution::solve(int A, int B, int C, int D) {
    vector<int> ans;
    ans.push_back(1);
    int i=0,j=0,k=0;
    while(D--){
        int x=min(ans[i]*A,min(ans[j]*B,ans[k]*C));
        if(x==ans[i]*A) i++;
        if(x==ans[j]*B) j++;
        if(x==ans[k]*C) k++;
        ans.push_back(x);
    }
    ans.erase(ans.begin());
    return ans;
}
```

### [Largest area of rectangle with permutations (Star Marked)](https://www.interviewbit.com/problems/largest-area-of-rectangle-with-permutations/)

```cpp
int calc(vector<int> row) {
    sort(row.begin(), row.end());
    int n = row.size();
    int ans = row[n - 1], width = 2;
    for(int i = n - 2; i >= 0; i--) {
        ans = max(ans, row[i]*width);
        width++;
    }
    return ans;
}

int Solution::solve(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    vector<int> row = a[0];
    int ans = calc(row);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0) row[j] = 0;
            else row[j]++;
        }
        ans = max(ans, calc(row));
    }
    return ans;
}
```

### [Ways to Decode](https://www.interviewbit.com/problems/ways-to-decode/)

```cpp
int recur(string &a, int ind, vector<int> &dp) {
    int n = a.size();
    if(ind == n) {
        dp[n] = 1;
        return 1;
    }
    if(a[ind] == '0') {
        dp[ind] = 0;
        return 0;
    }
    int ans;
    if(dp[ind + 1] == -1) {
        ans = recur(a, ind + 1, dp);
        dp[ind + 1] = ans%1000000007;
    }
    else ans = dp[ind + 1];
    ans %= 1000000007;
    if((n - ind) > 1) {
        int num = (a[ind] - '0')*10 + (a[ind + 1] - '0');
        if(num <= 26) {
            if(dp[ind + 2] == -1) {
                int gt = recur(a, ind + 2, dp);
                dp[ind + 2] = gt%1000000007;
                ans += gt;
            }
            else ans += dp[ind + 2];
        }
    }
    ans %= 1000000007;
    dp[ind] = ans;
    return ans;
}

int Solution::numDecodings(string a) {
    int n = a.size();
    vector<int> dp(n + 1, -1);
    return recur(a, 0, dp);
}
```

### [Stairs](https://www.interviewbit.com/problems/stairs/)

```cpp
int Solution::climbStairs(int a) {
    vector<int> dp(a + 1, 0); dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= a; i++) dp[i] += (dp[i - 1] + dp[i -2]);
    return dp[a];
}
```

### [Longest Increasing Subsequences](https://www.interviewbit.com/problems/longest-increasing-subsequence/)

```cpp
int Solution::lis(const vector<int> &a) {
    int n = a.size();
    vector<int> dp(n + 1, 1);
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n -1; j > i; j--) {
            if(a[j] > a[i]) dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    int ans = dp[0];
    for(int i = 1; i < n; i++) ans = max(ans, dp[i]);
    return ans;
}
```
