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

    vector<int> findTarget(unordered_map<int,int> &found, int n, int k){
        for(int i = 0 ; i < n; i++){
            int needed = k - nodes[i];
            if(found.find(needed) != found.end()){
                return {found[needed], i};
            }
            found[nodes[i]] = i;
        }

    return {};
    }

    bool findTarget(TreeNode* root, int k) {
        inOrder(root);

        unordered_map<int,int> found;        
        int n = nodes.size();
        vector<int> res = findTarget(found, n, k);
        
        return (res.size() == 2) ? true : false;
    }
};