class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }

        // Placing the n/2th element at it's accurate position, not sorting the entire array.
        nth_element(begin(nums), begin(nums)+n/2, end(nums));

        long long largeHalf = accumulate(begin(nums) + n/2, end(nums), 0LL);
        long long smallHalf = accumulate(begin(nums), begin(nums) + n/2, 0LL);

        return largeHalf - smallHalf;
    }
};