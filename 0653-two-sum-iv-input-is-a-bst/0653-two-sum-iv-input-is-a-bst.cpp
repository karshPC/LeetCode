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

        int left = 0;
        int right = nodes.size() -1;

        while(left < right){
            if(nodes[left] + nodes[right] == k){
                return true;
            }
            else if(nodes[left] + nodes[right] <k){
                left++;
            }
            else if(nodes[left] + nodes[right] > k){
                right--;
            }
        }        
    return false;
    }
};