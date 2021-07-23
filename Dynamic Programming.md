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

### [Tiling With Dominoes (Star Marked)](https://www.interviewbit.com/problems/tiling-with-dominoes/)

```cpp
// Method 1 (Combinatorics Solution, useful only for lesser number of rows)
#define mod 1000000007

int Solution::solve(int n) {
    if(n % 2) return 0;
    else {
        long long ans = 1; long long a0 = 1, a1 = 0, b1 = 1, b0 = 0;
        for(int i = 2; i <= n; i++) {
            long long na = ((long long)a0 + 2LL * b1) % mod;
            long long nb = (a1 + b0) % mod;
            a0 = a1; b0 = b1; a1 = na; b1 = nb;
        }
        return a1;
    }
}

// Method 2 (DP with Bitmask solution - easy to solve)
#define mod 1000000007

int Solution::solve(int n) {
    vector<vector<long long>> dp(n + 2, vector<long long> (8, 0LL));
    dp[1][3] = 1; dp[1][6] = 1; dp[0][7] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i][1] = dp[i - 1][6];

        dp[i][3] += dp[i - 1][7];
        dp[i][3] += dp[i - 1][4];
        dp[i][3] %= mod;

        dp[i][4] = dp[i - 1][3];

        dp[i][6] += dp[i - 1][7];
        dp[i][6] += dp[i - 1][1];
        dp[i][6] %= mod;

        dp[i][7] += dp[i - 1][3];
        dp[i][7] += dp[i - 1][6];
        dp[i][7] += dp[i - 2][7];
        dp[i][7] %= mod;
    }
    return dp[n][7];
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

### [Jump Game Array](https://www.interviewbit.com/problems/jump-game-array/)

```cpp
// Method 1 (DP gives MLE)
int recur(int ind, int n, vector<int> &a, vector<vector<int>> &dp) {
    if(ind == n - 1) return 1;
    if(a[ind] == 0) return 0;

    for(int k = 1; k <= a[ind]; k++) {
        if(ind + k < n) {
            int rec;
            if(dp[ind][k] == -1) {
                rec = recur(ind + k, n, a, dp);
                dp[ind][k] = rec;
            }
            else rec = dp[ind][rec];
            if(rec == 1) return 1;
        }
    }
    return 0;
}

int Solution::canJump(vector<int> &a) {
    int n = a.size(); vector<vector<int>> dp(n + 1, vector<int> (31, -1));
    return recur(0, n, a, dp);

}

// Method 2(using Greedy)
int Solution::canJump(vector<int> &a) {
    int n = a.size();
    int i = 0; int max_reach = 0;
    while(i <= max_reach) {
        max_reach = max(i + a[i], max_reach);
        if(max_reach >= n - 1) return 1;
        i++;
    }
    return 0;
}
```

### [Min Jumps Array (Star Marked)](https://www.interviewbit.com/problems/min-jumps-array/)

```cpp
// Method 1 (from a given point i the maximum position we can reach is i + 50000 so if there is no way to reach n in
// between [n - 50000, n] then there won't be any point from which I can reach n. So to get the minimum jumps
// I am taking the first point in the given range which will reach N as this would be sufficient enough)

int Solution::jump(vector<int> &a) {
    int n = a.size() - 1; int i = max(0, n - 50000);
    if(n == 0) return 0;
    int ans = 0;
    while(i >= 0) {
        int found = 0;
        for(int j = i; j < n; j++) {
            if(j + a[j] >= n) {
                n = j;
                i = max(0, n - 50000);
                ans++;
                found = 1;
                if(j == 0) return ans;
                break;
            }
        }
        if(!found) return -1;
    }
    return ans;
}

// Method 2 (storing the maximum possible jump from a point)
int Solution::jump(vector<int> &A) {
    if(A.size()==1)return 0;
    vector<int> aux=A;
    for (int i=1;i<A.size();i++){
        A[i]=max(A[i],A[i-1]-1);
    }

    int pos=0;
    int count=0;
    while(true){
        pos+=A[pos];
        count++;
        if(pos>=A.size()-1) return count;
        else if(A[pos]==0) return -1;
    }
}
```

### [Longest Arithmetic Progression (Star Marked)](https://www.interviewbit.com/problems/longest-arithmetic-progression/)

```cpp
// In Method 1 and Method 2 dp[i][j] = maximum length of arithmetic sequence starting at position i and havin common
// difference as cd
// Method 1 (O(n^2logn) Gives TLE in InterviewBit but AC in Leetcode while using map<pair<int, int>, int> dp;)
int Solution::solve(const vector<int> &a) {
    int n = a.size();
    map<pair<int, int>, int> dp;
    int ans = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            int cd = a[j] - a[i];
            if(dp.find({j, cd}) == dp.end()) dp[{j, cd}] = 1;
            dp[{i, cd}] = max(dp[{i, cd}], 1 + dp[{j, cd}]);
            ans = max(ans, dp[{i, cd}]);
        }
    }
    return ans;
}

// Method 2 (O(n^2) AC in both sites using unordered_map<int, int> dp[n];)
int Solution::solve(const vector<int> &a) {
    int n = a.size();
    unordered_map<int, int> dp[n];
    int ans = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            int cd = a[j] - a[i];
            if(dp[j][cd] == 0) dp[j][cd] = 1;
            dp[i][cd] = max(dp[i][cd], 1 + dp[j][cd]);
            ans = max(ans, dp[i][cd]);
        }
    }
    return ans;
}

// Method 3 (O(n^2) AC dp[i][j] = max length if a[i] is first element and a[j] is second element)
int Solution::solve(const vector<int> &a) {
    int n = a.size();
    if(n < 3) return n;
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
    unordered_map<int, int> mp; int ans = 2;
    for(int sec = n - 1; sec >= 0; sec--) {
        for(int fir = sec - 1; fir >= 0; fir--) {
            int x = 2*a[sec] - a[fir];
            dp[fir][sec] = 2;
            if(mp.find(x) == mp.end()) continue;
            int pos = mp[x];
            dp[fir][sec] = max(dp[fir][sec], 1 + dp[sec][pos]);
            ans = max(ans, dp[fir][sec]);
        }
        mp[a[sec]] = sec;
    }
    return ans;
}
```

### [Shortest common superstring (Star Marked)](https://www.interviewbit.com/problems/shortest-common-superstring/)

```cpp
// So basically to solve this question you need to observe that n = 18 and you can memorize it as a trick that
// if n is less than 20 then you can may be come up with a bitmask solution. So this observation along with
// the knowledge of travelling salesman problem i managed to solve this question.
int getAns(string a, string b) {
    int n = a.size(), m = b.size(), cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        int len = n - i;
        if(m >= len) {
            string a1 = a.substr(i, len);
            string b1 = b.substr(0, len);
            if(a1 == b1) {
                cnt = len;
                break;
            }
        }
    }
    return m - cnt;
}

int tsp(int pos, int mask, vector<vector<int>> &dp, vector<string> &a, int n, vector<vector<int>> &dp2) {
    if(mask == ((1 << n) - 1)) return 0;

    if(pos != -1 && dp[pos][mask] != -1) return dp[pos][mask];

    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        if((mask & (1 << i)) == 0) {
            int cur_ans;
            if(pos == -1) cur_ans = a[i].size() + tsp(i, mask | (1 << i), dp, a, n, dp2);
            else cur_ans = dp2[pos][i] + tsp(i, mask | (1 << i), dp, a, n, dp2);
            ans = min(ans, cur_ans);
        }
    }

    if(pos == -1) return ans;
    return dp[pos][mask] = ans;
}

int Solution::solve(vector<string> &a) {
    int n = a.size();
    vector<vector<int>> dp(19, vector<int> (300005, -1));
    vector<vector<int>> dp2(n + 1, vector<int> (n + 1, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) dp2[i][j] = getAns(a[i], a[j]);
        }
    }
    return tsp(-1, 0, dp, a, n, dp2);
}
```

### [Ways to color a 3xN Board (Star Makred)](https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/)

```cpp
// Method 1 (Using DP O(n * 36 * 36 * 3) Time and O(n * 4 * 4 * 4) space)
int valid(array<int, 3> a1, array<int, 3> a2) {
    for(int i = 0; i < 3; i++) {
        if(a1[i] == a2[i]) return 0;
    }
    return 1;
}

int Solution::solve(int n) {
    vector<vector<vector<vector<int>>>> dp(n + 1, vector<vector<vector<int>>> (4, vector<vector<int>> (4, vector<int> (4, 0))));
    vector<array<int, 3>> v;
    for(int i = 0; i <= 3; i++) {
        for(int j = 0; j <= 3; j++) {
            if(j != i) {
                for(int k = 0; k <= 3; k++) {
                    if(k != j){
                        dp[n - 1][i][j][k] = 1;
                        v.push_back({i, j, k});
                    }
                }
            }
        }
    }
    int mod = 1000000007;
    for(int i = n - 2; i >= 0; i--) {
        for(auto it : v) {
            for(auto it2 : v) {
                if (valid(it, it2)) {
                    dp[i][it[0]][it[1]][it[2]] += dp[i + 1][it2[0]][it2[1]][it2[2]];
                    dp[i][it[0]][it[1]][it[2]] %= mod;
                }
            }
        }
    }
    int ans = 0;
    for(auto it : v) {
        ans += dp[0][it[0]][it[1]][it[2]];
        ans %= mod;
    }
    return ans;
}

// Method 2 (Maths solution)
// To understand it better follow this [link](https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/574943/Java-Detailed-Explanation-with-Graph-Demo-DP-Easy-Understand)
int Solution::solve(int n) {
    long long abc = 24, aba = 12;
    for(int i = n - 2; i >= 0; i--) {
        long long new_abc = 11*abc + 10*aba;
        long long new_aba = 5*abc + 7*aba;
        aba = new_aba % 1000000007; abc = new_abc % 1000000007;
    }
    long long ans = ((long long)aba % 1000000007 + abc % 1000000007) % 1000000007;
    return ans;
}
```

### [Kth Manhattan Distance Neighbourhood](https://www.interviewbit.com/problems/kth-manhattan-distance-neighbourhood/)

```cpp
vector<vector<int> > Solution::solve(int a, vector<vector<int> > &b) {
    int n = b.size(), m = b[0].size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (m + 1, vector<int> (a + 1, 0)));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) dp[i][j][0] = b[i][j];
    }
    for(int k = 1; k <= a; k++) {
        for(int i = 0; i < n; i++) {
            for(int  j = 0; j < m; j++) {
                dp[i][j][k] = max(dp[i][j][k], dp[i][j][k - 1]);
                if(j + 1 < m) dp[i][j][k] = max(dp[i][j][k], dp[i][j + 1][k - 1]);
                if(i + 1 < n) dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][k - 1]);
                if(j - 1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1]);
                if(i - 1 >= 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1]);
            }
        }
    }
    vector<vector<int>> ans(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) ans[i][j] = dp[i][j][a];
    }
    return ans;
}
```

### [Best Time to Buy and Sell Stock with Transaction Fee LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& a, int fee) {
        int n = a.size();
        int ans = 0;
        vector<int> dp(n + 1, 0);
        int mx = -1e9;
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i], mx - a[i]);
            if(i + 1 < n) mx = max(mx, dp[i + 1] + a[i] - fee);
            else mx = a[i] - fee;
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};
```

### [Best Time to Buy and Sell Stock with Cooldown LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        vector<int> dp(n + 1, 0);
        int mx = -1e9;
        for(int i = n - 1; i >= 0; i--) {
            dp[i] = max(dp[i], mx - a[i]);
            if(i + 2 < n) mx = max(mx, dp[i + 2] + a[i]);
            else mx = max(mx, a[i]);
            dp[i] = max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};
```

### [Best Time to Buy and Sell Stock atmost B times (Star Marked)](https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stock-atmost-b-times/)

```cpp
int Solution::solve(vector<int> &a, int k) {
    int n = a.size();
    k = min(k, n/2);
    vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
    for(int i = 1; i <= k; i++) {
        int mx = -1e9;
        for(int j = n - 1; j >= 0; j--) {
            dp[j][i] = max(dp[j][i], mx - a[j]);
            if(j + 1 < n) mx = max(mx, dp[j + 1][i - 1] + a[j]);
            else mx = a[j];
            if(j + 1 < n) dp[j][i] = max(dp[j][i], dp[j + 1][i]);
        }

    }
    return dp[0][k];
}
```

### [Evaluate Expression To True (Star Marked)](https://www.interviewbit.com/problems/evaluate-expression-to-true/)

```cpp
// Based on Matrix Chain Multiplication
#define mod 1003

int Solution::cnttrue(string a) {
    int n = a.size();
    vector<vector<vector<int>>> dp(n + 5, vector<vector<int>> (n + 5, vector<int> (2, 0)));
    for(int i = 0; i < n; i += 2) {
        if(a[i] == 'T') dp[i][i][0] = 1;
        else dp[i][i][1] = 1;
    }
    for(int len = 2; len < n; len++) {
        for(int i = 0; i < n; i += 2) {
            int j = i + 2*(len - 1);
            if(j < n) {
                for(int k = i + 1; k < j; k += 2) {
                    long long ans1 = ((long long)dp[i][k - 1][0] * dp[k + 1][j][1]);
                    ans1 %= mod;
                    long long ans2 = ((long long)dp[i][k - 1][1] * dp[k + 1][j][0]);
                    ans2 %= mod;
                    long long ans3 = ((long long)dp[i][k - 1][0] * dp[k + 1][j][0]);
                    ans3 %= mod;
                    long long ans4 = ((long long)dp[i][k - 1][1] * dp[k + 1][j][1]);
                    ans4 %= mod;
                    long long ans = 0LL, Ans = 0LL;
                    if(a[k] == '^') {
                        ans = ((long long)ans1 + ans2); ans %= mod;
                        Ans = ((long long)ans3 + ans4); Ans %= mod;
                    }
                    else if(a[k] == '|') {
                        ans = ((long long)ans1 + ans2 + ans3); ans %= mod;
                        Ans = (long long)ans4; Ans %= mod;
                    }
                    else {
                        ans = (long long)ans3; ans %= mod;
                        Ans = ((long long)ans4 + ans2 + ans1); Ans %= mod;
                    }
                    dp[i][j][0] += ans; dp[i][j][0] %= mod;
                    dp[i][j][1] += Ans; dp[i][j][1] %= mod;
                }
            }
        }
    }
    return dp[0][n - 1][0];
}
```

### [Best Time to Buy and Sell Stock III](https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/)

```cpp
int Solution::maxProfit(const vector<int> &a) {
    int n = a.size();
    if(n == 0) return 0;
    vector<int> buy(n, 0); vector<int> sell(n, 0);
    int mx = a[n - 1];
    int ans = 0;
    for(int i = n -2; i >= 0; i--) {
        buy[i] = max(0, mx - a[i]);
        ans = max(ans, buy[i]);
        mx = max(mx, a[i]);
    }
    int mn = a[0];
    for(int i = 1; i < n; i++) {
        sell[i] = max(0, a[i] - mn);
        ans = max(ans, sell[i]);
        mn = min(mn, a[i]);
    }
    vector<int> pref_sell(sell);
    for(int i = 1; i < n; i++) pref_sell[i] = max(pref_sell[i], pref_sell[i - 1]);
    for(int i = n - 1; i >= 1; i--) ans = max(ans, buy[i] + pref_sell[i - 1]);
    return ans;
}
```

### [Longest valid Parentheses (Star Marked)](https://www.interviewbit.com/problems/longest-valid-parentheses/)

```cpp
// Method 1 (O(N^2) solution Gives TLE)
int Solution::longestValidParentheses(string a) {
    int n = a.size();
    vector<int> dp(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        stack<int> st;
        int ans = 0;
        for(int j = i; j < n; j++) {
            if(a[j] == '(') st.push(j);
            else {
                if(st.empty()) {
                    ans = 0;
                    break;
                }
                int tp = st.top(); st.pop();
                ans += 2;
                if(tp == i) {
                    if(i + ans < n) ans += dp[i + ans];
                    break;
                }
            }
        }
        if(!st.empty()) ans = 0;
        dp[i] = ans;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    return ans;
}

// Method 2 (O(N) solution)
int Solution::longestValidParentheses(string a) {
    int n = a.size();
    vector<int> dp(n + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == ')') continue;
        else {
            if(i + 1 < n) {
                int nxt = dp[i + 1];
                int pos = i + nxt + 1;
                if(pos < n) {
                    if(a[pos] == ')') {
                        dp[i] = dp[i + 1] + 2;
                        if(i + dp[i] < n) dp[i] += dp[i + dp[i]];
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
    return ans;
}
```

### [Maximum Path in Triangle](https://www.interviewbit.com/problems/maximum-path-in-triangle/)

```cpp
int Solution::solve(vector<vector<int> > &a) {
    int n = a.size(); vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for(int i = n - 1; i >= 0; i--) dp[n - 1][i] = a[n - 1][i];
    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(a[i][j] != 0) {
                dp[i][j] = max(dp[i][j], a[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]));
            }
        }
    }
    return dp[0][0];
}
```

### [Maximum Size Square Sub-matrix (Star Marked)](https://www.interviewbit.com/problems/maximum-size-square-sub-matrix/)

```cpp
// Method 1 (using 2 DP one for sum and other of max size of sub-matrix)
// dp2[i][j] = maximum sub-matrix with [i, j] as rightmost and bottomost point
int Solution::solve(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = a[i - 1][j - 1];
            dp[i][j] += dp[i][j - 1];
            dp[i][j] += dp[i - 1][j];
            dp[i][j] -= dp[i - 1][j - 1];
        }
    }
    vector<vector<int>> dp2(n + 1, vector<int> (m + 1, 0)); int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
                int cnt = dp2[i - 1][j - 1];
                int x = i - cnt - 1, y = j - cnt - 1;
                int cur = dp[i][j] - dp[i][y] - dp[x][j] + dp[x][y];
                if(cur == (cnt + 1) * (cnt + 1)) {
                    dp2[i][j] = cnt + 1;
                    ans = max(ans, (cnt + 1)*(cnt + 1));
                }
                else if (a[i - 1][j - 1] == 1) dp2[i][j] = 1;
        }
    }
    return ans;
}

// Method 2 (using only 1 DP)
int Solution::solve(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0)); int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1][j - 1] == 1) {
                int mn = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                dp[i][j] = mn + 1;
                ans = max(ans, (mn + 1) * (mn + 1));
            }
        }
    }
    return ans;
}
```

### [Unique Paths in a Grid](https://www.interviewbit.com/problems/unique-paths-in-a-grid/)

```cpp
int Solution::uniquePathsWithObstacles(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size(); vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    if(a[n - 1][m - 1] == 0) dp[n - 1][m - 1] = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(a[i][j] == 0) {
                if(i == n - 1 && j == m - 1) continue;
                dp[i][j] += (dp[i + 1][j] + dp[i][j + 1]);
            }
        }
    }
    return dp[0][0];
}
```

### [Max Rectangle in Binary Matrix](https://www.interviewbit.com/problems/max-rectangle-in-binary-matrix/)

```cpp
vector<int> apply(vector<int> &a) {
    int n = a.size();
    stack<pair<int, int>> st;
    vector<int> ans(n, 0);
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top().first >= a[i]) st.pop();
        if(st.empty()) ans[i] = a[i] * (i + 1);
        else {
            auto it = st.top();
            int pos = it.second;
            ans[i] = a[i] * (i - pos);
        }
        st.push({a[i], i});
    }
    return ans;
}

int calc(vector<int> row) {
    int n = row.size();
    vector<int> ans1 = apply(row);
    reverse(row.begin(), row.end());
    vector<int> ans2 = apply(row);
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, ans1[i] + ans2[n - i - 1] - row[n - i - 1]);
    return ans;
}

int Solution::maximalRectangle(vector<vector<int> > &a) {
    int n = a.size(), m = a[0].size();
    vector<int> row(m, 0); int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 0) row[j] = 0;
            else row[j]++;
        }
        ans = max(ans, calc(row));
    }
    return ans;
}
```

### [Minimum Cost to Cut a Stick LeetCode (Star Marked)](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

```cpp
// the problem in interview bit asks to get the order of cut which can be easily
// by saving parent for all the ranges we iterate through during recursion in a 2D array
// later on we can write another recursive function to retrieve the actual order of cuts using the parent array
class Solution {
public:
    int recur(int x, int y, int mn, int mx, vector<int> &b, vector<vector<int>> &dp) {
        if(x == y) return dp[x][y] = mx - mn;
        if(x > y || x < 0 || y >= b.size()) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        int ans = 1e9;
        for(int i = x; i <= y; i++) {
            int ans1 = recur(x, i - 1, mn, b[i], b, dp);
            int ans2 = recur(i + 1, y, b[i], mx, b, dp);
            int cur_ans = ans1 + ans2 + mx - mn;
            ans = min(ans, cur_ans);
        }
        return dp[x][y] = ans;
    }

    int minCost(int N, vector<int>& b) {
        sort(b.begin(), b.end());
        int n = b.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return recur(0, n - 1, 0, N, b, dp);
    }
};
```

### [Sub Matrices with sum Zero (Star Marked)](https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/)

```cpp
int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    if(n == 0) return 0; int m = a[0].size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    // dp[i][j] = sum for matrix for [0, 0] to [i, j]
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            dp[i][j] = a[i - 1][j - 1];
            dp[i][j] += dp[i][j - 1];
            dp[i][j] += dp[i - 1][j];
            dp[i][j] -= dp[i - 1][j - 1];
        }
    }
    vector<int> dp2(m + 1, 0);
    unordered_map<int, int> mp; int ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            // solve for the sub matrices starting at the (i + 1)th row and
            // ending at the jth column
            for(int k = 1; k <= m; k++) dp2[k] = dp[j][k] - dp[i][k];
            mp.clear();
            for(int k = 1; k <= m; k++) {
                if(dp2[k] == 0) ans++;
                ans += mp[dp2[k]];
                mp[dp2[k]]++;
            }
        }
    }
    return ans;
}
```

### [Coin Sum Infinite (Star Marked)](https://www.interviewbit.com/problems/coin-sum-infinite/)

```cpp
// Method 1 (Using O(N * B) space and time)
# define mod 1000007

int Solution::coinchange2(vector<int> &a, int b) {
    int n = a.size(); sort(a.begin(), a.end());
    vector<vector<int>> dp(n + 1, vector<int> (b + 1, 0));
    // dp[i][j] = number of ways to get sum j using the first i numbers;
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int sum = 1; sum <= b; sum++) {
            dp[i][sum] = dp[i - 1][sum];
            dp[i][sum] %= mod;
            if(sum >= a[i - 1]) {
                dp[i][sum] += dp[i][sum - a[i - 1]];
                dp[i][sum] %= mod;
            }
        }
    }
    return dp[n][b];
}

// Method 2 (Using O(N) space and O(N * B) time)
# define mod 1000007

int Solution::coinchange2(vector<int> &a, int b) {
    int n = a.size(); sort(a.begin(), a.end());
    vector<int> dp(b + 1, 0);
    // dp[i][j] = number of ways to get sum j using the first i numbers;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int sum = 1; sum <= b; sum++) {
            dp[sum] = dp[sum];
            dp[sum] %= mod;
            if(sum >= a[i - 1]) {
                dp[sum] += dp[sum - a[i - 1]];
                dp[sum] %= mod;
            }
        }
    }
    return dp[b];
}
```

### [Max Product Subarray](https://www.interviewbit.com/problems/max-product-subarray/)

```cpp
int Solution::maxProduct(const vector<int> &a) {
    int n = a.size(), inf = -1e9;
    vector<array<int, 2>> dp(n + 1, {inf, inf});
    if(a[n - 1] > 0) dp[n - 1][0] = a[n - 1];
    else if(a[n - 1] < 0) dp[n - 1][1] = a[n - 1];
    int ans = *max_element(a.begin(), a.end());
    for(int i = n - 2; i >= 0; i--) {
        if(a[i] > 0) {
            if(dp[i + 1][0] != inf) dp[i][0] = a[i] * dp[i + 1][0];
            else dp[i][0] = a[i];
            if(dp[i + 1][1] != inf) dp[i][1] = a[i] * dp[i + 1][1];
        }
        else if(a[i] < 0) {
            if(dp[i + 1][1] != inf) dp[i][0] = a[i] * dp[i + 1][1];
            if(dp[i + 1][0] != inf) dp[i][1] = a[i] * dp[i + 1][0];
            else dp[i][1] = a[i];
        }
    }
    for(int i = 0; i < n; i++) ans = max(ans, dp[i][0]);
    return ans;
}
```

### [Arrange II](https://www.interviewbit.com/problems/arrange-ii/)

```cpp
vector<vector<vector<int>>> dp;

int recur(string &a, int k, int x, int y) {
    int N = a.size();
    if(x == N && k == 0) return 0;
    if(x == N && k != 0) return 1e9;
    if(dp[x][y][k] != -1) return dp[x][y][k];
    int n = y - x + 1;
    int mx = max(n, n - (k - 1)); int cost, b = 0, w = 0; int ans = 1e9;
    for(int i = x; i < (x + mx); i++) {
        if(a[i] == 'W') w++;
        else b++;
        if((k != 1) || (k == 1 && i == N - 1)) {
            cost = b * w;
            int ret = recur(a, k - 1, i + 1, y);
            ans = min(ans, cost + ret);
        }
    }
    return dp[x][y][k] = ans;
}

int Solution::arrange(string a, int b) {
    int n = a.size();
    dp = vector<vector<vector<int>>> (n + 1, vector<vector<int>> (n + 1, vector<int> (b + 1, -1)));
    int ret = recur(a, b, 0, n - 1);
    if(ret == 1e9) return -1;
    return ret;
}
```

### [Max Sum Without Adjacent Elements](https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/)

```cpp
int Solution::adjacent(vector<vector<int> > &a) {
    vector<int> dp; int n = a[0].size();
    for(int i = 0; i < n; i++) dp.push_back(max(a[0][i], a[1][i]));
    if(n == 1) return dp[0];
    for(int i = n - 1; i >= 0; i--) {
        int cur_ans = 0;
        if(i + 2 < n) cur_ans = dp[i + 2];
        if(i + 3 < n) cur_ans = max(cur_ans, dp[i + 3]);
        dp[i] += cur_ans;
    }
    int ans = max(dp[0], dp[1]);
    return ans;
}
```

### [Tushar's Birthday Party](https://www.interviewbit.com/problems/tushars-birthday-party/)

```cpp
int Solution::solve(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    int n = b.size();
    vector<vector<int>> dp(n + 1, vector<int> (1005, 1e9));
    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= n; j++) {
            if(b[j - 1] > i) dp[j][i] = dp[j - 1][i];
            else {
                dp[j][i] = min(dp[j][i], c[j - 1] + dp[j][i - b[j - 1]]);
                dp[j][i] = min(dp[j][i], dp[j - 1][i]);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < a.size(); i++) {
        ans += dp[n][a[i]];
    }
    return ans;
}
```

### [0-1 Knapsack](https://www.interviewbit.com/problems/0-1-knapsack/)

```cpp
int Solution::solve(vector<int> &a, vector<int> &b, int c) {
    int n = a.size(); vector<vector<int>> dp(n + 1, vector<int> (c + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= c; j++) {
            dp[i][j] = dp[i + 1][j];
            if(j >= b[i]) dp[i][j] = max(dp[i][j], a[i] + dp[i + 1][j - b[i]]);
        }
    }
    return dp[0][c];
}
```

### [Split Array With Same Average LeetCode (Star Marked)](https://leetcode.com/problems/split-array-with-same-average)

```cpp
// Useful link: https://leetcode.com/problems/split-array-with-same-average/discuss/524407/C%2B%2B-solution-O(N*Sum)-DPsumbitmask-with-explanation
// Method 1 (O(N * sum * N) time and O(N * sum) space gives TLE)
class Solution {
public:
    bool splitArraySameAverage(vector<int>& a) {
        int n = a.size(), sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
        vector<vector<int>> dp(n + 1, vector<int> (sum + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int sm = sum; sm >= 0; sm--) {
                for(int len = 1; len <= n; len++) {
                    if(sm >= a[i]) {
                        dp[len][sm] = (dp[len][sm] | dp[len - 1][sm - a[i]]);
                    }
                }
            }
        }
        for(int i = 1; i <= n - 1; i++) {
            if((sum * i) % n == 0) {
                int sm = (sum * i) / n;
                if(dp[i][sm]) return true;
            }
        }
        return false;
    }
};

// Method 2 (O(N * sum) time and O(sum) space dp with bitmask)
class Solution {
public:
    bool splitArraySameAverage(vector<int>& a) {
        int n = a.size(), sum = 0;
        for(int i = 0; i < n; i++) sum += a[i];
        vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int sm = sum; sm >= 0; sm--) {
                if(sm >= a[i]) dp[sm] |= (dp[sm - a[i]] << 1);
            }
        }
        for(int i = 1; i <= n - 1; i++) {
            if((sum * i) % n == 0) {
                int sm = (sum * i) / n;
                if(dp[sm] & (1 << i)) return true;
            }
        }
        return false;
    }
};
```

### [Equal Average Partition (Star Marked)](https://www.interviewbit.com/problems/equal-average-partition/)

```cpp
// O(N * SUM * N)
// Always remember if you are asked to find the actual partition then there is no other way but to backtrack
// and find solution
vector<vector<vector<int>>> dp;
vector<int> taken;

int partition(int ind, int sm, int len, vector<int> &temp, vector<vector<int>> &ans, vector<int> &a) {
    int n = a.size();
    if(dp[ind][sm][len] != -1) return dp[ind][sm][len];
    if(len == 0) {
        if(sm == 0) {
            ans.push_back(temp);
            return dp[ind][sm][len] = 1;
        }
        return dp[ind][sm][len] = 0;
    }
    if(ind == n) return dp[ind][sm][len] = 0;
    if(sm - a[ind] >= 0) {
        temp.push_back(a[ind]); taken[ind] = 1;
        if(partition(ind + 1, sm - a[ind], len - 1, temp, ans, a)) return dp[ind][sm][len] = 1;
        taken[ind] = 0; temp.pop_back();
    }
    if(partition(ind + 1, sm, len, temp, ans, a)) return dp[ind][sm][len] = 1;
    return dp[ind][sm][len] = 0;
}

vector<vector<int> > Solution::avgset(vector<int> &a) {
    int n = a.size(), sum = 0; sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) sum += a[i];
    dp = vector<vector<vector<int>>> (n + 1, vector<vector<int>> (sum + 1, vector<int> (n + 1, -1)));
    taken = vector<int> (n + 1, 0);
    for(int i = 1; i <= n - 1; i++) {
        if((sum * i) % n == 0) {
            int sm = (sum * i) / n;
            vector<int> temp; vector<vector<int>> ans;
            if(partition(0, sm, i, temp, ans, a)) {
                temp.clear();
                for(int j = 0; j < n; j++) {
                    if(!taken[j]) temp.push_back(a[j]);
                }
                ans.push_back(temp);
                if(ans[0].size() < ans[1].size()) return ans;
                else if(ans[0].size() > ans[1].size()) {
                    swap(ans[0], ans[1]);
                    return ans;
                }
                else {
                    for(int j = 0; j < ans[0].size(); j++) {
                        if(ans[0][j] < ans[1][j]) return ans;
                        else if(ans[0][j] > ans[1][j]) {
                            swap(ans[0], ans[1]);
                            return ans;
                        }
                    }
                    return ans;
                }
            }

        }
    }
    return {};
}
```

### [Best Time to Buy and Sell Stocks II](https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-ii/)

```cpp
int Solution::maxProfit(const vector<int> &a) {
    int n = a.size(); if(n == 0) return 0;
    int mn = a[0], mx = a[0]; int ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] < mx) {
            ans += (mx - mn);
            mn = a[i], mx = a[i];
        }
        mx = max(mx, a[i]);
    }
    ans += (mx - mn);
    return ans;
}
```

### [Word Break II](https://www.interviewbit.com/problems/word-break-ii/)

```cpp
unordered_map<int, vector<string>> dp;
unordered_map<string, int> mp;

vector<string> recur(int x, int y, string &a) {
    if(x == a.size()) return {""};
    string s; vector<string> ans;
    if(dp.find(x) != dp.end()) return dp[x];
    for(int i = x; i <= y; i++) {
        s.push_back(a[i]);
        if(mp.find(s) != mp.end()) {
            vector<string> ret = recur(i + 1, y, a);
            for(auto it : ret) {
                string ss;
                if(it != "") ss = s + " " + it;
                else ss = s;
                ans.push_back(ss);
            }
        }
    }
    dp[x] = ans;
    return ans;
}

vector<string> Solution::wordBreak(string a, vector<string> &b) {
    int n = a.size(); dp.clear(); mp.clear(); for(auto it : b) mp[it] = 1;
    return recur(0, n - 1, a);
}
```

### [Max Sum Path in Binary Tree](https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/)

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
pair<int, int> travel(TreeNode* a) {
    if(!a) return {0, 0};
    int ret1 = 0, ret2 = 0, ans = a->val, cur_ans = a->val;
    if(a->left) {
        pair<int, int> p = travel(a->left); ret1 = p.first;
        ans = max(ans, p.second);
        cur_ans = max(cur_ans, a->val + ret1);
    }
    if(a->right) {
        pair<int, int> p = travel(a->right); ret2 = p.first;
        ans = max(ans, p.second);
        cur_ans = max(cur_ans, a->val + ret2);
    }
    ans = max(max(cur_ans, ans), ret1 + ret2 + a->val);
    return make_pair(cur_ans, ans);
}

int Solution::maxPathSum(TreeNode* a) {
    auto it = travel(a);
    return it.second;
}
```

### [Unique Binary Search Trees II](https://www.interviewbit.com/problems/unique-binary-search-trees-ii/)

```cpp
vector<int> dp;

int generate(int n)
{
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];

    int ans = 0;


    for(int i = 1; i <= n; i++)
    {
        int l = generate(i - 1);
        int r = generate(n - i);
        ans += l * r;
    }

    return dp[n] = ans;
}

int Solution::numTrees(int A) {
    dp = vector<int> (A + 1, -1);
    return generate(A);
}
```

### [Palindrome Partitioning II](https://www.interviewbit.com/problems/palindrome-partitioning-ii/)

```cpp
// Method 1 (O(N^3) as we calculate dp for every i in the range [1, N] and then we have)
// transition of O(N) for every i, and it takes O(N) time to check whether a given string is
// palindrome or not. This soultion get Accepted in InterviewBit but gives TLE in leetcode
vector<int> dp;

int palindrome(string s) {
    string rs; rs.resize(s.size()); reverse_copy(s.begin(), s.end(), rs.begin());
    if(s == rs) return 1;
    return 0;
}

int recur(string &a, int i) {
    string s;
    int n = a.size(), ret, ans = 1e9;
    if(i == n) return -1;
    if(dp[i] != -1) return dp[i];
    for(int j = i; j < n; j++) {
        s.push_back(a[j]);
        if(palindrome(s)) {
            ret = recur(a, j + 1);
            ans = min(ans, 1 + ret);
        }
    }
    return dp[i] = ans;
}

int Solution::minCut(string a) {
    int n = a.size(); dp = vector<int> (n + 1, -1); return recur(a, 0);
}

// Method 2 (somehow this gets Accepted in Leetcode)
class Solution {
public:
    vector<int> dp;

    int palindrome(string &s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) return 0;
            i++; j--;
        }
        return 1;
    }

    int recur(string &a, int i) {
        string s;
        int n = a.size(), ret, ans = 1e9;
        if(i == n) return -1;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < n; j++) {
            s.push_back(a[j]);
            if(palindrome(s)) {
                ret = recur(a, j + 1);
                ans = min(ans, 1 + ret);
            }
        }
        return dp[i] = ans;
    }

    int minCut(string a) {
        int n = a.size(); dp = vector<int> (n + 1, -1); return recur(a, 0);
    }
};

// Method 3 (O(N^2) space and O(N^2) time)
class Solution {
public:
    vector<int> dp;
    vector<vector<int>> dp2;

    int recur(string &a, int i) {
        int n = a.size(), ret, ans = 1e9;
        if(i == n) return -1;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < n; j++) {
            if(dp2[i][j]) {
                ret = recur(a, j + 1);
                ans = min(ans, 1 + ret);
            }
        }
        return dp[i] = ans;
    }

    int minCut(string a) {
        int n = a.size(); dp = vector<int> (n + 1, -1);
        dp2 = vector<vector<int>> (n + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < n; i++) dp2[i][i] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(a[i] == a[j]) {
                    if(j - i == 1) dp2[i][j] = 2;
                    else dp2[i][j] = dp2[i][j] || dp2[i + 1][j - 1];
                }
            }
        }
        return recur(a, 0);
    }
};

// Method 4 (O(N) space and O(N^2) time)
class Solution {
public:
    // Let's try and solve in O(N) space
    int minCut(string a) {
        int n = a.size(); vector<int> dp(n + 1, 1e9); dp[n] = -1;
        for(int i = n - 1; i >= 0; i--) {
            // Let's assume this point i is the centre of the palindrom
            int j = i, k = i;
            while(j >= 0 && k < n && a[j] == a[k]) {
                j--; k++;
                dp[j + 1] = min(dp[j + 1], 1 + dp[k]);
            }
            // Now let's try if the centre is of length i.e palindrome is of even length
            if(i - 1 >= 0) {
                k = i; j = i - 1;
                while(j >= 0 && k < n && a[j] == a[k]) {
                    j--; k++;
                     dp[j + 1] = min(dp[j + 1], 1 + dp[k]);
                }
            }
        }
        return dp[0];
    }
};
```

### [Palindrome Partitioning III LeetCode (Star Marked)](https://leetcode.com/problems/palindrome-partitioning-iii/submissions/)

```cpp
// Method 1 (O(N * K * N * N) time and O(N * K) space)
class Solution {
public:
    int getAns(string &a, int i, int j) {
        int mov = 0;
        while(i < j) {
            if(a[i] != a[j]) mov++;
            i++; j--;
        }
        return mov;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 1e9));
        for(int i = n - 1; i >= 0; i--) {
            for(int cuts = 0; cuts <= k; cuts++) {
                int len = n - i + 1;
                if(cuts > len - 1) continue;
                for(int j = i; j < n; j++) {
                    int mov = getAns(s, i, j);
                    if(cuts == 0) {
                        if(j == n - 1) dp[i][cuts] = mov;
                        continue;
                    }
                    dp[i][cuts] = min(dp[i][cuts], mov + dp[j + 1][cuts - 1]);
                }
            }
        }
        return dp[0][k - 1];
    }
};

// Method 2 (O(N * K * N) time for dp and  O(N * N * N) time for dp2 and O(N * k) space of dp and  O(N * N) space for dp2)
// overall you would have O(N ^ 3) time and O(N ^ 2) space
class Solution {
public:
    int getAns(string &a, int i, int j) {
        int mov = 0;
        while(i < j) {
            if(a[i] != a[j]) mov++;
            i++; j--;
        }
        return mov;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 1e9));
        vector<vector<int>> dp2(n + 1, vector<int> (n + 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) dp2[i][j] = getAns(s, i, j);
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int cuts = 0; cuts <= k; cuts++) {
                int len = n - i + 1;
                if(cuts > len - 1) continue;
                for(int j = i; j < n; j++) {
                    int mov = dp2[i][j];
                    if(cuts == 0) {
                        if(j == n - 1) dp[i][cuts] = mov;
                        continue;
                    }
                    dp[i][cuts] = min(dp[i][cuts], mov + dp[j + 1][cuts - 1]);
                }
            }
        }
        return dp[0][k - 1];
    }
};

// Method 3 (O(N * K * N) time for dp and  O(N * N) time for dp2 and O(N * k) space of dp and  O(N * N) space for dp2)
// overall you would have O(N ^ 3) time and O(N ^ 2) space
class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 1e9));
        vector<vector<int>> dp2(n + 1, vector<int> (n + 1, 0));

        for(int i = 0; i < n; i++) dp2[i][i] = 0;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                if(j - i == 1) {
                    if(s[i] != s[j]) dp2[i][j] = 1;
                }
                else {
                    dp2[i][j] = dp2[i + 1][j - 1];
                    if(s[i] != s[j]) dp2[i][j]++;
                }
            }
        }

        for(int i = n - 1; i >= 0; i--) {
            for(int cuts = 0; cuts <= k; cuts++) {
                int len = n - i + 1;
                if(cuts > len - 1) continue;
                for(int j = i; j < n; j++) {
                    int mov = dp2[i][j];
                    if(cuts == 0) {
                        if(j == n - 1) dp[i][cuts] = mov;
                        continue;
                    }
                    dp[i][cuts] = min(dp[i][cuts], mov + dp[j + 1][cuts - 1]);
                }
            }
        }
        return dp[0][k - 1];
    }
};
```

### [Word Break](https://www.interviewbit.com/problems/word-break/)

```cpp
vector<int> dp;
unordered_map<string, int> mp;

int recur(int x, string &a) {
    int n = a.size();
    if(x == n) return 1;
    string s;
    if(dp[x] != -1) return dp[x];
    for(int i = x; i <= n - 1; i++) {
        s.push_back(a[i]);
        if(mp.find(s) != mp.end()) {
            int ret = recur(i + 1, a);
            if(ret) return dp[x] = 1;
        }
    }
    return dp[x] = 0;
}

int Solution::wordBreak(string a, vector<string> &b) {
    int n = a.size();
    dp = vector<int> (n + 1, -1);
    mp.clear(); for(auto it : b) mp[it] = 1;
    return recur(0, a);
}
```

### [Super Egg Drop LeetCode (Star Marked)](https://leetcode.com/problems/super-egg-drop/submissions/)

```cpp
// Method 1 (O(K * N * N) time and O(K * N) space)
class Solution {
public:
    vector<vector<int>> dp;

    int recur(int k, int n) {
        if(k == 1) return dp[k][n] = n;
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(dp[k][n] != -1) return dp[k][n];
        int ans = 1e9;
        for(int i = 1; i <= n; i++) {
            int val1 = recur(k - 1, i - 1);
            int val2 = recur(k, n - i);
            ans = min(ans,1 + max(val1, val2));
        }
        return dp[k][n] = ans;
    }

    int superEggDrop(int k, int n) {
        dp = vector<vector<int>> (k + 1, vector<int> (n + 1, -1));
        return recur(k, n);
    }
};

// Method 2 (O(K * N * logN) time and O(K * N) space)
class Solution {
public:
    vector<vector<int>> dp;

    int recur(int k, int n) {
        if(k == 1) return dp[k][n] = n;
        if(n <= 0) return 0;
        if(n == 1) return 1;
        if(dp[k][n] != -1) return dp[k][n];
        int ans = 1e9;
        int low = 1, high = n;
        while(high >= low) {
            int mid = (low + high)/2;
            int val1 = recur(k - 1, mid - 1);
            int val2 = recur(k, n - mid);
            ans = min(ans,1 + max(val1, val2));
            if(val1 < val2) low = mid + 1;
            else high = mid - 1;
            if(dp[k][n] == -1) dp[k][n] = ans;
            else dp[k][n] = min(dp[k][n], ans);
        }
        return dp[k][n];
    }

    int superEggDrop(int k, int n) {
        dp = vector<vector<int>> (k + 1, vector<int> (n + 1, -1));
        int ans = recur(k, n);
        return ans;
    }
};
```

### [Merge elements](https://www.interviewbit.com/problems/merge-elements/)

```cpp
int Solution::solve(vector<int> &a) {
    int n = a.size();
    // since maximum value of n is 200, we will use something on the lines
    // of matrix chain multiplication
    vector<vector<int>> dp(n + 1, vector<int> (n + 1, 1e9));
    vector<int> pref(n + 1, 0);  pref[0] = a[0];
    for(int i = 0; i < n; i++) dp[i][i] = 0;
    for(int i = 1; i < n; i++) pref[i] += (pref[i - 1] + a[i]);
    for(int len = 2; len <= n; len++) {
        for(int i = 0; i < n; i++) {
            int j = i + len - 1;
            if(j < n) {
                for(int k = i; k < j; k++) {
                    if(i > 0) {
                        int left = pref[k] - pref[i - 1], right = pref[j] - pref[k];
                        dp[i][j] = min(dp[i][j], dp[i][k] + (left + right) + dp[k + 1][j]);
                    }
                    else {
                        int left = pref[k], right = pref[j] - pref[k];
                        dp[i][j] = min(dp[i][j], dp[i][k] + (left + right) + dp[k + 1][j]);
                    }
                }
            }
        }
    }
    return dp[0][n - 1];
}
```

### [Subset Sum Problem!](https://www.interviewbit.com/problems/subset-sum-problem/)

```cpp
// Method 1 (O(N * W))
int Solution::solve(vector<int> &a, int b) {
    // same as 0 - 1 knapsack
    int n = a.size();
    if(n == 0) {
        if(b != 0) return 0;
        return 1;
    }
    vector<vector<int>> dp(n + 1, vector<int> (b + 1, 0));
    for(int i = 0; i <= n; i++) dp[i][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= b; j++) {
            if(a[i - 1] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] | dp[i - 1][j - a[i - 1]];
        }
    }
    return dp[n][b];
}

// Mehtode 2 (O((N * W) / 32))
#include<bitset>

int Solution::solve(vector<int> &a, int b) {
    bitset<100005> sums;
    sums[0] = 1;
    for(int x : a)
        sums |= (sums<<x);
    if(sums.test(b)) return 1;
    return 0;
}
```

## LeetCode Dynamic Programming Hard Problems

### [Stone Game II (Star Marked)](https://leetcode.com/problems/stone-game-ii/)

```cpp
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size(); vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        // dp[i][j] is the maximum number of stones Alex can get when starting at index i with M = j
        vector<int> suf(n + 1, 0); for(int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + piles[i];
        for(int m = 1; m <= n; m++) dp[n - 1][m] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            for(int m = 1; m <= n; m++) {
                for(int j = 1; j <= 2*m; j++) {
                    if(i + j > n) continue;
                    dp[i][m] = max(dp[i][m], suf[i] - dp[i + j][max(j, m)]);
                }
            }
        }
        return dp[0][1];
    }
};
```

### [Stone Game III](https://leetcode.com/problems/stone-game-iii/)

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> suf(n + 1, 0); for(int i = n - 1; i >= 0; i--) suf[i] = suf[i + 1] + stoneValue[i];
        vector<int> dp(n + 1, -1e9); dp[n - 1] = stoneValue[n - 1]; dp[n] = 0;
        // dp[i] = maximum number of stones you can get if you start at ith position
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 1; j <= 3; j++) {
                if(i + j > n) continue;
                dp[i] = max(dp[i], suf[i] - dp[i + j]);
            }
        }
        if(dp[0] > suf[0] - dp[0]) return "Alice";
        else if(dp[0] < suf[0] - dp[0]) return "Bob";
        return "Tie";
    }
};
```

### [Stone Game VIII (Star Marked)](https://leetcode.com/problems/stone-game-viii/)

```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        // dp[i] = the maximum score difference the current player can get when the game starts at i, i.e.
        // stones 0 ~ i are already merged as a new stone i whose value is prefix[i].
        int n = stones.size(); vector<int> dp(n + 1, 0);
        if(n == 1) return 0;
        vector<int> pref(n , 0); pref[0] = stones[0];
        for(int i = 1; i < n; i++) pref[i] = pref[i - 1] + stones[i];
        int mx = pref[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = mx;
            mx = max(mx, pref[i] - dp[i]);
        }
        return dp[0];
    }
};
```

### [Distinct Subsequences II (Star Marked)](https://leetcode.com/problems/distinct-subsequences-ii/)

```cpp
#define mod 1000000007

class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size(); vector<int> dp(n + 1, 0);
        // dp[i] = number of distinct subsequences in [0........s[i]]
        dp[0] = 1;
        vector<int> last(26, -1);
        for(int i = 1; i <= n; i++) {
            dp[i] = 2*dp[i - 1]; dp[i] %= mod;
            if(last[s[i - 1] - 'a'] != -1) {
                dp[i] = ((long long)dp[i] - dp[last[s[i - 1] - 'a'] - 1] + mod) % mod;
            }
            last[s[i - 1] - 'a'] = i;
        }
        return dp[n] - 1;
    }
};
```

### [Paint House III (Star Marked)](https://leetcode.com/problems/paint-house-iii/)

```cpp
// O(M * target * N) solution, made first AC using this but some part of this code
// is complicated and tought to think.
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (n + 1, vector<int> (target + 1, 1e9)));
        if(houses[0] != 0) dp[0][houses[0]][1] = 0;
        else {
            for(int i = 1; i <= n; i++) dp[0][i][1] = cost[0][i - 1];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j <= target; j++) {
                if(houses[i] != 0) {
                    if(houses[i - 1] != 0) {
                        if(houses[i] == houses[i - 1]) dp[i][houses[i]][j] = dp[i - 1][houses[i]][j];
                        else dp[i][houses[i]][j] = dp[i - 1][houses[i - 1]][j - 1];
                    }
                    else {
                        for(int k = 1; k <= n; k++) {
                            if(k != houses[i]) dp[i][houses[i]][j] = min(dp[i][houses[i]][j], dp[i - 1][k][j - 1]);
                            else dp[i][houses[i]][j] = min(dp[i][houses[i]][j], dp[i - 1][k][j]);
                        }
                    }
                }
                else {
                    if(houses[i - 1] != 0) {
                        for(int k = 1; k <= n; k++) {
                            if(k != houses[i - 1]) dp[i][k][j] = min(dp[i][k][j], dp[i - 1][houses[i - 1]][j - 1] + cost[i][k - 1]);
                            else dp[i][k][j] = min(dp[i][k][j], dp[i - 1][houses[i - 1]][j] + cost[i][k - 1]);
                        }
                    }
                    else {
                        int note = -1, mn = 1e9;
                        for(int k = 1; k <= n; k++) {
                            if(mn > dp[i - 1][k][j - 1]) {
                                mn = dp[i - 1][k][j - 1];
                                note = k;
                            }
                        }
                        for(int k = 1; k <= n; k++) {
                            dp[i][k][j] = min(dp[i][k][j], dp[i - 1][k][j] + cost[i][k - 1]);
                            if(k != note) dp[i][k][j] = min(dp[i][k][j], mn + cost[i][k - 1]);
                            else dp[i][k][j] = min(dp[i][k][j], dp[i - 1][note][j] + cost[i][k - 1]);
                        }
                        if(note != -1) {
                            for(int k = 1; k <= n; k++) {
                                if(k != note) dp[i][note][j] = min(dp[i][note][j], dp[i - 1][k][j - 1] + cost[i][note - 1]);
                            }
                        }
                    }
                }
            }
        }
        int ans = 1e9;
        for(int i = 1; i <= n; i++) ans = min(ans, dp[m - 1][i][target]);
        if(ans == 1e9) return -1;
        return ans;
    }
};

// O(M * target * N^2) solution this has worse complexity but it is easy to understand
class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>> (n + 1, vector<int> (target + 1, 1e9)));
        if(houses[0] != 0) dp[0][houses[0]][1] = 0;
        else {
            for(int i = 1; i <= n; i++) dp[0][i][1] = cost[0][i - 1];
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j <= target; j++) {
                if(houses[i] != 0) {
                    if(houses[i - 1] != 0) {
                        if(houses[i] == houses[i - 1]) dp[i][houses[i]][j] = dp[i - 1][houses[i]][j];
                        else dp[i][houses[i]][j] = dp[i - 1][houses[i - 1]][j - 1];
                    }
                    else {
                        for(int k = 1; k <= n; k++) {
                            if(k != houses[i]) dp[i][houses[i]][j] = min(dp[i][houses[i]][j], dp[i - 1][k][j - 1]);
                            else dp[i][houses[i]][j] = min(dp[i][houses[i]][j], dp[i - 1][k][j]);
                        }
                    }
                }
                else {
                    if(houses[i - 1] != 0) {
                        for(int k = 1; k <= n; k++) {
                            if(k != houses[i - 1]) dp[i][k][j] = min(dp[i][k][j], dp[i - 1][houses[i - 1]][j - 1] + cost[i][k - 1]);
                            else dp[i][k][j] = min(dp[i][k][j], dp[i - 1][houses[i - 1]][j] + cost[i][k - 1]);
                        }
                    }
                    else {
                        for(int k = 1; k <= n; k++) {
                            for(int l = 1; l <= n; l++) {
                                if(k != l) dp[i][k][j] = min(dp[i][k][j], dp[i - 1][l][j - 1] + cost[i][k - 1]);
                                else dp[i][k][j] = min(dp[i][k][j], dp[i - 1][l][j] + cost[i][k - 1]);
                            }
                        }
                    }
                }
            }
        }
        int ans = 1e9;
        for(int i = 1; i <= n; i++) ans = min(ans, dp[m - 1][i][target]);
        if(ans == 1e9) return -1;
        return ans;
    }
};
```
