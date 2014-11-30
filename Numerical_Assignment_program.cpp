#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int n;
double a[100][100];
double b[100][100];
int count_1=0,count_2=1;
double ratio;
void input()
{
	cout<<"Enter the size of the Array:"<<"\n";
	cin>>n;
	cout<<"Enter the elements of the array\n";
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	{
	cout<<"A"<<i<<j<<":";
	cin>>a[i][j];
	if(i==j)
	b[i][j]=1.0;
	else b[i][j]=0.0;
	}
	}
}
void display()
{
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	{
	cout<<a[i][j]<<"   ";
	}
	cout<<"\n";
	}
}
void display_intermediate()
{
	for(int i=0;i<n;i++)
	{
	int temp=0;
	int flag=0;
	for(int j=0;j<2*n;j++)
	{
	if(flag==0)
	printf("%.2f  ",a[i][temp]);
	else printf("%.2f  ",b[i][temp]);
	temp++;
	if(temp==n){
	cout<<"|"<<"  ";
	temp=0;flag=1;}
	}
	cout<<"\n";
	}
}
int check_existence()
{
	int count=0;
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	{
	if(a[i][j]==0)count++;
	}
	if(count==n)return 1;
	count=0;
	}
	return 0;
}
void exchange(int l,int count)
{
  for(int i=0;i<n;i++)
    {
      double temp=a[count][i];
      a[count][i]=a[l][i];
      a[l][i]=temp;
      temp=b[count][i];
      b[count][i]=b[l][i];
      b[l][i]=temp;
    }
}
double round( double value )
{
    return floor( value*100 + 0.5 )/100;
}
void upper_triangular()
{
	while(count_2!=n)
	{
	  if(a[count_1][count_1]==0)
	    {
	      for(int l=count_1+1;l<n;l++)
		if(a[l][count_1]!=0)
		  {
		    exchange(l,count_1);
		    break;
		  }
	    }
		for(int i=count_2;i<n;i++)
		{
		  if(abs(a[i][count_1])!=0)
			{
			ratio=(double)a[i][count_1]/(double)a[count_1][count_1];
			for(int j=0;j<n;j++)
			{
			  a[i][j]=a[i][j]-a[count_1][j]*ratio;
			b[i][j]=b[i][j]-b[count_1][j]*ratio;
			}
			}
		}
		count_2++;
		count_1++;
	}
	if(check_existence())
	return;
	cout<<"STEP:1\n";
	display_intermediate();
	count_1=1,count_2=0;
}
void lower_triangular()
{
	while(count_2!=n-1)
	{
		for(int i=count_1;i<n;i++)
		{
		  if((a[count_2][i])!=0)
			{
			ratio=(double)a[count_2][i]/(double)a[i][i];
			for(int j=0;j<n;j++)
			{
			a[count_2][j]=a[count_2][j]-a[i][j]*ratio;
			b[count_2][j]=b[count_2][j]-b[i][j]*ratio;
			}
			}
		}
		count_2++;
		count_1++;
	}
	if(check_existence())
	return;
	cout<<"STEP:2\n";
	display_intermediate();
}
void identity_matrix()
{
	for(int i=0;i<n;i++)
	{
	ratio=a[i][i];
	a[i][i]/=ratio;
	for(int j=0;j<n;j++)
	{
		b[i][j]/=ratio;
	}
	}
	cout<<"STEP:3\n";
	display_intermediate();
}
void display_final()
{
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	{
	  if(abs(b[i][j])==0)
	  b[i][j]=0.0;
	printf("%.2f  ",b[i][j]);
	}
	cout<<"\n";
	}
}
int main()
{
	int choice=0;
	do
	{
	cout<<"INVERSE OF THE MATRIX USING GAUSS JORDON METHOD\n";
	cout<<"\n\n";
	int flag=0;
	cout<<"INPUT:\n";
	input();
	cout<<"\n\n";
	cout<<"INITIAL ARRAY:\n";
	display();
	cout<<"\n\n";
	cout<<"INITIAL:\n";
	display_intermediate();
	cout<<"\n\n";
	upper_triangular();
	cout<<"\n\n";
	if(check_existence())
	flag=1;
	if(flag!=1)
	lower_triangular();
	cout<<"\n\n";
	if(check_existence())
	flag=1;
	if(flag!=1)
	identity_matrix();
	cout<<"\n\n";
	if(flag==0)
	{
	cout<<"THE INVERSE OF THE MATRIX IS:\n";
	display_final();
	}
	else cout<<"THE INVERSE OF THE MATRIX DOES NOT EXIST";
	cout<<"\n\n";
	cout<<"DO YOU WANT TO REPEAT IT AGAIN\n";
	cout<<"1 --> YES\n";
	cout<<"2 --> NO\n";
	cin>>choice;
	cout<<"\n\n";
	flag=0,count_1=0,count_2=1;
	}while(choice!=2);
	return 0;
}
