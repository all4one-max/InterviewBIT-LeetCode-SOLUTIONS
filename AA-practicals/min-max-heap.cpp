#include<bits/stdc++.h>
using namespace std;

class MinHeap {
    vector<int> tree;
public:
    void push(int val) {
        tree.push_back(val);
        heapifyUp(tree.size() - 1);
    }
    void heapifyUp(int idx) {
        while (tree[(idx - 1) / 2] > tree[idx]) {
            swap(tree[(idx - 1) / 2], tree[idx]);
            idx = (idx - 1) / 2;
        }
    }
    int peek() {
        if (tree.size() == 0) throw new runtime_error("The heap is empty");
        return tree[0];
    }
    void remove(int val) {
        auto it = find(tree.begin(), tree.end(), val);
        if (it == tree.end()) throw new invalid_argument("Value not present in heap");
        int idx = it - tree.begin();
        swap(tree[idx], tree[tree.size() - 1]);
        tree.pop_back();
        heapifyDown(idx);
    }
    void heapifyDown(int idx) {
        while (idx < tree.size()) {
            int left = 2 * idx + 1, right = 2 * idx + 2;
            int leftVal = left >= tree.size() ? INT_MAX : tree[left];
            int rightVal = right >= tree.size() ? right = INT_MAX : tree[right];
            if (min(leftVal, rightVal) < tree[idx]) {
                if (leftVal == min(leftVal, rightVal)) {
                    swap(tree[left], tree[idx]);
                    idx = left;
                }
                else {
                    swap(tree[right], tree[idx]);
                    idx = right;
                }
            }
            else return;
        }
    }
    void pop() {
        remove(tree[0]);
    }
};
void heapSort(vector<int> &arr) {
    MinHeap minHeap;
    for (int &val : arr) minHeap.push(val);
    for (int i = 0; i < arr.size(); ++i) {
        cout << minHeap.peek() << " ";
        minHeap.pop();
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)cin >> arr[i];
    cout << "Sorted array ";
    heapSort(arr);
}
