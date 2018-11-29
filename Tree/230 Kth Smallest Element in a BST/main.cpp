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
private:
    int count = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        int num = 0;
        travel(root, k, num);
        return num;
    }
    void travel(TreeNode* root, int k, int &num){
        if(root){
            travel(root->left, k, num);
            if(++count == k){
                num = root->val;
                return;
            }
            travel(root->right, k, num);
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
