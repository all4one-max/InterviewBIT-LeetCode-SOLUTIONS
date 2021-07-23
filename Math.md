### [Prime Sum](https://www.interviewbit.com/problems/prime-sum/)

```cpp
bool prime(int x) {
    for(int i=2;i*i<=x;i++) {
        if (x%i==0) return false;
    }
    if (x==1) return false;
    return true;
}

vector<int> Solution::primesum(int a) {
    for(int i=2;i<(a/2+1);i++) {
        if (prime(i) && prime(a-i)) return {i,a-i};
    }
}
```

### [Sum of pairwise Hamming Distance](https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/)

```cpp
int Solution::hammingDistance(const vector<int> &a) {
    int n=a.size();
    vector<long long> dp(32,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<32;j++) {
            if (a[i]&(1<<j)) dp[j]++;
        }
    }
    long long ans=0,mod=1000000007;
    for(int i=0;i<32;i++) {
        ans+=(2*dp[i]*(n-dp[i]));
        ans%=mod;
    }
    return (int)ans;
}
```

### [FizzBuzz](https://www.interviewbit.com/problems/fizzbuzz/)

```cpp
vector<string> Solution::fizzBuzz(int a) {
    vector<string> arr(a,"0");
    for(int i=1;i<=a;i++) {
        string num=to_string(i);
        if (!(i%3) && !(i%5)) arr[i-1]="FizzBuzz";
        else if (!(i%3)) arr[i-1]="Fizz";
        else if (!(i%5)) arr[i-1]="Buzz";
        else arr[i-1]=num;
    }
    return arr;
}
```

### [Power Of Two Integers](https://www.interviewbit.com/problems/power-of-two-integers/)

```cpp
int Solution::isPower(int num) {
    if (num==1) return 1;
    for(int i=2;i*i<=num;i++) {
        int cpy=num;
        while (cpy%i==0) {
            cpy=cpy/i;
            if (cpy==1) return 1;
        }
    }
    return 0;
}
```

### [Excel Column Number](https://www.interviewbit.com/problems/excel-column-number/)

```cpp
int Solution::titleToNumber(string A) {
   int n=A.size();
   int ans=0;
   for(int i=0;i<n;i++) {
       ans+=(int(A[i])-64)*pow(26,n-i-1);
   }
   return ans;
}
```

### [Excel Column Title (Star Marked)](https://www.interviewbit.com/problems/excel-column-title/)

```cpp
string Solution::convertToTitle(int a) {
    string ans="";
    while (a) {
        int r = a%26;
        a=a/26;
        // consider the cases of AZ and ZZ
        if (r==0) a-=1;
        // cout<<r<<"\n";
        if (r==0) ans+='Z';
        else {
            r+=64;
            ans+=char(r);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
```

### [Palindrome Integer](https://www.interviewbit.com/problems/palindrome-integer/)

```cpp
int Solution::isPalindrome(int n) {
    int num=n;
    if (n<0) return false;
    int dig=0;
    while (n) {
        n/=10;
        dig++;
    }
    int right=1,left=pow(10,dig-1),iter=0;
    while (dig>0) {
        int left_dig=(num/left)%10;
        int right_dig=(num/right)%10;
        if (left_dig!=right_dig) return false;
        right*=10;left/=10;
        dig-=2;
        iter++;
    }
    return true;
}
```

### [Reverse integer (Star Marked)](https://www.interviewbit.com/problems/reverse-integer/)

```cpp
int Solution::reverse(int x) {
    // solution without using strings
    int rev = 0, sign = 1, digit;
    if (x < 0) {
        sign = -1;
        x *= -1;
    }
    while (x > 0) {
        digit = x%10;
        // check for overflow here
        if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && digit > (INT_MAX % 10))) {
            return 0;
        }
        rev = rev * 10 + digit;
        x/=10;
    }
    rev *= sign;
        return rev;
}
```

### [Greatest Common Divisor](https://www.interviewbit.com/problems/greatest-common-divisor/)

```cpp
int Solution::gcd(int a, int b) {
    if (b==0) return a;
    if (a%b==0) return b;
    if (a>b) return gcd(b,a%b);
    else return gcd(a,b%a);
}
```

### [Palindrome Integer](https://www.interviewbit.com/problems/palindrome-integer/)

```cpp
int Solution::isPalindrome(int n) {
    int num=n;
    if (n<0) return false;
    int dig=0;
    while (n) {
        n/=10;
        dig++;
    }
    int right=1,left=pow(10,dig-1),iter=0;
    while (dig>0) {
        int left_dig=(num/left)%10;
        int right_dig=(num/right)%10;
        if (left_dig!=right_dig) return false;
        right*=10;left/=10;
        dig-=2;
        iter++;
    }
    return true;
}
```

### [Trailing Zeros in Factorial](https://www.interviewbit.com/problems/trailing-zeros-in-factorial/)

```cpp
int Solution::trailingZeroes(int n) {
    int ans=0;
    for(int i=5;i<=n;i*=5) {
        ans+=n/i;
    }
    return ans;
}
```

### [Sorted Permutation Rank (Star Marked)](https://www.interviewbit.com/problems/sorted-permutation-rank/)

```cpp
int fct(int num,int mod) {
    int ans=1;
    while (num>0) {
        ans*=num;
        ans%=mod;
        num--;
    }
    return ans;
}

int get(vector<int> &avail,char c) {
    int val=(int)c,cnt=0;
    avail[val]=0;
    for(int i=0;i<val;i++) {
        if (avail[i]) cnt++;
    }
    return cnt;
}

int Solution::findRank(string a) {
    int n=a.size();
    int ans=1,mod=1000003;
    vector<int> avail(256,0);
    for(int i=0;i<n;i++) {
        avail[(int)a[i]]=1;
    }
    for(int i=0;i<n;i++) {
        int cnt=get(avail,a[i]);
        ans+=(cnt%mod)*fct(n-i-1,mod);
        ans%=mod;
    }
    return ans%mod;
}
```

### [Largest Coprime Divisor (Star Marked)](https://www.interviewbit.com/problems/largest-coprime-divisor/)

```cpp
int Solution::cpFact(int A, int B) {
    int x;
    while((__gcd(B,A)!=1))
    {
    x=__gcd(B,A);
    A=A/x;
    }
    return A;
}
```

### [Sorted Permutation Rank with Repeats (Star Marked)](https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/)

```cpp
#define ll long long int

ll fme(ll a, ll b,ll mod) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b = b >> 1;
  }
  return res % mod;
}

ll modinv(ll a,ll mod) {return fme(a, mod - 2, mod);}

ll get(vector<ll> &avail,char c,ll mod,ll num,vector<ll> &fact) {
    ll val=(ll)c, cnt=0;
    for(ll i=0;i<val;i++) {
        if (avail[i]) {
            avail[i]--;
            ll cur = fact[num];
            for(ll j=0;j<256;j++) {
                if (avail[j]) {
                    cur=cur*modinv(fact[avail[j]],mod);
                    cur%=mod;
                }
            }
            cnt+=cur;
            avail[i]++;
        }
    }
    avail[val]--;
    return cnt;
}

int Solution::findRank(string a) {
    ll n=a.size();
    ll fans=1,mod=1000003;
    vector<ll> fact(mod+5, 1);
    for (ll i = 1; i < (mod + 3); i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    vector<ll> avail(256,0);
    for(ll i=0;i<n;i++) {
        avail[(ll)a[i]]++;
    }
    for(ll i=0;i<n;i++) {
        ll cnt=get(avail,a[i],mod,n-i-1,fact);
        fans+=cnt;
        fans%=mod;
    }
    return fans%mod;
}
```

### [Rearrange Array (Star Marked)](https://www.interviewbit.com/problems/rearrange-array/)

```cpp
void Solution::arrange(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    for(int i=0;i<n;i++) {
        A[i]+=((A[A[i]]%n)*n);
    }
    for(int i=0;i<n;i++) {
        A[i]/=n;
    }
    return;
}
```

### [Grid Unique Paths (Star Marked)](https://www.interviewbit.com/problems/grid-unique-paths/)

```cpp
int Solution::uniquePaths(int m, int n) {
    // (m+n-2) C (n-1) = (m+n-2)! / (m-1)! * (n-1)!
    int ans=1;
    for (int i = n; i < (m + n - 1); i++) {
        ans *= i;
        ans /= (i - n + 1);
    }
    return ans;
}
```
