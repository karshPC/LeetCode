/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* ans = nullptr;

    int solve(TreeNode* node, TreeNode* p, TreeNode* q){
        if(!node){
            return 0;
        }

        int leftCheck = solve(node->left, p,q);
        int rightCheck = solve(node->right, p, q);

        int self =0;
        if(node == q || node == p){
            self =1;
        }

        int total = leftCheck + rightCheck + self;

        if(total == 2 && !ans){
            ans = node;
        }
        
    return min(total, 2);;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
    return ans;
    }
};