class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0)
            return false;
        //Solution
        int temp = x;
        long int n = 0;
        
        while(temp > 0){
            n *= 10;
            n += temp % 10;
            temp /= 10;
        }
        return n==x? true : false;


    }
};