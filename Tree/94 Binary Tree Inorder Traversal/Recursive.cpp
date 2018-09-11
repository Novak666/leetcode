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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> V;
        inorder(root, V);
        return V;
    }
public:
    void inorder(TreeNode* &T, vector<int> &V){
        if(T){
            inorder(T->left, V);
            V.push_back(T->val);
            inorder(T->right, V);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
