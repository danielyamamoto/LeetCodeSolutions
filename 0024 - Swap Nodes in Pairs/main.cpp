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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return nullptr;
        else if (head->next == nullptr) return head;
        
        ListNode* list = new ListNode(0);
        ListNode* curr = list;
        // Values
        int val = head->val;
        bool isActive = true;
        // Next node
        head = head->next;
        
        while (head != nullptr) {
            ListNode* tmp = new ListNode(0);
            
            if (isActive) {
                // Pair
                tmp->val = head->val;
                isActive = false;
            } else {
                // Odd
                tmp->val = val;
                val = head->val;
                isActive = true;                
            }
            // Update node
            curr->next = tmp;
            curr = curr->next;
            // Next node
            head = head->next;
        }

        // Last iteration
        ListNode* tmp = new ListNode(0);
        tmp->val = val;
        curr->next = tmp;
        curr = curr->next;
        
        return list->next;
    }
};