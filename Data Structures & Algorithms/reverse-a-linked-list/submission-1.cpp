class Solution {
// Okay I think I want to go all the way down
// then I want to reverse and iterate back up
// so I will use a while loop
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* prev_node = nullptr;
        while(head != nullptr){
            // keep a context of 3 nodes, previous, current, next
            ListNode* next_node = head->next;
            // point the current node at the previous
            head->next = prev_node;
            // make the current node the next previous node
            prev_node = head;
            // make the current node the next node
            head = next_node;
        }
        
        return prev_node;
    }
};
