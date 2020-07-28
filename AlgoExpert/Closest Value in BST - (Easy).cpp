#include<iostream>
#include<math.h>
using namespace std;

struct node
{
    int value;
    node *left, *right;
};
node *rootptr = NULL;

node *add(int data)
{
    node *newNode = new node;
    newNode->left = newNode->right = NULL;
    newNode->value = data;
    return newNode;
}

node *insert(node *node, int data)
{
    if(node == NULL)
        node = add(data);

    else if(node->value > data)
        node->left = insert(node->left, data);
    
    else
        node->right = insert(node->right, data);
    
    return node;
}

void inorder(node *root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->value<<" ";
    inorder(root->right);
}

void Closest_Value(node *head, int target)
{
    int closest = INT_MAX;
    int main_differ = INT_MAX;
    int current_differ = INT_MAX;
    int left_check = head->value;
    int right_check = head->value;

    while (head != NULL)
    {
        current_differ = abs(target - head->value);
        if(current_differ < main_differ)
        {
            main_differ = current_differ;
            closest = head->value;
        }
        
        if(head->left != NULL)
            left_check = abs(target - head->left->value);
            
        if(head->right != NULL)
            right_check = abs(target - head->right->value);

        if(left_check < right_check)
            head = head->left;

        else
            head = head->right;
    }

cout<<"Closest Value of "<<target<<" is "<<closest<<endl;    
}

int main()
{
    rootptr = NULL;
    rootptr=insert(rootptr,10);
    rootptr=insert(rootptr,5);
    rootptr=insert(rootptr,15);
    rootptr=insert(rootptr,2);
    rootptr=insert(rootptr,5);
    rootptr=insert(rootptr,13);
    rootptr=insert(rootptr,22);
    rootptr=insert(rootptr,1);
    rootptr=insert(rootptr,14);
    cout<<endl;
    cout<<"\nINORDER \t::\t";
    inorder(rootptr);
    cout<<endl;
    cout<<endl;
    int tar = 12;
    Closest_Value(rootptr, tar);
    
}