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

    void recoverTree(TreeNode* root) {        
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        TreeNode* fir = NULL;
        TreeNode* sec = NULL;

        while(curr) {
            if(!curr->left) {
                if(prev && prev->val > curr->val) {
                    if(!fir)
                        fir = prev;
                    sec = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find the IP
                TreeNode* IP = curr->left;
                while(IP->right && IP->right != curr)
                    IP = IP->right;

                if(!IP->right) {
                    IP->right = curr;
                    curr = curr->left;
                } else {
                    if(prev && prev->val > curr->val) {
                        if(!fir)
                            fir = prev;
                        sec = curr;
                    }                
                    prev = curr;
                    IP->right = NULL;
                    curr = curr->right;
                }
            }
        }

        if(fir && sec) {
            swap(fir->val, sec->val);
        }        
    }
};