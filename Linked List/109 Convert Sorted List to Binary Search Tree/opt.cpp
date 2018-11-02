//先递归，dfs再写入数据，一次遍历数据time O(n)
class Solution {
public:
    ListNode *node;
    int len(ListNode *head){
        ListNode *p = head;
        int len = 0;
        while(p){
            len++;
            p = p->next;
        }
        return len;
    }
    TreeNode *generate(int n){
        if(!n)
            return NULL;
        TreeNode *root = new TreeNode(0);
        root->left = generate(n / 2);
        root->val = node->val;
        node = node->next;
        root->right = generate(n - n / 2 - 1);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        node = head;
        return generate(len(head));
    }
};
