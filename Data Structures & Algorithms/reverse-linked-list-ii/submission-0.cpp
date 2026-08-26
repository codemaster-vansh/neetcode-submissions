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
        ListNode dummy1(0);
        dummy1.next = head;

        ListNode* prev = &dummy1;
        ListNode* curr = head;

        for (int i = 1;i < left;i++) {
            prev = curr;
            curr = curr -> next;
        }

        ListNode* range_tail = curr;
        ListNode* range_head_node = prev;
        ListNode* next_node = curr -> next;

        for (int i = 0;i < right - left + 1;i++) {
            if (curr == nullptr) break;

            curr -> next = prev;
            prev = curr;
            curr = next_node;
            if (curr) 
                next_node = curr -> next;
        }

        // if (curr == nullptr) // What to do here?

        ListNode* range_tail_node = curr;
        range_head_node -> next = prev;

        range_tail -> next = range_tail_node;

        return dummy1.next;
    }
};