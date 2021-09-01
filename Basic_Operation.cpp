#include<bits/stdc++.h>
using namespace std;

//Defining Node by using class or you can also use structure.

class node{
public:
  int data;
  node* next;
}*first=NULL;

//Counting number of nodes in a linked list by iterative method

int countNode(node* p)
{
  int c=0;
  while(p)
  {
    c++;
    p=p->next;
  }
  return c;
}

//Counting number of nodes in a linked list by recursive method

int RecursiveCountNode(node* p)
{
  if(p!=NULL)
  {
    return RecursiveCountNode(p->next)+1;
  }
  else
  {
    return 0;
  }
}

// Finding sum of a given linked list by iterative method

int sum(node* p)
{
  int s=0;
  while(p!=NULL)
  {
    s=s+p->data;
    p=p->next;

  }
  return s;
}

// Finding sum of a given linked list by recursive method

int RecursiveSum(node* p)
{
  if(p!=NULL)
  {
    return RecursiveSum(p->next)+p->data;

  }
  else
  {
    return 0;
  }
}

//Finding maximum value in linked list by iterative method

int max(node* p)
{
  int m=INT_MIN;
  while(p!=NULL)
  {
    if(p->data>m)
    m=p->data;
    p=p->next;
  }
  return m;
}

//Finding maximum value in linked list by recursive method

int Rmax(node* p)
{
  int x=0;
  if(p==NULL)
  {
    return INT_MIN;
  }
  else
  {
    x=Rmax(p->next);
    if(x>p->data)
    {
      return x;
    }
    else
    {
      return p->data;
    }
  }
}

//........Alternative method.....

int R1max(node* p)
{
  int x=0;
  if(p==NULL)
  {
    return INT_MIN;
  }
  x=Rmax(p->next);
  return x>p->data?x:p->data; // Ternary operator
} 

// Linear Search in linked list

node* Lsearch(node* p,int key)
{
  while(p!=NULL)
  {
    if(key==p->data)
    {
      return p;
    }
    p=p->next;
  }

  return NULL;
}

//Recursive Search in Linked list

node* Rsearch(node* p,int key)
{
  if(p==NULL)
  {
    return NULL;
  }
  if(key==p->data)
  {
    return p;
  }
  else
  {
    return Rsearch(p->next,key);
  }
}

//Improving Linear Search reducing time complexity

node* ImprovedSearch(node* p,int key)
{
  node* q;
  while(p!=NULL)
  {
    if(key==p->data)
    {
      q->next=p->next;
      p->next=first;
      first=p;
      return p;

    }
    q=p;
    p=p->next;

  }

  return NULL;
}

//Inserting a node in linked list i.e in the beginning of linked list or in any given index

void Insert(node* p,int index,int x)
{
  node* t;
  if(index<0 || index>countNode(p))
  {
    return;

  }
  t=new node;
  t->data=x;
  if(index==0)
  {
    t->next=first;
    first=t;
  }
  else
  {
    p=first;
    for(int i=0;i<index-1;i++)
    {
      p=p->next;
    }
    t->next=p->next;
    p->next=t;
  }
}

//Inserting an element in a sorted linked list

void sortedList(node* p,int x)
{
  node* t,*q=NULL;
  t=new node;
  t->data=x;
  t->next=NULL;
  if(first==NULL)
  {
    first=t;
  }
  else
  {
    while(p && p->data<x)
    {
      q=p;
      p=p->next;
    }
    if(p==first)
    {
      t->next=first;
      first=t;
    }
    else
    {
      t->next=q->next;
      q->next=t;
    }
  }
}

//Deleting a node in a linked list

int deleteNode(node* p,int index)
{
  node* q=NULL;
  int x=-1;

  if(index<0 || index>countNode(p))
    return -1;

  if(index==1)
  {
    q=first;
    x=first->data;
    first=first->next;
    delete q;
    return x;
  }
  else
  {
    for(int i=0;i<index-1;i++)
    {
      q=p;
      p=p->next;
    }
    q->next=p->next;
    x=p->data;
    delete p;
    return x;
  }
}

//Check if linked list is sorted or not

int isSorted(node* p)
{
  int x=INT_MIN;
  while(p!=NULL)
  {
    if(p->data<x)
      return false;
    x=p->data;
    p=p->next;
  }
  return true;
}

//Removing duplicate element in a sorted linked list

void removeDuplicate(node* p)
{
  node *q=p->next;
  while(q!=NULL)
  {
    if(p->data!=q->data)
    {
      p=q;
      q=q->next;
    }
    else
    {
      p->next=q->next;
      delete q;
      q=p->next;
    }
  }
}

// Reversing a linked list by reversing the link

void Reverse1(node* p)
{
  node *q=NULL;
  node *r=NULL;
  while(p!=NULL)
  {
    r=q;
    q=p;
    p=p->next;
    q->next=r;
  }
  first=q;
}

// Reversing a linked list by recursive method

void Reverse2(node *q,node* p)
{
  if(p!=NULL)
  {
    Reverse2(p,p->next);
    p->next=q;
  }
  else
  {
    first=q;
  }
}

// Function to print the element of linked list

void display(node* p)
{
  while(p!=NULL)
  {
    cout<<p->data<<"->";
    p=p->next;
  }
  cout<<endl;
}


//Creating and displaying linked list in main function
 
int main(int argc, char const *argv[])
{
  
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  first=new node;
  node* temp;
  first->data=arr[0];
  first->next=NULL;
  node* last=new node;
  last=first;

  for(int i=1;i<n;i++)
  {
    temp=new node;
    temp->data=arr[i];
    temp->next=NULL;

    last->next=temp;
    last=temp;
  }

  display(first);

  cout<<"Number of node by iterative="<<countNode(first)<<endl;
  cout<<"Number of nodes by Recursive="<<RecursiveCountNode(first)<<endl;

  cout<<"Sum by iterative="<<sum(first)<<endl;
  cout<<"Sum by Recursive="<<RecursiveSum(first)<<endl;

  cout<<"Maximum value by iterative method="<<max(first)<<endl;
  cout<<"Maximum value by recursive method="<<Rmax(first)<<endl;

  // node* t;
  // t=ImprovedSearch(first,3);
  // if(t)
  // {
  //   cout<<"Element found is "<<t->data<<endl;
  // }
  // else
  // {
  //   cout<<"Element Not Found"<<endl;
  // }

  // display(first);

  // Insert(first,3,122);
  // display(first);

  // sortedList(first,45);
  // display(first);

  // cout<<"Deleted element "<<deleteNode(first,7)<<endl;
  // display(first);

  if(isSorted(first))
  {
    cout<<"Linked list is sorted"<<endl;
  }
  else
  {
    cout<<"Linked list is not sorted"<<endl;
  }

  removeDuplicate(first);
  display(first);

  // Reverse1(first);
  // display(first);

  Reverse2(NULL,first);
  display(first);






  return 0;
}