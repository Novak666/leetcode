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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return vector<int>{};
        queue<TreeNode*> Q;
        vector<int> V;
        Q.push(root);
        Q.push(NULL);
        TreeNode *cur, *pre;
        while(!Q.empty()){
            cur = Q.front();
            Q.pop();
            if(!cur){
                if(Q.size() > 0)
                    Q.push(NULL);
            }
            else{
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                pre = cur;
                cur = Q.front();
                if(!cur) V.push_back(pre->val);
            }
        }
        return V;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
