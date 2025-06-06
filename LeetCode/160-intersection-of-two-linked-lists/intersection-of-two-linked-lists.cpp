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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp = headA;
        map<ListNode*, int>mpp;
        while(temp){
            mpp[temp]=1;
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            if(mpp[temp]) return temp;
            temp=temp->next;
        }
        return NULL;
    }
};