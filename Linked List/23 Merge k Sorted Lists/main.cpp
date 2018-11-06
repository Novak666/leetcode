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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);  //头结点简化了算法
        ListNode* p = &head;
        while(l1 && l2){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;  //没有多余的附加指针
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        return head.next;
    }
    void merge(vector<ListNode*>& lists, int &k){
        int n = k / 2;
        int i = 0;
        for(; i < n; i++)
            lists[i] = mergeTwoLists(lists[i * 2], lists[i * 2 + 1]);
        if(k % 2)
            lists[i] = lists[i * 2];
        k = n + k % 2;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(!k)
            return NULL;
        while(k != 1){
            merge(lists, k);
        }
        return lists[0];
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
