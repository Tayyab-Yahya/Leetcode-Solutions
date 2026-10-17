class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        string ans = "";

        for(auto &vec : knowledge) {
            m[vec[0]] = vec[1];
        }
        
        int i = 0;

        while(i < s.size()) {
            if(s[i] == '(')  {
                int j = s.find(')', i+1);
                string key = s.substr(i+1, j-i-1);
                ans += m.count(key)? m[key] : "?";
                i = j;
            } else {
                ans.push_back(s[i]);
            }
            i++;
        }

        return ans;
    }
};