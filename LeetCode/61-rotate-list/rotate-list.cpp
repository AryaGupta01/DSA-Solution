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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(head==NULL) return head;
        int count=1;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
        temp->next=head;
        temp=head;
        k=k%count;
        for(int i=1; i<count-k;i++){
            temp=temp->next;

        }
        head=temp->next;
        temp->next=NULL;
        return head;
        
    }
};