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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int sum = 0, flag = 0;
        sum = find(root, sum, flag);
        return sum;
    }
    int find(TreeNode* root, int sum, int flag){
        if(!root->left && !root->right && flag)
            return sum + root->val;
        if(root->left){
            flag = 1;
            sum = find(root->left, sum, flag);
        }
        if(root->right){
            flag = 0;
            sum = find(root->right, sum, flag);
        }
        return sum;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
