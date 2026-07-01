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
        ListNode* dummy = new ListNode(0,head);

        if (head == NULL || head->next == NULL) return head;

        ListNode* before = dummy;

        for (int i =1; i < left; i++){
            before = before->next;
        }

        ListNode* lastRev = before->next;

        ListNode* prev = NULL;
        ListNode* curr = before->next;

        for (int i = 1; i <= right-left+1;i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        before->next = prev;
        lastRev->next = curr;

    return dummy->next;

    }
};