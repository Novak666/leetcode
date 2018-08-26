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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        if(!head)
            return head;
        while(p->next){
            if(p->val == p->next->val){
                ListNode* q = p->next;
                p->next = p->next->next;
                delete q;
            }
            else
                p = p->next;
        }
        return head;
    }
};
