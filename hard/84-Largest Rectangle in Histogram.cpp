class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        int maxArea = -1;
        stack<int> s;

        //Left Nearest Smaller
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            left[i] = s.empty()? -1 : s.top();
            s.push(i);
        }

        //Clearing stack
        while(!s.empty())
            s.pop();

        //Right Nearest smaller
        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && heights[s.top()] >= heights[i]) {
                s.pop();
            }
            right[i] = s.empty()? n : s.top();
            s.push(i);
        }

        //Calculating largest rectangle
        for(int i=0; i<n; i++){
            int width = right[i] - left[i] - 1;
            int area = heights[i]*width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};