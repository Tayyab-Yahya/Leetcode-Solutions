class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        unordered_set<int> m;
        
        for(int i=0; i<digits.size(); i++){
            if(digits[i]==0)
                continue;
            
            for(int j=0; j<digits.size(); j++){
                
                for(int k=0; k<digits.size(); k++){
                    if(digits[k]%2 != 0 || i==j || j==k || k==i)
                        continue;
                    
                    int number = (digits[i]*100) + (digits[j]*10) + digits[k];
                    if(m.find(number) == m.end()){
                        count++;
                        m.insert(number);
                    }
                }
            }
        }

        return count;
    }
};