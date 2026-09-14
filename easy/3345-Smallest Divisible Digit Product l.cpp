class Solution {
public:
    int smallestNumber(int n, int t) {
        
        bool isDivisible = false;

        if(n==0){
            return n;
        }

        for(int i=n; (i<n+10 && !isDivisible); i++){
            //Digitwise product
            int temp = i, prod = 1;

            while(temp>0){
                prod *= (temp%10);
                temp /= 10;
            }
            //Check divisibility
            if(prod%t==0){
                isDivisible = true;
                return i;
            }
        }

        return 1;
    }
};