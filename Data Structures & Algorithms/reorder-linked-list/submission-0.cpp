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
        if (head == nullptr || head -> next == nullptr) return;

        ListNode* fast = head;
        ListNode* prev_slow = nullptr;
        ListNode* slow = head;

        while (fast && fast -> next) {
            fast = fast -> next -> next;
            prev_slow = slow;
            slow = slow -> next;
        }

        prev_slow -> next = nullptr;

        ListNode* next_node;
        ListNode* prev_node = nullptr;
        ListNode* curr = slow;

        while (curr) {
            next_node = curr -> next;
            curr -> next = prev_node;
            prev_node = curr;
            curr = next_node;
        }

        ListNode* r = prev_node;
        ListNode* l = head;

        ListNode* curr_tracker = head;
        ListNode* toret = curr_tracker;
        l = l -> next;

        bool flag = false;
        while (l != nullptr && r != nullptr) {
            if (!flag) {
                curr_tracker -> next = r;
                curr_tracker = curr_tracker -> next;
                r = r -> next;
            }

            if (flag) {
                curr_tracker -> next = l;
                curr_tracker = curr_tracker -> next;
                l = l -> next;
            }

            flag ^= 1;
        }

        while (r != nullptr) {
            curr_tracker -> next = r;
            r = r -> next;
            curr_tracker = curr_tracker -> next;
        }

        return;
    }
};
