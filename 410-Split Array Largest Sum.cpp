class Solution {
public:

    bool isValid( vector<int> arr, int n, int m, int maximumAllowedPages ){

        int students = 1, pages = 0;
        for( int i=0; i<n; i++ ){
            
            if( arr[i] > maximumAllowedPages )
                return 0;

            if( pages + arr[i] <= maximumAllowedPages ){
                pages += arr[i];
            } else {
                students++;
                pages = arr[i];
            }
        }
        return students <= m;
    }

    int splitArray(vector<int>& nums, int m) {

        int n = nums.size();

        if( n < m ){
            return -1;
        }

        // 'st' = Maximum_Array_Value
        // 'end' = Sum_Of_Array_Values
        int sum = 0, max = -9999;

        for(int i=0; i<n; i++){
            if(max < nums[i])
                max = nums[i];
            sum += nums[i];
        }

        int st = max, end = sum, ans = -1;

        while(st <= end){
            int mid = st + (end-st)/2;
            if(isValid( nums, n, m, mid )){
                //Left
                ans = mid;
                end = mid - 1;
            } else {
                //Right
                st = mid + 1;
            }
        }
        return ans;

    }
};