//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverseNode(Node* head){
      Node* temp=head;
      Node* back=NULL;
      while(temp){
          Node* front=temp->next;
          temp->next=back;
          back=temp;
          temp=front;
      }
      return back;
  }
    Node* addOne(Node* head) {
        head=reverseNode(head);
        Node* temp=head;
        int c=1;
        while(temp){
             temp->data=temp->data+c;
            if(temp->data<10){
                c=0;
                break;
            }
            else{
                temp->data=0;
                c=1;
            }
            temp=temp->next;
        }
        if(c==1){
            Node* newNode=new Node(1);
            head=reverseNode(head);
            newNode->next=head;
            return newNode;
        }
        head=reverseNode(head);
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends