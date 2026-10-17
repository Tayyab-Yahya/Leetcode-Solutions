// class Solution {
// public:
//     int climbStairs(int n) {
//         if(n<=3)
//             return n;
        
//         int a = 3, b = 2;
//         for(int i=0; i<n-3; i++){
//             a += b;
//             b = a-b;
//         }
//         return a;
//     }
// };

// ANOTHER APPROACH

class Solution {
public:
    int climbStairs(int n) {        
        if(n <= 3) return n;
        
        int result = 0;
        int prev1 = 2; //n-1
        int prev2 = 1; //n-2

        for(int i=3; i<=n; i++) {
            result = prev1 + prev2;
            prev2 = prev1;
            prev1 = result;
        }
        return result;
    }
};