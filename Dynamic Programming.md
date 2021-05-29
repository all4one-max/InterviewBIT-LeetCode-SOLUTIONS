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

### [Jump Game Array](https://www.interviewbit.com/problems/jump-game-array/)

```cpp
// Method 1 (DP giver MLE)
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

### [Ways to color a 3xN Board (Star Makred)](https://www.interviewbit.com/problems/ways-to-color-a-3xn-board/)

```cpp
// Method 1 (Using DP O(n * 36 * 36) Time and O(n * 4 * 4 * 4) space)
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
    // v.size() = 36
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
