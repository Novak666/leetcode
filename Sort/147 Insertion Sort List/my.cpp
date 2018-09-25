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
    ListNode* insertionSortList(ListNode* head) {
        ListNode node(0);
        ListNode *p, *q = head;
        while(q){
            p = &node;
            while(p->next && p->next->val < q->val)
                p = p->next;
            ListNode *r = q;
            q = q->next;
            r->next = p->next;
            p->next = r;
        }
        return node.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
