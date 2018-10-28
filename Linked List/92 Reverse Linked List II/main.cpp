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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode start(0);
        ListNode *p = &start, *q, *end;
        int i = 1;
        while(i < m){
            q = head->next;
            head->next = p->next;
            p->next = head;
            head = q;
            p = p->next;
            i++;
        }
        end = head;
        while(i <= n){
            q = head->next;
            head->next = p->next;
            p->next = head;
            head = q;
            i++;
        }
        end->next = head;
        return start.next;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
