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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return Check(root->left, root->right);
    }
    bool Check(TreeNode *l, TreeNode *r){
        if(!l && !r) return true;
        if(!l || !r) return false;
        return l->val == r->val && Check(l->left, r->right) && Check(l->right, r->left);
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
