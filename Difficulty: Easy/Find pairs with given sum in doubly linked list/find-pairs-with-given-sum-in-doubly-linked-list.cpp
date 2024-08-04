//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        
        vector<pair<int, int>>ans;
        Node* front= head;
        Node* back=head;
        while(back->next!=NULL){
            back=back->next;
        }
        while(front->data < back->data){
            int d1= front->data;
            int d2= back->data;
            
            int sum = d1+d2;
            if(sum==target){
                ans.push_back({d1,d2});
                front=front->next;
                back=back->prev;
            }
            else if(sum>target){
                back=back->prev;
            }
            else{
                front=front->next;
            }
        }
        
        
        // while(temp1->next!=NULL){
        //     Node* temp2=temp1->next;
        //     while(temp2!=NULL){
        //       if((temp1->data)+(temp2->data)==target){
        //         ans.push_back({temp1->data,temp2->data});
        //     }
        //     temp2=temp2->next;
        //     }
        //     temp1=temp1->next;
            
        // }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends