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
        if(begin > end){ //边界条件
            V.push_back(NULL);
            return V;
        }
        for(int i = begin; i <= end; i++){ //以i为根
            vector<TreeNode*> left = generate(begin, i - 1); //左边子树的排列
            vector<TreeNode*> right = generate(i + 1, end);  //右边子树的排列
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
