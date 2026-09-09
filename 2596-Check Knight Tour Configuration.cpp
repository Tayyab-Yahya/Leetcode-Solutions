class Solution {
public:
    bool isValidHelper(vector<vector<int>>& grid, int r, int c, int expVal, int n) {
        
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != expVal)
            return false;
        if(expVal == n*n-1)
            return true;
        
        bool ans1 = isValidHelper(grid, r-2, c+1, expVal+1, n);
        bool ans2 = isValidHelper(grid, r-1, c+2, expVal+1, n);
        bool ans3 = isValidHelper(grid, r+1, c+2, expVal+1, n);
        bool ans4 = isValidHelper(grid, r+2, c+1, expVal+1, n);
        bool ans5 = isValidHelper(grid, r+2, c-1, expVal+1, n);
        bool ans6 = isValidHelper(grid, r+1, c-2, expVal+1, n);
        bool ans7 = isValidHelper(grid, r-1, c-2, expVal+1, n);
        bool ans8 = isValidHelper(grid, r-2, c-1, expVal+1, n);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();

        return isValidHelper(grid, 0, 0, 0, n);
    }
};