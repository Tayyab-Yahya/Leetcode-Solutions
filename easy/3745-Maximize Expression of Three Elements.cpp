class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, min = INT_MAX;

        for(int val : nums) {
            if(val > max1) {
                max2 = max1;
                max1 = val;
            } else if(val > max2) {
                max2 = val;
            }
            if(val < min) {
                min = val;
            }
        }

        return max1 + max2 - min;
    }
};