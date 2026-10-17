class Solution {
public:
    int minInsertions(string s) {
        int result = 0, count = 0, i = 0, n = s.size();

        while(i < n)
        {
            if(s[i] == '(') {
                count++;
                i++;
            } else { // ')'
                if(count > 0) {
                    count--;                    
                } else {
                    result++;
                }

                if(i+1<n && s[i+1]==')') {
                    i += 2;
                } else {
                    i++;
                    result++;
                }
            }
        }

        return result + 2*count;
    }
};