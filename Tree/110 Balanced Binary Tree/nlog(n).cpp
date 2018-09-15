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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        int left = height(root->left);
        int right = height(root->right);
        return abs(left - right) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
    int height(TreeNode* root){
        if(!root)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
