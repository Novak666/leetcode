class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return check(root, NULL, NULL);
    }
    bool check(TreeNode* root, TreeNode* min, TreeNode* max){ //�Զ����£����ñ���ģ����µݹ�
        if(!root)
            return true;
        if((max && root->val >= max->val) || (min && root->val <= min->val))
            return false;
        return check(root->left, min, root) && check(root->right, root, max);
    }
};
