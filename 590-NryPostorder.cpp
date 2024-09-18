#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
public:

    int val;
    vector<Node*> children;

    Node() {};
    Node(int _val) {
        val = _val;
    };
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    };
    ~Node() {};
};

class solution {
public:

    vector<int> result;

    Node* createFromString(vector<int> &NryTree) {

        Node *root;
        Node *tail = root;
        for (int i = 0; i < NryTree.size(); i++) {
            if (NryTree[i] != -1)
            {
                tail->val = NryTree[i];
            }
            
        }
        
    };

    vector<int> postorder(Node* root) {

        if (root->children.empty()) {
            result.push_back(root->val);
            cout << root->val;
        }
        else {
            for (int i = 0; i < root->children.size(); i++) {
                postorder(root->children[0]);
            }
        }
    }
};

