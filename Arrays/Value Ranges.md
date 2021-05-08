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
