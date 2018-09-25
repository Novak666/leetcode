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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        vector<int> V;
        while(cur){
            V.push_back(cur->val);
            cur = cur->next;
        }
        sort(V.begin(), V.end());
        cur = head;
        for(int i = 0; i < V.size(); i++){
            cur->val = V[i];
            cur = cur->next;
        }
        return head;
    }
};
