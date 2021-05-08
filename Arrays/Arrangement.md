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
