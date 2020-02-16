#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
	int info;
	node *next;
}*root=NULL;
void creation();
void insertion(node *);
void deletion(node *);
void display(node *);
void creation()
{
	root=new node;
	cout<<"enter the 1 node"<< endl;
	cin>>root->info;
	root->next=NULL;
}

void insertion(node *p)                    
{
     while(p->next!=NULL)
     {
          p = p->next;                    
     }
     node *temp = new node;
     cout<<"Enter data-value: ";
     cin>> temp->info; 
     temp->next = NULL;
     p->next = temp;                   
}
void deletion(node *ptr)                
{
     node *ptrP = NULL;                      
     if(ptr==NULL)
     {
         cout<<"List is empty.."  << endl;
         return ;
     }
     int val;
     cout<<"Enter data-value to delete: ";
     cin>> val; 
     while( (ptr!=NULL)&&(ptr->info!=val) )
     {
          ptrP = ptr;
          ptr = ptr->next;                    
     }
     
     if(ptr==NULL)                      
     {     
           cout<<"Value doesn't exist in list"  << endl; 
           return ;
     }
     else if(ptrP==NULL)             
     {
          root = root->next;
          delete ptr; 
     }          
     else                                
     {
          ptrP->next = ptr->next;       
          delete ptr;   
     }
}

void display(node *p)
{
					                   
     cout<<"\n Elements in linked-list are: " << endl;
     while(p!=NULL)
     {
         cout<< p->info  <<" --> ";
         p = p->next;
     }        
     cout<<"NULL" << endl;
}


int main()
{
	int choice;
	if(root==NULL)
	{
		creation();
	}
	while(1)
	{   cout<<"---------------------------\n ";
		cout<<"enter your choice"<< endl;
		cout<<"1 for insertion"<< endl;
		cout<<"2 for deletion"<< endl;
		cout<<"3 for display"<< endl;
		cout<<"----------------------------\n";
		cin>>choice;
		switch(choice)
		{
			case 1: insertion(root);
			break;
			case 2: deletion(root);
			break;
			case 3: display(root);
			break;
			default :
				cout<<"please enter the correct choice"<< endl;
		}
	}
}