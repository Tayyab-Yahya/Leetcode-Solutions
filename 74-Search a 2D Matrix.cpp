class Solution {
public:
    bool searchInRow(vector<vector<int>>& m, int t, int r){
        int n = m[0].size();
        int s = 0, e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(m[r][mid] == t){
                return true;
            } else if(m[r][mid] > t){
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size(), n = matrix[0].size();
        int startRow = 0, endRow = m-1;
        
        while( startRow <= endRow ){
            int midRow = startRow + ( endRow - startRow )/2;

            if(matrix[midRow][0] <= target && matrix[midRow][n-1] >= target){
                return searchInRow(matrix, target, midRow);
            } else if (target < matrix[midRow][0]){
                endRow = midRow - 1;
            } else {
                startRow = midRow + 1;
            } 
        }

        return false;
    }
};