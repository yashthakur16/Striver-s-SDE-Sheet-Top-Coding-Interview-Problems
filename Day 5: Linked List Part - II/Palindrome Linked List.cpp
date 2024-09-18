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


    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        

        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=curr->next;

        while(Next!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=Next;
            Next=curr->next;
        } 
          
        curr->next=prev;
        prev=curr;

        return prev;

    }
    bool isPalindrome(ListNode* head) 
    {
        if(head==NULL||head->next==NULL)
        {
            return true;
        }
        ListNode* middle=findMiddle(head);

        ListNode* newHead=reverse(middle->next);
        ListNode* curr=head;
        ListNode* second=newHead;

        while(newHead!=NULL )
        {
            if(newHead->val!=curr->val)
            {
                reverse(second);
                return false;
            }
            newHead=newHead->next;
            curr=curr->next;
        }

        reverse(second);

        return true;
        
    }
};
