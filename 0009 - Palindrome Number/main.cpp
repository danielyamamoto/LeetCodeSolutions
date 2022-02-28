class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) { return false; }
        else if (x < 10) { return true; }
        else {
            string number = to_string(x);
            for (int i = 0; i < number.size(); i++) {
                if (number[i] != number[(number.size()-1)-i]) {
                    return false;
                }
            }
            return true;
        }
    }
};