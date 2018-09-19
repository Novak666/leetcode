class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        if (root->left && !root->left->left && !root->left->right) return root->left->val + sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int flag = 0;
        int *sum = new int;
        *sum = 0;
        find(root, sum, flag);
        flag = *sum;
        delete sum;
        return flag;
    }
    void find(TreeNode* root, int* &sum, int flag){
        if(!root->left && !root->right && flag)
            *sum = *sum + root->val;
        if(root->left)
            find(root->left, sum, 1);
        if(root->right)
            find(root->right, sum, 0);
    }
};

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int sum = 0, flag = 0;
        find(root, &sum, flag);
        return sum;
    }
    void find(TreeNode* root, int* sum, int flag){
        if(!root->left && !root->right && flag)
            *sum = *sum + root->val;
        if(root->left)
            find(root->left, sum, 1);
        if(root->right)
            find(root->right, sum, 0);
    }
};
