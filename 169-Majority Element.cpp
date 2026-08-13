class Solution {
public:
    int majorityElement(vector<int>& nums) {

        //Moore's Voting Algorithm
        int frequency = 0, ans = 0;

        for(int i=0; i<nums.size(); i++){
            
            if(frequency == 0){
                ans = nums[i];
            } 
            if(ans == nums[i]){
                frequency++;
            } else {
                frequency--;
            }
        }
        return ans;
        
    }
};