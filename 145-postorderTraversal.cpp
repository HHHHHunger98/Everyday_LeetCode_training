#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void postTree(TreeNode *cur, vector<int> &res) {

        if (cur==NULL)
        {
            return;
        }else {
            postTree(cur->left, res);
            postTree(cur->right, res);
            res.push_back(cur->val);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postTree(root, res);
        return res;
    }
};