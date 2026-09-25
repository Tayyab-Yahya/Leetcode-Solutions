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
    TreeNode* nextRight = NULL;
    void flatten(TreeNode* root) {
        if(!root)
            return;
        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;

        // Alternate Solution (Iterative)
        
        //  TreeNode* curr = root;
        // while(curr) {
        //     if(curr->left) {
        //         TreeNode* pred = curr->left;
        //         while(pred->right)
        //             pred = pred->right;                
        //         pred->right = curr->right;
        //         curr->right = curr->left;
        //         curr->left = NULL;
        //         curr = curr->right;
        //     } else {
        //         curr = curr->right;
        //     }
        // }
    }
};