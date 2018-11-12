class Solution {
public:
    void recoverTree(TreeNode* root) {
      vector<int> values;
      inorder(root, values);
      sort(values.begin(), values.end());
      int i = 0;
      assign(root, values, &i);
    }

    void inorder(TreeNode* root, vector<int>& res) {
      if(!root) return ;
      inorder(root->left, res);
      res.push_back(root->val);
      inorder(root->right, res);
    }

    void assign(TreeNode* root, vector<int>& values, int *i) {
      if(!root) return ;
      assign(root->left, values, i);
      root->val = values[(*i)++];
      assign(root->right, values, i);
    }
};

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
    void recoverTree(TreeNode* root) {
        vector<int> V;
        inorder(root, V);
        sort(V.begin(), V.end());
        int *i = new int;
        *i = 0;
        recover(root, V, i);
        delete i;
    }
    void inorder(TreeNode* root, vector<int> &V){
        if(root){
            inorder(root->left, V);
            V.push_back(root->val);
            inorder(root->right, V);
        }
    }
    void recover(TreeNode* root, vector<int> &V, int* &i){
        if(root){
            recover(root->left, V, i);
            root->val = V[(*i)++];
            recover(root->right, V, i);
        }
    }
};
