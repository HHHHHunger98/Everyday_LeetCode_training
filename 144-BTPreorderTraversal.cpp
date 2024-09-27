#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

struct TreeNode
{   
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void genBTFromArrPreorder(TreeNode* &curNode, vector<int>& arr, int &cur){
        
        if ( cur < size(arr) && arr[cur] == 0)
        {
            curNode = NULL;
            cur++;
            return;
        }else if (cur < size(arr)){
            TreeNode* node = new TreeNode(arr[cur]);
            curNode = node;
            cur++;
            genBTFromArrPreorder(curNode->left, arr, cur);
            genBTFromArrPreorder(curNode->right, arr, cur);
        }
    }

    void preTree(vector<int> &res, TreeNode *root) {
        if (root == NULL)
        {
            return;
        }else {
            res.push_back(root->val);
            preTree(res, root->left);
            preTree(res, root->right);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preTree(res, root);
        return res;
    }
};

int main() {

    vector<int> arr = {1,0,2,3};
    TreeNode* t = NULL;
    Solution s;
    int cur = 0;
    s.genBTFromArrPreorder(t, arr, cur);
    vector<int> res = s.preorderTraversal(t);
    for(auto i : res){
        cout << i << ' ';
    }
    return 0;
}