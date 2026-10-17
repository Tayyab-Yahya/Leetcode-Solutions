class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[i] = true;

        for(int j=0; j<adj[0].size(); j++) {
            if(adj[i][j] && !vis[j]) {
                dfs(j, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {        
        int n = isConnected.size();
        int numberOfProvinces = 0;
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                dfs(i, isConnected, vis);
                numberOfProvinces++;
            }
        }
        return numberOfProvinces;    
    }
};