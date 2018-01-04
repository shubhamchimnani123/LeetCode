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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l = l1;
        ListNode* r = l2;
        int s = (l->val + r->val) % 10;
        int y = (l->val + r->val) / 10;
        ListNode* h = new ListNode(s);
        ListNode* c = h;
        
        while(l->next!=NULL && r->next!=NULL){
            l = l->next;
            r = r->next;
            s = (l->val + r->val + y) % 10;
            y = (l->val + r->val + y) / 10;
            c->next = new ListNode(s);
            c = c->next;
        }
        if(l->next == NULL)
            l = r;
        while(l->next!=NULL){
            l = l->next;
            s = (l->val + y) % 10;
            y = (l->val  + y) / 10;
            c->next = new ListNode(s);
            c = c->next;
        }
        if(y==1){
            c->next = new ListNode(1);
            c = c->next;
        }
        return h;       
    }
};