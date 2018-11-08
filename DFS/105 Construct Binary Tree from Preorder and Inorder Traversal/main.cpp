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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return root;
    }
    TreeNode* build(vector<int>& preorder, int b1, int e1, vector<int>& inorder, int b2, int e2){
        if(b1 >= e1)
            return NULL;
        auto p = find(inorder.begin() + b2, inorder.begin() + e2, preorder[b1]);
        int temp = p - inorder.begin() - b2;
        TreeNode* root = new TreeNode(preorder[b1]);
        root->left = build(preorder, b1 + 1, b1 + 1 + temp, inorder, b2, b2 + temp);
        root->right = build(preorder, b1 + 1 + temp, e1, inorder, b2 + temp + 1, e2);
        return root;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
