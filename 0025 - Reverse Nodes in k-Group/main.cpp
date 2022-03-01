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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        
        vector<vector<int>> nodes = kNodes(head, k);
        getReverse(nodes, k);
        vector<int> rev = mergeVectors(nodes);        
        
        vector<ListNode*> res;
        
        for (int i = 0; i < rev.size(); ++i) {
            res.push_back(new ListNode(rev[i]));
        }
        
        for (int i = 0; i < rev.size()-1; ++i) {
            res[i]->next = res[i+1];
        }
        
        return res[0];
    }
    
private:
    vector<vector<int>> kNodes(ListNode* head, int k) {
        int ctn = 0;
        vector<vector<int>> nodes;
        vector<int> tmp;
        ListNode* ans = head;
        
        while (head != nullptr) { 
            tmp.push_back(head->val);
            ++ctn;
            
            if (ctn == k) {
                nodes.push_back(tmp);
                ctn = 0;
                tmp.clear();
            } 
            
            head = head->next;
        }
        // Last iteration
        if (ctn != k) nodes.push_back(tmp); 
        
        return nodes;
    }
    
    void getReverse(vector<vector<int>> &nodes, int k) {
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i].size() == k) std::reverse(nodes[i].begin(), nodes[i].end());
        }   
    }
    
    vector<int> mergeVectors(vector<vector<int>> vecs) {
        vector<int> res;
        
        for (int i = 0; i < vecs.size(); ++i) {
            res.insert(res.end(), vecs[i].begin(), vecs[i].end());
        }
        
        return res;
    }
};