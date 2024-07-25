//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>

/* a Node of the doubly linked list */
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends
/* Structure of Node
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;

  Node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        Node* temp=head;
        Node* back=NULL;
        Node* front=NULL;
        int cnt=1;
        while(temp){
            if(cnt==x){
               break;
            }
                temp=temp->next;
                cnt++;
            }
            front=temp->next;
            back=temp->prev;
            if(back==NULL) // We have to delete first node 
            {
                head=head->next;
                 front->prev=NULL;
                temp->next=NULL;
                delete temp;
            }
            else if(front==NULL)
            {
                temp->prev =NULL;
                back->next=NULL;
                delete temp;
            }
            else{
             temp->next=NULL;
                back->next=front;
                temp->prev=NULL;
                front->prev=back;
                delete temp;
            }
        return head;
    }
};

//{ Driver Code Starts.

/* Function to print Nodes in a given doubly linked list
   This function is same as printList() of singly linked lsit */
void printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above functions*/
int main() {
    int t, x, n, i;
    scanf("%d", &t);

    while (t--) {
        /* Start with the empty list */
        struct Node *temp, *head = NULL;
        scanf("%d", &n);

        temp = NULL;

        for (i = 0; i < n; i++) {
            scanf("%d", &x);

            if (head == NULL) {
                head = new Node(x);
                temp = head;
            } else {
                Node *temp1 = new Node(x);
                temp->next = temp1;
                temp1->prev = temp;
                temp = temp->next;
            }
        }

        scanf("%d", &x);

        Solution ob;
        head = ob.deleteNode(head, x);

        printList(head);
        while (head->next != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }

        free(head);
    }
    return 0;
}

// } Driver Code Ends