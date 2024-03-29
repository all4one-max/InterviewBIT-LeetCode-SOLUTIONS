/**
* Implement splay trees
*
*/
#include <iostream>
#include <vector>
using namespace std;
// Node structure
struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
};


typedef Node *NodePtr;


// class SplayTree
class SplayTree {
private:
    NodePtr root;


    void preOrderHelper(NodePtr node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrderHelper(node->left);
            preOrderHelper(node->right);
        }
    }


    void inOrderHelper(NodePtr node) {
        if (node != nullptr) {
            inOrderHelper(node->left);
            cout << node->data << " ";
            inOrderHelper(node->right);
        }
    }


    void postOrderHelper(NodePtr node) {
        if (node != nullptr) {
            postOrderHelper(node->left);
            postOrderHelper(node->right);
            cout << node->data << " ";
        }
    }


    NodePtr searchTreeHelper(NodePtr node, int key) {
        if (node == nullptr || key == node->data) {
            return node;
        }


        if (key < node->data) {
            return searchTreeHelper(node->left, key);
        }
        return searchTreeHelper(node->right, key);
    }


    void deleteNodeHelper(NodePtr node, int key) {
        NodePtr x = nullptr;
        NodePtr t, s;
        while (node != nullptr) {
            if (node->data == key) {
                x = node;
            }


            if (node->data <= key) {
                node = node->right;
            } else {
                node = node->left;
            }
        }


        if (x == nullptr) {
            cout << "Couldn't find key in the tree" << endl;
            return;
        }
        split(x, s, t); // split the tree
        if (s->left) { // remove x
            s->left->parent = nullptr;
        }
        root = join(s->left, t);
        delete(s);
        s = nullptr;
    }


    void printHelper(NodePtr root, string indent, bool last) {
        // print the tree structure on the screen
        if (root != nullptr) {
            cout << indent;
            if (last) {
                cout << "└────";
                indent += "     ";
            } else {
                cout << "├────";
                indent += "|    ";
            }


            cout << root->data << endl;


            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }


    // rotate left at node x
    void leftRotate(NodePtr x) {
        NodePtr y = x->right;
        x->right = y->left;
        if (y->left != nullptr) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }


    // rotate right at node x
    void rightRotate(NodePtr x) {
        NodePtr y = x->left;
        x->left = y->right;
        if (y->right != nullptr) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }


    // splaying
    void splay(NodePtr x) {
        while (x->parent) {
            if (!x->parent->parent) {
                if (x == x->parent->left) {
                    // zig rotation
                    rightRotate(x->parent);
                } else {
                    // zag rotation
                    leftRotate(x->parent);
                }
            } else if (x == x->parent->left && x->parent == x->parent->parent->left) {
                // zig-zig rotation
                rightRotate(x->parent->parent);
                rightRotate(x->parent);
            } else if (x == x->parent->right && x->parent == x->parent->parent->right) {
                // zag-zag rotation
                leftRotate(x->parent->parent);
                leftRotate(x->parent);
            } else if (x == x->parent->right && x->parent == x->parent->parent->left) {
                // zig-zag rotation
                leftRotate(x->parent);
                rightRotate(x->parent);
            } else {
                // zag-zig rotation
                rightRotate(x->parent);
                leftRotate(x->parent);
            }
        }
    }


    // joins two trees s and t
    NodePtr join(NodePtr s, NodePtr t) {
        if (!s) {
            return t;
        }


        if (!t) {
            return s;
        }
        NodePtr x = maximum(s);
        splay(x);
        x->right = t;
        t->parent = x;
        return x;
    }


    // splits the tree into s and t
    void split(NodePtr &x, NodePtr &s, NodePtr &t) {
        splay(x);
        if (x->right) {
            t = x->right;
            t->parent = nullptr;
        } else {
            t = nullptr;
        }
        s = x;
        s->right = nullptr;
        x = nullptr;
    }


public:
    SplayTree() {
        root = nullptr;
    }


    // Pre-Order traversal
    void preorder() {
        preOrderHelper(this->root);
    }


    // In-Order traversal
    void inorder() {
        inOrderHelper(this->root);
    }


    // Post-Order traversal
    void postorder() {
        postOrderHelper(this->root);
    }


    // search the tree for the key k
    NodePtr searchTree(int k) {
        NodePtr x = searchTreeHelper(this->root, k);
        if (x) {
            splay(x);
        }
        return x;
    }


    // find the node with the minimum key
    NodePtr minimum(NodePtr node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }


    // find the node with the maximum key
    NodePtr maximum(NodePtr node) {
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }


    // find the successor of a given node
    NodePtr successor(NodePtr x) {
        if (x->right != nullptr) {
            return minimum(x->right);
        }


        NodePtr y = x->parent;
        while (y != nullptr && x == y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }


    // find the predecessor of a given node
    NodePtr predecessor(NodePtr x) {
        if (x->left != nullptr) {
            return maximum(x->left);
        }


        NodePtr y = x->parent;
        while (y != nullptr && x == y->left) {
            x = y;
            y = y->parent;
        }


        return y;
    }


    void insert(int key) {
        NodePtr node = new Node;
        node->parent = nullptr;
        node->left = nullptr;
        node->right = nullptr;
        node->data = key;
        NodePtr y = nullptr;
        NodePtr x = this->root;


        while (x != nullptr) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }


        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }


        splay(node);
    }


    NodePtr getRoot() {
        return this->root;
    }


    void deleteNode(int data) {
        deleteNodeHelper(this->root, data);
    }


    void prettyPrint() {
        printHelper(this->root, "", true);
    }


};


int main() {
    vector<int> arr;
    SplayTree st;
    for (int i = 0; i < 10; i++) {
        int k = rand() % 100;
        cout << "Inserting " << k << endl;
        arr.push_back(k);
        st.insert(k);
        st.inorder();
        cout << endl << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << "Deleting " << arr[i] << endl;
        st.deleteNode(arr[i]);
        st.inorder();
        cout << endl << endl;
    }
    return 0;
}
