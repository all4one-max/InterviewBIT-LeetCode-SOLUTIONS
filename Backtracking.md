### [Subset (Star Marked)](https://www.interviewbit.com/problems/subset/)

```cpp
// Method 1 (using Power Set)
bool comp(vector<int> v1,vector<int> v2) {
    int n1 = v1.size(), n2 = v2.size();
    for(int i = 0;i<min(n1,n2);i++) {
        if(v1[i]>v2[i]) return false;
        if(v2[i]>v1[i]) return true;
    }
    if(n2>n1) return true;
    return false;
}

vector<vector<int> > Solution::subsets(vector<int> &a) {
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    int n = a.size();
    for(int i = 0; i < (1 << n); i++) {
        vector<int> arr;
        for(int j = 0;j < n;j++) {
            if(i&(1<<j)) {
                arr.push_back(a[j]);
            }
        }
        ans.push_back(arr);
    }
    sort(ans.begin(), ans.end(), comp);
    return ans;
}

// Method 2 (using Backtracking)
bool comp(vector<int> v1,vector<int> v2) {
    int n1 = v1.size(), n2 = v2.size();
    for(int i = 0;i < min(n1,n2); i++) {
        if(v1[i] > v2[i]) return false;
        if(v2[i] > v1[i]) return true;
    }
    if(n2 > n1) return true;
    return false;
}

void solve(vector<int> &a, int i, int n, vector<vector<int>> &ans) {
    if(i == (n-1)) {
        ans.insert(ans.begin(), {a[i]});
        return;
    }

    solve(a, i + 1, n, ans);

    int sz = ans.size();
    for(int j = 0;j < sz; j++) {
        vector<int> cpy(ans[j]);
        cpy.push_back(a[i]);
        sort(cpy.begin(), cpy.end());
        ans.push_back(cpy);
    }
    ans.insert(ans.begin(), {a[i]});
    return;
}

vector<vector<int> > Solution::subsets(vector<int> &a) {
    if(a.size() == 0) return {{}};
    vector<vector<int>> ans;
    solve(a, 0, a.size(), ans);
    vector<int> c = {};
    ans.insert(ans.begin(), c);
    sort(ans.begin(),ans.end(),comp);
    return ans;
}

// Method 3 (using Not So intuitive Backtracking)
void solve(vector<int> &a,int i, int n, vector<vector<int>> &ans, vector<int> &temp) {
    ans.push_back(temp);

    for(int j = i;j < n;j++) {
        temp.push_back(a[j]);
        solve(a, j + 1, n, ans, temp);
        temp.pop_back();
    }

    return;
}

vector<vector<int> > Solution::subsets(vector<int> &a) {
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(a, 0, a.size(), ans, temp);
    return ans;
}
```

### [Combination Sum](https://www.interviewbit.com/problems/combination-sum/)

```cpp
void solve(vector<int> &a, int i, int n, vector<vector<int>> &ans, vector<int> &temp, int sm, int b) {
   if (sm == b) ans.push_back(temp);

   for(int j = i;j < n; j++) {
       if (sm + a[j] <= b) {
           temp.push_back(a[j]);
           solve(a, j, n, ans, temp, sm + a[j], b);
           temp.pop_back();
       }
   }
   return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &a, int b) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int n = a.size();
    vector<vector<int>> ans;
    vector<int> temp;
    solve(a, 0, n, ans, temp, 0, b);
    return ans;
}
```

### [Combination Sum II (Star Marked)](https://www.interviewbit.com/problems/combination-sum-ii/)

```cpp
// Method 1 (appending answer in set<vector<int>>)
void solve(vector<int> &a, int i, int n, set<vector<int>> &ans, vector<int> &temp, int sm, int b) {
   if (sm == b) ans.insert(temp);

   for(int j = i;j < n; j++) {
        if(sm<=b) {
            temp.push_back(a[j]);
            solve(a, j + 1, n, ans, temp, sm + a[j], b);
            temp.pop_back();
        }
   }
   return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &a, int b) {
    sort(a.begin(), a.end());
    int n = a.size();
    set<vector<int>> ans;
    vector<int> temp;
    solve(a, 0, n, ans, temp, 0, b);
    vector<vector<int>> ret;
    for(auto it : ans) ret.push_back(it);
    return ret;
}

// Method 2 (using backtracking with counters)
#define fi             first
#define se             second

void solve(vector<int> &a, vector<vector<int>> &ans, vector<int> &temp, int sm, int b, map<int, int> freq, int last) {
   if (sm == b) ans.push_back(temp);

   for(auto it : freq) {
       if(it.fi >= last) {
           if(it.se > 0) {
               if(sm + it.fi<=b) {
                   temp.push_back(it.fi);
                   freq[it.fi]--;
                   solve(a, ans, temp, sm + it.fi, b, freq, it.fi);
                   temp.pop_back();
                   freq[it.fi]++;
               }
           }
       }
   }
   return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &a, int b) {
    // sort(a.begin(), a.end());
    // Since map stores numbers in sorted order therefore we don't need to sort the array
    int n = a.size();
    vector<vector<int>> ans;
    map<int,int> freq;
    for(auto it : a) freq[it]++;
    vector<int> temp;
    solve(a, ans, temp, 0, b, freq, -1);
    return ans;
}

// Method 3 (using backtracking with index)
void solve(vector<int> &a, int i, int n, vector<vector<int>> &ans, vector<int> &temp, int sm, int b) {
   if (sm == b) ans.push_back(temp);

   int j = i;
    while(j<n) {
        if(sm + a[j]<=b) {
            temp.push_back(a[j]);
            solve(a, j + 1, n, ans, temp, sm + a[j], b);
            int k = j;
            while(k<n && a[k]==a[j]) k++;
            j = k;
            temp.pop_back();
        }
        else j++;
   }
   return;
}

vector<vector<int> > Solution::combinationSum(vector<int> &a, int b) {
    sort(a.begin(), a.end());
    int n = a.size();
    vector<vector<int>> ans;
    vector<int> temp;
    solve(a, 0, n, ans, temp, 0, b);
    return ans;
}
```

### [Combinations](https://www.interviewbit.com/problems/combinations/)

```cpp
void solve(vector<int> &v, int n, int i, vector<vector<int>> &ans, vector<int> &temp, int k) {
    if(k == 0) ans.push_back(temp);

    for(int j = i; j < n; j++) {
        temp.push_back(v[j]);
        solve(v, n, j + 1, ans, temp, k - 1);
        temp.pop_back();
    }

    return;
}

vector<vector<int> > Solution::combine(int a, int b) {
    vector<int> v;
    for(int  i = 1;i <=a; i++) v.push_back(i);

    vector<vector<int>> ans;
    vector<int> temp;

    solve(v, a, 0, ans, temp, b);

    return ans;
}
```

### [Subsets II](https://www.interviewbit.com/problems/subsets-ii/)

```cpp
#define fi             first
#define se             second

void solve(map<int,int> &freq, int n, int last, vector<vector<int>> &ans, vector<int> &temp) {
    ans.push_back(temp);

    for(auto it : freq) {
        if(it.fi >= last && it.se > 0) {
            temp.push_back(it.fi);
            freq[it.fi]--;
            solve(freq, n, it.fi, ans, temp);
            temp.pop_back();
            freq[it.fi]++;
        }
    }
    return;
}

vector<vector<int> > Solution::subsetsWithDup(vector<int> &a) {
    map<int,int> freq;
    for(auto it : a) freq[it]++;
    int n = a.size();

    vector<vector<int>> ans;
    vector<int> temp;
    solve(freq, n, -1, ans, temp);
    return ans;
}
```

### [Letter Phone](https://www.interviewbit.com/problems/letter-phone/)

```cpp
void solve(string a, map<int, string> &mp, int i, int n, vector<string> &ans, string temp) {
    if(i == n) {
        ans.push_back(temp);
        return;
    }

    for(auto it : mp[a[i] - '0']) {
        string cpy = temp + it;
        solve(a, mp, i + 1, n, ans, cpy);
    }
    return;
}

vector<string> Solution::letterCombinations(string a) {
    int n = a.size();
    map<int, string> mp = {{0, "0"}, {1, "1"}, {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"},
        { 6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
    };
    vector<string> ans;
    string temp = "";
    solve(a, mp, 0, n, ans, temp);
    return ans;
}
```

### [Palindrome Partitioning](https://www.interviewbit.com/problems/palindrome-partitioning/)

```cpp
int isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(s[i] != s[j]) return 0;
        i++; j--;
    }
    return 1;
}

void solve(string a, int i, int n, vector<vector<string>> &ans, vector<string> &temp) {
    if(i == n) ans.push_back(temp);

    string s = "";

    for(int j = i; j < n; j++) {
        s+=a[j];
        if(isPalindrome(s)) {
            temp.push_back(s);
            solve(a, j + 1, n, ans, temp);
            temp.pop_back();
        }
    }
    return;
}

vector<vector<string> > Solution::partition(string a) {
    int n = a.size();
    vector<vector<string>> ans;
    vector<string> temp;
    solve(a, 0, n, ans, temp);
    return ans;
}
```

### [Generate all Parentheses II](https://www.interviewbit.com/problems/generate-all-parentheses-ii/)

```cpp
void solve(int n, vector<string> &ans, string temp, int left, int right) {
    if(left + right == 2*n) {
        ans.push_back(temp);
        return;
    }

    if (left < n) {
        temp.push_back('(');
        solve(n, ans, temp, left + 1, right);
        temp.pop_back();
    }
    if (right < left) {
        temp.push_back(')');
        solve(n, ans, temp, left, right + 1);
        temp.pop_back();
    }
    return;
}

vector<string> Solution::generateParenthesis(int n) {
    string temp = "";
    vector<string> ans;
    solve(n, ans, temp, 0, 0);
    return ans;
}
```
