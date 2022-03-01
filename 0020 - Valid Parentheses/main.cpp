class Solution {
public:    
    bool isValid(string s) {
        if (s.size() <= 1) { return false; }
        
        stack<char> stk;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') { stk.push(s[i]); }
            else if (s[i] == '}' && !stk.empty() && stk.top() == '{') { stk.pop(); }
            else if (s[i] == ')' && !stk.empty() && stk.top() == '(') { stk.pop(); }
            else if (s[i] == ']' && !stk.empty() && stk.top() == '[') { stk.pop(); }
            else { return false; }
        }
        
        return stk.empty() ? true : false;
    }
};