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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA)
            return NULL;
        if(!headB)
            return NULL;
        ListNode *a, *b;
        a = headA; b = headB;
        while(a && b){
            if(a->val != b->val){
                a = a->next;
                b = b->next;
            }
            else
                return a;
        }
        if(!a)
            a = headB;
        else
            b = headA;
        while(a && b){
            if(a->val != b->val){
                a = a->next;
                b = b->next;
            }
            else
                return a;
        }
        if(!a)
            a = headB;
        else
            b = headA;
        while(a && b){
            if(a->val != b->val){
                a = a->next;
                b = b->next;
            }
            else
                return a;
        }
        return NULL;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
