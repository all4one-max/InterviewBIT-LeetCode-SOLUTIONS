#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<long long, null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
#define int             long long
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          (long long)v.size()
#define pii            pair<int, int>

class A {
public:
    // static int heap_sze = 0, stack_sze = 0; can't do this because
    // C++ forbids in-class initialization of non-const static member

    static int heap_sze, stack_sze;

    A() {
        stack_sze++;
    }
    ~A() {
        stack_sze--;
    }
    void* operator new(size_t t) {
        heap_sze++;
        stack_sze--;
        void* p = (A*)malloc(t);
        return p;
    }
    void operator delete(void* p) {
        heap_sze--;
        stack_sze++;
        free(p);
    }
};


int A::heap_sze = 0;
int A::stack_sze = 0;

void solve() {

    A d1, d2;
    // these are local variables and they are stored in the stack section
    // of the memory

    A* ptr1 = new A();
    A* ptr2 = new A();
    // these are dynamic variables and they are stored in the heap section
    // of the memory

    cout << "NUM ELEMENTS IN HEAP " << A::heap_sze << endl;
    cout << "NUM ELEMENTS IN STACK " << A::stack_sze << endl;

    delete ptr1;

    cout << "NUM ELEMENTS IN HEAP " << A::heap_sze << endl;
    cout << "NUM ELEMENTS IN STACK " << A::stack_sze << endl;

    // malloc allocates memory but doesn't call constructor
    // free de-allocates memory but doesn't call destructor
    return;
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
    // for printing erros
    freopen("Errors.txt", "w", stderr);
# endif
    int t = 1;
    fo(i, t) solve();
    return 0;
}
