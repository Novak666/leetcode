#include <iostream>

using namespace std;

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        mypush(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *min = S.top();
        S.pop();
        mypush(min->right);
        return min->val;
    }
private:
    stack<TreeNode *> S;
    void mypush(TreeNode *root){
        while(root){
            S.push(root);
            root = root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
