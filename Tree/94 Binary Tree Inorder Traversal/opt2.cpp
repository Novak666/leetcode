/*1. �����ǰ�ڵ������Ϊ�գ��������ǰ�ڵ㲢�����Һ�����Ϊ��ǰ�ڵ㡣

2. �����ǰ�ڵ�����Ӳ�Ϊ�գ��ڵ�ǰ�ڵ�����������ҵ���ǰ�ڵ�����������µ�ǰ���ڵ㡣

   a) ���ǰ���ڵ���Һ���Ϊ�գ��������Һ�������Ϊ��ǰ�ڵ㡣��ǰ�ڵ����Ϊ��ǰ�ڵ�����ӡ�

   b) ���ǰ���ڵ���Һ���Ϊ��ǰ�ڵ㣬�������Һ���������Ϊ�գ��ָ�������״���������ǰ�ڵ㡣��ǰ�ڵ����Ϊ��ǰ�ڵ���Һ��ӡ�

3. �ظ�����1��2ֱ����ǰ�ڵ�Ϊ�ա�
*/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> V;
        TreeNode *cur = root, *pre = NULL;
        while(cur != NULL){
            if(cur->left == NULL){
                V.push_back(cur->val);
                cur = cur->right;
            }
            else{
                pre = cur->left;
                while(pre->right != NULL && pre->right != cur)
                    pre = pre->right;
                if(pre->right == NULL){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    V.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return V;
    }
};
