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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL){
                res.push_back(ans);
                ans.clear();
                if(q.empty())
                    break;
                else {
                    q.push(NULL);                
                    continue;
                }
            }
            
            ans.push_back(curr->val);

            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }

        return res;
        
    }
};