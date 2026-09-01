class Solution {
public:
    void getAllSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets) {

        if( i == nums.size()){
            allSubsets.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);

        //include
        getAllSubsets(nums, ans, i+1, allSubsets);

        ans.pop_back();

        //exclude
        getAllSubsets(nums, ans, i+1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> allSubsets;

        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};