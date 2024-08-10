//{ Driver Code Starts
// Initial Template for C++
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
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution {
  public:
    // Function to rotate a linked list.
    Node* rotate(Node* head, int k) 
    {
        // Your code here
       vector<int>dummy;
       convert(head,dummy,k);
       Node* temp=head;
       int i=0;
       while(temp!=NULL)
       {
           temp->data=dummy[i];
           temp=temp->next;
           i++;
       }
       return head;
    }
    void convert(Node* head,vector<int>& dummy,int k)
    {
        vector<int>temp1;
        Node* temp=head;
        while(temp!=NULL)
        {
            temp1.push_back(temp->data);
            temp=temp->next;
        }
        for(int i=0;i<temp1.size();i++)
        {
            dummy.push_back(temp1[(i+k)%temp1.size()]);
        }
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends