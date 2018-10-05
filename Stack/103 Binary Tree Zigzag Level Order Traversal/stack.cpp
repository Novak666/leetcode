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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> V(h);
        stack<pair<TreeNode*, int>> S1, S2;
        S1.push({root, 0});
        int level = 0;
        TreeNode* p = NULL;
        while(!S1.empty() || !S2.empty()){
            if(level % 2 == 0){
                if(!S1.empty()){
                    p = S1.top().first;
                    level = S1.top().second;
                    S1.pop();
                }
                else{
                    level++;
                    p = NULL;
                }
            }
            else{
                if(!S2.empty()){
                    p = S2.top().first;
                    level = S2.top().second;
                    S2.pop();
                }
                else{
                    level++;
                    p = NULL;
                }
            }
            if(p){
                if(level % 2 == 0){
                    V[level].push_back(p->val);
                    S2.push({p->left, level + 1});
                    S2.push({p->right, level + 1});
                }
                else{
                    V[level].push_back(p->val);
                    S1.push({p->right, level + 1});
                    S1.push({p->left, level + 1});
                }
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
