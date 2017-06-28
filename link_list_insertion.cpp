#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

void insertAtBegining(struct node** headRef, int newData);

void insertAtEnd(struct node** headRef, int newData);

void printList(struct node *node)
{
    while (node != NULL)
    {
        cout<<node->data<<' ';
        node = node->next;
    }
    cout<<'\n';
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n, ch, tmp;
        struct node* head = NULL;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>tmp>>ch;
            if(ch) insertAtEnd(&head, tmp);
            else insertAtBegining(&head, tmp);
        }
        printList(head);
    }
    return 0;
}
void insertAtBegining(struct node** headRef, int newData)
{
  struct node *temp=(struct node*)malloc(sizeof(struct node));
  temp->next=*headRef;
  temp->data=newData;
  *headRef=temp;
}

// function appends the data at the end of the list
void insertAtEnd(struct node** head_ref, int new_data)
{
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=new_data;
    struct node *temp=*head_ref;
    if(temp==NULL)
    {
        insertAtBegining(head_ref,new_data);
        return ;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->next=NULL;
}
