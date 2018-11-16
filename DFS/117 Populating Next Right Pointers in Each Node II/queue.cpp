#include <iostream>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        queue<TreeLinkNode *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            TreeLinkNode *cur = Q.front();
            Q.pop();
            if(!cur){
                if(Q.size() > 0) //判断结束的标志
                    Q.push(NULL);
            }
            else{
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
                TreeLinkNode *pre = cur;
                cur = Q.front();
                pre->next = cur;
            }
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
