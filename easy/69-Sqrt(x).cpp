class Solution {
public:
    int mySqrt(int x) {
        int st = 1, end = x;
        while(st <= end) {
            long long mid = st + (end-st)/2;
            long long sq = mid*mid;

            if(sq <= x) {
                st = mid+1;
            } else {
                end = mid-1;
            }
        }
        return end;
    }
};