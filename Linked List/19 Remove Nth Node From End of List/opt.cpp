//一次遍历完成操作
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode start(0);
        start.next = head;
        ListNode *p = &start, *q = &start;
        for(int i = 0; i <=n; i++)
            p = p->next;
        while(p){
            p = p->next;
            q = q->next;
        }
        ListNode *temp = q->next;
        q->next = q->next->next;
        delete temp;
        return start.next;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode(0);
        start->val = 0;
        start->next = head;
        ListNode *p = start, *q = start;
        for(int i = 0; i <=n; i++)
            p = p->next;
        while(p){
            p = p->next;
            q = q->next;
        }
        ListNode *temp = q->next;
        q->next = q->next->next;
        delete temp;
        return start->next;
    }
};
