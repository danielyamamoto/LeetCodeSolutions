class Solution {
public:
    string getPermutation(int n, int k) {
        string permutations, result;
        
        for (int i = 1; i <= n; i++) 
            permutations += to_string(i);
        
        int index = 1;
        
        do {
            if (index == k) {
                result = permutations;
                break;
            } else index++;
        } while (next_permutation(permutations.begin(), permutations.end()));
        
        return result;
    }
};