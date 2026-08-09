/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    stack <TreeNode*> asc;
    stack <TreeNode*> dsc;

    TreeNode* getSmall(){
        if(asc.empty()) return nullptr;

        TreeNode* small = asc.top();
        asc.pop();
        
        TreeNode* right = small->right;
        while(right){
            asc.push(right);
            right = right->left;
        }
        
        return small;
    }

    TreeNode* getBig(){
        if(dsc.empty()) return nullptr;
        
        TreeNode* big = dsc.top();
        dsc.pop();

        TreeNode* left = big->left;
        while(left){
            dsc.push(left);
            left = left->right;
        }
    return big;
    }

    bool findTarget(TreeNode* root, int k) {
        TreeNode* t = root;
        while(t){
            asc.push(t);
            t = t->left;    
        }

        t = root;

        while(t){
            dsc.push(t);
            t = t->right;
        }

        TreeNode* i = getSmall();
        TreeNode* j = getBig();

        while(i && j && i != j && i->val < j->val){
            int sum = i->val + j->val;
            if(sum == k){
                return true;
            }
            
            else if(i->val + j->val < k){
                i = getSmall();
            }

            else{
                j = getBig();
            }
        }

    return false;
    }
};