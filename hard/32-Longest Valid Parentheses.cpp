class Solution {
public:    

    int longestValidParentheses(string s) {        
        int result = 0, open = 0, close = 0;

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '(') open++;
            else close++;
            
            if(close > open)
                open = close = 0;
            else if(open == close)
                result = max(result, open + close);
        }

        open = close = 0;

        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == '(') open++;
            else close++;
            
            if(open > close)
                open = close = 0;
            else if(open == close)
                result = max(result, open + close);
        }

        return result;
    }
};