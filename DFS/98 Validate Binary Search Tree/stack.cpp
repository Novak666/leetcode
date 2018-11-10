#include <iostream>

using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        //��������ܱ���BST����С�������
        stack<TreeNode*> S;
        bool has_pre = false;
        int pre = 0; //�������ʼ��
        TreeNode* cur = root;
        while(cur || !S.empty()){
            if(cur){
                S.push(cur);
                cur = cur->left;
            }
            else{
                cur = S.top();
                S.pop();
                if(has_pre && cur->val <= pre) //��һ����has_pre���Ʋ�����
                    return false;
                has_pre = true;
                pre = cur->val;
                cur = cur->right;
            }
        }
        return true;
    }
};

int main()
{
    TreeNode *root = new TreeNode(2);
    TreeNode *left = new TreeNode(1);
    TreeNode *right = new TreeNode(3);
    root->left = left;
    root->right = right;
    Solution S;
    bool s = S.isValidBST(root);
    cout << LONG_MIN << endl;
    cout << INT_MIN << endl;
    return 0;
}
