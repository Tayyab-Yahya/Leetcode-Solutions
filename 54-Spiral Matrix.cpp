class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();

        int startingRow = 0, startingColumn = 0;
        int endingRow = m - 1, endingColumn = n - 1;

        while( startingRow <= endingRow && startingColumn <= endingColumn )
        {
            //Top
            for(int i = startingColumn; i <= endingColumn; i++){
                ans.push_back(matrix[startingRow][i]);
            }
            //Right
            for(int i = startingRow+1; i <= endingRow; i++){
                ans.push_back(matrix[i][endingColumn]);
            }
            //Bottom
            for(int i = endingColumn-1; i >= startingColumn; i--){
                
                if(startingRow == endingRow){
                    break;
                }
                ans.push_back(matrix[endingRow][i]);
            }
            //Left
            for(int i = endingRow-1; i >= startingRow+1; i--){
                
                if(startingColumn == endingColumn){
                    break;
                }
                ans.push_back(matrix[i][startingColumn]);
            }

            startingRow++;
            endingRow--;
            startingColumn++;
            endingColumn--;
        }
        return ans;
    }
};