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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        int cnt=0;
        ListNode* curr=head;

        while(curr!=NULL)
        {
            curr=curr->next;
            cnt++;
        }

        k=k%cnt;


        for(int i=0;i<k;i++)
        {
            if(fast->next==NULL)
            {
                fast=head;
            }
            else
            {
                fast=fast->next;
            }
        }
        
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }

        if(slow->next==NULL)
        {
            return head;
        }
        
        ListNode* forward=slow->next;

        slow->next=NULL;

        fast->next=head;

        return forward;
        
    }
};
