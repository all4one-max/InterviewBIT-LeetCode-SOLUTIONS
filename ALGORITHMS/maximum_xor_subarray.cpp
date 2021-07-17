#include <bits/stdc++.h>
#include <map>
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
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

int n, x, m, y, e, t, k, len, u1, u2,  f, q, unque = 0;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
vector<int> arr(mx2, 0);
class trie_node {
public :
	trie_node* left;
	trie_node* right;
};

void insert(int val, trie_node* head) {
	trie_node* curr = head;
	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;
		if (bit) {
			if (!curr->right) curr->right = new trie_node();
			curr = curr->right;
		}
		else {
			if (!curr->left) curr->left = new trie_node();
			curr = curr->left;
		}
	}
	return;
}

int max_xor_sub(trie_node* head, int val) {
	trie_node* curr = head;
	int curr_xor_sub = 0;
	for (int j = 31; j >= 0; j--) {
		int bit = (val >> j) & 1;
		if (bit) {
			if (curr->left) {
				curr_xor_sub += pow(2, j);
				curr = curr->left;
			}
			else curr = curr->right;

		}
		else {
			if (curr->right) {
				curr_xor_sub += pow(2, j);
				curr = curr->right;
			}
			else curr = curr->left;
		}
	}
	return curr_xor_sub;
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
	trie_node* head = new trie_node();
	int ini = 0, ans = -1 * 1e9;
	insert(ini, head);
	fo(i, n) {
		ini = arr[i] ^ ini;
		ans = max(ans, ini);
		ans = max(ans, max_xor_sub(head, ini));
		insert(ini, head);
	}
	cout << ans << endl;
	return 0;
}
