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

int n, x, m, y, e, t, len, u1, u2,  f, q;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
class trie_node {
public :
	trie_node* left;
	trie_node* right;
	int left_cnt = 0;
	int right_cnt = 0;
};

void insert(int val, trie_node* head) {
	trie_node* curr = head;
	for (int i = 31; i >= 0; i--) {
		int bit = (val >> i) & 1;
		if (bit) {
			curr->right_cnt++;
			if (!curr->right) curr->right = new trie_node();
			curr = curr->right;
		}
		else {
			curr->left_cnt++;
			if (!curr->left) curr->left = new trie_node();
			curr = curr->left;
		}
	}
	return;
}

int count_xor_k(trie_node* head, int val, int k) {
	if (head == nullptr) return 0;
	trie_node* root = head;
	int res = 0;
	for (int j = 31; j >= 0; j--) {
		bool current_bit_of_k = (k >> j) & 1;
		bool current_bit_of_element = (val >> j) & 1;
		if (current_bit_of_k)//if the current bit of k is 1
		{
			if (current_bit_of_element)//if current bit of element is 1
			{
				res += root->right_cnt;
				if (root->left == NULL)
					return res;
				root = root->left;
			}

			else//if current bit of element is 0
			{
				res += root->left_cnt;
				if (root->right == NULL)
					return res;
				root = root->right;
			}
		}
		else//if the current bit of k is zero
		{
			if (current_bit_of_element)//if current bit of element is 1
			{
				if (root->right == NULL)
					return res;
				root = root->right;
			}
			else//if current bit of element is 0
			{
				if (root->left == NULL)
					return res;
				root = root->left;
			}
		}
	}
	return res;
}

signed main()
{	tezi
# ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for getting input from output.txt
	freopen("output.txt", "w", stdout);
# endif
	cin >> t;
	while (t--) {
		int total = 0, k;
		cin >> n >> k;
		trie_node* head = new trie_node();
		int ini = 0;
		insert(ini, head);
		fo(i, n) {
			cin >> x;
			ini = x ^ ini;
			//cout << count_xor_k(head, arr[i]) << endl;
			//cout << ini << endl;
			total += count_xor_k(head, ini, k);
			insert(ini, head);
		}
		cout << total << endl;
	}
	return 0;
}
