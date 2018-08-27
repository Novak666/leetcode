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
    bool isPalindrome(ListNode* head) {
        vector <int> V;
        ListNode* p = head;
        while(p){
            V.push_back(p->val);
            p = p->next;
        }
        for(int i = 0; i < V.size() / 2; i++)
            if(V[i] != V[V.size() - i - 1])
                return false;
        return true;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
