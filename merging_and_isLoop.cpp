#include<bits/stdc++.h>
using namespace std;

//Creating Node of a linked list

class Node
{
public:
  int data;
  Node *next;
}*first=NULL,*second=NULL,*third=NULL;

//Creating first linked list

void create(int A[],int n)
{
  Node *t,*last;
  first=new Node;
  first->data=A[0];
  first->next=NULL;
  last=first;
   
  for(int i=1;i<n;i++)
  {
    t=new Node;
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
} 

//creating second linked list

void create2(int A[],int n)
{
  Node *t,*last;
  second=new Node;
  second->data=A[0];
  second->next=NULL;
  last=second;
 
  for(int i=1;i<n;i++)
  {
    t=new Node;
    t->data=A[i];
    t->next=NULL;
    last->next=t;
    last=t;
  }
}

//Merging two linked list

void Merge(Node *p,Node *q)
{
  Node *last;

  if(p->data < q->data)
  {
    third=last=p;
    p=p->next;
    third->next=NULL;
  }
  else
  {
    third=last=q;
    q=q->next;
    third->next=NULL;
  }

  while(p && q)
   {
    if(p->data < q->data)
    {
      last->next=p;
      last=p;
      p=p->next;
      last->next=NULL;
    }
    else
    {
      last->next=q;
      last=q;
      q=q->next;
      last->next=NULL;
    }
   }

   if(p) last->next=p;
   if(q) last->next=q;
 
}

//Display a linked list

void Display(Node *p)
{
  while(p!=NULL)
  {
    cout<<p->data<<"->";
    p=p->next;
  }
  cout<<endl;
}

// Detecting a loop in linked list

bool isLoop(Node* first)
{
  Node *p,*q;
  p=q=first;
  do
  {
    p=p->next;
    q=q->next;
    q=q?q->next:q;
  }while(p && q && p!=q);

  if(p==q)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Creating main funtion
int main()
{
 
  int A[]={10,20,40,50,60}; 
  int B[]={15,18,25,30,55};
  create(A,5);
  create2(B,5);
  Display(first);
  Display(second);
 
 
  Merge(first,second); 
  Display(third); 

  cout<<isLoop(first);
 
 return 0;
}