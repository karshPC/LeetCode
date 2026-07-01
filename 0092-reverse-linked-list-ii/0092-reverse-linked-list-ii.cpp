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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0, head);

        // Move to the node just before 'left'
        ListNode* before = dummy;
        for (int i = 1; i < left; i++) {
            before = before->next;
        }

        // Reverse the sublist
        ListNode* prev = nullptr;
        ListNode* curr = before->next;
        ListNode* revLast = curr;

        for (int i = 1; i <= right - left + 1; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Reconnect the reversed part
        before->next = prev;
        revLast->next = curr;

        return dummy->next;
    }
};