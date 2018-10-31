#include <iostream>

using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head && !head->next)
            return NULL;
        ListNode start(0);
        start.next = head;
        ListNode *pre = &start, *cur = start.next;
        while(cur){
            ListNode *p = cur;
            if(p->next && p->next->val == p->val){
                while(p->next && p->next->val == cur->val)
                    p = p->next;
                p = p->next;
                destroy(cur, p);
                pre->next = p;
                cur = p;
            }
            else{
                pre = pre->next;
                cur = cur->next;
            }
        }
        return start.next;
    }
    void destroy(ListNode* cur, ListNode* p){
        while(cur != p){
            ListNode *q = cur;
            cur = cur->next;
            delete q;
        }
    }
};

int main()
{

    Solution S;
    ListNode* head = new ListNode(1);
    ListNode* head2 = new ListNode(1);
    ListNode* head3 = new ListNode(1);
    ListNode* head4 = new ListNode(2);
    ListNode* head5 = new ListNode(3);
    head->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    ListNode* p = head;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }
    head = S.deleteDuplicates(NULL);
    p = head;
    while(p){
        cout << p->val << endl;
        p = p->next;
    }
    return 0;
}
