#include <iostream>

using namespace std;



struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p = head;
        if(!head)
            return head;
        while(p->next){
            if(p->val == val){
                p->val = p->next->val;
                ListNode* q = p->next;
                p->next = p->next->next;
                delete q;
            }
            else
                p = p->next;
        }
        if(p->val == val){
            delete p;   //典型错误,好好理解delete究竟在干嘛
            p = NULL;
        }
        return head;
    }
};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* k = new ListNode(6);
    head->next = k;
    ListNode* p = new ListNode(2);
    k->next = p;
    ListNode* q = new ListNode(6);
    p->next = q;
    Solution S;
    head = S.removeElements(head, 6);
    ListNode* r = head;
    while(r){
        cout << r->val << endl;
        r = r->next;
    }
    return 0;
}
