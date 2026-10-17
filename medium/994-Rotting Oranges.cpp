class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<pair<int, int>, int>> Q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    Q.push({{i, j}, 0});
                }
            }
        }

        while(!Q.empty()) {
            int i = Q.front().first.first;
            int j = Q.front().first.second;
            int time = Q.front().second;
            Q.pop();
            ans = max(ans, time);

            if(i-1 >= 0 && grid[i-1][j] == 1 && !vis[i-1][j]) { //top
                Q.push({{i-1, j}, time+1});
                vis[i-1][j] = true;
            }
            if(j+1 < m && grid[i][j+1] == 1 && !vis[i][j+1]) { //right
                Q.push({{i, j+1}, time+1});
                vis[i][j+1] = true;
            }
            if(i+1 < n && grid[i+1][j] == 1 && !vis[i+1][j]) { //bottom
                Q.push({{i+1, j}, time+1});
                vis[i+1][j] = true;
            }
            if(j-1 >= 0 && grid[i][j-1] == 1 && !vis[i][j-1]) { //left
                Q.push({{i, j-1}, time+1});
                vis[i][j-1] = true;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return ans;
    }
};