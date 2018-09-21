#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> V(h);
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            TreeNode* p = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            if(p){ //Ð¡ÐÄÂ©µô
                V[level].push_back(p->val);
                Q.push({p->left, level + 1});
                Q.push({p->right, level + 1});
            }
        }
        return V;
    }
    int height(TreeNode* root){
        if(!root)
            return NULL;
        return max(height(root->left), height(root->right)) + 1;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
