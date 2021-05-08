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

### [First Missing Integer](https://www.interviewbit.com/problems/first-missing-integer/)

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
