### [Matrix Median](https://www.interviewbit.com/problems/matrix-median/)

```cpp
int check(vector<vector<int>> &a, int n, int m, int val, int N){
    int cnt=0,cnt2=0;
    for(int i=0;i<n;i++) {
        for(int j=0; j<m;j++) {
            if (a[i][j]<val) cnt++;
            if (a[i][j]==val) cnt2++;
        }
    }
    if (cnt>=N/2 || cnt2==1) return cnt;
    for(int i=0;i<n;i++) {
        for(int j=0; j<m;j++) {
            if (a[i][j]==val) {
                cnt2--;
                cnt++;
                if (cnt>=N/2 || cnt2==1) return cnt;
            }
        }
    }
    return cnt;
}

int Solution::findMedian(vector<vector<int>> &a) {
    int n=a.size(),m=a[0].size();
    int high=-1,low=INT_MAX;
    for(int i=0;i<n;i++) {
        for(int j=0; j<m;j++) {
            low=min(low,a[i][j]);
            high=max(high,a[i][j]);
        }
    }
    int ret,mid;
    int N=n*m;
    while (high-low>1) {
        mid=(low+high)/2;
        ret=check(a,n,m,mid,N);
        // cout<<low<<" "<<mid<<" "<<high<<" "<<ret<<"\n";
        int found=0;
        for(int i=0;i<n;i++) {
            for(int j=0; j<m;j++) {
                if (a[i][j]==mid) {
                    found=1;
                    break;
                }
            }
        }
        if (N%2) {
            if (ret>N/2) high=mid;
            else if (ret<N/2) low=mid;
            else
            {
                if (found) return mid;
                else low=mid;
            }
        }
        else {
            if (ret>N/2) high=mid;
            else if (ret==N/2)
            {
                if (found) return mid;
                else low=mid;
            }
            else if (ret==(N/2-1))
            {
                if (found) return mid;
                else low=mid;
            }
            else low=mid;
        }
        // cout<<low<<" "<<high<<" "<<"\n";
    }
    ret=check(a,n,m,low,N);
    // cout<<ret<<"\n";
    int found=0;
    for(int i=0;i<n;i++) {
        for(int j=0; j<m;j++) {
            if (a[i][j]==low) {
                found=1;
                break;
            }
        }
    }
    if (N%2) {
        if (ret==N/2 && found) return low;
    }
    else {
        if (ret==N/2 && found) return low;
        if (ret==(N/2-1) && found) return low;
    }
    return high;
}
```

### [Square Root of Integer](https://www.interviewbit.com/problems/square-root-of-integer/)

```cpp

#define ll long long int

int Solution::sqrt(int a) {
    // cout<<a<<"\n";
    ll low=1,high=a;
    while (high-low>1) {
        ll mid=(low+high)/2;
        // cout<<mid<<"\n";
        // ll val=mid*mid;
        if (mid*mid==a) return mid;
        else if (mid*mid>a) {
            if ((mid-1)*(mid-1)<a) return mid-1;
            high=mid;
        }
        else if (mid*mid<a) {
            if ((mid+1)*(mid+1)>a) return mid;
            low=mid;
        }
    }
    if (low*low==a) return low;
    else if (low*low>a) {
        if ((low-1)*(low-1)<a) return low-1;
    }
    else if (low*low<a) {
        if ((low+1)*(low+1)>a) return low;
    }
    return high;
}
```

### [Allocate Books](https://www.interviewbit.com/problems/allocate-books/)

```cpp
int Solution::books(vector<int> &a, int b) {
    long long int low=0,high=10000000000;
    int n=a.size(),ans;
    if (n<b) return -1;
    while (high-low>1) {
        long long int mid=(low+high)/2;

        int cur=0,std=0,possible=1;
        for(int i=0;i<n;i++) {
            if (cur+a[i]>mid) {
                if (cur==0) {
                    possible=0;
                    break;
                }
                else {
                    cur=0;
                    if (a[i]>mid) {
                        possible=0;
                        break;
                    }
                    std++;
                }
            }
            cur+=a[i];
            if (i==n-1) std++;
        }
        // cout<<low<<" "<<mid<<" "<<high<<" "<<std<<"\n";
        if (possible && std<=b) high=mid;
        else low=mid;

    }
    // cout<<low<<" "<<high<<"\n";
    int cur=0,std=0,possible=1;
    for(int i=0;i<n;i++) {
        if (cur+a[i]>low) {
            if (cur==0) {
                possible=0;
                break;
            }
            else {
                cur=0;
                if (a[i]>low) {
                    possible=0;
                    break;
                }
                std++;
            }
        }
        cur+=a[i];
        if (i==n-1) std++;
    }
    if (!possible || std>b) return high;
    return low;
}
```

### [Painter's Partition Problem](https://www.interviewbit.com/problems/painters-partition-problem/)

```cpp
# define ll long long int
int Solution::paint(int a, int b, vector<int> &c) {
    ll low = -1, n = c.size(), high = 0;
    for(int i=0;i<n;i++) {
        low = max(low,(ll)c[i]*b);
        high += ((ll)c[i]*b);
    }
    while (high - low>1) {
        ll mid = (low + high)/2;
        // cout<<low<<" "<<mid<<" "<<high<<"\n";
        ll cur=0,std=0,possible=1;
        for(int i=0;i<n;i++) {
            if (cur + (ll)c[i]*b>mid) {
                if (cur==0) {
                    possible=0;
                    break;
                }
                else {
                    cur=0;
                    if ((ll)c[i]*b>mid) {
                        possible=0;
                        break;
                    }
                    std++;
                }
            }
            cur+=((ll)c[i]*b);
            if (i==n-1) std++;
        }
        if (possible && std<=a) high=mid;
        else low=mid;
    }
    ll cur=0,std=0,possible=1;
    for(int i=0;i<n;i++) {
        if (cur + (ll)c[i]*b>low) {
            if (cur==0) {
                possible=0;
                break;
            }
            else {
                cur=0;
                if ((ll)c[i]*b>low) {
                    possible=0;
                    break;
                }
                std++;
            }
        }
        cur+=((ll)c[i]*b);
        if (i==n-1) std++;
    }
    if (!possible || std>a) return high%10000003;
    return low%10000003;
}
```

### [Matrix Search](https://www.interviewbit.com/problems/matrix-search/)

```cpp
int Solution::searchMatrix(vector<vector<int> > &a, int b) {
    int n = a.size(), m = a[0].size();
    int low = 0, high = n - 1, note = -1;
    while (high - low>1) {
        int mid = (low + high)/2;
        if (b>=a[mid][0] && b<=a[mid][m - 1]) {
            note = mid;
            break;
        }
        else if (a[mid][0]>b) high = mid;
        else low = mid;
    }
    if (note == -1 && b>=a[low][0] && b<=a[low][m - 1]) note = low;
    if (note == -1 && b>=a[high][0] && b<=a[high][m - 1]) note = high;
    if (note == -1) return 0;
    low = 0, high = m - 1;
    while (high - low>1) {
        int mid = (low + high)/2;
        if (a[note][mid] == b) return 1;
        else if (a[note][mid]>b) high = mid - 1;
        else low = mid + 1;
    }
    if (a[note][low] == b) return 1;
    if (a[note][high] == b) return 1;
    return 0;
}
```

### [Search for a Range](https://www.interviewbit.com/problems/search-for-a-range/)

```cpp
vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int n=A.size();
    int strt = lower_bound(A.begin(),A.end(),B) - A.begin();
    int end = upper_bound(A.begin(),A.end(),B) - A.begin();
    if (strt<n && A[strt]==B) {
        return {strt,end-1};
    }
    else return {-1,-1};
}
```

### [Sorted Insert Position](https://www.interviewbit.com/problems/sorted-insert-position/)

```cpp
int Solution::searchInsert(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int low=0,high=n-1;
    while (high-low>1) {
        int mid=(low+high)/2;
        if (A[mid]==B) return mid;
        else if (A[mid]>B) high=mid;
        else if (A[mid]<B) low=mid;
    }
    if (A[high]==B) return high;
    if (A[low]==B) return low;
    if (B>A[high]) return high+1;
    if (B<A[low]) return low;
    return high;

}
```

### [Implement Power Function](https://www.interviewbit.com/problems/implement-power-function/)

```cpp
# define ll long long
int Solution::pow(int a, int b, int mod) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if (a==0) return 0;
    if (b==0) return 1;
    ll c = (ll)a,d = (ll)b;
    ll rest = 1;
    while (d) {
        if (d & 1) rest = ((ll)1*rest * c + mod) % mod;
        c = (c * c + mod) % mod;
        d = d >> 1;
    }
    return (int)rest;
}
```

### [Simple Queries](https://www.interviewbit.com/problems/simple-queries/)

```cpp
#define mod 1000000007
long long divisorProduct(int n) {
    long long product = 1;
    for(int i=1; i*i<=n; i++){
        if (n%i == 0){
            if (n/i == i) product = (product*i)%mod;
            else{
                product = (product*i)%mod;
                product = (product*(n/i))%mod;
            }
        }
    }
    return product;
}

bool compare(pair<int, long long> a, pair<int, long long> b){
    return a.first > b.first;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    int n=A.size();
    vector<int> leftFreq(n, 1);
    vector<int> rightFreq(n, 1);
    for(int i=1; i<n; i++){
        int prev=i-1;
        while(prev>=0 && A[prev]<=A[i]){
            leftFreq[i] += leftFreq[prev];
            prev -= leftFreq[prev];
        }
    }
    for(int i=n-2; i>=0; i--){
        int next=i+1;
        while(next<n && A[next]<A[i]){
            rightFreq[i] += rightFreq[next];
            next += rightFreq[next];
        }
    }

    vector<pair<int, long long>> numFreq(n);
    for(int i=0; i<n; i++) numFreq[i] = {divisorProduct(A[i]), leftFreq[i]*rightFreq[i]};
    sort(numFreq.begin(), numFreq.end(), compare);
    vector<long long> cumFreq(n);
    cumFreq[0]=numFreq[0].second;
    for(int i=1; i<n; i++) cumFreq[i] = numFreq[i].second + cumFreq[i-1];

    vector<int> ans;
    for(int i=0; i<B.size(); i++){
        auto id=lower_bound(cumFreq.begin(), cumFreq.end(), B[i])-cumFreq.begin();
        ans.push_back(numFreq[id].first);
    }
    return ans;
}
```

### [Median of Array](https://www.interviewbit.com/problems/median-of-array/)

```cpp
double Solution::findMedianSortedArrays(const vector<int> &a, const vector<int> &b) {
    int m = a.size(), n = b.size();

    if (m>n) return findMedianSortedArrays(b,a);
    int low = 0, high = m;
    while (high>=low) {
        // partitionX number of elements on the left part of array a
        int partitionX = (low + high)/2;
        int partitionY = (m + n + 1)/2 - partitionX;

        int maxlefta = (partitionX == 0) ? INT_MIN : a[partitionX - 1];
        int maxleftb = (partitionY == 0) ? INT_MIN : b[partitionY - 1];

        int minrighta = (partitionX == m) ? INT_MAX : a[partitionX];
        int minrightb = (partitionY == n) ? INT_MAX : b[partitionY];

        int left_val = max(maxlefta,maxleftb);
        int right_val = min(minrighta,minrightb);

        if (maxlefta<=minrightb && maxleftb<=minrighta) {

            if ((m+n)%2==0) return ((double)left_val + right_val)/2;
            else return ((double)left_val);
        }
        if (maxlefta>minrightb) high = partitionX - 1;
        else low = partitionX + 1;
    }

}
```

### [Rotated Sorted Array Search](https://www.interviewbit.com/problems/rotated-sorted-array-search/)

```cpp
int Solution::search(const vector<int> &a, int b) {
    int n = a.size();
    int low = 0, high = n - 1;
    while (high - low >1 ){
        int mid = (low + high)/2;
        if (a[mid]==b) return mid;
        if (a[mid]>=a[low]) {
            if (b>=a[low] && b<=a[mid]) high = mid;
            else low = mid;
        }
        else {
            if (b>=a[low] || b<=a[mid]) high = mid;
            else low = mid;
        }
    }
    if (a[low] == b) return low;
    if (a[high] == b) return high;
    return -1;
}
```
