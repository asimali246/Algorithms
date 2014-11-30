#include<iostream>
using namespace std;
class employee
{
      public:
      struct Node{
             int emp_id;
             char name[30];
             /*char designation[30];
             double salary;
             int yoe;
             int flat_no;
             char street[30];
             char place[30];
             char district[30];
             char state[30];
             int pin_code;*/
             Node *next;
             }*head,*save,*ptr,*tmp;
             int k;
             void input()
             {
                  k=0;
                  int choice=1;head=NULL;
                  cout<<"Enter the details:"<<endl;
                  do
                  {
                     k++;
                     ptr=new Node;
                     cout<<"Name:";
                     cin>>ptr->name;
                     cout<<"Employee id:";
                     cin>>ptr->emp_id;
                     ptr->next=NULL;
                     insert(ptr);
                     cout<<"Do you want to enter more:"<<endl;
                     cout<<"1--> Yes:"<<endl;
                     cout<<"2--> No:"<<endl;
                     cin>>choice;
                     }while(choice!=2);
             }
             void insert(Node* ptr)
             {
                  if(head==NULL)head=ptr;
                  else {ptr->next=head;head=ptr;}
             }
             void sort()
             {
                  int i,j;Node *compare;Node *tmp1;int flag=0;
                  ptr=head;save=head;ptr=ptr->next;tmp=head;tmp=tmp->next;
                  for(i=1;i<k;i++)
                  {
                                 // cout<<"rtr"<<endl;
                      tmp1=head;
                      compare=ptr;flag=0;
                      for(j=i;j>0&&compare->emp_id<save->emp_id;j--)
                      {save->next=tmp->next;flag=1;
                      if(tmp1!=save)
                      while(tmp1->next!=save){tmp1=tmp1->next;}save=tmp1;
                      tmp=save->next;
                      }
                      ptr=ptr->next;
                      if(j==0){compare->next=save;head=compare;}
                      else if(flag==1){
                      save->next=compare;compare->next=tmp;}
                      save=head;
                      while(save->next!=ptr)save=save->next;tmp=save->next;
                      //if(save==head)comapare=head;
                  }
             }
             
             void display()
             {
                  cout<<"The sorted order:"<<endl;
                  ptr=head;
                  while(ptr!=NULL)
                  {cout<<ptr->emp_id<<endl;ptr=ptr->next;}
             }
};
int main()
{
    employee obj;
    obj.input();
    obj.sort();
    obj.display();
    system("pause");
    return 0;
}
