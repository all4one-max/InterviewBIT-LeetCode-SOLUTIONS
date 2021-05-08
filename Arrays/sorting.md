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
