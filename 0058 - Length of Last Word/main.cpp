class Solution {
public:      
    int lengthOfLastWord(string s) {
        vector<char> tmp;

        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == ' ' && tmp.size() != 0) { break; }
            else if (s[i] != ' ') { tmp.push_back(s[i]); }
        }

        return tmp.size();
    }
};