class Solution {
public:
    int binarySearch(vector<int>& arr, int t, int s, int e){
        if(s<=e){
            int mid = s + (e-s)/2;
            
            if(arr[mid] == t)
                return mid;
            else if(arr[mid] > t){
                return binarySearch(arr, t, s, mid-1);
            }
            else
                return binarySearch(arr, t, mid+1, e);
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size()-1);
    }
};