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
        if (head == nullptr || head->next == nullptr) return nullptr;
    
        vector<ListNode*> nodes;
        
        while (head != nullptr) {
            nodes.push_back(new ListNode(head->val));
            head = head->next;
        }
        
        // Remove specific node
        nodes.erase(nodes.begin() + (nodes.size() - n));
        
        // Reassing the next node
        for (int i = 0; i < nodes.size()-1; ++i) {
            nodes[i]->next = nodes[i+1];
        }
        
        return nodes[0];
    }
};