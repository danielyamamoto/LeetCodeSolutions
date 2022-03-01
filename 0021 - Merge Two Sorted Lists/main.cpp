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
        // Base case
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        else if (list1 == nullptr && list2 != nullptr) return list2;
        else if (list1 != nullptr && list2 == nullptr) return list1;
        
        ListNode* list = new ListNode(0);
        ListNode* curr = list;
        
        while (list1 != nullptr || list2 != nullptr) {
            ListNode* tmp = new ListNode(0);
            
            if (list1 == nullptr) { // There are not elements in the list1
                curr->next = list2;
                break;
            } else if (list2 == nullptr) { // There are not elements in the list2
                curr->next = list1;
                break;
            } else if (list1->val >= list2-> val) {
                tmp->val = list2->val;
                list2 = list2->next;
            } else {
                tmp->val = list1->val;
                list1 = list1->next;
            }
            
            curr->next = tmp;
            curr = curr->next;
        }
    
        return list->next;
    }
};