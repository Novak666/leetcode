
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return head;
        ListNode p(0);  //Í·½áµã
        ListNode *cur = &p;
        p.next = head;
        while(cur->next){
            if(cur->next->val == val){
                ListNode *q = cur->next;
                cur->next = cur->next->next;
                delete q;
            }
            else
                cur = cur->next;
        }
        return p.next;
    }
};
