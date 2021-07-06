### [Number of 1 Bits](https://www.interviewbit.com/problems/number-of-1-bits/)

```cpp
int Solution::numSetBits(unsigned int a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count = 0;
    while (a) {
        if (a&1) count++;
        a=a>>1;
    }
    return count;
}
```

### [Reverse Bits (Star Marked)](https://www.interviewbit.com/problems/reverse-bits/)

```cpp
unsigned int Solution::reverse(unsigned int a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ans=0;
    for(int i=0;i<32;i++) {
        ans<<=1;
        if (a&1) ans|=1;
        a=a>>1;
    }
    return ans;
}
```

### [Divide Integers (Star Marked)](https://www.interviewbit.com/problems/divide-integers/)

```cpp
int Solution::divide(int x, int y) {
    long long a = (long long)x; long long b = (long long)y;
    if (a==INT_MIN && b==-1) return INT_MAX;
    int flag=1;
    if ((a<0 && b>0) || (a>0 && b<0)) flag=-1;
    a=abs(a);b=abs(b);
    int quotient=0;
    while ((a-b)>=0) {
        // take the maximum power of 2 in the quotient out
        int power=0;
        while ((a-(b<<power))>=0) {
            power++;
        }
        power--;
        a-=(b<<power);
        quotient+=(1<<power);
    }
    return flag*quotient;
}
```

### [Different Bits Sum Pairwise](https://www.interviewbit.com/problems/different-bits-sum-pairwise/)

```cpp
int Solution::cntBits(vector<int> &a) {
    long long n = a.size(), ans = 0;
    for(int j=0;j<32;j++) {
        int count=0;
        for(int i=0;i<n;i++) {
            if ((a[i]>>j)&1) count++;
        }
        ans+=((2*((count*(n-count))%1000000007))%1000000007);
        ans%=(1000000007);
    }
    return ans;
}
```

### [Min XOR value](https://www.interviewbit.com/problems/min-xor-value/)

```cpp
int Solution::findMinXor(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());
    int ans=a[0]^a[1];
    for(int i=0;i<n-1;i++) {
        ans=min(ans,a[i]^a[i+1]);
    }
    return ans;
}
```

### [Count Total Set Bits (Star Marked)](https://www.interviewbit.com/problems/count-total-set-bits/)

```cpp
int Solution::solve(int n) {
    n++;
    int ans = 0;
    int power_of_2 = 1;
    while (power_of_2<=n) {
        int num_pairs = (n/power_of_2);
        ans+=((num_pairs/2)*power_of_2);
        ans%=1000000007;
        ans+=(num_pairs&1) ? (n%power_of_2) : 0;
        ans%=1000000007;
        power_of_2*=2;
    }
    return ans;
}
```

### [Palindromic Binary Representation (Star Marked)](https://www.interviewbit.com/problems/palindromic-binary-representation/)

```cpp
int Solution::solve(int a) {
    vector<long long> ans={1,3,5,7};
    for(int i=3;i<32;i++) {
        long long base=1LL+(1LL<<i);
        vector<array<long long,2>> bit_pairs;
        for(long long bit=1;bit<=(i/2);bit++) {
            bit_pairs.push_back({bit,i-bit});
        }
        long long sz=bit_pairs.size();
        for(long long j=0;j<(1<<sz);j++) {
            long long num=base,cpy=j,ind=0;
            while (cpy) {
                if (cpy&1) {
                    num+=(1LL<<(bit_pairs[ind][0]));
                    if (bit_pairs[ind][0]!=bit_pairs[ind][1]) num+=(1LL<<(bit_pairs[ind][1]));
                }
                ind++;
                cpy=cpy>>1;
            }
            ans.push_back(num);
        }
    }
    sort(ans.begin(),ans.end());
    return ans[a-1];
}
```

### [Single Number](https://www.interviewbit.com/problems/single-number/)

```cpp
int Solution::singleNumber(const vector<int> &a) {
    int ans=a[0];
    for(int i=1;i<a.size();i++) ans^=a[i];
    return ans;
}
```

### [Single Number II](https://www.interviewbit.com/problems/single-number-ii/)

```cpp
int Solution::singleNumber(const vector<int> &a) {
    int ans = 0;
    for(int j=0;j<32;j++) {
        int cnt=0;
        for(int i=0;i<a.size();i++) {
            if ((a[i]>>j)&1) cnt++;
        }
        if (cnt%3) {
            ans+=(1<<j);
        }
    }
    return ans;
}
```

## LeetCode Bit Manipulation Hard Problems

### [Triples with Bitwise AND Equal To Zero (Star Marked)](https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/)

```cpp
class Solution {
public:
    int countTriplets(vector<int>& nums) {
        int n = nums.size(); unordered_map<int, int> ump;
        for(auto it : nums) {
            for(auto it2 : nums) ump[it & it2]++;
        } int ans = 0;
        for(auto it : nums) {
            for(auto it2 : ump) {
                if((it & it2.first) == 0) ans += it2.second;
            }
        }
        return ans;
    }
};
```

### [Minimum One Bit Operations to Make Integers Zero (Star Marked)](https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/)

```cpp
// it takes (1<<(i + 1)) - 1 operations to go from a number which has it's ith bit set
// to 0. i.e 1000 to 0000 will take (1<<4) - 1 = 15

// O(32) time and O(32) space, may be you can optimise the space complexity
class Solution {
public:
    int get1(int ind, vector<int> &bits) {
        if(bits[ind] == 0) {
            if(ind == 0) return 1;
            int ret = get1(ind - 1, bits);
            return (ret + (1<<ind));
        }
        else {
            if(ind == 0) return 0; int ans = 0;
            for(int i = ind - 1; i >= 0; i--) {
                if(bits[i]) {
                    if(i == 0) ans++;
                    else {
                        int ret = get1(i - 1, bits);
                        ans += (ret + (1<<i));
                    }
                    break;
                }
            }
            return ans;
        }
    }

    int minimumOneBitOperations(int n) {
        vector<int> bits(32, 0);
        for(int i = 0; i < 32; i++) {
            if(n & (1<<i)) bits[i] = 1;
        }
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            if(bits[i]) {
                if(i == 0) ans = 1;
                else {
                    int ret = get1(i - 1, bits);
                    ans += (ret + (1<<i));
                }
                break;
            }
        }
        return ans;
    }
};
```

### [Number of Squareful Arrays](https://leetcode.com/problems/number-of-squareful-arrays/)

```cpp
// O(N!)
class Solution {
public:
    void solve(unordered_map<int, int> &ump, int &ans, int cnt, int n, int last) {
        if(cnt == n) {
            ans++;
            return;
        }
        for(auto it : ump) {
            if(it.second > 0) {
                if(last != -1) {
                    int sq = sqrt(it.first + last);
                    if(sq * sq != (it.first + last)) continue;
                }
                ump[it.first]--;
                solve(ump, ans, cnt + 1, n, it.first);
                ump[it.first]++;
            }
        }
        return;
    }

    int numSquarefulPerms(vector<int>& nums) {
        unordered_map<int, int> ump; for(auto it : nums) ump[it]++; int n = nums.size();
        int ans = 0;
        solve(ump, ans, 0, n, -1);
        return ans;
    }
};
```

### [Count Pairs With XOR in a Range (Star Marked)](https://leetcode.com/problems/count-pairs-with-xor-in-a-range/)

```cpp
// used https://leetcode.com/problems/count-pairs-with-xor-in-a-range/discuss/1122495/C%2B%2B-with-picture for solving
// trie is often used to group numbers based on their bit prefixes.
struct trie_node {
    trie_node* left;
    trie_node* right;
    int cnt;
    trie_node() {
        left = NULL; right = NULL;
        cnt = 1;
    }
};

class Solution {
public:
    void insert(int num, trie_node* head) {
        for(int i = 14; i >= 0; i--) {
            int bit = (num>>i);
            if(bit & 1) {
                if(!head->right) head->right = new trie_node();
                else head->right->cnt++;
                head = head->right;
            }
            else {
                if(!head->left) head->left = new trie_node();
                else head->left->cnt++;
                head = head->left;
            }
        }
        return;
    }

    int lessk(trie_node* head, int k, int num) {
        int ans = 0;
        for(int i = 14; i >= 0; i--) {
            int bitnum = ((num>>i)&1); int bitk = ((k>>i)&1);
            if(!bitnum && !bitk) {
                if(!head->left) return ans;
                head = head->left;
            }
            else if(!bitnum && bitk) {
                if(head->left) ans += head->left->cnt;
                if(!head->right) return ans;
                head = head->right;
            }
            else if(bitnum && !bitk) {
                if(!head->right) return ans;
                head = head->right;
            }
            else {
                if(head->right) ans += head->right->cnt;
                if(!head->left) return ans;
                head = head->left;
            }
        }
        return ans;
    }

    int countPairs(vector<int>& nums, int low, int high) {
        trie_node* head = new trie_node(); int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int ret1 = lessk(head, low, nums[i]); int ret2 = lessk(head, high + 1, nums[i]);
            ans += (ret2 - ret1);
            insert(nums[i], head);
        }
        return ans;
    }
};
```

### [Maximum XOR With an Element From Array](https://leetcode.com/problems/maximum-xor-with-an-element-from-array/)

```cpp
struct trie_node {
    trie_node* left;
    trie_node* right;
    trie_node() {
        left = NULL; right = NULL;
    }
};

class Solution {
public:
    static bool comp(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[1];
    }

    void insert(int num, trie_node* head) {
        trie_node* cur = head;
        for(int i = 31; i >= 0; i--) {
            int bit = ((num>>i)&1);
            if(bit) {
                if(!cur->right) cur->right = new trie_node();
                cur = cur->right;
            }
            else {
                if(!cur->left) cur->left = new trie_node();
                cur = cur->left;
            }
        }
        return;
    }

    int max_xor_pair(int num, trie_node* head) {
        int ans = 0; trie_node* cur = head;
        for(int i = 31; i >= 0; i--) {
            int bit = ((num>>i)&1);
            if(bit) {
                if(cur->left) {
                    ans += (1<<i);
                    cur = cur->left;
                }
                else if(cur->right) cur = cur->right;
                else break;
            }
            else {
                if(cur->right) {
                    ans += (1<<i);
                    cur = cur->right;
                }
                else if(cur->left) cur = cur->left;
                else break;
            }
        }
        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < queries.size(); i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), comp); vector<int> ans(queries.size(), -1);
        int n = nums.size(); int j = 0; trie_node* head = new trie_node();
        for(int i = 0; i < queries.size(); i++) {
            while(j < n && nums[j] <= queries[i][1]) {
                insert(nums[j], head);
                j++;
            }
            if(j == 0) continue;
            int mx = max_xor_pair(queries[i][0], head);
            ans[queries[i][2]] = mx;
        }
        return ans;
    }
};
```

### [Make the XOR of All Segments Equal to Zero (Star Marked)](https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/)

```cpp
// Method 1 (O(K * 1024 * 1024) gives TLE)
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size(); vector<vector<int>> dp(n, vector<int> (1024, 1e9));
        unordered_map<int, int> ump[k];
        for(int i = 0; i < n; i++) ump[i%k][nums[i]]++;
        // dp[i][j] = minimum number of change in the array cylcle [0.....i] such that xor is j.
        for(int xr = 0; xr <= 1023; xr++) {
            int cnt = ((n - 1)/k) + 1;
            dp[0][xr] = min(dp[0][xr], cnt - ump[0][xr]);
        }
        for(int i = 1; i < k; i++) {
           for(int j = 0; j <= 1023; j++) {
               for(int x = 0; x <= 1023; x++) {
                   int cnt = ((n - 1 - i)/k) + 1; int get = cnt - ump[i][x];
                   dp[i][j] = min(dp[i][j], get + dp[i - 1][j ^ x]);
               }

           }
        }
        return dp[k - 1][0];
    }
};

// Method 2 (O(K * 1024 * (K/N)) gives AC)
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size(); vector<vector<int>> dp(n, vector<int> (1024, 1e9));
        unordered_map<int, int> ump[k];
        for(int i = 0; i < n; i++) ump[i%k][nums[i]]++;
        // dp[i][j] = minimum number of change in the array [0.....i] such that xor is j.
        int last_best = 1e9;
        for(int xr = 0; xr <= 1023; xr++) {
            int cnt = ((n - 1)/k) + 1;
            dp[0][xr] = min(dp[0][xr], cnt - ump[0][xr]);
            last_best = min(last_best, dp[0][xr]);
        }

        for(int i = 1; i < k; i++) {
            int cnt = ((n - 1 - i)/k) + 1; int cur_best = 1e9;
           for(int j = 0; j <= 1023; j++) {
               for(int x = i; x < n; x += k) {
                   int get = cnt - ump[i][nums[x]];
                   dp[i][j] = min(dp[i][j], get + dp[i - 1][j ^ nums[x]]);
               }
               dp[i][j] = min(dp[i][j], last_best + cnt);
               cur_best = min(cur_best, dp[i][j]);
           }
            last_best = cur_best;
        }
        return dp[k - 1][0];
    }
};
```

### [Minimum XOR Sum of Two Arrays](https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/)

```cpp
// variation of travelling salesman problem
// O(N * (2^N) * N) as there are N * (2^N) states and we have transition of N.
class Solution {
public:
    int tsp(int k, int mask, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp) {
        int n = nums1.size();
        if(k == n || (mask == ((1<<n) - 1))) return 0;
        if(dp[k][mask] != -1) return dp[k][mask];
        int ans = 2e9;
        for(int i = 0; i < n; i++) {
            if(((mask>>i)&1) == 0) {
                int cur_ans = (nums1[k]^nums2[i]) + tsp(k + 1, mask|(1<<i), nums1, nums2, dp);
                ans = min(ans, cur_ans);
            }
        }
        return dp[k][mask] = ans;
    }

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int> ((1<<15), -1));
        return tsp(0, 0, nums1, nums2, dp);
    }
};
```
