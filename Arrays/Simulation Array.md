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

### [Spiral Order Matrix II](https://www.interviewbit.com/problems/spiral-order-matrix-ii/)

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
