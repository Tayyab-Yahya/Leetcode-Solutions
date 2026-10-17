class Solution {
public:
    // Wormhole Teleportation Algorithm

    string reverseParentheses(string s) {        
        int n = s.size();
        
        stack<int> firstBracketIdx;
        vector<int> door(n);

        for(int i=0; i<n; i++) {
            if(s[i] == '(') {
                firstBracketIdx.push(i);
            } else if(s[i] == ')') {
                int j = firstBracketIdx.top();
                firstBracketIdx.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        string result = "";
        int flag = 1;

        for(int i = 0; i < n; i += flag) {
            if(s[i] == '(' || s[i] == ')') {
                i = door[i];
                flag = -flag;
            } else {
                result.push_back(s[i]);
            }
        }

        return result;
    }
};