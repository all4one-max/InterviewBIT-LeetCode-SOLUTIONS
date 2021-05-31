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

### [Meeting rooms](https://www.interviewbit.com/problems/meeting-rooms/)

```cpp
bool comp(array<int, 2> a1, array<int, 2> a2) {
    if(a1[0] < a2[0]) return true;
    else if(a1[0] > a2[0]) return false;
    if(a1[1] == -1) return true;
    return false;
}

int Solution::solve(vector<vector<int> > &a) {
    // solve using events method
    vector<array<int, 2>> v;
    int n = a.size();
    for(int i = 0; i < n; i++) {
        v.push_back({a[i][0], 1});
        v.push_back({a[i][1], -1});
    }
    sort(v.begin(), v.end(), comp);
    int rooms = 0, cur = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i][1] == 1) {
            if(cur == rooms) {
                cur++;
                rooms++;
            }
            else cur++;
        }
        else cur--;
    }
    return rooms;
}
```

### [Distribute Candy (Star Marked)](https://www.interviewbit.com/problems/distribute-candy/)

```cpp
// Method 1 (O(nlogn))
bool comp(array<int, 2> a1, array<int, 2> a2) {
    if(a1[0] < a2[0]) return true;
    else if(a1[0] > a2[0]) return false;
    return false;
}

int Solution::candy(vector<int> &a) {
    int n = a.size();
    vector<int> candy(n, 0);
    vector<array<int, 2>> v;
    for(int i = 0; i < n; i++) v.push_back({a[i], i});
    sort(v.begin(), v.end(), comp);
    for(int i = 0; i < n; i++) {
        int num = v[i][0], ind = v[i][1];
        if(((ind == n - 1) || (ind + 1 < n && candy[ind + 1] == 0)) && ((ind == 0) || (ind - 1 >= 0 && candy[ind - 1] == 0))) {
            candy[ind] = 1;
            continue;
        }
        if(ind + 1 < n && candy[ind + 1] != 0) {
            if(a[ind] == a[ind + 1]) candy[ind] = 1;
            else candy[ind] = 1 + candy[ind + 1];
        }
        if(ind - 1 >= 0 && candy[ind - 1] != 0) {
            if(a[ind] == a[ind - 1]) {
                if(candy[ind] == 0) candy[ind] = 1;
            }
            else candy[ind] = max(candy[ind], 1 + candy[ind - 1]);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans += candy[i];
    return ans;
}
```

### [Seats (Star Marked)](https://www.interviewbit.com/problems/seats/)

```cpp
// Method 1 (Using dp)
int Solution::seats(string a) {
    int n = a.size(); vector<long long> pref(n + 1, 0); vector<long long> suf(n + 1, 0);
    if(n <= 2) return 0;
    long long cnt = 0;
    for(int i = 0; i < n; i++) {
        if(cnt) {
            if(i != 0) pref[i] = pref[i - 1];
            if(a[i] == '.') pref[i] = ((long long)pref[i] + cnt);
        }
        if(a[i] == 'x') cnt++;
    }
    cnt = 0;
    for(int i = n - 1; i >= 0; i--) {
        if(cnt) {
            suf[i] = suf[i + 1];
            if(a[i] == '.') suf[i] = ((long long)suf[i] + cnt);
        }
        if(a[i] == 'x') cnt++;
    }
    long long ans = suf[0];
    for(int i = 0; i < n; i++) {
        if(i != n - 1) ans = min(ans, ((long long)pref[i] + suf[i + 1]));
        else ans = min(ans, pref[n - 1]);
    }
    return (int)(ans % 10000003);
}

// Method 2 (it is optimal to place all the x's around the median)
int Solution::seats(string a) {
    int n = a.size();
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 'x') cnt++;
    }
    if(n == 0 || cnt == 1 || cnt == 0) return 0;
    int x = cnt/2 + 1; int cnt2 = 0, pos = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] == 'x') cnt2++;
        if(cnt2 == x) {
            pos = i;
            break;
        }
    }
    int cur = pos - 1, ans = 0;
    for(int i = pos - 1; i >= 0; i--) {
        if(a[i] == 'x') {
            ans = (ans + (cur - i)) % 10000003;
            cur--;
        }
    }
    cur = pos + 1;
    for(int i = pos + 1; i < n; i++) {
        if(a[i] == 'x') {
            ans = (ans + (i - cur)) % 10000003;
            cur++;
        }
    }
    return ans;
}
```

### [Assign Mice to Holes](https://www.interviewbit.com/problems/assign-mice-to-holes/)

```cpp
int Solution::mice(vector<int> &a, vector<int> &b) {
    sort(a.begin(), a.end()); sort(b.begin(), b.end()); int n = a.size();
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, abs(a[i] - b[i]));
    return ans;
}
```

### [Gas Station (Star Marked)](https://www.interviewbit.com/problems/gas-station/)

```cpp
int Solution::canCompleteCircuit(const vector<int> &a, const vector<int> &b) {
    int n = a.size();
    int tank = 0, start = 0, total = 0;
    for(int i = 0; i < n; i++) {
        tank += (a[i] - b[i]); total += (a[i] - b[i]);
        if(tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    if(total < 0) return -1;
    return start;
}
```

### [Disjoint Intervals](https://www.interviewbit.com/problems/disjoint-intervals/)

```cpp
bool comp(vector<int> &v1, vector<int> &v2) {
    if(v1[0] < v2[0]) return true;
    else if(v1[0] > v2[0]) return false;
    if(v1[1] < v2[1]) return true;
    return false;
}

int Solution::solve(vector<vector<int> > &a) {
    int n = a.size();
    sort(a.begin(), a.end(), comp);
    int l = a[0][0], r = a[0][1], ans = 1;
    for(int i = 1; i < n; i++) {
        if(a[i][0] == l && a[i][1] == r) continue;
        if(a[i][0] == l) continue;
        else {
            if(a[i][0] > r) {
                l = a[i][0];
                r = a[i][1];
                ans++;
            }
            else {
                if(a[i][1] < r) r = a[i][1];
            }
        }
    }
    return ans;
}
```

### [Largest Permutation](https://www.interviewbit.com/problems/largest-permutation/)

```cpp
vector<int> Solution::solve(vector<int> &a, int b) {
    unordered_map<int, int> mp; int n = a.size();
    for(int i = 0; i < n; i++) mp[a[i]] = i;
    int val = n;
    for(int i = 0; i < n; i++) {
        if(a[i] != val && b) {
            int ind = mp[val];
            swap(a[i], a[ind]);
            mp[a[ind]] = ind;
            mp[val] = i;
            b--;
        }
        val--;
    }
    return a;
}
```
