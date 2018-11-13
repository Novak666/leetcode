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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        //stack������������ ������·������һ��while��һ��ǰ�������Ϊ�ܷ�����ҽ��ı�־
        vector<vector<int>> paths;
        vector<int> path;
        stack<TreeNode*> S;
        int val = 0;
        TreeNode *pre = NULL, *cur = root;
        while(cur || !S.empty()){
            while(cur){
                S.push(cur);
                val += cur->val;
                path.push_back(cur->val);
                cur = cur->left;
            }
            cur = S.top();
            if(val == sum && !cur->left && !cur->right)
                paths.push_back(path);
            if(cur->right && cur->right != pre)
                cur = cur->right;
            else{
                path.pop_back();
                S.pop();
                val -= cur->val;
                pre = cur;
                cur = NULL;
            }
        }
        return paths;
    }
};
