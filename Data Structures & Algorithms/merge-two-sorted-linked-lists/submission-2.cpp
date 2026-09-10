class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        if(list1 == nullptr && list2 != nullptr) return list2;
        if(list1 != nullptr && list2 == nullptr) return list1;
        
        // pick the smallest node to start off
        ListNode* first_node;
        if(list1->val <= list2->val){
            first_node = list1;
            list1 = list1->next;
        }else{
            first_node = list2;
            list2 = list2->next;
        }

        ListNode* next_node = first_node;
        while(list1 != nullptr || list2 != nullptr){
            if(list1 == nullptr && list2 != nullptr){
                next_node->next = list2;
                return first_node;
            }
            if(list1 != nullptr && list2 == nullptr){
                next_node->next = list1;
                return first_node;
            }
            // if they're both not pointers go ahead and put the smallest on
            if(list1 != nullptr && list2 != nullptr){
                if(list1->val <= list2->val){
                    next_node->next = list1;
                    list1 = list1->next;
                }else{
                    next_node->next = list2;
                    list2 = list2->next;
                }
            }
            next_node = next_node->next;
        }
        return first_node;
    }
};
