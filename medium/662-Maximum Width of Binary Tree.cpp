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
    int widthOfBinaryTree(TreeNode* root) {
       int maxWidth = 0;
       queue<pair<TreeNode*, unsigned long long>> q;

        q.push({root, 0});

        while(q.size() > 0) {
            unsigned long long leftIdx = q.front().second;
            unsigned long long rightIdx = q.back().second;
            int currLevelSize = q.size();
            maxWidth = max(maxWidth, (int)(rightIdx-leftIdx+1));

            for(int i=0; i<currLevelSize; i++){
                auto temp = q.front();
                q.pop();
                if(temp.first->left)
                    q.push({temp.first->left, 2*(temp.second)+1});
                if(temp.first->right)
                    q.push({temp.first->right, 2*(temp.second)+2});
            }            
        }

        return maxWidth;
    }
};