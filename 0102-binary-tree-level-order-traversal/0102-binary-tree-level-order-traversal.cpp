class Solution {
public:
    vector<vector<int>> res;

    void solve(TreeNode* node){
        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> temp;
            while(lvlSize--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
            }
        res.push_back(temp);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        solve(root);
    return res;
    }
};