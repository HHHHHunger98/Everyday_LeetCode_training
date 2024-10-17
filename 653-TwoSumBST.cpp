#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traversel(TreeNode* root, vector<int> &res) {
    if (root == nullptr){
        return;
    }else {
        res.push_back(root->val);
        traversel(root->left, res);
        traversel(root->right, res);
    }
}

bool findTarget(TreeNode* root, int k) {
    
    vector<int> res;
    traversel(root, res);

    for (auto i : res)
    {
        for (auto j : res){
            if(i!=j && i + j == k){
                return true;
            }
        }
    }
    
    return false;
}

// Using Hash Map to store the traversal result, and check whether the diff: k - root->val in the map.


int main () {

    return 0;
}