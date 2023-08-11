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
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //节点范围在1~100之间
        ListNode *L=new ListNode();
        ListNode *p=L,*q;
        while(l1!=nullptr&&l2!=nullptr){
            int val=l1->val+l2->val+p->val;
            p->val=val%10;
            ListNode *temp=new ListNode(val/10);
            temp->next=p->next;
            p->next=temp;
            q=p;
            p=p->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1!=nullptr){
            while(l1!=nullptr){
                int val=l1->val+p->val;
                p->val=val%10;
                ListNode *temp=new ListNode(val/10);
                temp->next=p->next;
                p->next=temp;
                q=p;
                p=p->next;
                l1=l1->next;
            }
        }
        if(l2!=nullptr){
            while(l2!=nullptr){
                int val=l2->val+p->val;
                p->val=val%10;
                ListNode *temp=new ListNode(val/10);
                temp->next=p->next;
                p->next=temp;
                q=p;
                p=p->next;
                l2=l2->next;
            }
        }
        if(p->next==nullptr&&p->val==0){
            q->next=nullptr;
        }
        return L;
    }
};