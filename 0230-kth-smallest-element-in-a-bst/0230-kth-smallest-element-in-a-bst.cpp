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

    priority_queue<int> pq;

    void solve(TreeNode* node, int k){
        if(node == nullptr) return;
        
        pq.push(node->val);

        if(pq.size() >k){
            pq.pop();
        }

        solve(node->left, k);
        solve(node->right, k);
    
    return;
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr) return 0;
        solve(root, k);
    return pq.top();
    }   
};