class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //Using Tabulation (DP)
        
        int n = cost.size();        

        int prev1 = 0, prev2 = 0;
        int result = prev1;

        for(int i = 2; i <= n; i++) {
            result = min( prev1 + cost[i-1], prev2 + cost[i-2] );
            prev2 = prev1;
            prev1 = result;
        }

        return result;
    }
};