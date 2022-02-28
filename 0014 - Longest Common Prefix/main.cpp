class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) { return strs[0]; }
        else {
            string prefix = "";
            string tmp = strs[0];
            
            for (int i = 0; i < tmp.size(); i++) {
                for (int j = 0; j < strs.size(); j++) {
                    if (tmp[i] != strs[j][i]) { return prefix; }
                }
                prefix += tmp[i];
            }
            
            return prefix;
        }    
    }
};