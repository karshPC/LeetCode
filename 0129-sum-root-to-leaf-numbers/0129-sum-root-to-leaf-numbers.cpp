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

    int sum =0;
    vector<int> diary;


    void calculateSum(){
        int n = diary.size();
        for(int i = 0; i < n; i++){
            sum += diary[i];
        }
    return;
    }

    void solve(TreeNode* node, int localSum){
        if(!node) return;

        localSum = localSum * 10 + node->val;

        if(node->left == nullptr && node->right == nullptr){
            diary.push_back(localSum);
        }

        solve(node->left, localSum);
        solve(node->right, localSum);

    return;
    }

    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        calculateSum();
    return sum;
    }
};