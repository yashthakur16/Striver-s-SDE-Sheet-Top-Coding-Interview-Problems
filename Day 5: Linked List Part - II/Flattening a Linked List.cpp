//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    
    Node *mergeHead(Node *l1,Node* l2)
    {
        Node* temp=new Node(0);
        Node* dummy=temp;
        
        
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->data<l2->data)
            {
                dummy->bottom=l1;
               
                l1=l1->bottom;
            }
            else
            {
                dummy->bottom=l2;
                l2=l2->bottom;
            }
             dummy->next=NULL;
            dummy=dummy->bottom;
        }
        
        if(l1!=NULL)
        {
            dummy->bottom=l1;
        }
        
        if(l2!=NULL)
        {
            dummy->bottom=l2;
        }
        
        return temp->bottom;
    }
    
    Node *merge(Node *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        
        Node* newHead=merge(head->next);
        
        return mergeHead(newHead,head);
    }
    
    Node *flatten(Node *root) 
    {
        Node *Ans=merge(root);
        
        return Ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends
