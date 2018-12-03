#include <iostream>

using namespace std;

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
    int rob(TreeNode* root) {
        //相当巧妙，分为偷子树的根结点和不偷根结点
        //dfs返回最大的利益，但保留了子代信息 dfs后直接考虑最深层，看能不能解决问题
        int num = 0;
        return dfs(root, num);
    }
    int dfs(TreeNode* root, int &no_root){
        if(!root)
            return 0;
        int no_leftsubroot = 0, no_rightsubroot = 0;
        int left = dfs(root->left, no_leftsubroot);
        int right = dfs(root->right, no_rightsubroot);
        no_root = left + right;
        return max(root->val + no_leftsubroot + no_rightsubroot, no_root);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
