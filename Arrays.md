### [Min Steps in Infinite Grid](https://www.interviewbit.com/problems/min-steps-in-infinite-grid/)

```cpp
class Solution:
    # @param A : list of integers
    # @param B : list of integers
    # @return an integer
    def coverPoints(self, a, b):
        x,y=a[0],b[0]
        n=len(a)
        ans=0
        for i in range(1,n):
            gx,gy=a[i],b[i]
            mx,mn=max(abs(gx-x),abs(gy-y)),min(abs(gx-x),abs(gy-y))
            ans+=mx
            x,y=gx,gy
        return ans
```

### [Max Sum Contiguous Subarray](https://www.interviewbit.com/problems/max-sum-contiguous-subarray/)

```cpp
// kadance's Algo
int Solution::maxSubArray(const vector<int> &a) {
    int n=a.size();
    int mx_sm_including=0;
    int mx_sm=*max_element(a.begin(),a.end());
       for(int i=0;i<n;i++) {
        mx_sm_including += a[i];
        if (mx_sm_including > mx_sm) mx_sm = mx_sm_including;
        if (mx_sm_including < 0) {
          mx_sm_including = 0;
        }
      }
    return mx_sm;

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

### [Maximum Absolute Difference (star Marked)](https://www.interviewbit.com/problems/maximum-absolute-difference/)

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

### [Flip (star Marked)](https://www.interviewbit.com/problems/flip/)

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

### [Triplets with Sum between given range (star Marked)](https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/)

```cpp
public class Solution {
public int solve(ArrayList<String> A) {
    List<Double> queue = new ArrayList<>();
    double sum = 0;
    for (String s : A) {
        double val = Double.parseDouble(s);
        if (queue.size()<3) {
            queue.add(val);
            sum += Double.parseDouble(s);
        }else if (queue.size()==3&&sum>=2&&queue.get(2)>val){
            sum -= queue.get(2);
            sum += val;
            queue.remove(2);
            queue.add(val);
        }else if (queue.size()==3&&sum<1&&val>queue.get(0)){
            sum -= queue.get(0);
            sum += val;
            queue.remove(0);
            queue.add(val);
        }
        Collections.sort(queue);
        if (queue.size()==3&&sum>1&&sum<2)
            return 1;
    }
    if (queue.size()==3&&sum>1&&sum<2)
        return 1;

    return 0;
}
}
```

### [Find Duplicate in Array (star Marked)](https://www.interviewbit.com/problems/find-duplicate-in-array/)

```cpp
// Tortois method
int Solution::repeatedNumber(const vector<int> &a) {
    int slow = a[0];
    int fast = a[0];
    while (true) {
        slow=a[slow];
        fast=a[a[fast]];
        if (slow==fast) break;
    }
    slow=a[0];
    while (slow!=fast) {
        slow=a[slow];
        fast=a[fast];
    }
    return slow;
}
```

### [Maximum Consecutive Gap (star Marked)](https://www.interviewbit.com/problems/maximum-consecutive-gap/)

```cpp
int Solution::maximumGap(const vector<int> &a) {
    int n=a.size();
    int mx=*max_element(a.begin(),a.end());
    int mn=*min_element(a.begin(),a.end());
    float gap=((mx-mn)/(float)(n-1));
    if (n<2 || gap==0) return 0;
    int INF=1000000000;
    vector<array<int,2>> dp(n,{INF,-1});
    for(int i=0;i<n;i++) {
        int pos=((a[i]-mn)/gap);
        dp[pos][1]=max(dp[pos][1],a[i]);
        dp[pos][0]=min(dp[pos][0],a[i]);
    }
    int ans=-1;
    for(int i=0;i<n;i++) {
        if (dp[i][1]!=-1 && dp[i][0]!=INF) ans=max(ans,dp[i][1]-dp[i][0]);
        if (i!=0) {
            if (dp[i][0]!=INF && dp[i-1][1]!=-1) ans=max(ans,dp[i][0]-dp[i-1][1]);

        }
        if (dp[i][1]==-1 && dp[i][0]==INF) dp[i][1]=dp[i-1][1];dp[i][0]=dp[i-1][0];
    }
    return ans;

}
```

### [Wave Array](https://www.interviewbit.com/problems/wave-array/)

```cpp
vector<int> Solution::wave(vector<int> &a) {
    int n=a.size();
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;i+=2) {
        swap(a[i],a[i+1]);
    }
    return a;
}
```

### [Hotel Bookings Possible](https://www.interviewbit.com/problems/hotel-bookings-possible/)

```cpp
bool comp(pair<int,int> p1,pair<int,int> p2) {
    if (p1.first<p2.first) return true;
    else if (p1.first==p2.first) {
        if (p1.second<p2.second) return true;
    }
    return false;
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int>> v;
    int n=arrive.size();
    for (int i=0;i<n;i++) {
        v.push_back({arrive[i],1});
        v.push_back({depart[i],-1});
    }
    int rooms=K,rooms_available=K;
    sort(v.begin(),v.end(),comp);
    for(auto it:v) {
        if (it.second==1) {
            if (rooms_available) rooms_available-=1;
            else return false;
        }
        else rooms_available+=1;
    }
    return true;
}
```

### [Max Distance](https://www.interviewbit.com/problems/max-distance/)

```cpp
bool comp(array<int,2> one, array<int,2> two) {
    if (one[0]<two[0]) return true;
    else if (one[0]==two[0]) {
        if (one[1]<two[1]) return true;
        else return false;
    }
    return false;
}

int Solution::maximumGap(const vector<int> &a) {
    int n=a.size();
    vector<array<int,2>> b;
    for(int i=0;i<n;i++) {
        b.push_back({a[i],i});
    }
    sort(b.begin(),b.end(),comp);
    int ans=0;
    int mx=b[n-1][1];
    for(int i=n-2;i>=0;i--) {
        ans=max(ans,mx-b[i][1]);
        mx=max(mx,b[i][1]);
    }
    return ans;
}
```

### [Maximum Unsorted Subarray (star Marked)](https://www.interviewbit.com/problems/maximum-unsorted-subarray/)

```cpp
vector<int> Solution::subUnsort(vector<int> &a) {
    int n=a.size();
    int left=-1,right=-1;
    for(int i=0;i<n-1;i++) {
        if (a[i]>a[i+1]) {
            left=i;
            break;
        }
    }
    for(int i=n-1;i>0;i--) {
        if (a[i]<a[i-1]) {
            right=i;
            break;
        }
    }
    if (left==-1) return {-1};
    int mn=INT_MAX,mx=INT_MIN;
    for(int i=left;i<=right;i++) {
        mn=min(mn,a[i]);
        mx=max(mx,a[i]);
    }
    for(int i=left-1;i>=0;i--) {
        if (i==0 && a[i]>mn) {
            left=0;
            break;
        }
        if (a[i]<=mn) {
            left=i+1;
            break;
        }
    }
    for(int i=right+1;i<n;i++) {
        if (i==n-1 && a[i]<mx) {
            right=n-1;
            break;
        }
        if (a[i]>=mx) {
            right=i-1;
            break;
        }
    }
    return {left,right};
}
```

### [Kth Row of Pascal's Triangle](https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/)

```cpp
vector<int> Solution::getRow(int n) {
    vector<vector<int>> arr;
    arr.push_back({1});
    arr.push_back({1,1});
    for(int i=2;i<=n;i++) {
        vector<int> temp;
        temp.push_back(1);
        for(int j=1;j<arr[i-1].size();j++) {
            temp.push_back(arr[i-1][j]+arr[i-1][j-1]);
        }
        temp.push_back(1);
        arr.push_back(temp);
    }
    return arr[n];
}
```

### [Spiral Order Matrix II (star Marked)](https://www.interviewbit.com/problems/spiral-order-matrix-ii/)

```cpp
vector<vector<int> > Solution::generateMatrix(int n) {
    int mx=n*n;
    int i=0,j=0,cnt=1,dir=0;
    vector<vector<int>> ans(n,vector<int> (n,0));
    while (cnt<=mx) {
        ans[i][j]=cnt++;
        if (dir==0) {
            j++;
            if (j==n || ans[i][j]!=0) {
                dir=1;
                j--;
                i++;
            }
        }
        else if (dir==1) {
            i++;
            if (i==n || ans[i][j]!=0) {
                dir=2;
                i--;
                j--;
            }
        }
        else if (dir==2) {
            j--;
            if (j==-1 || ans[i][j]!=0) {
                dir=3;
                j++;
                i--;
            }
        }
        else if (dir==3) {
            i--;
            if (i==-1 || ans[i][j]!=0) {
                dir=0;
                i++;
                j++;
            }
        }
    }
    return ans;
}

```

### [Pascal Triangle](https://www.interviewbit.com/problems/pascal-triangle/)

```cpp
vector<vector<int> > Solution::solve(int n) {
    vector<vector<int>> arr;
    if (n==0) return arr;
    arr.push_back({1});
    if (n==1) return arr;
    arr.push_back({1,1});
    if (n==2) return arr;
    for(int i=2;i<n;i++) {
        vector<int> temp;
        temp.push_back(1);
        for(int j=1;j<arr[i-1].size();j++) {
            temp.push_back(arr[i-1][j]+arr[i-1][j-1]);
        }
        temp.push_back(1);
        arr.push_back(temp);
    }
    return arr;
}
```

### [Anti Diagonals](https://www.interviewbit.com/problems/anti-diagonals/)

```cpp
void get(vector<int> &temp,int x,int y,vector<vector<int> > &a,int n) {
        while (x<n && y>=0) {
            temp.push_back(a[x][y]);
            x++;y--;
        }
        return;
}

vector<vector<int> > Solution::diagonal(vector<vector<int> > &a) {
    vector<vector<int>> ans;
    int n=a.size(),m=a[0].size();
    for(int j=0;j<m;j++) {
        vector<int> temp;
        get(temp,0,j,a,n);
        ans.push_back(temp);
    }
    for (int i=1;i<n;i++) {
        vector<int> temp;
        get(temp,i,m-1,a,n);
        ans.push_back(temp);
    }
    return ans;
}
```

### [Largest Number](https://www.interviewbit.com/problems/largest-number/)

```cpp
int get_dg(int x) {
    while (x>=10) {
        x/=10;
    }
    return x;
}

int num_dig(int x) {
    int dig=0;
    while (x) {
        x/=10;
        dig++;
    }
    return dig;
}

bool comp(int x,int y) {
    int dgx=num_dig(x);
    int dgy=num_dig(y);
    long long newx=pow(10,dgy)*x+y;
    long long newy=pow(10,dgx)*y+x;
    if (newx>=newy) return true;
    return false;
}

string Solution::largestNumber(const vector<int> &a) {
    vector<int> arr[10];
    int n=a.size();
    for(int i=0;i<n;i++) {
        int dig = get_dg(a[i]);
        arr[dig].push_back(a[i]);
    }
    for(int i=0;i<10;i++) {
        sort(arr[i].begin(),arr[i].end(),comp);
    }
    string s="";
    for(int i=9;i>=0;i--) {
        if (arr[i].size()) {
            for(auto it:arr[i]) {
                string num=to_string(it);
                if (num=="0" && s=="0") continue;
                s+=num;
            }
        }
    }
    return s;
}
```

### [Rotate Matrix (star Marked)](https://www.interviewbit.com/problems/rotate-matrix/)

```cpp
void Solution::rotate(vector<vector<int> > &arr) {
    int n=arr.size();
    int t_start=1,t_end=n-1;
    for(int i=0;i<n/2;i++) {
        for(int j=t_start;j<t_end;j++) {
            swap(arr[i][j],arr[j][n-i-1]);
        }
        int k=n-i-2;
        for(int j=t_start;j<t_end;j++) {
            swap(arr[i][j],arr[n-i-1][k]);
            k--;
        }
        k=n-i-2;
        for(int j=t_start;j<t_end;j++) {
            swap(arr[i][j],arr[k][i]);
            k--;
        }
        swap(arr[i][i],arr[i][t_end]);
        swap(arr[i][i],arr[n-i-1][t_end]);
        swap(arr[i][i],arr[n-i-1][i]);
        t_start++;t_end--;
    }
}
```

### [Next Permutation (star Marked)](https://www.interviewbit.com/problems/next-permutation/)

```cpp
vector<int> Solution::nextPermutation(vector<int> &a) {
    int n=a.size(),last=1;
    for(int i=1;i<n;i++) {
        if (a[i]>a[i-1]) {
            last=0;
            break;
        }
    }
    if (last) {
        reverse(a.begin(),a.end());
        return a;
    }
    int note=n-1;
    for(int i=n-2;i>=0;i--) {
        if (a[i]>a[i+1]) {
            note=i;
        }
        else if (a[i]<a[i+1]) break;
    }
    if (note==n-1) {
        swap(a[n-2],a[n-1]);
    }
    else {
        int swap_with=a[note-1],change;
        for(int i=n-1;i>=note;i--) {
            if (a[i]>swap_with) {
                change=i;
                break;
            }
        }
        swap(a[note-1],a[change]);
        reverse(a.begin()+note,a.end());
    }
    return a;
}
```

### [Find Permutation (star Marked)](https://www.interviewbit.com/problems/find-permutation/)

```cpp
vector<int> Solution::findPerm(const string s, int n) {
    vector<int> arr(n,-1);
    int l=1,r=n;
    if (s[0]=='D') {
        arr[0]=r;
        r-=1;
    }
    else {
        arr[0]=l;
        l=2;
    }
    for(int i=0;i<n-1;i++) {
        if (i==n-2) {
            if (s[i]=='D') {
                arr[i+1]=l;
                l+=1;
            }
            else {
                arr[i+1]=r;
                r-=1;
            }
        }
        if (s[i]=='I' && s[i+1]=='D') {
            arr[i+1]=r;
            r-=1;
        }
        if (s[i]=='D' && s[i+1]=='I') {
            arr[i+1]=l;
            l+=1;
        }
    }
    for(int i=0;i<n-1;i++) {
        if (arr[i+1]==-1) {
            if (s[i+1]=='I') {
                arr[i+1]=l;
                l+=1;
            }
            else {
                arr[i+1]=r;
                r-=1;
            }
        }
    }
    return arr;
}
```

### [Merge Intervals](https://www.interviewbit.com/problems/merge-intervals/)

```cpp
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int l=newInterval.start,r=newInterval.end,n=intervals.size();
    int mx=max(l,r),mn=min(l,r),cnt=-1;
    if (n==0) {
        intervals.push_back(newInterval);
        return intervals;
    }
    if (intervals[n-1].end<mn) {
        struct Interval add={mn,mx};
        intervals.push_back(add);
        return intervals;
    }
    vector<Interval> ans;
    for(int i=0;i<n;i++) {
        cnt++;
        if (intervals[i].end>=mn) {
            struct Interval add={min(mn,intervals[i].start),-1};
            ans.push_back(add);
            break;
        }
        else ans.push_back(intervals[i]);
    }
    for(int i=0;i<n;i++) {
        if (intervals[i].end>=mx) {
            if (intervals[i].start>mx) {
                ans[cnt].end=mx;
                ans.push_back(intervals[i]);
                cnt++;
            }
            else ans[cnt].end=max(mx,intervals[i].end);
            break;
        }
    }
    if (ans[cnt].end==-1) ans[cnt].end=mx;
    for(int i=0;i<n;i++) {
        if (intervals[i].start>ans[cnt].end) {
            ans.push_back(intervals[i]);
            cnt++;
        }
    }
    return ans;
}
```

### [Merge Overlapping Intervals](https://www.interviewbit.com/problems/merge-overlapping-intervals/)

```cpp
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp(Interval a, Interval b) {
     return a.start<b.start;
 }

vector<Interval> Solution::merge(vector<Interval> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(a.begin(),a.end(),comp);
    vector<Interval> ans;
    int l=a[0].start,r=a[0].end,n=a.size();
    for(int i=1;i<n;i++) {
        if (a[i].start>r) {
            struct Interval add={l,r};
            ans.push_back(add);
            l=a[i].start;
        }
        r=max(r,a[i].end);
    }
    struct Interval add={l,r};
    ans.push_back(add);
    return ans;
}
```

### [Set Matrix Zeros](https://www.interviewbit.com/problems/set-matrix-zeros/)

```cpp
void Solution::setZeroes(vector<vector<int> > &a) {
    int m=a.size(),n=a[0].size();
    int r=1,c=1;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if (j==0 && a[i][0]==0) r=0;
            if (i==0 && a[0][j]==0) c=0;
            if (a[i][j]==0) {
                a[i][0]=0;
                a[0][j]=0;
            }
        }
    }
    for(int i=1;i<m;i++) {
        for(int j=1;j<n;j++) {
            if (a[i][j]==1 && (a[i][0]==0 || a[0][j]==0)) {
                a[i][j]=0;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if (a[0][i] && c==0) a[0][i]=0;
    }
    for(int i=0;i<m;i++) {
        if (a[i][0] && r==0) a[i][0]=0;
    }
    return;
}
```

### [First Missing Integer (star Marked)](https://www.interviewbit.com/problems/first-missing-integer/)

```cpp
int Solution::firstMissingPositive(vector<int> &a) {
    int n = a.size();
    // in O(n) time and O(n) space we can make an array of size N
    // and use it as hash table
    // but for O(n) time and O(1) space we will use the array itself
    for(int i=0;i<n;i++) {
        if (a[i]>0 and a[i]<=n) {
            int correct_pos = a[i] - 1;
            while (a[i]>0 and a[i]<=n) {
                swap(a[i],a[correct_pos]);
                if (a[i]<1 || a[i]>n || a[i]==(i+1)) break;
                correct_pos = a[i] - 1;
                if (a[correct_pos] == (correct_pos + 1)) break; // due to the case [1, 1, 1, 1]
            }
        }
    }
    for(int i=0;i<n;i++) {
        if (a[i]!=(i+1)) return (i+1);
    }
    return (n+1);
}
```

### [Repeat and Missing Number Array (star Marked)](https://www.interviewbit.com/problems/repeat-and-missing-number-array/)

```cpp
vector<int> Solution::repeatedNumber(const vector<int> &a) {
    int n=a.size();
    long long sum=0,sum2=0;
    for(int i=1;i<=n;i++) {
        sum+=i;
        sum2+=((long long)i*(long long)i);
    }
    long long asum=0,asum2=0;
    for(int i=0;i<n;i++) {
        asum+=a[i];
        asum2+=((long long)a[i])*((long long)a[i]);
    }
    long long aminb=asum-sum;
    long long aplub=(asum2-sum2)/aminb;
    long long aa=(aminb+aplub)/2;
    long long bb=(aplub-aminb)/2;
    return {(int)aa,(int)bb};
}
```

### [N/3 Repeat Number (star Marked)](https://www.interviewbit.com/problems/n3-repeat-number/)

```cpp
int Solution::repeatedNumber(const vector<int> &a) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=a.size();
    int num1=0,num2=0,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++) {
        if (num1==a[i]) cnt1++;
        else if (num2==a[i]) cnt2++;
        else if (cnt1==0) {num1=a[i];cnt1++;}
        else if (cnt2==0) {num2=a[i];cnt2++;}
        else {
            cnt1--;
            cnt2--;
        }
        // cout<<num1<<" "<<cnt1<<" "<<num2<<" "<<cnt2<<"\n";
    }
    cnt1=0;cnt2=0;
    for(int i=0;i<n;i++) {
        if (a[i]==num1) cnt1++;
        else if (a[i]==num2) cnt2++;
    }
    // cout<<num1<<" "<<cnt1<<" "<<num2<<" "<<cnt2<<"\n";
    if (cnt1>n/3) return num1;
    if (cnt2>n/3) return num2;
    return -1;
}
```

### [Minimum Lights to Activate](https://www.interviewbit.com/problems/minimum-lights-to-activate/)

```cpp
int Solution::solve(vector<int> &a, int b) {
    int n = a.size(), i = 0, ans = 0;
    while(i < n) {
        ans++; int fnd = 0;
        for(int j = min(n, i + b) - 1; j > max(0, i - b); j--) {
            if(a[j] == 1) {
                i = j + b;
                fnd = 1;
                break;
            }
        }
        if(!fnd) return -1;
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

## LeetCode Arrays Hard Problems

### [The Skyline Problem](https://leetcode.com/problems/the-skyline-problem/)

```cpp
// Method 1 (A bit Complex Implementation)
class Solution {
public:
    static bool comp(array<int, 4> a1, array<int, 4> a2) {
        if(a1[0] < a2[0]) return true;
        else if(a1[0] == a2[0]) {
            return a1[2] > a2[2];
        }
        return false;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<array<int, 4>> events;
        for(int i = 0; i < n; i++) {
            events.push_back({buildings[i][0], buildings[i][2], 1, buildings[i][1]});
            events.push_back({buildings[i][1], buildings[i][2], -1, buildings[i][1]});
        }
        sort(events.begin(), events.end(), comp);
        multiset<pair<int, int>> st; vector<vector<int>> ans;
        for(int i = 0; i < events.size(); i++) {
            if(events[i][2] == 1) {
                if(ans.size()) {
                    int m = ans.size();
                    if(ans[m - 1][1] < events[i][1]) {
                        if(ans[m - 1][0] == events[i][0]) ans[m - 1][1] = events[i][1];
                        else ans.push_back({events[i][0], events[i][1]});
                    }
                }
                else ans.push_back({events[i][0], events[i][1]});
                st.insert({events[i][1], events[i][3]});
            }
            else {
                int m = ans.size();
                st.erase(st.find({events[i][1], events[i][0]}));
                if(st.size() == 0) {
                    if(ans[m - 1][0] == events[i][0]) ans[m - 1][1] = 0;
                    else ans.push_back({events[i][0], 0});
                    continue;
                }
                auto mx = *(prev(st.end()));
                if(mx.first < ans[m - 1][1]) {
                    if(ans[m - 1][0] == events[i][0]) ans[m - 1][1] = mx.first;
                    else ans.push_back({events[i][0], mx.first});
                }
            }
        }
        return ans;
    }
};

// Method 2 (Simpler Implementation)
class Solution {
public:
    static bool comp(vector<int> a1, vector<int> a2) {
        if(a1[0] < a2[0]) return true;
        else if(a1[0] == a2[0]) {
            return a1[2] > a2[2];
        }
        return false;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<vector<int>> events;
        for(int i = 0; i < n; i++) {
            events.push_back({buildings[i][0], buildings[i][2], 1});
            events.push_back({buildings[i][1], buildings[i][2], -1});
        }
        sort(events.begin(), events.end(), comp);
        multiset<int> st; vector<vector<int>> ans;
        st.insert(0);
        for(int i = 0; i < events.size(); i++) {
            int pos = events[i][0], height = events[i][1];
            if(events[i][2] == 1) {
                if(height > *st.rbegin()) ans.push_back({pos, height});
                st.insert(height);
            }
            else {
                st.erase(st.find(height));
                if(height > *st.rbegin()) ans.push_back({pos, *st.rbegin()});
            }
        }
        vector<vector<int>> arr; int m = ans.size();
        for(int i = 0; i < m; i++) {
            if(i + 1 < m && ans[i][0] != ans[i + 1][0]) arr.push_back(ans[i]);
            if(i == m - 1) arr.push_back(ans[i]);
        }
        return arr;
    }
};
```

### [Rectangle Area II (Star Marked)](https://leetcode.com/problems/rectangle-area-ii/)

```cpp
#define mod 1000000007

class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int n = rectangles.size();
        vector<int> x, y;
        for(int i = 0; i < rectangles.size(); i++) {
            x.push_back(rectangles[i][0]); x.push_back(rectangles[i][2]);
            y.push_back(rectangles[i][1]); y.push_back(rectangles[i][3]);
        }
        sort(x.begin(), x.end()); x.resize(unique(x.begin(), x.end()) - x.begin());
        sort(y.begin(), y.end()); y.resize(unique(y.begin(), y.end()) - y.begin());
        map<int, int> mapx; map<int, int> mapy;
        for(int i = 0; i < x.size(); i++) mapx[x[i]] = i;
        for(int i = 0; i < y.size(); i++) mapy[y[i]] = i;
        vector<vector<int>> grid(250, vector<int> (250, 0));
        for(int i = 0; i < rectangles.size(); i++) {
            for(int j = mapx[rectangles[i][0]]; j < mapx[rectangles[i][2]]; j++) {
                for(int k = mapy[rectangles[i][1]]; k < mapy[rectangles[i][3]]; k++) grid[k][j] = 1;
            }
        }
        long long ans = 0;
        for(int i = 0; i < 250; i++) {
            for(int j = 0; j < 250; j++) {
                if(grid[i][j]) {
                    ans += ((long long)(x[j + 1] - x[j]) * (y[i + 1] - y[i]));
                    ans %= mod;
                }
            }
        }
        return (int)ans;
    }
};
```

### [Describe the Painting (Star Marked)](https://leetcode.com/problems/describe-the-painting/)

```cpp
// Method 1 (I don't know how this works)
class Solution {
public:
    static bool comp(array<int, 4> v1, array<int, 4> v2) {
        if(v1[0] < v2[0]) return true;
        else if(v1[0] > v2[0]) return false;
        return v1[1] < v2[1];
    }

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();
        vector<array<int, 4>> events;
        for(int i = 0; i < n; i++) {
            events.push_back({segments[i][0], 1, segments[i][2], segments[i][1]});
            events.push_back({segments[i][1], -1, segments[i][2], segments[i][1]});
        }
        sort(events.begin(), events.end(), comp);
        multiset<int> st;
        vector<vector<long long>> ans;
        long long col = 0; int sz = 0;;
        for(int i = 0; i < events.size(); i++) {
            int l = events[i][0], r = events[i][3], color = events[i][2];
            if(events[i][1] == 1) {
                col = col + (long long)color;
                if(sz && ans[sz - 1][0] == l) ans[sz - 1][2] = col;
                else {
                    if(sz && st.size()) ans[sz - 1][1] = l;
                    ans.push_back({l, -1, col});
                    sz++;
                }
                st.insert(r);
            }
            else {
                col -= color;
                st.erase(st.find(r));
                ans[sz - 1][1] = r;
                if(r == ans[sz - 1][0]) ans[sz - 1][2] = col;
                if(st.size() && *st.rbegin() > r && r != ans[sz - 1][0]) {
                    ans.push_back({r, -1, col});
                    sz++;
                }
            }
        }
        return ans;
    }
};

// Method 2 (this is something you will understand but still it's not easy to implement correctly in first go)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(array<int, 4> v1, array<int, 4> v2) {
        if(v1[0] < v2[0]) return true;
        else if(v1[0] > v2[0]) return false;
        return v1[1] < v2[1];
    }

    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();
        vector<array<int, 4>> events;
        for(int i = 0; i < n; i++) {
            events.push_back({segments[i][0], 1, segments[i][2], segments[i][1]});
            events.push_back({segments[i][1], -1, segments[i][2], segments[i][1]});
        }
        sort(events.begin(), events.end(), comp);
        multiset<int> st;
        vector<vector<long long>> ans;
        long long col = 0; int sz = 0;;
        for(int i = 0; i < events.size(); i++) {
            int l = events[i][0], r = events[i][3], color = events[i][2];
            if(events[i][1] == 1) {
                col += (long long)color;
                if(!sz) {
                    ans.push_back({l, r, col});
                    sz++;
                }
                else {
                    if(ans[sz - 1][0] == l) {
                        ans[sz - 1][1] = max((int)ans[sz - 1][1], (int)r);
                        ans[sz - 1][2] = col;
                    }
                    else {
                        if(ans[sz - 1][1] > l) {
                            ans.push_back({l, max((int)r, (int)ans[sz - 1][1]), col});
                            ans[sz - 1][1] = l;
                        }
                        else ans.push_back({l, r, col});
                        sz++;
                    }
                }
            }
            else {
                col -= (long long)color;
                if(ans[sz - 1][0] == r) ans[sz - 1][2] = col;
                else if(ans[sz - 1][1] > r) {
                    ans.push_back({r, ans[sz - 1][1], col});
                    ans[sz - 1][1] = r;
                    sz++;
                }
            }
        }
        return ans;
    }
};

// Method 3 (very simple implementation)
class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n = segments.size();
        vector<vector<long long>> ans;
        map<long long, long long> mp;
        for(int i = 0; i < n; i++) {
            mp[segments[i][0]] += segments[i][2];
            mp[segments[i][1]] -= segments[i][2];
        }
        int prev = -1; long long col = 0;
        for(auto it : mp) {
            if(prev != -1 && col) ans.push_back({prev, it.first, col});
            prev = it.first;
            col += it.second;
        }
        return ans;
    }
};
```
