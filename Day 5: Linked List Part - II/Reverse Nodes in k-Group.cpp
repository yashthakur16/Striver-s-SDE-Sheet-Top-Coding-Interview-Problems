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
        if(head==nullptr || head->next==nullptr)
        {
            return head;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=curr->next;

        while(Next!=nullptr)
        {
            curr->next=prev;
            prev=curr;
            curr=Next;
            Next=curr->next;
        }
        curr->next=prev;
            prev=curr;
            curr=Next;
            return prev;
    }

    ListNode* findNode(ListNode* curr, int k)
    {
        for(int i=0;i<k-1&&curr!=NULL;i++)
        {
            curr=curr->next;
        }

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode* temp=head;
        
        ListNode* prev=nullptr;

        while(temp!=NULL)
        {
            ListNode* kthNode=findNode(temp,k);

            if(kthNode==NULL)
            {
                break;
            }

            ListNode*nextNode=kthNode->next;
            kthNode->next=NULL;

            reverse(temp);
            
            if(temp==head)
            {
                head=kthNode;
                
            }
            else
            {
                prev->next=kthNode;
                       
            }
            prev=temp;
            
            temp->next=nextNode;
            temp=temp->next;
            

        
        }
        return head;
        
    }
};
