class Solution {
public:
    int reverse(int x) {
        string number = to_string(x), result;
        
        for (int i = number.size()-1; i >= 0; i--) {
            if (number[i] == '-') { result.insert(0, 1, number[i]); }
            else { result += number[i]; }
        }

        try {
            return stoi(result);
        } catch (const std::out_of_range& oor) {
            return 0;
        }
    }
};