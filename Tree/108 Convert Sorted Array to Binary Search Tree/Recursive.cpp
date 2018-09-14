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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return BST(nums, 0, nums.size() - 1);
    }
    TreeNode* BST(vector<int>& nums, int low, int high){
        TreeNode* node = NULL;
        if(low <= high){
            int mid = (low + high) / 2;
            node = new TreeNode(nums[mid]);
            node->left = BST(nums, low, mid - 1);
            node->right = BST(nums, mid + 1, high);
        }
        return node;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
