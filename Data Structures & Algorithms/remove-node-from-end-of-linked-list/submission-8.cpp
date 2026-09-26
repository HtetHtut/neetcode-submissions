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
        // okay so I think I want to keep track of two nodes at once
        // n node and furthest node
        // I'll keep chunking furthest node down until the furthest node is n + 1 away from n node
        // then I move them both down, if furthest node

        ListNode* furthest_node = head;
        ListNode* n_node = head;
        ListNode* last_node = head;

        int node_delta = 0;
        int total_size = 0;
        while (furthest_node != nullptr){
            furthest_node = furthest_node->next;
            node_delta++;
            total_size++;
            last_node = n_node;
            if (node_delta > n){
                n_node = n_node->next;
                node_delta--;
            }
            
        }
        if(node_delta < n){
            return nullptr;
        }
        if(total_size == node_delta){
            return head->next;
        }
        last_node->next = n_node->next;
        return head;
    }
};
