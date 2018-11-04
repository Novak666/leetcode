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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        ListNode *p = head;
        int len = 0;
        while(p->next){
            len++;
            p = p->next;
        }
        len++;
        ListNode *end = p;
        k = k % len;
        if(k == 0)
            return head;
        int i = 0;
        p = head;
        while(i < len - k - 1){
            i++;
            p = p->next;
        }
        end->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
