class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        for(int i=0; i<chars.size(); i++)
        {
            int count = 0;
            char ch = chars[i];
            while(i<chars.size() && ch == chars[i]){
                i++;
                count++;
            }
            if(count==1){
                chars[idx++] = ch;
            } else {
                string counts = to_string(count);
                chars[idx++] = ch;
                for(char c : counts){
                    chars[idx++] = c;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};