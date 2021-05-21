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
