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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> V;
        preorder(root, V);
        return V;
    }
    void preorder(TreeNode* root, vector<int>& V){
        if(root){
            V.push_back(root->val);
            preorder(root->left, V);
            preorder(root->right, V);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
