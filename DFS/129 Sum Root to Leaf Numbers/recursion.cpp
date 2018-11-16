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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int sum = 0;
        string s = "";
        recursion(root, sum, s);
        return sum;
    }
    void recursion(TreeNode* root, int &sum, string &s){
        s += to_string(root->val);
        if(!root->left && !root->right)
            sum += stoi(s);
        if(root->left) recursion(root->left, sum, s);
        if(root->right) recursion(root->right, sum, s);
        s.pop_back();
    }
};

int main()
{
    string s;
    test("");
    cout << s << endl;
    return 0;
}
