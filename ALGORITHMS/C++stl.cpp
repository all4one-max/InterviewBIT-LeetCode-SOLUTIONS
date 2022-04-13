#include <bits/stdc++.h>
using namespace std;

#define all(v)         v.begin(), v.end()
********************** NOTE ***************************
// The lines are solely written for explanation
// purpose. They will not compile. Reuse of
// same variable names are done to explain.
// Do not mix the above line with the current line.
*******************************************************

// Pairs
void explainPair() {

    pair<int, int> p = {1, 3};

    // prints 1 3
    cout << p.first << " " << p.second;


    pair<int, pair<int, int>> p = {1, {3, 4}};

    // prints 1 4 3
    cout << p.first << " " << p.second.second << " " << p.second.first;


    pair<int, int> arr[] = { {1, 2}, {2, 5}, {5, 1}};

    // Prints 5
    cout << arr[1].second;

}


void explainVector() { // it allows dynamic allocation i.e you can change the size whenever you want

    // A empty vector
    vector<int> v;  // {}

    v.push_back(1); // {1}
    v.emplace_back(2); // {1, 2}

    vector<pair<int, int>>vec;

    v.push_back({1, 2});
    v.emplace_back(1, 2);

    // Vector of size 5 with
    // everyone as 100
    vector<int> v(5, 100); // {100, 100, 100, 100, 100}

    // A vector of size 5
    // initialized with 0
    // might take garbage value,
    // dependent on the vector
    vector<int> v(5); // {0, 0, 0, 0, 0}

    vector<int> v1(5, 20); // {20, 20, 20, 20, 20}
    vector<int> v2(v1); // {20, 20, 20, 20, 20} // this will make copy of v1



    // Take the vector to be {10, 20, 30, 40}
    vector<int>::iterator it = v.begin();

    it++;
    cout << *(it) << " "; // prints 20


    it = it + 2;
    cout << *(it) << " "; // prints 30

    vector<int>::iterator it = v.end(); // it will point to a memory address after 40

    vector<int>::iterator it = v.rend(); // it will point to a memory address before 10

    vector<int>::iterator it = v.rbegin(); // it will point to 40

    vectot<int>::iterator it = v.cbegin(); // it will point to 10 and the iterator will not move



    cout << v[0] << " " << v.at(0);

    cout << v.back() << " "; // will print the last element i.e 40


    // Ways to print the vector

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }


    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    for (auto it : v) {
        cout << it << " ";
    }

    // {10, 20, 12, 23}
    v.erase(v.begin() + 1); // {10,12,23} // it is O(n)

    // {10, 20, 12, 23, 35}
    v.erase(v.begin() + 2, v.begin() + 4); // // {10, 20, 35} [start, end)


    // Insert function

    vector<int>v(2, 100); // {100, 100}
    v.insert(v.begin(), 300); // {300, 100, 100};
    v.insert(v.begin() + 1, 2, 10); // {300, 10, 10, 100, 100}

    vector<int> copy(2, 50); // {50, 50}
    v.insert(v.begin(), copy.begin(), copy.end()); // {50, 50, 300, 10, 10, 100, 100}

    // {10, 20}
    cout << v.size(); // 2

    //{10, 20}
    v.pop_back(); // {10}

    // v1 -> {10, 20}
    // v2 -> {30, 40}
    v1.swap(v2); // v1 -> {30, 40} , v2 -> {10, 20}

    v.clear(); // erases the entire vector

    cout << v.empty();

    vector<array<int, 3>> arr; // it makes vector of array where each array has 3 elements

    // LET'S LEARN lower_bound and upper_bound()
    vector<int> h = {1, 2, 3, 4, 7};
    auto it = lower_bound(all(h), 3) - h.begin();
    cout << it << endl; // 2
    auto it = lower_bound(all(h), 5) - h.begin();
    cout << it << endl; // 4
    auto it = lower_bound(all(h), 9) - h.begin();
    cout << it << endl; // 5
    auto it = upper_bound(all(h), 3) - h.begin();
    cout << it << endl; // 3
    auto it = upper_bound(all(h), 7) - h.begin();
    cout << it << endl; // 5

    // basically lower_bound return the pos of x if x is there else it returns the position of the
    // element just greater than x.
    // whereas upper_bound return the pos of the element just greater than x.

}


void explainList() { // use list when you want to insert at the front otherwise prefer vector as
    list<int> ls;    // it's complexities are better than list

    ls.push_back(2); // {2}
    ls.emplace_back(4); // {2, 4}

    ls.push_front(5); // {5, 2, 4};

    ls.emplace_front(); // {2, 4};

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}

void explainDeque() {

    deque<int>dq;
    dq.push_back(1); // {1}
    dq.emplace_back(2); // {1, 2}
    dq.push_front(4); // {4, 1, 2}
    dq.emplace_front(3); // {3, 4, 1, 2}

    dq.pop_back(); // {3, 4, 1}
    dq.pop_front(); // {4, 1}

    dq.back();

    dq.front();

    // rest functions same as vector
    // begin, end, rbegin, rend, clear, insert, size, swap
}


void explainStack() {
    stack<int> st;
    st.push(1); // {1}
    st.push(2); // {2, 1}
    st.push(3); // {3, 2, 1}
    st.push(3); // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    cout << st.top(); // prints 5  "** st[2] is invalid **"

    st.pop(); // st looks like {3, 3, 2, 1}

    cout << st.top(); // 3

    cout << st.size(); // 4

    cout << st.empty();

    stack<int>st1, st2;
    st1.swap(st2);
}

void explainQueue() {
    queue<int> q;
    q.push(1); // {1}
    q.push(2); // {1, 2}
    q.emplace(4); // {1, 2, 4}

    q.back() += 5;

    cout << q.back(); // prints 9

    // Q is {1, 2, 9}
    cout << q.front(); // prints 1

    q.pop(); // {2, 9}

    cout << q.front(); // prints 2

    // size swap empty same as stack
}

void explainPQ() {
    priority_queue<int>pq;

    pq.push(5); // {5}
    pq.push(2); // {5, 2}
    pq.push(8); // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    cout << pq.top(); // prints 10

    pq.pop(); // {8, 5, 2}

    cout << pq.top(); // prints 8

    // size swap empty function same as others

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(5); // {5}
    pq.push(2); // {2, 5}
    pq.push(8); // {2, 5, 8}
    pq.emplace(10); // {2, 5, 8, 10}

    cout << pq.top(); // prints 2

}

void explainSet() {
    set<int>st;
    st.insert(1); // {1}
    st.emplace(2); // {1, 2}
    st.insert(2); // {1, 2}
    st.insert(4); // {1, 2, 4}
    st.insert(3); // {1, 2, 3, 4}

    // Functionality of insert in vector
    // can be used also, that only increases
    // efficiency

    // begin(), end(), rbegin(), rend(), size(),
    // empty() and swap() are same as those of above

    // {1, 2, 3, 4, 5}
    auto it = st.find(3);

    // {1, 2, 3, 4, 5}
    auto it = st.find(6);

    // {1, 4, 5}
    st.erase(5); // erases 5 // takes logarithmic time


    int cnt = st.count(1);


    auto it = st.find(3);
    st.erase(it); // it takes constant time

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1, 4, 5} [first, last)

    // lower_bound() and upper_bound() function works in the same way
    // as in vector it does.

    // This is the syntax they return an iterator
    // vector<int> v = {1,3,5,7}
    auto it = st.lower_bound(2);
    cout << *it << endl; // 3
    auto it = st.lower_bound(6);
    cout << *it << endl; // 7
    auto it = st.lower_bound(8); //st.end()

    auto it = st.upper_bound(3);

    // you cannot erase the last element of set by doing this
    st.erase(st.rbegin());
    // to erase the last element of set you need to do something like this
    st.erase(prev(st.end()));
}

void explainMultiSet() {
    // Everything is same as set
    // only stores duplicate elements also


    multiset<int>ms;
    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    ms.erase(1); // all 1's erased

    int cnt = ms.count(1);

    // only a single one erased
    ms.erase(ms.find(1)); // O(log(size of multiset)) to find and then O(1) to erase

    // ms.find() returns ms.end() if the number is not present in the multiset

    // To get the maximum element in the multiset we do
    int max_ele_of_multiset = *prev(ms.end());

    ms.erase(ms.find(1), ms.find(1) + 2);

    // rest all function same as set
}

void explainUSet() {
    unordered_set<int> st;
    // lower_bound and upper_bound function
    // does not works, rest all functions are same
    // as above,  it does not stores in any
    // particular order it has a better complexity
    // than set in most cases, except some when collision happens
}

void explainMap() {

    // {key, value}
    map<int, int> mpp;

    map<int, pair<int, int>> mpp;

    map< pair<int, int>, int> mpp;

    // key values can be anything

    mpp[1] = 2;
    mpp.emplace({3, 1});

    mpp.insert({2, 4});

    mpp[ {2, 3}] = 10;

    {
        {1, 2}
        {2, 4}
        {3, 1}
    }

    for (auto it : mpp) {
        cout << it.first << " " << it.second << endl;
    }

    // same options for using iterators
    // as we did in vector for the insert function


    cout << mpp[1]; // prints 2
    cout << mpp[5]; // prints 0, since it does not exists


    auto it = mpp.find(3); // points to the position where 3 is found
    cout << *(it).second;

    auto it = mpp.find(5); // points to the end of the map since 5 not there

    // lower_bound and upper_bound works exactly in the
    // same way as explained in the other video

    // This is the syntax
    auto it = mpp.lower_bound(2);

    auto it = mpp.upper_bound(3);

    // erase, swap, size, empty, are same as above

}

void explainMultimap() {
    // everything same as map, only it can store multiple keys
    // only mpp[key] cannot be used here

}


void explainUnorderedMap() {
    // same as set and unordered_Set difference.
    unordered_map<int, int> mp;
    // to use pair in unordered map do this
    struct hash_pair {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2>& p) const
        {
            auto hash1 = hash<T1> {}(p.first);
            auto hash2 = hash<T2> {}(p.second);
            return hash1 ^ hash2;
        }
    };
    unordered_map<pair<int, int>, bool, hash_pair> um;
}

void explainBitSet() {
    // A bitset is an array of bool but each Boolean value is not stored separately instead bitset
    // optimizes the space such that each bool takes 1 bit space only, so space taken by bitset bs
    // is less than that of bool bs[N] and vector bs(N). However, a limitation of bitset is, N must
    // be known at compile time, i.e., a constant (this limitation is not there with vector and dynamic array)

    // NOTE : INDEXING IN BITSET STARTS FROM BACKWARDS

    const int size = 8;
    bitset<size> bset(); // 00000000
    bitset<size> bset1(7); // 0000000111
    bitset<size> bset2(string("10110")); // 00010110

    int num_of_set_bit = bset1.count(); // 3 i.e it counts the number of set bits

    int check_bit = bset2.test(1); // 1 i.e test returns 1 if bit is set at ith index

    int check_bit = bset1.any(); // 1 i.e any() returns 1 if at least one bit is set

    int check_bit = bset.none(); // 1 i.e none() returns 1 if none of the bit is set

    cout << bset.set(); // 11111111 i.e it will set bit at all the positions
    cout << bset.set(3, 0); // 00001000 i.e it sets the ith to whatever u assign
    cout << bset1.set(4); // 00001111 i.e by default it sets the bit to 1

    // similarly reset will set the bits to 0
    // flip will convert 1->0 and 0->1

    // u can apply bitwise operations on the whole bitset
    cout << bset1&bset2; // 00000110
}

bool comp(pair<int, int>p1, pair<int, int>p2) {
    if (p1.second < p2.second) {
        return true;
    } else if (p1.second == p2.second) {
        if (p1.first > p2.second) return true;
    }
    return false;
}

struct fraction {
    int p, q;
    fraction(int num, int den) : p(num), q(den) {}
    bool operator<(const fraction &other)const {
        int val = (((int)q * other.p) < ((int)other.q * p));
        return val;
    }
    bool operator<=(const fraction &other)const {
        int val = (((int)q * other.p) <= ((int)other.q * p));
        return val;
    }
};

void explainExtra() {

    sort(a + 2, a + 4); // [first, last)

    sort(a, a + n, greater<int>);

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

    // sort it according to second element
    // if second element is same, then sort
    // it according to first element but in descending

    sort(a, a + n , comp);

    // {4,1}, {2, 1}, {1, 2}};


    int num = 7; // 111
    int cnt = __builtin_popcount();

    long long num = 165786578687;
    int cnt = __builtin_popcountll();


    string s = "123";

    do {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));

    // 123
    // 132
    // 213
    // 231
    // 312
    // 321

    int maxi = *max_element(a, a + n);

    /*std::any_of
    This is a very useful function that returns true iff any of the elements in the range [first, last)
    satisfies some condition. Let's say you want to figure out if an array contains at least one 9.*/
    bool ok = any_of(a.begin(), a.end(), [](int x) { return x == 9; });

    /*std::all_of
    This is another useful function that functions similar to std::any_of. The difference is that it
    returns true iff all the elements in the range [first, last) follow some condition.*/
    bool ok = all_of(a.begin(), a.end(), [](int x) { return x == 9; });

    /*std::none_of
    This is yet another function that is close relatives of the two mentioned above. This function returns true
    iff all the elements does not follow some condition.*/
    bool ok = none_of(a.begin(), a.end(), [](int x) { return x == 9; });

    /*std::count
    This functions counts the number of elements in the range [first, last) that are equal to some variable val.*/
    int cnt = count(a.begin(), a.end(), x);

    /*std::find
    This function returns the first iterator that compares equal to val.*/
    int hld = find(a.begin(), a.end(), x) - a.begin();
}


int main() {

    return 0;
}

