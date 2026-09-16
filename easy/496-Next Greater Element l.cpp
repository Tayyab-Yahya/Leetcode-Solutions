class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> m;
        vector<int> ans;
        stack<int> stk;

        for(int i=nums2.size()-1; i>=0; i--){
            while(!stk.empty() && stk.top() <= nums2[i]){
                stk.pop();
            }
            if(stk.empty()){
                m[nums2[i]] = -1;
            } else {
                m[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++){
            ans.push_back(m[nums1[i]]);
        }
        return ans;
    }
};