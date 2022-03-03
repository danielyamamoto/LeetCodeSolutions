class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0, bottom = row-1, left = 0, right = col-1;
        int direction = 0;
        
        while (top <= bottom && left <= right) {
            switch (direction) {
                // Top
                case 0:
                    for (int i = left; i <= right; i++) {
                        result.push_back(matrix[top][i]);
                    }
                    top++;
                    direction++;
                    break;
                // Right
                case 1:
                    for (int i = top; i <= bottom; i++) {
                        result.push_back(matrix[i][right]);    
                    }
                    right--;
                    direction++;
                    break;
                // Bottom  
                case 2:
                    for (int i = right; i >= left; i--) {
                        result.push_back(matrix[bottom][i]);    
                    }
                    bottom--;
                    direction++;
                    break;
                // Left  
                case 3:
                    for (int i = bottom; i >= top; i--) {
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                    direction = 0;
                    break;            
            }
        }
        
        return result;
    }
};