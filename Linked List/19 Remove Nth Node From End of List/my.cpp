#include <iostream>

using namespace std;

 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        head = reverse(head);
        int i = 0;
        ListNode start(0);
        start.next = head;
        ListNode *p = &start;
        while(i != n - 1){
            p = p->next;
            i++;
        }
        ListNode *temp = p->next;
        p->next = p->next->next;
        delete temp;
        return reverse(start.next);
    }
    ListNode* reverse(ListNode* head){
        if(!head)
            return NULL; //±ðÂ©ÁË£¡£¡£¡
        ListNode start(0);
        //start.next = head;
        ListNode *p = &start, *q;
        while(head){
            q = head->next;
            head->next = p->next;
            p->next = head;
            head = q;
        }
        return start.next;
    }
};

int main()
{
    ListNode *head, *head2, *head3, *head4, *head5;
    head = new ListNode(1);
    //head->val = 0;
    head2 = new ListNode(2);
    head3 = new ListNode(3);
    head4 = new ListNode(4);
    head5 = new ListNode(5);
    head->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    ListNode* p = head;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }
    Solution S;
    head = S.removeNthFromEnd(head, 2);
    p = head;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
