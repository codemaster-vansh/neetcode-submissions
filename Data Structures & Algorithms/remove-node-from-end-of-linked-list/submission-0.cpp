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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head -> next == nullptr) return nullptr;
        int len = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            curr = curr -> next;
            len++;
        }

        int x = len - n;

        curr = head;
        ListNode dummy = ListNode(0);
        dummy.next = curr;
        ListNode* prev = &dummy;

        for (int i = 0;i < x;i++) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;
        curr -> next = nullptr;

        return dummy.next;
    }
};
