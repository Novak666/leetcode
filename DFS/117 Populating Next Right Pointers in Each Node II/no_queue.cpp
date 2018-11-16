class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)   return;
        TreeLinkNode *cur = root, *head = NULL, *tail = NULL;
        while(cur) {
            if(cur->left) {
                if(tail) {
                    tail->next = cur->left;
                    tail = tail->next;
                } else {
                    head = cur->left;
                    tail = cur->left;
                }
            }
            if(cur->right) {
                if(tail) {
                    tail->next = cur->right;
                    tail = tail->next;
                } else {
                    head = cur->right;
                    tail = cur->right;
                }
            }
            if(cur->next)
                cur = cur->next;
            else {
                cur = head;
                head = NULL;
                tail = NULL;
            }
        }
    }
};
