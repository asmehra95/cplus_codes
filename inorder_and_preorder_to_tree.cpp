#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct node
{
        int data;
        struct node * left;
        struct node *right;
};
struct node* new_node(int d)
{
    struct node *n= (struct node *)malloc(sizeof(node));
    n->data=d;
    n->left=NULL;
    n->right=NULL;
}
void preorder(struct node* root)
{
    if(root)
    {
        cout<<" "<<root->data;
        preorder(root->left);
        preorder(root->right);
    }
}
struct node * makeTree(char in[],char pre[],int inS,int inE)
{
   struct node * cur;
   static int inPtr=0;
   if(inS>inE)
        return NULL;
    cur=new_node(pre[inPtr++]);
   if(inS==inE)
        return cur;

    cur->left=makeTree(in,pre,inS,inE-1);
    cur->right=makeTree(in,pre,inOrd+1,inE)
}
int main()
{
    struct node *root,*parent,*childL,*childR,*temp;
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    int len=sizeof(in)/sizeof(in[0]);
    root=makeTree(in,pre,0,len-1);

    return 0;
}
