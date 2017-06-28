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
void rev2(struct node **head)
{
    struct node *prev,*cur,*next;
    prev=NULL;
    cur=*head;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head=prev;
}
node* addOne(struct node *head)
{
    struct node* cur=head;
    int d;
    int carry=0,f=0;
    while(cur!=NULL)
    {
        d=cur->data;
        if(f==0)
        {
           d++;
           f++;
        }
        d+=carry;
        int n=floor(log10(abs(d)))+1;
        if(n>1)
        {
            cur->data=d % 10;
            carry=1;
        }else{
            cur->data=d;
            carry=0;
        }
        if(carry==1 && cur->next==NULL)
        {
            struct node *new_node=(struct node *)malloc(sizeof(struct node));
            new_node->data=1;
            new_node->next=NULL;
            cur->next=new_node;
        }
        cur=cur->next;
    }
    return head;
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
    rev2(&head);
    head=addOne(head);
    rev2(&head);
    printList(head);
    return 0;
}
