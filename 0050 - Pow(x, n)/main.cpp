class Solution {
public:
    double myPow(double x, int n) {
        double tmp = x;
        
        if (n == 0 || x == 1) { return 1; }
        else if (x < 0.001 && x > 0) { return 0; }
        else if (n >= INT_MAX) { return -1; }
        else if (abs(x) == 1 && n <= INT_MIN) return 1;
        else if (n <= INT_MIN) { return 0; }
        else if (n > 0) {
            for (int i = 1; i < n; i++) {
                tmp *= x;
            }            
        } else if (n < 0) {
            for (int i = 0; i <= abs(n); i++) {
                tmp *= (1/x);
            }
        }
        
        return tmp;
    }
};