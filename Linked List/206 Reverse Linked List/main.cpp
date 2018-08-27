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
    ListNode* reverseList(ListNode* head) {
        ListNode *p, *q;  //��ͷ�����Լ򻯲���
        p = NULL;
        while(head){
            q = head->next;
            head->next = p;
            p = head;
            head = q;
        }
        return p;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
