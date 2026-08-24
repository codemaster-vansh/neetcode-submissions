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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr_new = &dummy;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        int carry = 0;

        while (curr1 != nullptr && curr2 != nullptr) {
            int sum1 = curr1 -> val + curr2 -> val + carry;
            carry = sum1 / 10;
            int rem = sum1 % 10;
            curr_new -> next = new ListNode(rem);
            curr_new = curr_new -> next;
            curr1 = curr1 -> next;
            curr2 = curr2 -> next;
        }

        while (curr1 != nullptr) {
            int sum1 = curr1 -> val + carry;
            carry = sum1 / 10;
            int rem = sum1 % 10;
            curr_new -> next = new ListNode(rem);
            curr_new = curr_new -> next;
            curr1 = curr1 -> next;
        }

        while (curr2 != nullptr) {
            int sum1 = curr2 -> val + carry;
            carry = sum1 / 10;
            int rem = sum1 % 10;
            curr_new -> next = new ListNode(rem);
            curr_new = curr_new -> next;
            curr2 = curr2 -> next;
        }

        if (carry != 0) {
            curr_new -> next = new ListNode(carry);
        }

        return dummy.next;
    }
};
