class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> V;
        stack<TreeNode*> S;
        TreeNode *cur, *last = root;
        S.push(root);
        while(!S.empty()){
            cur = S.top();
            while(cur && cur->left != last && cur->right != last){
                S.push(cur->left);
                cur = cur->left;
            }
            if(!S.top())
                S.pop();
            if(!S.empty()){
                cur = S.top();
                if(cur->right && cur->right != last)
                    S.push(cur->right);
                else{
                    V.push_back(cur->val);
                    last = cur;
                    S.pop();
                }
            }
        }
        return V;
    }
};
