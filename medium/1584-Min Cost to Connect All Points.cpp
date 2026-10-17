class Solution {
public:
    int manhattanDistance(vector<vector<int>>& points, int p1, int p2) {
        return abs(points[p1][0] - points[p2][0]) + 
                abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mstCost = 0;
        vector<bool> mstSet(n, false);

        // PQ -> Min Heap
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        pq.push({0, 0});

        while(pq.size() > 0) {
            auto p = pq.top();
            int wt = p.first;
            int node = p.second;

            pq.pop();

            if(mstSet[node]) continue; //skip if already visited

            mstSet[node] = true;
            mstCost += wt;

            for(int i=0; i<n; i++) {
                if(!mstSet[i]) {
                    int edgeWt = manhattanDistance(points, i, node);
                    pq.push({edgeWt, i});
                }
            }
        }

        return mstCost;
    }
};