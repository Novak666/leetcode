class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> V;
        int level = 1;
        DFS(root, level, V);
        return V;
    }
    void DFS(TreeNode* root, int level, vector<int> &V){
        if(!root)
            return;
        if(V.size() < level) V.push_back(root->val);
        DFS(root->right, level + 1, V);
        DFS(root->left, level + 1, V);
    }
};
