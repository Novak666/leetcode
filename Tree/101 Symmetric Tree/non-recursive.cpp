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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        stack<TreeNode*> S1, S2;
        TreeNode *p, *q;
        S1.push(root);
        S2.push(root);
        while(!S1.empty() && !S2.empty()){
            p = S1.top(); q = S2.top();
            S1.pop(); S2.pop();
            if(p->val != q->val) return false;
            if(p->left) S1.push(p->left);
            if(q->right) S2.push(q->right);
            if(S1.size() != S2.size()) return false;
            if(p->right) S1.push(p->right);
            if(q->left) S2.push(q->left);
            if(S1.size() != S2.size()) return false;
        }
        return S1.size() == S2.size();
    }
};
