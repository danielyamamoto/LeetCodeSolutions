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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) return head;
        
        vector<ListNode*> nodes = getNodes(head);
        int rot = k % nodes.size();
        if (rot == 0) return head;
        int target = nodes.size()-rot;
        rotateNodes(nodes, target);

        return nodes[target];
    }
    
private:
    vector<ListNode*> getNodes(ListNode* head) {
        vector<ListNode*> nodes;
        
        while (head != nullptr) {
            nodes.push_back(new ListNode(head->val));
            head = head->next;
        }
        
        return nodes;
    }
    
    void rotateNodes(vector<ListNode*> nodes, int target) {
        for (int i = target; i < nodes.size()-1; ++i) {
            nodes[i]->next = nodes[i+1];
        }
        
        for (int i = 0; i < target; ++i) {
            if (i == 0) nodes[nodes.size()-1]->next = nodes[i];
            else nodes[i-1]->next = nodes[i];
        }
    }
};