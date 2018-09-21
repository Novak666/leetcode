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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> V;
        TreeNode head(0);
        head.left = root;
        TreeNode *cur = &head, *pre = NULL;
        while(cur){
            if(!cur->left)
                cur = cur->right;
            else{
                pre = cur->left;
                while(pre->right && pre->right != cur)
                    pre = pre->right;
                if(!pre->right){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    reversePush(cur->left, pre, V);
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return V;
    }
    void reversePush(TreeNode* begin, TreeNode* end, vector<int> &V){
        reverse(begin, end); //修改指针,倒序输出
        TreeNode* cur = end;
        while(true){
            V.push_back(cur->val);
            if(cur == begin)
                break;   //小心出错
            cur = cur->right;
        }
        reverse(end, begin);
    }
    void reverse(TreeNode* begin, TreeNode* end){
        if(begin == end)
            return;
        TreeNode *x = begin, *y = begin->right, *z;
        while(x != end){
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
    }
};
