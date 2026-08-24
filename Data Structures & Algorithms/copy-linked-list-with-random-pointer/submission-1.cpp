/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> hash_map;

        Node* curr = head;
        while (curr != nullptr) {
            hash_map[curr] = new Node(curr -> val);
            curr = curr -> next;
        }

        curr = head;
        while (curr != nullptr) {
            Node* curr_new = hash_map[curr];
            curr_new -> next = hash_map[curr -> next];
            curr_new -> random = hash_map[curr -> random];
            curr = curr -> next;
        }

        return hash_map[head];
    }
};
