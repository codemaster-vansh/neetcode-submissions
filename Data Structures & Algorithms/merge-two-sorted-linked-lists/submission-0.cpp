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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode* current = nullptr;
        ListNode* toret = nullptr;

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        if (curr1 -> val <= curr2 -> val) {
            current = curr1;
            curr1 = curr1 -> next;
        } else {
            current = curr2;
            curr2 = curr2 -> next;
        }

        toret = current;

        while (curr1 != nullptr && curr2 != nullptr) {
            if (curr1 -> val <= curr2 -> val) {
                current -> next = curr1;
                curr1 = curr1 -> next;
            } else {
                current -> next = curr2;
                curr2 = curr2 -> next;
            }
            current = current -> next;
        }

        if (curr1 == nullptr) {
            while (curr2 != nullptr) {
                current -> next = curr2;
                curr2 = curr2 -> next;
                current = current -> next;
            }
        }

        if (curr2 == nullptr) {
            while (curr1 != nullptr) {
                current -> next = curr1;
                curr1 = curr1 -> next;
                current = current -> next;
            }
        }

        return toret;
    }
};
