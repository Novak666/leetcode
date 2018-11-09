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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
        return root;
    }
    TreeNode* build(vector<int>& inorder, int b1, int e1, vector<int>& postorder, int b2, int e2){
        if(b2 >= e2)
            return NULL;
        auto p = find(inorder.begin() + b1, inorder.end() + e1, postorder[e2 - 1]);
        int temp = p - inorder.begin() - b1;
        TreeNode* root = new TreeNode(postorder[e2 - 1]);
        root->left = build(inorder, b1, b1 + temp, postorder, b2, b2 + temp);
        root->right = build(inorder, b1 + temp + 1, e1, postorder, b2 + temp, e2 - 1);
        return root;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
