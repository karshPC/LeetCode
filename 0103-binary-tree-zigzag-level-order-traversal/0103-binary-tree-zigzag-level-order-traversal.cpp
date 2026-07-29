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
        if(node == nullptr) return;
        queue<TreeNode*> q;
        
        int leftToRight = 1; //ZigZag
        q.push(node);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> temp(levelSize);
            
            int first = 0; // ZigZag
            int last = levelSize -1; // ZigZag

            while(levelSize--){
                TreeNode* t = q.front();
                q.pop();

                if(leftToRight){
                    temp[first] = t->val;
                    first++;
                }
                else{
                    temp[last] = t->val;
                    last--;
                }

                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
            }
        res.push_back(temp);
        leftToRight = 1 - leftToRight;
        }
    return;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        solve(root);
    return res;
    }
};