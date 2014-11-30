#include<iostream>
using namespace std;
struct Node{
           int data;
           Node *next;
           }*head,*rear,*ptr,*save,*ptr1,*new1;
           void insert(Node*);
           void insert1();
           void display();
           int choice;
int main()
{
    
           int n,i;head=rear=NULL;
           cout<<"Enter n:"<<endl;
           cin>>n;
           for(i=0;i<n;i++)
           {
              ptr=new Node;
              cin>>ptr->data;
              ptr->next=NULL;
              insert(ptr);
              }
             // insert1();
              display();
              system("pause");
              return 0;
}
void insert(Node* ptr)
{
     if(head==NULL){head=rear=ptr;}
     else {ptr->next=head;head=ptr;
           }
}
/*void insert1()
{
     new1=new Node;
     cin>>new1->data;new1->next=NULL;
     cin>>choice;int i=1;ptr1=head;
     while(i++!=choice){save=ptr1;ptr1=ptr1->next;}
     if(choice==1){save=head;head=new1;new1->next=save;}else{
     save->next=new1;new1->next=ptr1;}
     }*/
void display()
{
     ptr=head;
     while(ptr!=NULL)
     {
        cout<<"Node 1:"<<ptr->data<<endl;
        ptr=ptr->next;
        }
}
