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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string s1, s2;
        
        while (l1 != nullptr) {
            s1 += to_string(l1->val);
            l1 = l1->next;
        }
        
        while (l2 != nullptr) {
            s2 += to_string(l2->val);
            l2 = l2->next;
        }
        
        // Flip 
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        
        // Sum the big sum as string
        string sum = findSum(s1, s2);
        // Flip the answer
        reverse(sum.begin(), sum.end());
        
        // List result
        ListNode* list = new ListNode(0);
        ListNode* curr = list;
        
        for (int i = 0; i < sum.length(); i++) {
            ListNode* tmp = new ListNode(0);
            tmp->val = sum[i]-'0';
            curr->next = tmp;
            curr = curr->next;
        }
        
        return list->next;
    }
    
private:
    // Function for finding sum of larger numbers
    string findSum(string str1, string str2) {
        // Before proceeding further, make sure length
        // of str2 is larger.
        if (str1.length() > str2.length())
            swap(str1, str2);

        // Take an empty string for storing result
        string str = "";

        // Calculate length of both string
        int n1 = str1.length(), n2 = str2.length();
        int diff = n2 - n1;

        // Initially take carry zero
        int carry = 0;

        // Traverse from end of both strings
        for (int i = n1-1; i >= 0; i--) {
            // Do school mathematics, compute sum of
            // current digits and carry
            int sum = ((str1[i]-'0') + (str2[i+diff]-'0') + carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }

        // Add remaining digits of str2[]
        for (int i = n2-n1-1; i >= 0; i--) {
            int sum = ((str2[i]-'0') + carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }

        // Add remaining carry
        if (carry) str.push_back(carry + '0');

        // reverse resultant string
        reverse(str.begin(), str.end());

        return str;
    }
};