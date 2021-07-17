// Inversion Count for an array indicates – how far (or close) the array is from being sorted.
// If the array is already sorted then inversion count is 0.
// If the array is sorted in the reverse order that inversion count is the maximum.

// If we are given an unsorted array then it does not mean the inversion number
// will be the minimum number of operations to sort the array but if it is also given
// that we can swap only adjacent pair of elements then inversion number gives the minimum
// number of operations to sort the array
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
#include <unordered_map>
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int            long long
#define fo(i,n)        for(int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define sz(v)          v.size()
#define pii            pair<int, int>
// TIME COMPLEXITY : O(max_element)
int n, x, m, y, e, t, k, len, u1, u2,  f;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
vector<int> BIT(mx, 0);
vector<int> arr(mx, 0);

bool comp(int a, int b)
{
	return (a >= b);
}

void update(int index,  int val) {
	while (index <= n) {
		BIT[index] += val;
		index += (index & (-index));
	}
	return;
}

int query(int index) {
	int sum = 0;
	while (index > 0) {
		sum += BIT[index];
		index -= (index & (-index));
	}
	return sum;
}

signed main()
{	tezi
# ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for getting input from output.txt
	freopen("output.txt", "w", stdout);
# endif
	cin >> n;
	fo(i, n) cin >> arr[i];
	int mx = *max_element(all(arr));
	int invcnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		invcnt += (query(arr[i] - 1));
		update(arr[i], 1);
	}
	cout << invcnt << endl;
	return 0;
}

/*
    #######
   #
  #
 #######   #     #  # ####   # #     #
       #  # #   #  # #   #  # # #   #
      #  ####  #  # ####   ####  # #
######  #   # #### #    # #   #   #
*/
