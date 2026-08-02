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

    bool isSymmetricII(TreeNode* left, TreeNode* right){
        if (left == nullptr && right == nullptr) return true;

        if (left == nullptr || right == nullptr) return false;

        if(left->val != right->val) return false;

        bool caseOne = isSymmetricII(left->left, right->right);
        bool caseTwo = isSymmetricII(left->right, right->left);

    return caseOne && caseTwo;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        bool check = true;
        check = isSymmetricII(root->left, root->right);
        
    return check;    
    }
};