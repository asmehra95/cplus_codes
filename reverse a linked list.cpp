#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node* next;
};
void printList(struct node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<endl;
}
void rev(struct node** head)
{
    struct node *prev=NULL,*cur=NULL,*next=*head;
    while(next!=NULL)
    {
        cur=next;
        next=next->next;
       // cout<<cur->data<<endl;
        if(prev==NULL)
        {
            cur->next=NULL;
            prev=cur;
        }else{
            cur->next=prev;
            prev=cur;
        }
        if(next==NULL)
        {
            *head=cur;
            cout<<prev->data;
            cout<<"prev data baby";
        }
    }
}
int main()
{
    int n,i;
    cout<<"Enter Number of elements: ";
    cin>>n;
    struct node *head,*prev,*n1;
    head=NULL;
    prev=NULL;
    while(n--)
    {
        n1=(struct node*)malloc(sizeof(struct node));
        n1->next=NULL;
        cin>>n1->data;
        if(head==NULL)
        {
            head=n1;
            prev=n1;
        }else{
            prev->next=n1;
            prev=n1;
        }
    }
    printList(head);
    printf("after rev ");
    rev(&head);
    printList(head);
    return 0;
}
