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

    bool isSymmetricII(TreeNode* nodeLeft, TreeNode* nodeRight){

        if(nodeLeft == nullptr && nodeRight == nullptr)
            return true;

        if(nodeLeft == nullptr || nodeRight == nullptr)
            return false;

        if(nodeLeft->val != nodeRight->val)
            return false;

        bool left = isSymmetricII(nodeLeft->left, nodeRight->right);
        bool right = isSymmetricII(nodeLeft->right, nodeRight->left);

        return left && right;
    }

    bool isSymmetric(TreeNode* root) {

        if(root == nullptr)
            return true;

        return isSymmetricII(root->left, root->right);
    }
};