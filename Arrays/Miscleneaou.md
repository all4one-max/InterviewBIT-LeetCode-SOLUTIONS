### [Minimum Lights to Activate](https://www.interviewbit.com/problems/minimum-lights-to-activate/)

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

int Solution::solve(vector<int> &a, int b) {
    int n=a.size();
    int zero=0;
    int i=0;
    while (i<n) {
        if (a[i]==0) zero++;
        else break;
        i++;
    }
    if (zero>(b-1) || (i==n && zero>0)) return -1;
    i=n-1;
    zero=0;
    while (i>=0) {
        if (a[i]==0) zero++;
        else break;
        i--;
    }
    if (zero>(b-1) || (i==-1 && zero>0)) return -1;
    zero=0;
    fo(i,n) {
        if (a[i]==0) zero++;
        else {
            if (zero>(2*b-2)) return -1;
            zero=0;
        }
    }
    /*now the tough part*/
    int ans=0;
    fo(i,n) {
        if (a[i]==1 || a[i]==0) {
            int found=0;
            for(int j=(n-1);j>=0;j--) {
                if (a[j]==1 && (j-b+1)<=i) {
                    for(int k=j;k>=max((j-b+1),0);k--) {
                        if (a[k]==0 || a[k]==1) a[k]+=2;
                    }
                    for(int k=j+1;k<=min(n-1,j+b-1);k++) {
                        if (a[k]==0 || a[k]==1) a[k]+=2;
                    }
                    ans++;
                    found=1;
                    break;
                }
            }
            if (found==0) {
                for(int j=i;j>=0;j--) {
                    if ((a[j]==3 || a[j]==1) && (j+b-1)>=i) {
                        for(int k=j;k>=max((j-b+1),0);k--) {
                            if (a[k]==0 || a[k]==1) a[k]+=2;
                        }
                        for(int k=j+1;k<=min(n-1,j+b-1);k++) {
                            if (a[k]==0 || a[k]==1) a[k]+=2;
                        }
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    return ans;
}
```

### [Maximum Sum Triplet](https://www.interviewbit.com/problems/maximum-sum-triplet/)

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

int Solution::solve(vector<int> &a) {
  int n=a.size();
  multiset<int> st(all(a));
  int mx = -1;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (mx == -1) {
      mx = max(mx, a[i]);
      st.erase(st.find(a[i]));
      continue;
    }
    if (mx > a[i]) {
      if (st.lower_bound(a[i]) != st.begin()) {
        int strt = *prev(st.lower_bound(a[i]));
        ans = max(ans, strt + a[i] + mx);
      }
    }
    mx = max(mx, a[i]);
    st.erase(st.find(a[i]));
  }
  return ans;
}
```

### [Maximum Area of Triangle!](https://www.interviewbit.com/problems/maximum-area-of-triangle/)

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

int area(int b,int h) {
    int val=b*h;
    int ret=val/2;
    if (val%2) ret++;
    return ret;
}

int Solution::solve(vector<string> &a) {
    int n=a.size();
    int m=a[0].size();
    int dp[m][3][2];
    int dp2[3][2];
    fo(i,m) {
        fo(j,3) {
            dp[i][j][0]=100000;
            dp[i][j][1]=-1;
            dp2[j][0]=100000;
            dp2[j][1]=-1;
        }
    }
    for(int j=0;j<m;j++) {
        for(int i=0;i<n;i++) {
            if (a[i][j]=='r') {
                dp[j][0][0]=min(dp[j][0][0],i);
                dp[j][0][1]=max(dp[j][0][1],i);
            }
            else if (a[i][j]=='g') {
                dp[j][1][0]=min(dp[j][1][0],i);
                dp[j][1][1]=max(dp[j][1][1],i);
            }
            else {
                dp[j][2][0]=min(dp[j][2][0],i);
                dp[j][2][1]=max(dp[j][2][1],i);
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if (a[i][j]=='r') {
                dp2[0][0]=min(dp2[0][0],j);
                dp2[0][1]=max(dp2[0][1],j);
            }
            else if (a[i][j]=='g') {
                dp2[1][0]=min(dp2[1][0],j);
                dp2[1][1]=max(dp2[1][1],j);
            }
            else {
                dp2[2][0]=min(dp2[2][0],j);
                dp2[2][1]=max(dp2[2][1],j);
            }
        }
    }
    int ans=0;
    for(int j=0;j<m;j++) {

            int base,height;
            // r g or g r
            base=0;height=0;
            if (dp[j][0][0]!=100000 && dp[j][1][1]!=-1) height=max(height,abs(dp[j][0][0]-dp[j][1][1]));
            if (dp[j][1][0]!=100000 && dp[j][0][1]!=-1) height=max(height,abs(dp[j][1][0]-dp[j][0][1]));
            if (dp2[2][0]!=100000) base=max(base,abs(j-dp2[2][0]));
            if (dp2[2][1]!=-1) base=max(base,abs(j-dp2[2][1]));
            if (base && height) ans=max(ans,area(base+1,height+1));
            // r b or b r
            base=0;height=0;
            if (dp[j][0][0]!=100000 && dp[j][2][1]!=-1) height=max(height,abs(dp[j][0][0]-dp[j][2][1]));
            if (dp[j][2][0]!=100000 && dp[j][0][1]!=-1) height=max(height,abs(dp[j][2][0]-dp[j][0][1]));
            if (dp2[1][0]!=100000) base=max(base,abs(j-dp2[1][0]));
            if (dp2[1][1]!=-1) base=max(base,abs(j-dp2[1][1]));
            if (base && height) ans=max(ans,area(base+1,height+1));
            // g b or b g
            base=0;height=0;
            if (dp[j][2][0]!=100000 && dp[j][1][1]!=-1) height=max(height,abs(dp[j][2][0]-dp[j][1][1]));
            if (dp[j][1][0]!=100000 && dp[j][2][1]!=-1) height=max(height,abs(dp[j][1][0]-dp[j][2][1]));
            if (dp2[0][0]!=100000) base=max(base,abs(j-dp2[0][0]));
            if (dp2[0][1]!=-1) base=max(base,abs(j-dp2[0][1]));
            if (base && height) ans=max(ans,area(base+1,height+1));

    }
    return ans;
}
```

### [Pick from both sides!](https://www.interviewbit.com/problems/pick-from-both-sides/)

```cpp
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define sz(v)          v.size()
#define pii            pair<int, int>

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int> pref(n,0);
    pref[0]=A[0];
    fo1(i,n) {
        pref[i]+=pref[i-1];
        pref[i]+=A[i];
    }
    int ans=pref[B-1];
    fo(i,B) {
        int bck=B-i;
        int cur_ans=0;
        if (i!=0) cur_ans+=pref[i-1];
        cur_ans+=pref[n-1];
        if ((n-bck-1)!=-1) cur_ans-=pref[n-bck-1];
        ans=max(ans,cur_ans);
    }
    return ans;
}
```

### [Max Min](https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/)

```cpp
int Solution::solve(vector<int> &a) {
    int mx=*max_element(a.begin(),a.end());
    int mn=*min_element(a.begin(),a.end());
    return mx+mn;
}
```
