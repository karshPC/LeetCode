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
    ListNode* reverseList(ListNode* head) {
        vector<ListNode*> seen;
        ListNode* temp = head;
        while(temp){
            seen.push_back(temp);
            temp = temp->next;
        }

        if(seen.empty()) return NULL;
        
        int left = 0, right = seen.size()-1;
        while(left<=right){
            if (left == right) break;
            swap(seen[left], seen[right]);
            left++;
            right--;
        }
        for (int i =0; i<seen.size()-1;i++){
            seen[i]->next = seen[i+1];
        }
        seen.back()->next = nullptr;

    return seen[0];
    }
};