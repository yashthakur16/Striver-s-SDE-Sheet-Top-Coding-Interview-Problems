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


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0;
        ListNode* ans=new ListNode(0,nullptr);
        ListNode* newHead=ans;
        while(l1!=nullptr && l2!=nullptr)
        {
            int data=carry+l1->val+l2->val;
            ListNode* node=new ListNode(data%10);
            ans->next=node;
            ans=ans->next;
            carry=data/10;
            l1=l1->next;
            l2=l2->next;
        }

        while(l1!=nullptr)
        {
             int data=carry+l1->val;
            ListNode* node=new ListNode(data%10);
            ans->next=node;
            ans=ans->next;
            carry=data/10;
            l1=l1->next;
        }

        while(l2!=nullptr)
        {
             int data=carry+l2->val;
            ListNode* node=new ListNode(data%10);
            ans->next=node;
            ans=ans->next;
            carry=data/10;
            l2=l2->next;
        }

        while(carry!=0)
        {
            int data=carry;
            ListNode* node=new ListNode(data%10);
            ans->next=node;
            ans=ans->next;
            carry=data/10;

        }
        newHead=newHead->next;
        return newHead;


        



    }
};
