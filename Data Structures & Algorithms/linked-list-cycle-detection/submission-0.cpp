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
        if (head == nullptr) return false;

        bool cycle_found = false;
        unordered_set<int> found_values{};
        while(!cycle_found && head->next != nullptr){
            if(!found_values.contains(head->val)){
                found_values.insert(head->val);
            }
            else{
                cycle_found = true;
            }
            head = head->next;
        }
        return cycle_found;
    }
};
