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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode * temp=head;
        if(temp->next==NULL){
            head=NULL;
            return head;
        }
        int count =0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp =head;
        int mid=(count/2)+1;//4
        for(int i=0; i<mid-2; i++){
            temp=temp->next;
        }
        if(temp->next->next==NULL){
            temp->next=NULL;
            return head;
        }
        temp->next=temp->next->next;
        return head;
    }
};