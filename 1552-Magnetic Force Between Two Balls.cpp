class Solution {
public:

    bool isPossible(vector<int> arr, int n, int m, int minAllowedForce) {

        int balls = 1, lastBasketPos = arr[0];

        for(int i=1; i<n; i++){
            if( arr[i] - lastBasketPos >= minAllowedForce ) {
                balls++;
                lastBasketPos = arr[i];
            }
            if( balls == m )
                return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());
        int n = position.size();
        int st = 1, end = position[n-1] - position[0], ans = -1;

        while( st <= end ){
            
            int mid = st + ( end - st ) / 2;
            if( isPossible(position, n, m, mid) ) { //Right
                st = mid + 1;
                ans = mid;
            } else { //Left
                end = mid - 1;
            }

        }
        return ans;
    }
};