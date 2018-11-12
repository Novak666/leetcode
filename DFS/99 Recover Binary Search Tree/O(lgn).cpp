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
    void recoverTree(TreeNode* root) {
        TreeNode *pre = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        findnode(root, first, second, pre);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
    void findnode(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode* &pre){
        if(!root)
            return;
        findnode(root->left, first, second, pre);
        if(first == NULL && pre && pre->val > root->val)
            first = pre;
        if(first != NULL && pre->val > root->val)
            second = root;
        pre = root;
        findnode(root->right, first, second, pre);
    }
};
