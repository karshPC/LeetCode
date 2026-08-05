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

    vector<int> nodes;

    void inOrder(TreeNode* node){
        if(!node) return;

        inOrder(node->left);
        nodes.push_back(node->val);
        inOrder(node->right);
    
    return;
    }

    bool findTarget(TreeNode* root, int k) {
        inOrder(root);

        unordered_map<int,int> found;        
        int n = nodes.size();
        
        for(int i = 0 ; i < n; i++){
            int needed = k - nodes[i];
            if(found.find(needed) != found.end()){
                return true;
            }
            found[nodes[i]] = i;
        }

    return false;       
    }
};