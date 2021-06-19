## InterviewBit Problems

### [3 Sum](https://www.interviewbit.com/problems/3-sum/)

```cpp
int Solution::threeSumClosest(vector<int> &a, int b) {
    int n = a.size();
    sort(a.begin(),a.end());
    long long ans=(long long)a[0]+(long long)a[1]+(long long)a[2];
    for(int i=0;i<n-2;i++) {
        int l=i+1,r=n-1;
        while (r>l) {
            long long sum = (long long)a[i] + (long long)a[l] + (long long)a[r];
            if (abs(sum-(long long)b)<abs(ans-(long long)b)) {
                ans=sum;
            }
            if (sum>b) r--;
            else if (sum<b) l++;
            else break;
        }
        // cout<<ans<<"\n";
    }
    return (int)ans;
}
```

### [3 Sum Zero](https://www.interviewbit.com/problems/3-sum-zero/)

```cpp
vector<vector<int> > Solution::threeSum(vector<int> &a) {
    int n = a.size();
    sort(a.begin(),a.end());
    set<vector<int>> st;
    vector<vector<int>> ans;
    // for(auto it:a) cout<<it<<" ";cout<<"\n";
    for(int i=0;i<n-2;i++) {
        int l=i+1,r=n-1;
        if (a[i]<=0) {
            while (r>l) {
                long long sm = (long long)a[i] + (long long)a[l] + (long long)a[r];
                if (sm==0) {
                    st.insert({a[i],a[l],a[r]});
                    l++;r--;
                }
                if (sm>0LL) r--;
                if (sm<0LL) l++;
            }
        }
    }
    for(auto it:st) ans.push_back(it);
    return ans;
}
```

### [Diffk (Star Marked)](https://www.interviewbit.com/problems/diffk/)

```cpp
int Solution::diffPossible(vector<int> &a, int b) {
    int n = a.size();
    int i = 0,j=1;
    while (i<n && j<n) {
        if (i==j) j++;
        if (a[j]-a[i]==b) return 1;
        else if (a[j]-a[i]<b) j++;
        else i++;
    }
    return 0;
}
```

### [Merge Two Sorted Lists II (Star Marked)](https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/)

```cpp
void Solution::merge(vector<int> &A, vector<int> &B)
{

    // O(1) space
    // If all elements of B are placed in array
    // then elements of A are already in place

    int i = A.size() - 1; // i pointing to last index of A
    int j = B.size() - 1; // j pointing to last index of B

    int lastPos = A.size() + B.size() - 1; // lastPos pointing to last index of merged array A and B

    A.resize(A.size() + B.size());

    while(j >= 0)
    {
        if(i >= 0 and A[i] > B[j])
            A[lastPos--] = A[i--];
        else
            A[lastPos--] = B[j--];
    }

}
```

### [Intersection Of Sorted Arrays](https://www.interviewbit.com/problems/intersection-of-sorted-arrays/)

```cpp
vector<int> Solution::intersect(const vector<int> &a, const vector<int> &b) {
    int n = a.size(), m = b.size();
    vector<int> ans;
    int i = 0,j = 0;
    while (i<n && j<m) {
        if (a[i]<b[j]) i++;
        if (a[i]>b[j]) j++;
        if (a[i]==b[j]) {
            ans.push_back(a[i]);
            i++;j++;
        }
    }
    return ans;
}
```

### [Remove Duplicates from Sorted Array](https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array/)

```cpp
int Solution::removeDuplicates(vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = a.size(),nn=1;
    int i = 1,j=1,last=a[0];
    while (i<n) {
        if (a[i]>last) {
            last=a[i];
            swap(a[i],a[j]);
            nn+=1;
            j++;
        }
        i++;
    }
    return nn;
}
```

### [Remove Duplicates from Sorted Array II](https://www.interviewbit.com/problems/remove-duplicates-from-sorted-array-ii/)

```cpp
int Solution::removeDuplicates(vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = a.size();
    int i = 1,j = 1,last=a[0],cnt=1,nn=1;
    while (i<n) {
        if (a[i]>last) {
            last=a[i];
            swap(a[i],a[j]);
            cnt=1;
            nn+=1;
            j++;
        }
        else {
            cnt+=1;
            if (cnt==2) {
                swap(a[i],a[j]);
                nn+=1;
                j++;
            }
        }
        i++;
    }
    return nn;
}
```

### [Remove Element from Array (Star Marked)](https://www.interviewbit.com/problems/remove-element-from-array/)

```cpp
int Solution::removeElement(vector<int> &a, int b) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = a.size();
    int i,j = -1,nn=0;
    for(int i=0;i<n;i++) {
        if (a[i]==b) {
            j=i;
            break;
        }
        else nn+=1;
    }
    if (j==-1) return n;
    i=j+1;
    // a[j] will always be b
    while(i<n) {
        if (a[i]!=b) {
            swap(a[i],a[j]);
            nn+=1;
            j++;
        }
        i++;
    }
    return nn;
}
```

### [Sort by Color](https://www.interviewbit.com/problems/sort-by-color/)

```cpp
void Solution::sortColors(vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have aa doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = a.size();
    int k=0,i=0,j=n-1;
    while (k<n) {
        if (a[k]==0 && k>i) {
            swap(a[k],a[i]);
            i++;
            k--;
        }
        else if (a[k]==2 && j>k) {
            swap(a[k],a[j]);
            j--;
            k--;
        }
        k++;
    }
    return;

}
```

### [Max Continuous Series of 1s (Star Marked)](https://www.interviewbit.com/problems/max-continuous-series-of-1s/)

```cpp
vector<int> Solution::maxone(vector<int> &a, int m) {
    int n = a.size(),cnt0 = 0,i = 0,j = 0,start = 0,ans = 0;
    while(i<n && j<n) {
        if (a[j]==0) {
            if (cnt0==m) {
                for(int k=i;k<n;k++) {
                    if (a[k]==0) {
                        i=k+1;
                        break;
                    }
                }
            }
            else cnt0++;
        }
        int cur_ans=j-i+1;
        if (cur_ans>ans) {
            ans=cur_ans;
            start=i;
        }
        j++;
    }
    vector<int> v;
    int cnt=m;
    for(int i=start;i<n;i++) {
        if (a[i]==1) v.push_back(i);
        else {
            if (cnt) {
                v.push_back(i);
                cnt--;
            }
            else break;
        }
    }
    return v;
}
```

### [Array 3 Pointers (Star Marked)](https://www.interviewbit.com/problems/array-3-pointers/)

```cpp
int Solution::minimize(const vector<int> &a, const vector<int> &b, const vector<int> &c) {
    int i = 0, j = 0, k = 0;
    int n = a.size(), m = b.size(), l = c.size();
    int ans = 1e9;
    while (i<n && j<m && k<l) {
        int cur_ans = max({a[i],b[j],c[k]}) - min({a[i],b[j],c[k]});
        ans=min(ans,cur_ans);
        if (a[i]<=b[j] && a[i]<=c[k]) i++;
        else if (b[j]<=a[i] && b[j]<=c[k]) j++;
        else k++;
    }
    return ans;
}
```

### [Container With Most Water (Star Marked)](https://www.interviewbit.com/problems/container-with-most-water/)

```cpp
int Solution::maxArea(vector<int> &A) {
int i=0, j=A.size()-1, area=0, maxA=0;
while(i<j)
{
area=(j-i)*min(A[j],A[i]);
maxA=max(area,maxA);
if(A[i]<=A[j]) i++;
else j--;
}
return maxA;
}
```

### [Counting Subarrays!](https://www.interviewbit.com/problems/counting-subarrays/)

```cpp
int Solution::solve(vector<int> &a, int b) {
    int n = a.size();
    int i=0,j=0,sm=a[0],ans=0;
    while (j<n) {
        if (sm>=b) {
            if (i==j) {
                i++;
                j++;
                if (j==n) break;
                sm=a[j];
            }
            else {
                sm-=a[i];
                i++;
            }
        }
        else {
            ans+=(j-i+1);
            j++;
            if (j==n) break;
            sm+=a[j];
        }
    }
    return ans;
}
```

### [Subarrays with distinct integers! (Star Marked)](https://www.interviewbit.com/problems/subarrays-with-distinct-integers/)

```cpp
int cnt(vector<int> &a, int b) {
    int n  = a.size();
    if (b==0) return 0;
    int i = 0, j = 0,dis = 0,ans=0;
    map<int,int> mp;
    while (j<n) {
        if (mp[a[j]]==0) dis++;
        mp[a[j]]++;
        if (dis<=b) {
            ans+=(j-i+1);
        }
        else {
            for(int k=i;k<j;k++) {
                if (mp[a[k]]==1) dis--;
                mp[a[k]]--;
                if (dis<=b) {
                    i=k+1;
                    break;
                }
            }
            ans+=(j-i+1);
        }
        j++;
    }
    return ans;
}

int Solution::solve(vector<int> &a, int b) {
    int ans = (cnt(a,b)-cnt(a,b-1));
    return ans;
}
```

## LeetCode 2 Pointers Hard Problems

### [Count Unique Characters of All Substrings of a Given String](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/)

```cpp
// Method 1 (using O(N*26) space and O(N*26) time)
class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> store[26]; int n = s.size();
        for(int i = 0; i < n; i++) {
            store[s[i] - 'A'].push_back(i);
        }
        int ans = 0;
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < store[i].size(); j++) {
                int pos = store[i][j], prev = -1, next = n;
                if(j - 1 >= 0) prev = store[i][j - 1];
                if(j + 1 < store[i].size()) next = store[i][j + 1];
                ans += ((pos - prev) * (next - pos));
                ans %= 1000000007;
            }
        }
        return ans;
     }
};

// Method 2 (using O(N) space and O(N) time)
class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> last(26, -1); int n = s.size();
        vector<int> nxt(n, n); vector<int> prv(n, -1);
        for(int i = 0; i < n; i++) {
            prv[i] = last[s[i] - 'A'];
            if(last[s[i] - 'A'] != -1) nxt[last[s[i] - 'A']] = i;
            last[s[i] - 'A'] = i;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int pos = i, prev = prv[i], next = nxt[i];
            ans += ((pos - prev) * (next - pos));
            ans %= 1000000007;
        }
        return ans;
     }
};
```

### [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/submissions/)

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> store[100];
        unordered_map<int, int> ump;
        for(int i = 0; i < t.size(); i++) ump[t[i] - 'A']++; int len = 1e9, ind = -1;
        for(int i = 0; i < s.size(); i++) {
            store[s[i] - 'A'].push_back(i); int found = 1, mn = 1e9;
            for(auto it : ump) {
                int cnt = it.second;
                if(store[it.first].size() >= cnt) {
                    int pos = store[it.first][store[it.first].size() - cnt];
                    mn = min(mn, pos);
                }
                else {
                    found = 0;
                    break;
                }
            }
            if(found) {
                int cur_len = i - mn + 1;
                if(cur_len < len) {
                    len = cur_len;
                    ind = mn;
                }
            }
        }
        string ans = "";
        if(ind != -1) ans = s.substr(ind, len);
        return ans;
    }
};
```

### [Delivering Boxes from Storage to Ports (Star Marked)](https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/submissions/)

```cpp
// VERY VERY VERY HARD PROBLEM
// Method 1 (O(N^2) time and O(N) space) gives TLE
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size(); vector<int> dp(n + 1, 1e9); dp[n] = 0;
        for(int i = n - 1; i >= 0; i--) {
            int cur_box = 0, cur_weight = 0, trips = 0;
            for(int j = i; j < n; j++) {
                if(cur_box != maxBoxes) {
                    if(cur_weight + boxes[j][1] <= maxWeight) {
                        cur_box++;
                        cur_weight += boxes[j][1];
                        trips++;
                        if(trips != 1 && boxes[j][0] == boxes[j - 1][0]) trips--;
                        dp[i] = min(dp[i], trips + dp[j + 1] + 1);
                    }
                    else break;
                }
                else break;
            }
        }
        for(int i = 0; i <= n; i++) cout<<dp[i]<<" ";
        cout<<endl;
        return dp[0];
    }
};

// Method 2 (O(N * logN) time and O(N) space) gives AC
class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
        int n = boxes.size(); vector<int> dp(n + 1, 1e9); dp[n] = 0;
        vector<int> dp2(n + 1, 0); dp2[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            if(boxes[i][0] != boxes[i + 1][0]) dp2[i] = (1 + dp2[i + 1]);
            else dp2[i] = dp2[i + 1];
        }
        int l = n, r = n - 1; multiset<int> mst; int cur_box = 0, cur_weight = 0;

        for(int i = n - 1; i >= 0; i--) {
            l--;
            cur_box++; cur_weight += boxes[i][1];
            if(i != n - 1 && boxes[i][0] == boxes[i + 1][0]) mst.insert(dp[i + 1] - dp2[i + 1] + 1);
            else mst.insert(dp[i + 1] - dp2[i + 1]);
            if(cur_box > maxBoxes) {
                cur_weight -= boxes[r][1];
                if(r != n - 1 && boxes[r][0] == boxes[r + 1][0]) mst.erase(mst.find(dp[r + 1] - dp2[r + 1] + 1));
                else mst.erase(mst.find(dp[r + 1] - dp2[r + 1]));
                r--;
                cur_box--;
            }
            while(cur_weight > maxWeight) {
                cur_weight -= boxes[r][1];
                if(r != n - 1 && boxes[r][0] == boxes[r + 1][0]) mst.erase(mst.find(dp[r + 1] - dp2[r + 1] + 1));
                else mst.erase(mst.find(dp[r + 1] - dp2[r + 1]));
                r--;
                cur_box--;
            }
            int mn = *mst.begin();
            dp[i] = mn + dp2[i] + 1;
        }
        return dp[0];
    }
};
```

## LeetCode Sliding Window Hard Problems

### [Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/submissions/)

```cpp
// Method 1 (O(N^2) time) gives TLE
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(); int ans = 0, l = -1, r = -1, parity = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                if(i + k - 1 >= n) return -1;
                for(int j = i; j <= i + k - 1; j++) nums[j] = 1 - nums[j];
                ans++;
            }
        }
        return ans;
    }
};

// Method 2 (O(N * logN) time and O(N) space) gives AC
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(); int ans = 0; vector<int> right; int sz = 0;
        for(int i = 0; i < n; i++) {
            int parity;
            if(!sz) parity = 0;
            else {
                int pos = lower_bound(right.begin(), right.end(), i) - right.begin();
                if(pos == sz) parity = 0;
                else {
                    int cnt = sz - pos;
                    if(cnt % 2) parity = 1;
                    else parity = 0;
                }
            }
            if(parity % 2) nums[i] = 1 - nums[i];
            if(nums[i] == 0) {
                if(i + k - 1 >= n) return -1;
                ans++;
                sz++;
                right.push_back(i + k - 1);
            }
        }
        return ans;
    }
};
```