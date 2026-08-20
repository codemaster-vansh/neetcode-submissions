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
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return false;
        ListNode* hare = head;
        ListNode* tortoise = head;

        while (hare != nullptr) {
            hare = hare -> next;
            if (hare != nullptr) hare = hare -> next;
            tortoise = tortoise -> next;
            if (hare == tortoise) return true;
        }

        return false;
    }
};
