class Solution {
public:

    int solve(TreeNode* node, int currentSum){
        if(node == nullptr) return 0;

        currentSum = currentSum * 10 + node->val;
        
        if(node->left == nullptr && node->right == nullptr){
            return currentSum;
        }

        return solve(node->left, currentSum) + solve(node->right, currentSum);
    }

    int sumNumbers(TreeNode* root) {
        int res = solve(root, 0);
    return res;
    }
};