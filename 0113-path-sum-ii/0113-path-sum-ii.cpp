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

    vector<vector<int>> result;

    void solve(TreeNode* node, vector<int> &temp,int sum, int targetSum){
        if(node == nullptr) return;

        temp.push_back(node->val);
        sum+= node->val;


        if(node->left == nullptr && node->right == nullptr){
            if(sum == targetSum){
                result.push_back(temp);
            }
        }
        
        solve(node->left, temp, sum, targetSum);
        solve(node->right, temp, sum, targetSum);

        temp.pop_back();

    return;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> temp;
        solve(root, temp, 0, targetSum);
    return result;
    }
};