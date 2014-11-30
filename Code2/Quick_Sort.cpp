#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
     int t=a;
     a=b;
     b=t;
}
void sort(int a[],int low,int high)
{
     int i=low,j=high,pivot,flag=1;
     if(low<high)
     {
       while(flag)
       {
        pivot=a[low];
        do{
            i++;
            }while(i<high&&a[i]<pivot);
        do{
            j--;
            }while(a[j]>pivot&&j>low);
            if(i<j)swap(a[i],a[j]);
            else flag=0;
        }
        swap(a[low],a[j]);
        sort(a,low,j-1);
        sort(a,j+1,high);
     }
}
int main()
{
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,0,n);
    for(int i=0;i<n;i++)
    cout<<a[i]<<"  ";
    system("pause");
    return 0;
}
