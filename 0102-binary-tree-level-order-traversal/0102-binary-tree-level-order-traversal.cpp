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

    void solve(TreeNode* node, vector<vector<int>> &res){
        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty()){
            int lvlsize = q.size();
            vector<int> temp;
            for(int i = 0; i < lvlsize; i++){
                TreeNode* t = q.front();
                q.pop();

                temp.push_back(t->val);

                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
            }
        res.push_back(temp);
        }
    return;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> res;
        solve(root, res);
    return res;
    }
};