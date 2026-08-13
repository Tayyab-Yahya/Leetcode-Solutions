class Solution {
public:
    string longestCommonPrefix(vector<string>& S) {
        
        sort(S.begin(), S.end());

        string s1 = S[0], s2 = S[S.size()-1];
        int index = 0;

        while(index<s1.length()){
            if(s1[index]==s2[index])
                index++;
            else
                break;
        }

        return index==0? "" : s1.substr(0, index);

    }
};