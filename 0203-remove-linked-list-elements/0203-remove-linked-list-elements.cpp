class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while(curr){
            if(curr->val == val){
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
    ListNode* ans = dummy->next;
    delete dummy;
    return ans;
    }
};