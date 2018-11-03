#include <iostream>

using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){ //����ָ���ҵ��е㣬������������ż�����ȵ����
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;  //��ת�ڶ�������
        fast = head2->next;
        head2->next = NULL;
        while(fast){  //
            slow = fast->next;
            fast->next = head2;
            head2 = fast;
            fast = slow;
        }
        slow = head;
        fast = head2;     //�ϲ�
        for(; slow;){
          auto temp = slow->next;
            slow->next = fast;
            slow = slow->next;
            fast = temp;
        }
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *head1 = new ListNode(2);
    head->next = head1;
    Solution S;
    S.reorderList(head);
    cout << "Hello world!" << endl;
    return 0;
}
