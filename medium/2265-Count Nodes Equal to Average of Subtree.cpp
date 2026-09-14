/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int totalCount = 0;

    vector<int> getAverage(TreeNode* root){
        if(root==nullptr)
            return {0,0};
        
        //{Sum, Count}
        vector<int> leftVec = getAverage(root->left);
        vector<int> rightVec = getAverage(root->right);

        int totalSum = leftVec[0] + rightVec[0] + root->val;
        int count = leftVec[1] + rightVec[1] + 1;
        int avg = totalSum/count;
        
        if(avg == root->val)
            totalCount++;
        
        return {totalSum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        getAverage(root);
        return totalCount;
    }
};