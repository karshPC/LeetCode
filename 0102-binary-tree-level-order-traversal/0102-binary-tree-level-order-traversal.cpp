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

    void solve(TreeNode* node){
        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> temp;
            while(levelSize--){
                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if(t->left != nullptr) q.push(t->left);
                if(t->right!= nullptr) q.push(t->right);
            }
        result.push_back(temp);
        }
    return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        solve(root);
    return result;
    }
};