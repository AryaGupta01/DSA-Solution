//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* a Node of the doubly linked list */
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x)
  {
      data = x;
      next = prev = NULL;
  }
};

void addNode(Node *head, int pos, int data);

Node *insert(Node *head, int x)
{
    if (head == NULL)
    {
        return new Node(x);
    }
    Node *n = new Node(x);
    
    head->next = n;
    n->prev = head;
    head = n;
    return head;
}

void printList(Node *head)
{
  // The purpose of below two loops is
  // to test the created DLL
  Node *temp=head;
  if (temp != NULL) {
    int ct1=0,ct2=0;
  while (temp->next!=NULL)
    temp=temp->next,ct1++;
  while (temp->prev!=NULL)
   temp = temp->prev,ct2++;
   if(ct1!=ct2){
       cout<<-1<<"\n";
       return;
   }
  }
  while (temp != NULL)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  
  cout << endl;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
  {
  Node *head = NULL; 
  Node *root = NULL;
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
     int x;
     scanf("%d",&x);
     head = insert(head, x);
     if(root==NULL) root = head;
  }     
  head = root;
  int pos,data;
  cin>>pos>>data;
  addNode(head, pos, data);
  printList(head);
  }
  return 0;
}
// } Driver Code Ends


/* a Node of the doubly linked list 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

//Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data)
{  
   Node*temp= new Node(data);
   Node*temp1=head;
   int length=0;


   while(temp1){
       length++;
       temp1=temp1->next;
   }
   if(pos>length)return;
   
   temp1=head;
   
   for(int i=1;i<=pos;i++){
       temp1=temp1->next;
   }
   temp->next=temp1->next;
   temp->prev=temp1;
   temp1->next=temp;
   if(temp->next!=nullptr)
   temp->next->prev=temp;
   
}