### [Repeat and Missing Number Array](https://www.interviewbit.com/problems/repeat-and-missing-number-array/)

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

### [N/3 Repeat Number](https://www.interviewbit.com/problems/n3-repeat-number/)

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
