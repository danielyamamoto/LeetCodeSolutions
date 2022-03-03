class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int> (n, 0));
        int top = 0, bottom = n-1, left = 0, right = n-1;
        int direction = 0, counter = 1;
        
        while (top <= bottom && left <= right) {
            switch (direction) {
                // Top
                case 0:
                    for (int i = left; i <= right; i++) {
                        result[top][i] = counter;
                        counter++;
                    }
                    top++;
                    direction++;
                    break;
                // Right
                case 1:
                    for (int i = top; i <= bottom; i++) {
                        result[i][right] =  counter;
                        counter++;
                    }
                    right--;
                    direction++;
                    break;
                // Bottom  
                case 2:
                    for (int i = right; i >= left; i--) {
                        result[bottom][i] = counter;
                        counter++;
                    }
                    bottom--;
                    direction++;
                    break;
                // Left  
                case 3:
                    for (int i = bottom; i >= top; i--) {
                        result[i][left] = counter;
                        counter++;
                    }
                    left++;
                    direction = 0;
                    break;            
            }
        }
        
        return result;
    }
};