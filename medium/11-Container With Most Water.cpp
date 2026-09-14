class Solution {
public:
    int maxArea(vector<int>& height) {

        // int maxVolume = 0;
        // for(int left=0; left<height.size()-1; left++){
        //     for(int right=left+1; right<height.size(); right++){
        //         int volume = min(height[left], height[right])*(right-left);
        //         maxVolume = max(maxVolume, volume);
        //     }
        // }
        // return maxVolume;

        int left = 0, right = height.size()-1, maxVol=0;
        while(left<right){
            int currVol = min(height[left], height[right])*(right-left);
            maxVol = max(maxVol, currVol);
            height[left] < height[right] ? left++ : right--;
        }
        return maxVol;
    }
};