### [Highest Product](https://www.interviewbit.com/problems/highest-product/)

```cpp
int Solution::maxp3(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());
    int ans = a[n - 3]*a[n - 2]*a[n - 1];
    ans = max(ans, max(a[n - 1]*a[n - 2]*a[0],a[0]*a[1]*a[n - 1]));
    return ans;
}
```

### [Majority Element](https://www.interviewbit.com/problems/majority-element/)

```cpp
int Solution::majorityElement(const vector<int> &a) {
    int n = a.size(); int ele, count = 0;
    for(int i = 0; i < n; i++) {
        int x = a[i];
        if (count == 0) {
            count = 1;
            ele = x;
        }
        else {
          if (x == ele) count++;
          else count--;
        }
    }
    return ele;
}
```
