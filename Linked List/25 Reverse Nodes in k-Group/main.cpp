#include <iostream>

using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode start(0);
        start.next = head;
        ListNode *begin = &start, *end = &start;
        for(int i = 0; end; i++, end = end->next){ //±ß½çÌõ¼þ
            if(i == k){
                ListNode *next_begin =  end->next;
                begin = end = reverse(begin, k);
                end->next = next_begin;
                i = 0;
            }
        }
        return start.next;
    }
    ListNode* reverse(ListNode* begin, int k){
        ListNode *temp = begin->next, *p = begin->next->next;
        k--;
        while(k > 0){
            ListNode *q = p->next;
            p->next = begin->next;
            begin->next = p;
            p = q;  //ÒÅÂ©
            k--;
        }
        return temp;
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
    Solution S;
    S.reverseKGroup(head, 3);
    cout << "Hello world!" << endl;
    return 0;
}
