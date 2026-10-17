class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> result(seq.size());
        int depth = 0;
        for(int i=0; i<seq.size(); i++) {
            if(seq[i] == '(') {
                depth++;
                result[i] = depth % 2;
            } else {
                result[i] = depth % 2;
                depth--;
            }
        }
        return result;
    }
};