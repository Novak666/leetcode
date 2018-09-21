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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> V;
        post(root, V);
        return V;
    }
    void post(TreeNode* root, vector<int>& V){
        if(root){
            post(root->left, V);
            post(root->right, V);
            V.push_back(root->val);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
