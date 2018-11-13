#include <iostream>

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *cur = root;  //左子树变到右子树
        while(cur){
            if(cur->left){
                TreeNode *pre = cur->left;
                while(pre->right)
                    pre = pre->right;
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
