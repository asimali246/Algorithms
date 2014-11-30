#include<iostream>
using namespace std;
int flag=0;
struct Node{
       int key;
       Node *left,*right,*parent;
       char color;
       }*root,*y,*w,*ptr,*x,*tmp;
void left_rotate(Node *x)
{
     y=x->right;
     x->right=y->left;
     if(y->left!=NULL)
     	y->left->parent=x;
     y->parent=x->parent;
     if(x->parent==NULL)
     	root=y;
     else if(x==x->parent->left)
     	x->parent->left=y;
     else x->parent->right=y;
     y->left=x;
     x->parent=y;
}
void right_rotate(Node *x)
{
	y=x->left;
	x->left=y->right;
	if(y->right!=NULL)
		y->right->parent=x;
	y->parent=x->parent;
	if(x->parent==NULL)
		root=y;
	else if(x==x->parent->right)
		x->parent->right=y;
	else
		x->parent->left=y;
	y->right=x;
	x->parent=y;
}
void insert_fix_up(Node *z)
{
	while(z->parent!=NULL&&z->parent->color=='R')
	{
		if(z->parent->parent!=NULL&&z->parent==z->parent->parent->left)
		{
			y=z->parent->parent->right;
			if(y!=NULL&&y->color=='R')
			{
				z->parent->color='B';
				y->color='B';
				z->parent->parent->color='R';
				z=z->parent->parent;
			}
			else{
			if(z==z->parent->right)
			{
				z=z->parent;
				left_rotate(z);
			}
			z->parent->color='B';
			z->parent->parent->color='R';
			right_rotate(z->parent->parent);
			}
		}
		else
		if(z->parent->parent!=NULL)
        {
            y = z->parent->parent->left;
            
            if ( y!=NULL&&y->color == 'R' )
            {
                z->parent->color = 'B';
                y->color = 'B';
                z->parent->parent->color = 'R';
                z = z->parent->parent;
            }
            else
            {
                if ( z == z->parent->left )
                {
                    z = z->parent;
                    right_rotate( z );
                }
                z->parent->color = 'B';
                z->parent->parent->color = 'R';
                left_rotate( z->parent->parent );
            }
        }
	}
	root->color='B';
}
void insert(Node *z)
{
	y=NULL;
	x=root;
	while(x!=NULL)
	{
		y=x;
		if(z->key<x->key)
			x=x->left;
		else
			x=x->right;
	}
	z->parent=y;
	if(y==NULL)
		root=z;
	else if(z->key<y->key)
		y->left=z;
	else y->right=z;
	z->left=NULL;
	z->right=NULL;
	z->color='R';
	insert_fix_up(z);
}

void transplant(Node *u,Node *v)
{
	if(u->parent==NULL)
		root=v;
	else if(u==u->parent->left)
			u->parent->left=v;
	else
		u->parent->right=v;
	if(v!=NULL)
	v->parent=u->parent;
}
Node* tree_minimum(Node *x)
{
	while(x->left!=NULL)
	{
		x=x->left;
	}
	return x;
}
void delete_fix_up(Node *x)
{
	while(x!=NULL&&x!=root&&x->color=='B')
	{
		if(x==x->parent->left)
		{
			w=x->parent->right;
			if(w->color=='R')
			{
				w->color='B';
				x->parent->color='R';
				left_rotate(x->parent);
				w=x->parent->right;
			}
			if(w->left->color=='B'&&w->right->color=='B')
			{
				w->color='R';
				x=x->parent;
			}
			else{
			if(w->right->color=='B')
			{
				w->left->color=='B';
				w->color='R';
				right_rotate(w);
				w=x->parent->right;
			}
			w->color=x->parent->color;
			x->parent->color='B';
			w->right->color='B';
			left_rotate(x->parent);
			x=root;
			}
		}
		else
		{
			w = x->parent->left;
            
            if ( w->color == 'R' )
            {
                w->color = 'B';
                x->parent->color = 'R';
                right_rotate( x->parent );
                w = x->parent->left;
            }
            
            if ( w->right->color == 'B' && w->left->color == 'B' )
            {
                w->color = 'R';
                x = x->parent;
            }
            else{ 
            if ( w->left->color == 'B' )
            {
                w->right->color = 'B';
                w->color = 'R';
                left_rotate( w );
                w = x->parent->left;
            }
            
            w->color = x->parent->color;
            x->parent->color = 'B';
            w->left->color = 'B';
            right_rotate( x->parent );
            x = root;
		}}
	}
	if(x!=NULL)
	x->color='B';
}
void delet(Node *z)
{
	y=z;
	char y_original_color=y->color;
	if(z->left==NULL)
	{
		x=z->right;
		transplant(z,z->right);
	}
	else
	if(z->right==NULL)
	{
		x=z->left;
		transplant(z,z->left);
	}
	else
	{
		y=tree_minimum(z->right);
		y_original_color=y->color;
		x=y->right;
		if(y->parent==z&&x!=NULL)
			x->parent=y;
		else
		if(y->parent!=z)
		{
			transplant(y,y->right);
			y->right=z->right;
			y->right->parent=y;
		}
		transplant(z,y);
		y->left=z->left;
		y->left->parent=y;
		y->color=z->color;
	}
	if(y_original_color=='B')
		delete_fix_up(x);
}
Node* search(int n)
{
	Node *found;
	found=root;
	while(found!=NULL)
	{
		if(found->key>n)
			found=found->left;
		else if(found->key<n)
			found=found->right;
		else return found;
	}
	flag=1;
	return NULL;
}
void display(Node *trav)
{
     if(trav->left!=NULL)
     {
     tmp=trav->left;
     cout<<"Left Child of  \""<<trav->key<<"\"\n";
     cout<<tmp->key<<": "<<tmp->color<<"\n";
     display(tmp);
     }
     if(trav->right!=NULL)
     {
     tmp=trav->right;
     cout<<"Right Child of  \""<<trav->key<<"\"\n";
     cout<<tmp->key<<": "<<tmp->color<<"\n";
     display(tmp);
     }
}
int main()
{
    root=NULL;
	while(1){
	cout<<"Enter your choice\n";
	cout<<"1--> Insertion\n2--> Deletion\n3--> Search\n4--> Display\n5--> Exit\n";
	int choice;
	cin>>choice;
	if(choice==1)
	{
		cout<<"Enter the value\n";
		ptr=new Node;
		ptr->left=NULL;
		ptr->right=NULL;
		cin>>ptr->key;
		insert(ptr);
	}
	if(choice==2)
	{
		cout<<"Enter the node to be deleted\n";
		int n;
		cin>>n;
		ptr=search(n);
		if(flag==1){cout<<"NOT FOUND\n";}
		else delet(ptr);
	}
	if(choice==3)
	{
		cout<<"Enter the value to be searched\n";
		int n;
		cin>>n;
		ptr=search(n);
		if(flag==1){cout<<"NOT FOUND\n";}
		else cout<<"VALUE FOUND\n";
	}
	if(choice==4)
	{
        if(root!=NULL){
        cout<<"Root\n";
        cout<<root->key<<" : "<<root->color<<"\n";
		display(root);
		cout<<"\n";}
	}
	if(choice==5)break;
	flag=0;
    }
}
