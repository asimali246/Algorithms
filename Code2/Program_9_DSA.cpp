#include<iostream>
using namespace std;
struct Node
    {
           char name[100];
           Node *left;
           Node *right;
    }*ptr,*head,*trav,*tmp,*finder,*tmp2;
    void insert(Node*);
    void deleted(char[]);
    void search(char[]);
    void display(Node*);
    int s=0,k=0;
int main()
{
    int n,i,j;int choice=0;
    do{
    cout<<"Enter your choice:"<<endl;
    cout<<"1-->  Insert :"<<endl;
    cout<<"2-->  Delete :"<<endl;
    cout<<"3-->  Search :"<<endl;
    cout<<"4-->  Display :"<<endl;
    cout<<"5--> Exit:"<<endl;
    cin>>choice;
    if(choice==1)
    {
    k++;s=0;
    cout<<"Enter the Name:"<<endl;
    ptr=new Node;
    cin>>ptr->name;
    ptr->left=NULL;
    ptr->right=NULL;
    if(k==1)head=ptr;
    insert(ptr);
    }
    if(choice==2)
    {
                 char name[100];
                 cout<<"Enter the name you want to delete:"<<endl;
                 cin>>name;
                 tmp=head;
                 deleted(name);
    }
    if(choice==3)
    {
                 char name[100];
                 cout<<"Enter the name you want to search:"<<endl;
                 cin>>name;
                 search(name);
    }
    if(choice==4)
    {
                 if(s!=1)
                 cout<<"Root  "<<head->name<<endl;
                 display(head);
    }
      }while(choice!=5);
      return 0; 
}
void deleted(char name[100])
{
     trav=head;int p,q,flag=0;tmp=head;
     if(head->left==NULL&&head->right==NULL&&strcmp(head->name,name)==0){k=0;head=NULL;flag=1;s=1;}
     else {while(flag!=1)
     {
         if(trav->left!=NULL)
         {if(strcmp(trav->name,name)>0){tmp=trav;p=1,q=0;trav=trav->left;}}
         if(trav->right!=NULL)
         { if(strcmp(trav->name,name)<0){tmp=trav;p=0,q=1;trav=trav->right;}}
         if(strcmp(trav->name,name)==0)
         {
                 flag=1;int r=0;
                 if(trav->left==NULL&&trav->right==NULL){if(p==1&q==0)tmp->left=NULL;if(p==0&q==1)tmp->right=NULL;}
                 else if(trav->left==NULL&&trav->right!=NULL)
                 {if(p==1&q==0)tmp->left=trav->right;
                 if(p==0&q==1)tmp->right=trav->right;
                 }
                 else if(trav->left!=NULL&trav->right==NULL)
                 {if(p==1&q==0)tmp->left=trav->left;
                 if(p==0&q==1)tmp->right=trav->left;
                 }
                 else if(trav->left!=NULL&&trav->right!=NULL)
                 {
                      int test=0;int t=0,l=0;
                      finder=trav->right;
                      tmp2=finder;
                      if(trav==head){t=1;if(finder->left==NULL){l=1;head=finder;finder->left=tmp->left;}
                      else {
                      while(test!=1)
                      {
                         if(finder->left==NULL)test=1;
                         else {tmp2=finder;finder=finder->left;}
                      }
                      }
                      }
                      else {
                      if(finder->left==NULL){if(p==1&q==0){tmp->left=finder;finder->left=trav->left;}
                      if(p==0&q==1){tmp->right=finder;finder->left=trav->left;}
                      }
                      else {
                      while(test!=1)
                      {  r=1;
                         if(finder->left==NULL)test=1;
                         else {tmp2=finder;finder=finder->left;}
                      }}}
                      if(l==0){
                      if(finder->right!=NULL)tmp2->left=finder->right;
                      else tmp2->left=NULL;}
                      if(t==1&&l==0){head=finder;finder->left=tmp->left;finder->right=tmp->right;}
                      else {
                      if(p==1&q==0){tmp->left=finder;if(r==1){finder->left=trav->left;finder->right=trav->right;}}
                      if(p==0&q==1){tmp->right=finder;if(r==1){finder->left=trav->left;finder->right=trav->right;}}
                 }}
         }                                   
         if(trav->left==NULL&&trav->right==NULL&&strcmp(trav->name,name)!=0)break;
     }}
     if(flag==0)cout<<"Name could not be found"<<endl;
     else cout<<"Name successfully deleted"<<endl;
}
void insert(Node *ptr)
{
     trav=head;int flag=0;
     while(flag!=1)
     {
          if(strcmp(ptr->name,trav->name)<0)
          { if(trav->left==NULL){flag=1;trav->left=ptr;}
          else trav=trav->left;
          }
          else if(strcmp(ptr->name,trav->name)>0)
          {  if(trav->right==NULL){flag=1;trav->right=ptr;}
          else trav=trav->right;
          }
          else break;
     }
}
void search(char name[100])
{
     trav=head;
     int flag=0;
     while(flag!=1)
     {
         if(trav->left!=NULL)
         {if(strcmp(trav->name,name)>0)trav=trav->left;}
         if(trav->right!=NULL)
         { if(strcmp(trav->name,name)<0)trav=trav->right;}
         if(strcmp(trav->name,name)==0){flag=1;cout<<"Name Present in Binary search tree"<<endl;}
         if(trav->left==NULL&&trav->right==NULL&&strcmp(trav->name,name)!=0)break;
         if(trav->left==NULL&&strcmp(trav->name,name)>0)break;
         if(trav->right==NULL&&strcmp(trav->name,name)<0)break;
     }
     if(flag==0)cout<<"Name not present in Binary search tree:"<<endl;
}
void display(Node *trav)
{
     if(s==1){cout<<"Binary Search tree Empty"<<endl;}
     else {
     if(trav->left!=NULL)
     {
     tmp=trav->left;
     cout<<"Left Child of  \""<<trav->name<<"\" is "<<tmp->name<<endl;
     display(tmp);
     }
     if(trav->right!=NULL)
     {
     tmp=trav->right;
     cout<<"Right Child of  \""<<trav->name<<"\" is "<<tmp->name<<endl;
     display(tmp);
     }}
}  
