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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
     ListNode* temp1= list1;
     ListNode* temp2= list2;  
     ListNode* dummy= new ListNode(-1);
     ListNode* newList= dummy;
     while(temp1!=NULL && temp2!=NULL){
        if(temp1->val<temp2->val){
            newList->next=temp1;
            newList=newList->next;
            temp1=temp1->next;
        }
        else{
            newList->next=temp2;
            newList=newList->next;
            temp2=temp2->next;
        }
     }
     if(temp1==NULL){
        while(temp2!=NULL){
            newList->next=temp2;
            newList=newList->next;
            temp2=temp2->next; 
        }
     }
     else {
        while(temp1!=NULL){
            newList->next=temp1;
            newList=newList->next;
            temp1=temp1->next;
        }
     }
     return dummy->next;
    }
};