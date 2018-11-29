#include <iostream>
#include <vector>

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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return generate(1, n);
    }
    vector<TreeNode*> generate(int begin, int end){
        vector<TreeNode*> V;
        if(begin > end){ //�߽�����
            V.push_back(NULL);
            return V;
        }
        for(int i = begin; i <= end; i++){ //��iΪ��
            vector<TreeNode*> left = generate(begin, i - 1); //�������������
            vector<TreeNode*> right = generate(i + 1, end);  //�ұ�����������
            for(int l = 0; l < left.size(); l++){
                for(int r = 0; r < right.size(); r++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[l];
                    root->right = right[r];
                    V.push_back(root);
                }
            }
        }
        return V;
    }
};

int main()
{
    cout << V.size() << endl;
    return 0;
}
