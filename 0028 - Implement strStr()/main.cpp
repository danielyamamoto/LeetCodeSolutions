class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        
        // Base case
        if (n < m && m > 0) return -1;
        else if (n == 0 || m == 0 || haystack == needle) return 0;
        
        if (std::size_t pos = haystack.find(needle)) return pos;
        else {
            for (int i = 0; i < n; i++) {
                if (haystack[i] == needle[0]) {
                    if (haystack.substr(i, m) == needle) return i;
                } else continue;
            }    
        }
        
        return -1;
    }
};