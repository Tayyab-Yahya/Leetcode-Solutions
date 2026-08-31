class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int low = 0, high = 0; 
        int minLenWindow = INT_MAX, currentSum = 0;

        for(; high < nums.size(); high++){
            currentSum += nums[high];

            while(currentSum >= target){
                int currentWindow = high - low + 1;
                minLenWindow = min(minLenWindow, currentWindow);
                currentSum -= nums[low];
                low++;
            }
        }

        return minLenWindow == INT_MAX? 0 : minLenWindow;

    }
};