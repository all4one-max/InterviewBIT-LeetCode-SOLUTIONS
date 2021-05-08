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