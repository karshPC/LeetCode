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

    bool result = true;

    int solve(TreeNode* node){
        if(!node) return 0;
        int left = solve(node->left);
        int right = solve(node->right);
        if(abs(left-right) > 1) result = false;       

        return 1+ max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        solve(root);
    return result;
    }
};