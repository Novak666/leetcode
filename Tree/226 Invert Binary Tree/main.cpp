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
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return NULL;
        TreeNode* p = root->left;
        root->left = root->right;
        root->right = p;
        invertTree(root->right);
        invertTree(root->left);
        return root;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
