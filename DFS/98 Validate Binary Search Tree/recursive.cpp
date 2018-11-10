class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, NULL, NULL);
    }
    bool check(TreeNode* root, TreeNode* min, TreeNode* max){ //自顶向下，做好本层的，向下递归
        if(!root)
            return true;
        if((max && root->val >= max->val) || (min && root->val <= min->val))
            return false;
        return check(root->left, min, root) && check(root->right, root, max);
    }
};
