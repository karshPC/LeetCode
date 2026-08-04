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

    vector<vector<int>> res;

    void solve(TreeNode* node){
        queue<TreeNode*> q;
        q.push(node);
        bool leftToRight = true;

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> temp(levelSize);
            
            int start = 0;
            int end = levelSize-1;
            
            while(levelSize--){
                TreeNode* t = q.front();
                q.pop();

                if(leftToRight){
                    temp[start] = t->val;
                    start++;
                }
                else{
                    temp[end] = t->val;
                    end--;
                }

                if(t->left != nullptr) q.push(t->left);
                if(t->right!= nullptr) q.push(t->right);
            }
            
            res.push_back(temp);
            leftToRight = !leftToRight;
        }
    return;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        solve(root);
    return res;
    }
};