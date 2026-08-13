class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        // Changing k when k > nums.size()
        k = k % nums.size();

        // Reverse the entire array
        reverse(nums.begin(), nums.end());

        // Reverse the elements from 0 index to k-1 (first k elements)
        reverse(nums.begin(), nums.begin()+k);

        // Reverse the elements from k index to n-1 (last n-k elements)
        reverse(nums.begin()+k, nums.end());
    }
};