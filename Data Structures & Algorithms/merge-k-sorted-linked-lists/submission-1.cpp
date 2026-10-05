#include <queue>
#include <vector>

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap comparator: smaller val has higher priority
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

        // 1. Seed the heap with the head of each non-empty list
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        // 2. Extract min, splice, and push the next element
        while (!pq.empty()) {
            ListNode* smallest = pq.top();
            pq.pop();

            // Splice onto the merged chain
            tail->next = smallest;
            tail = tail->next;

            // If this list has a successor, push it to replace the extracted node
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};