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
    void reorderList(ListNode* head) {
        
        vector<ListNode*> nodes;
        ListNode* temp = head;

        while(temp){
            nodes.push_back(temp);
            temp = temp->next;
        }

        int low = 0, high = nodes.size()-1;

        while(low<high){
            nodes[low]->next = nodes[high];
            low++;

            if (low == high) break;

            nodes[high]->next = nodes[low];
            high--;
            
        }
    nodes[low]->next = nullptr;
    }
};