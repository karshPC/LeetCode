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

    bool solve(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr) return false;
        if(left->val != right->val) return false;

        bool check1 = solve(left->left, right->right);
        bool check2 = solve(left->right, right->left);
    return check1 && check2;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        bool check = true;
        check = solve(root->left, root->right);
    return check;
    }
};