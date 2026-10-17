class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        
        int maxDiff = INT_MIN;
        int n = nums1.size();
        
        for(int i = 0; i < n; i++) {
            maxDiff = max(maxDiff, abs(nums1[i]-nums2[i]));
        }

        vector<int> countDiff(maxDiff+1, 0);

        for(int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            countDiff[d]++;
        }

        int K = k1 + k2;

        for(int curr = maxDiff; curr > 0 && K > 0; curr--) {
            if(countDiff[curr] == 0) continue;

            int countOps = min(K, countDiff[curr]);
            countDiff[curr] -= countOps;
            countDiff[curr-1] += countOps;
            K -= countOps;
        }

        long long result = 0;

        for(long long i = 1; i <= maxDiff; i++) {
            result += (countDiff[i] * i * i);
        }

        return result;
    }
};