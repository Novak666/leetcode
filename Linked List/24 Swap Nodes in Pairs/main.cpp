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
    ListNode* swapPairs(ListNode* head) {
        ListNode start(0);
        start.next = head;
        ListNode *p = &start;
        while(p->next && p->next->next){
            ListNode *q = p->next;
            p->next = p->next->next;
            ListNode *r = p->next;
            q->next = r->next;
            r->next = q;
            p = p->next->next;
        }
        return start.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
