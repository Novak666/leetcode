#include <iostream>

using namespace std;

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        while(root){
            TreeLinkNode *head = root;
            while(root){
                if(!root->left) break;
                root->left->next = root->right;
                if(root->next)
                    root->right->next = root->next->left;
                root = root->next;
            }
            root = head->left;
        }
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
