#include <iostream>

using namespace std;

class Solution {
public:
    //**important** find mid node, and create a new node, divide the list into left and right, and then conquer
    //time: O(nlogn); space: O(logn). T(n) = 2T(n/2) + O(n)
    TreeNode* sortedListToBST(ListNode* head) {
        return dfs(head, NULL);
    }
    TreeNode* dfs(ListNode* head, ListNode* end){
        if(head == end)
            return NULL;
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = dfs(head, slow);
        node->right = dfs(slow->next, end);
        return node;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
