#include<iostream>
using namespace std;
void push(char);
char pop();
int number(char);
char top_element();
char infix[100],ans[100],s[100];
    int top=-1;int k=0;
    int p1,p2,length;int i;char pop_ele;
int main()
{
    cout<<"Enter the infix expression:"<<endl;
    cin>>infix;
    length=strlen(infix);
    for(i=0;i<length;i++)
    {
                         //cout<<"hey"<<endl;
        if(infix[i]!='('&&infix[i]!=')'&&infix[i]!='*'&&infix[i]!='/'&&infix[i]!='+'&&infix[i]!='-')
        {ans[k++]=infix[i];
        }
        else if(infix[i]=='(')
             {push('(');}
        else if(infix[i]==')')
             {
                pop_ele=pop();
                while(pop_ele!='('){
                ans[k++]=pop_ele;pop_ele=pop();}
                }
        else
             {
                 p1=number(infix[i]);
                 char top_ele=top_element();
                 p2=number(top_ele);
                 if(p1>p2)push(infix[i]);
                 else {
                      while(p2>=p1)
                      {
                         if(top_ele=='0')break;
                         pop_ele=pop();
                         ans[k++]=pop_ele;
                         top_ele=top_element();
                         p2=number(top_ele);
                         }
                         push(infix[i]);
                         }
                 }
                 }
        pop_ele=pop();
        while(pop_ele!='0'){
        ans[k++]=pop_ele;pop_ele=pop();}
        cout<<"The post fix expression is:"<<endl;
        cout<<ans;
        system("pause");
        return 0;
}
void push(char ch)
{
     s[++top]=ch;
     }
char pop()
{
          if(top==-1)return '0';
          else return s[top--];
          }
          int number(char ch)
          {
               if(ch=='*'||ch=='/')return 2;
               if(ch=='+'||ch=='-')return 1;
               else return 0;
               }
               char top_element()
               {
                    if(top==-1)return '0';
                    else
                    return s[top];
                    }
