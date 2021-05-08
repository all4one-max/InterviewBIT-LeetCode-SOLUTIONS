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
