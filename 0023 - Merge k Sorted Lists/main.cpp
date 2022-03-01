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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listsSize = lists.size();
        // Base case
        if (listsSize == 0) return nullptr;
    
        vector<pair<int, ListNode*>> nodes;
        
        for (int i = 0; i < listsSize; ++i) {
            ListNode* currList = lists[i];
            
            while (currList != nullptr) {
                nodes.push_back({currList->val, currList});
                currList = currList->next;
            }
        }
        
        if (nodes.size() == 0) return nullptr;
        
        // Sort all the nodes by non-decreasing
        // Sort: https://www.geeksforgeeks.org/sorting-a-vector-in-c/
        sort(nodes.begin(), nodes.end());
        
        for (int i = 0; i < nodes.size()-1; ++i) {
            nodes[i].second->next =  nodes[i+1].second;
        }
        
        return nodes[0].second;
    }
};