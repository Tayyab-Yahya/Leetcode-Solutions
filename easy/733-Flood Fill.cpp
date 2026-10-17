class Solution {    
public:
    void helper(vector<vector<int>>& image, int i, int j, int newColor, int orgColor) {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] == newColor || image[i][j] != orgColor)
            return;
        
        image[i][j] = newColor;        

        helper(image, i-1, j, newColor, orgColor); //top
        helper(image, i, j+1, newColor, orgColor); //right
        helper(image, i+1, j, newColor, orgColor); //bottom
        helper(image, i, j-1, newColor, orgColor); //left
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {        
        helper(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};