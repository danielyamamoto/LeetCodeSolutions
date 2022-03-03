class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        vector<int> tmp;
        
        for(int i = 0; i < matrix.size(); i++) {
            for (int j = matrix.size()-1; j >= 0; j--) {
                tmp.push_back(matrix[j][i]);
            }
            result.push_back(tmp);
            tmp.clear();
        }
        matrix = result;
    }
};