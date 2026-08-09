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

    bool result;

    void solve(TreeNode* node, int sum, int targetSum){
        if(node == nullptr) return;

        sum = sum+ node->val;

        if(node->left == nullptr && node->right == nullptr){
            if(sum == targetSum){
                result = true;
                return;
            }
        }

        solve(node->left, sum, targetSum);
        solve(node->right, sum, targetSum);
    
    return;
    }   

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        solve(root,0, targetSum);
    
    return result;
    }
};