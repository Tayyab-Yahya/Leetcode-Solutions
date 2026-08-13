class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // Step 1: Find the pivot element
        int pivot = -1, n = nums.size();
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot==-1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Swap with the next larger element
        for(int i=n-1; i>pivot; i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 3: Reverse elements from 'pivot+1' to 'n-1'
        
        // reverse(nums.begin()+pivot+1, nums.end());
        int i = pivot+1, j = n-1;
        while( i <= j ){
            swap(nums[i++], nums[j--]);
        }
    }
};