class Solution {
    public:
    bool isAnagram(string s, string t) {

        if(s.length()!=t.length())
            return false;

        vector<int> count(26, 0);
        for(int i=0; i<s.length(); i++){
            int index = s[i]-'a';
            count[index]++;
        }
        for(int i=0; i<s.length(); i++){
            int index = t[i]-'a';
            count[index]--;
        }
        for(int val : count){
            if(val != 0)
                return false;
        }
        return true;
    }
};