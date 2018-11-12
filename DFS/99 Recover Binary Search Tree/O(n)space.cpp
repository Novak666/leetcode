#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> V;
        inorder(root, V);
        vector<int> temp(V);
        sort(temp.begin(), temp.end());
        int p, q;
        bool flag = true;
        for(int i = 0; i < V.size(); i++){
            if(V[i] != temp[i] && flag){
                p = V[i];
                flag = false;
            }
            if(V[i] != temp[i])
                q = V[i];
        }
        preorder(root, p, q);
    }
    void inorder(TreeNode* root, vector<int> &V){
        if(root){
            inorder(root->left, V);
            V.push_back(root->val);
            inorder(root->right, V);
        }
    }
    void preorder(TreeNode* root, int p, int q){
        if(root){
            if(root->val == p)
                root->val = q;
            else if(root->val == q) //±ØÐëÊ¹ÓÃif else
                root->val = p;
            preorder(root->left, p, q);
            preorder(root->right, p, q);
        }
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *root1 = new TreeNode(3);
    TreeNode *root2 = new TreeNode(2);
    root->left = root1;
    root1->right = root2;
    Solution S;
    S.recoverTree(root);
    return 0;
}
