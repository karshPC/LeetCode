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

    bool isSameTree(TreeNode* p, TreeNode* q) { 
        if(p == nullptr && q == nullptr) return true;
        if((p == nullptr && q != nullptr) || (q == nullptr && p != nullptr)) return false;

        bool left = false;
        bool right = false;
        if (p != nullptr && q != nullptr){
            if(p->val != q->val) return false;
            left = isSameTree(p->left, q->left);
            right = isSameTree(p-> right, q->right);
        }

    return (left== false || right ==false) ? false : true;
    }
};                                         