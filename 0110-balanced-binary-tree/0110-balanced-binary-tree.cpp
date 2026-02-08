/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL)    return 0;
        int lst = levels(root->left);
        int rst = levels(root->right);
        int res = 1 + max(lst, rst);
        return res;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int lst = levels(root->left);
        int rst = levels(root->right);
        if(abs(lst-rst) > 1)    
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};