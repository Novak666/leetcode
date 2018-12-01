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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int count = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* p= Q.front();
            Q.pop();
            count++;
            if(p->left) Q.push(p->left);
            if(p->right) Q.push(p->right);
        }
        return count;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
