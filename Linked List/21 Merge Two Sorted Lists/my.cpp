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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL;
        if(!l1)
            return l2;
        else if(!l2)
            return l1;
        else
        {
            ListNode *p, *q, *r, *s;
            p = l1; q = l2;
            while(p && q)
            {
                if(p->val <= q->val)
                {
                    r = p;
                    p = p->next;
                    if(!l3)
                        l3 = s = p;
                    else
                    {
                        s->next = r;
                        s = s->next;
                    }
                }
                else
                {
                    r = q;
                    q = q->next;
                    if(!l3)
                        l3 = s = q;
                    else
                    {
                        s->next = r;
                        s = s->next;
                    }
                }
            }
            if(!p)
                s->next = q;
            else
                s->next = p;
        }
        return l3;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
