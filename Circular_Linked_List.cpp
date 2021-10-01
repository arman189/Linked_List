//Circular Linked List

#include<bits/stdc++.h>
using namespace std;

//Defining node

class node
{
public:
  int data;
  node* next;
}*first;

//Function to create a linked list using array

void create(int arr[],int n)
{
  node *t,*last;
  first=new node;
  first->data=arr[0];
  first->next=first;
  last=first;

  for(int i=1;i<n;i++)
  {
    t=new node;
    t->data=arr[i];
    t->next=last->next;
    last->next=t;
    last=t;
  }
}

//Length of a circular linked list

int length(node *p)
{
  int len=0;
  do
  {
    len++;
    p=p->next;
  }while(p!=first);
  return len;
}

//Inserting in a circular linked list

void insert(node *p,int index,int x)
{
  node *t;
  if(index<0 || index>length(p))
  {
    return;
  }
  if(index==0)
  {
    t=new node;
    t->data=x;
    if(first==NULL)
    {
      first=t;
      first->next=first;
    }
    else
    {
      while(p->next!=first)
      {
        p=p->next;
      }
        p->next=t;
        t->next=first;
        first=t;
      
    }
  }
  else
  {
    for(int i=0;i<index-1;i++)
    {
      p=p->next;
    }
    t=new node;
    t->data=x;
    t->next=p->next;
    p->next=t;
  }
}

//Display an element in a linked list by iterative

void display(node* p)
{
  do
  {
    cout<<p->data<<"->";
    p=p->next;
  }while(p!=first);
  cout<<endl;
}

//Function to print an element in a linked list by recursive method

// void Rdisplay(node* p)
// {
//   static int flag=0;
//   while(p!=first || flag==0 )
//   {
//     flag=1;
//     cout<<p->data<<"->";
//     Rdisplay(p->next);
//   }
//   flag=0;
// }

//Main function

int main(int argc, char const *argv[])
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }

  create(arr,n);
  display(first);

  cout<<"Length of circular linked list= "<<length(first)<<endl;

  insert(first,4,55);
  display(first);
  return 0;
}