class Solution {
public:
    vector<int> add(vector<int>& arr) {
            vector<int> newArr(arr.size()+1);
            newArr[0] = 1;
            newArr[1] = 0;
            for(int i=2; i<newArr.size(); i++) {
                newArr[i] = arr[i-1];
            }
            return newArr;
        }

    vector<int> plusOne(vector<int>& digits) {

        if(digits.empty())
            return {};
        
        if(digits.size()==1){
            digits[0]++;
            if(digits[0]>9){
                return {1,0};
            }
            return digits;
        }

        digits[digits.size()-1]++;

        for(int i=digits.size()-1; i>0; i--){
            if(digits[i]>9 && i!=0) {
                digits[i] = 0;
                digits[i-1]++;
            }
        }
        if(digits[0]>9){
            vector<int> Arra = add(digits);
            return Arra;
        }
        return digits;
    }
};