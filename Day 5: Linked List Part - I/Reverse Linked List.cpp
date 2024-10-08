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

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* next=head->next;

        while(next!=NULL)
        {
            curr->next=prev;
            prev=curr;
            curr=next;
            next=curr->next;
        }

            curr->next=prev;
            prev=curr;

        return prev;
    }
    
    ListNode* reverseList(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }

        ListNode *ans=reverse(head);
        return ans;
        
    }
};
