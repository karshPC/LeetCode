/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode* temp = head;
        vector<ListNode* > seen;
        
        while(temp){
            seen.push_back(temp);
            temp = temp->next;
        }
    
        int left = 0, right = seen.size()-1;

        while(left<=right){
            if (seen[left]->val != seen[right]->val){
                return false;
            }
            left++;
            right--;
        }

    return true;
    }
};