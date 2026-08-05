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

    TreeNode* ans = nullptr;

    void solve(TreeNode* node, int val){
        if(node == nullptr){
            return;
        }
    
        if(node->val == val){
            ans = node;
            return;
        }

        if(node->val < val){
            solve(node->right, val);
        }
        else{
            solve(node->left, val);
        }

    return;
    }


    TreeNode* searchBST(TreeNode* root, int val) {
        solve(root, val);
    return ans;
    }
};