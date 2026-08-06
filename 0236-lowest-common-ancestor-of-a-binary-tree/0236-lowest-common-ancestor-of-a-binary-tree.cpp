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
        if(!node) return 0;

        int left = solve(node->left, p, q);
        int right = solve(node->right, p, q);

        int self = 0;
        if(node == p || node == q){
            self = 1;
        }

        int total = left+ right+ self;

        if(total == 2 && !ans){
            ans = node;
        }
    return total;
    }
    

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root, p, q);
    return ans;
    }
};