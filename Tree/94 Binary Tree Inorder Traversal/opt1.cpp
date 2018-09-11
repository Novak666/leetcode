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
        stack<TreeNode *> S;
        TreeNode *p;
        S.push(root);
        while(!S.empty()){
            p = S.top();
            while(p){
                S.push(p->left);
                p = p->left;
            }
            S.pop();
            if(!S.empty()){
                p = S.top();
                V.push_back(p->val);
                S.pop();
                S.push(p->right);
            }
        }
        return V;
    }
};
