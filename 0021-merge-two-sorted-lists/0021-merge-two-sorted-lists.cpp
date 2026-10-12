/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(1000);
        ListNode* t = c;
        while(a != NULL && b != NULL){
            if(a->val <= b->val){
                t->next = a;
                a = a->next;
                t = t->next;
            }else{
                t->next = b;
                b = b->next;
                t = t->next;
            }
        }
        if(a != NULL)  t->next = a;
        else  t->next = b;
        return c->next;
    }
};