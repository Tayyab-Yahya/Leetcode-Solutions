class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        unordered_set<int> s;
        int n = grid.size();
        int a, b, actualSum = 0;
        vector<int> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        int expectedSum = (n*n) * ((n*n)+1)/2;
    
        b = expectedSum - actualSum + a;
        ans.push_back(b);
        return ans;

    }
};