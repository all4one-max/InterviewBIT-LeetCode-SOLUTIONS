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
