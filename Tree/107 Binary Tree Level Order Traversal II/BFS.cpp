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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> V(h);
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){    //BFS
            TreeNode* p = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            if(p){
                V[h - 1 - level].push_back(p->val);
                Q.push({p->left, level + 1});
                Q.push({p->right, level + 1});
            }
        }
        return V;
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
