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

    vector<int> result; // 1 2 3 4

    void solve(TreeNode* node){
        if(node == nullptr) return;

        solve(node->left);
        result.push_back(node->val);
        solve(node->right);
    
    return;
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;
        solve(root);

        int n = result.size();

    return result[k-1];
    }   
};