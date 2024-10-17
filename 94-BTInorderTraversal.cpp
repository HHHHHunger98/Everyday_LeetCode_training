#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{

    public:
        Solution() {}
        ~Solution() {}
        void inorderT(vector<int> &res, TreeNode *root){
            if (root == nullptr)
            {
                return ;
            }else{
                inorderT(res, root->left);
                res.push_back(root->val);
                inorderT(res, root->right);
            }
        }
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            inorderT(res, root);

            return res;
        }

};

int main() {

    return 0;
}