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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if(!root)
            return paths;
        findPaths(root, paths, to_string(root->val));
        return paths;
    }
    void findPaths(TreeNode* root, vector<string> &paths, string s){
        if(!root->left && !root->right){
            paths.push_back(s);
            return;
        }
        if(root->left)
            findPaths(root->left, paths, s + "->" + to_string(root->left->val));
        if(root->right)
            findPaths(root->right, paths, s + "->" + to_string(root->right->val));
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
