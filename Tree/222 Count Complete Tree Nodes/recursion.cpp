/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        TreeNode *l = root, *r = root;
        int level = 0;
        while(r){
            level++;
            r = r->right;
            l = l->left;
        }
        if(!l)
            return pow(2, level) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
