#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode *cur = &head, *p = l1, *q = l2;
        int carry = 0;
        while(p != NULL || q != NULL){
            int x = (p != NULL) ? p->val : 0;
            int y = (q != NULL) ? q->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(p != NULL) p = p->next;
            if(q != NULL) q = q->next;
        }
        if(carry)
            cur->next = new ListNode(carry);
        return head.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
