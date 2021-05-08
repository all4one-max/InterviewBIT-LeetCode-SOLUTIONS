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

### [Add One To Number](https://www.interviewbit.com/problems/add-one-to-number/)

```cpp
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define sz(v)          v.size()
#define pii            pair<int, int>

vector<int> Solution::plusOne(vector<int> &a) {
    int n=a.size();
    int cnt=0,i=0;
    while (i<n) {
        if (a[i]==0) cnt++;
        else break;
        i++;
    }
    vector<int> ans;
    if (cnt==n) {ans.pb(1);return ans;}
    if (a[n-1]!=9) {
        for(int i=cnt;i<(n-1);i++) {
            ans.pb(a[i]);
        }
        ans.pb(a[n-1]+1);
    }
    else {
        int carry=1;
        ans.pb(0);
        if (n==1) {ans.pb(1);reverse(ans.begin(),ans.end());return ans;}
        for(int i=n-2;i>=cnt;i--) {
            if (a[i]==9 && carry==1) {
                ans.pb(0);
                carry=1;
                if (i==cnt) {
                    ans.pb(1);
                    break;
                }
            }
            else if (a[i]!=9 && carry==1) {
                 ans.pb(a[i]+1);
                 carry=0;
            }
            else ans.pb(a[i]);
        }
        reverse(ans.begin(),ans.end());
    }
    return ans;
}
```

### [Maximum Absolute Difference](https://www.interviewbit.com/problems/maximum-absolute-difference/)

```cpp
int Solution::maxArr(vector<int> &A) {
    int max_1 = INT_MIN;
    int max_2 = INT_MIN;
    int min_1 = INT_MAX;
    int min_2 = INT_MAX;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]+i>max_1) max_1 = A[i]+i ;
        if (A[i]+i<min_1) min_1 = A[i]+i ;
        if(A[i]-i>max_2) max_2 = A[i]-i ;
        if (A[i]-i<min_2) min_2 = A[i]-i ;
    }
    return max((max_1-min_1),(max_2-min_2));
}
```

### [Partitions](https://www.interviewbit.com/problems/partitions/)

```cpp
int Solution::solve(int n, vector<int> &b) {
    vector<int> pref(n,0);
    pref[0]=b[0];
    map<int,int> mpp;
    mpp[pref[0]]++;
    for(int i=1;i<n;i++) {
        pref[i]+=pref[i-1];
        pref[i]+=b[i];
        mpp[pref[i]]++;
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        int sm=pref[i];
        // x 2*x 3*x
        mpp[sm]--;
        if (pref[n-1]==3*sm) {
            if (sm==0 && mpp[sm]-1>=1) ans+=(mpp[sm]-1);
            else if (sm!=0 && mpp[2*sm]) ans+=mpp[2*sm];
        }
    }
    return ans;
}
```

### [Flip](https://www.interviewbit.com/problems/flip/)

```cpp
vector<int> Solution::flip(string a) {
    int n=a.size();

    vector<int> ans;
    int tot_cnt=0;
    for(int i=0;i<n;i++) {
        if (a[i]=='1') tot_cnt++;
    }
    int zero=0,one=0,mx=tot_cnt,note=1;
    for(int i=0;i<n;i++) {
        int cnt=tot_cnt;
        if (a[i]=='1') one++;
        else zero++;
        if (zero<one) {
            zero=0;one=0;
            note=(i+2);
        }
        cnt+=(zero-one);
        if (cnt>mx) {
            ans.clear();
            ans.push_back(note);
            ans.push_back(i+1);
            mx=cnt;
        }
    }
    // cout<<mx;
    return ans;
}
```
