class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        
        int result = 0, tmp = 1;
        string word = "";
        
        for (int i = 0; i < s.size()-1; ++i) {
            tmp = 1;
            word = "";
            word += s[i];
                
            for (int j = i+1; j < s.size(); ++j) {
                if (word.find(s[j]) != std::string::npos) {
                    break;
                } else {
                    ++tmp;
                    word += s[j];
                }
            }
            
            result = max(result, tmp);
        }
        
        return result;
    }
};