class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tmp = nums1;
        tmp.insert(tmp.end(), nums2.begin(), nums2.end());
        sort(tmp.begin(), tmp.end());
        
        if (tmp.size() == 1) { 
            return tmp[0]; 
        } else if (tmp.size() == 2) { 
            double res = tmp[0] + tmp[1];
            return res/2; 
        } else {
            if (tmp.size()%2 == 0) {
                int size = tmp.size()/2;
                double res = tmp[size-1] + tmp[size];
                return res/2;
            } else {
                int size = tmp.size()/2 + 1;
                return tmp[size-1];
            }
        }
    }
};