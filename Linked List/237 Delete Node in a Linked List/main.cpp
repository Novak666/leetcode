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
    void deleteNode(ListNode* node) {
        ListNode* p;
        node->val = node->next->val;
        p = node->next;
        node->next = node->next->next;
        delete p;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
