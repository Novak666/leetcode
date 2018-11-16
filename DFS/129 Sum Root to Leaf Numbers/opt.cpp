class Solution {
public:
    void rec(TreeNode* root, string str, int& sum)
    {
        str+=to_string(root->val);

        if(!root->left && !root->right)
            sum+=stoi(str);

        if(root->left)
            rec(root->left, str, sum);
        if(root->right)
            rec(root->right, str, sum);

        str.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int sum=0;

        rec(root,"",sum);
        return sum;
    }
};
