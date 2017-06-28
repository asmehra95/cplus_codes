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
};
void preorder(struct node* root)
{
    if(root)
    {
        cout<<" "<<root->data;
        preorder(root->left);
        preorder(root->right);

    }
}
void inorder(struct node * root)
{
    if(root)
    {

        inorder(root->left);
        cout<<" "<<root->data;
        inorder(root->right);

    }
}
void postorder(struct node * root)
{
    if(root)
    {

        postorder(root->left);
        postorder(root->right);
        cout<<" "<<root->data;
    }
}
void preorder_nr(struct node* root)
{
    stack <struct node*> s;
   // s.push(root->data);
    struct node *cur=root;
    while(1)
    {
        while(cur)
        {
            cout<<" "<<cur->data;
            s.push(cur);
            cur=cur->left;
        }
        if(s.empty())
            break;
        cur=s.top()->right;
        s.pop();
    }
}
void inorder_nr(struct node* root)
{
    struct node * cur=root;
    stack <struct node*> s;
    while(1)
    {
        while(cur){
            s.push(cur);
            cur=cur->left;
        }
        if(s.empty())
            break;
        cout<<s.top()->data<<" ";
        cur=s.top()->right;
        s.pop();
    }
}
void postorder_nr(struct node* root)
{
    struct node * cur=root,*temp;
    stack <struct node*> s;
    do
    {
        while(cur){
            if(cur->right)
                s.push(cur->right);
            s.push(cur);
            cur=cur->left;
        }
        cur=s.top();
        s.pop();
        if(cur->right && cur->right==s.top())
        {
           //temp=s.top();
           s.pop();
           s.push(cur);
           //s.push(temp);
           cur=cur->right;
        }
        else{
            cout<<cur->data<<" ";
            cur=NULL;
        }
    }while(!s.empty());
}
void levelOrder(struct node* root)
{
    queue <struct node*> q;
    cout<<" "<<root->data;
    struct node* temp;
    q.push(root->left);
    q.push(root->right);
    do
    {
        temp=q.front();
        q.pop();
        cout<<" "<<temp->data;
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
            q.push(temp->right);

    }while(!q.empty());
}
map< int, vector<struct node *> > verticalOrder(struct node* root)
{
    struct node *parent,*cur=root;
    map< int, vector<struct node *> > hm;
    map< int, vector<struct node *> > ::iterator mp;
    int hd=0;
    vector<struct node *> v,*vp,temp_vec;
    v.push_back(root);
    hm[hd]=v;
    queue<struct node *> q;
    queue<int> q_hd;
    queue<struct node *> par;
    q.push(root->left);
    q.push(root->right);
    q_hd.push(0);
    q_hd.push(0);
    par.push(root);
    par.push(root);
    do
    {
        int p_hd;

        p_hd=q_hd.front();
        q_hd.pop();

        parent=par.front();
        par.pop();

        cur=q.front();
        q.pop();
        if(parent->left == cur)
        {
            p_hd=p_hd-1;
        }else if(parent->right==cur)
        {
            p_hd+=1;
        }
        if(hm.find(p_hd)!=hm.end())
        {
            temp_vec=hm[p_hd];
            temp_vec.push_back(cur);
            hm[p_hd]=temp_vec;
        }else{
            vp=new vector<struct node *>();
            (*vp).push_back(cur);
            hm[p_hd]=*vp;
        }
        if(cur->left)
        {
            q.push(cur->left);
            q_hd.push(p_hd);
            par.push(cur);
        }

        if(cur->right)
        {
            q.push(cur->right);
            q_hd.push(p_hd);
            par.push(cur);
        }

    }while(!q.empty());
    mp=hm.begin();
    vector <struct node*> :: iterator vi;
    while(mp!=hm.end())
    {
        cout<<endl;
        cout<<" HD: "<<mp->first<<" ";
        vi=(mp->second).begin();
        cout<<"nodes : ";
        while(vi!=(mp->second).end())
        {
            cout<<" "<<(*vi)->data;
            vi++;
        }
        mp++;
    }
    return hm;
}
void bottom_view(struct node* root)
{
    map< int, vector<struct node*> > hm=verticalOrder(root);
    map< int , vector<struct node *> > :: iterator it;
    vector<struct node *> temp;
    it=hm.begin();
    struct node *temp_Node;
    cout<<"\n";
    while(it!=hm.end())
    {
        temp=it->second;
        temp_Node=*temp.rbegin();
        cout<<temp_Node->data;
        it++;
    }
}
int sum=0;
stack<int> s;
stack <int> temp;
void k_sum(struct node * root, int k)
{
    if(root==NULL)
        return;
    sum+=root->data;
    s.push(root->data);
    if(sum==k)
    {
        cout<<"path: \n";
        while(!s.empty())
        {
            cout<<s.top()<<" ";
            temp.push(s.top());
            s.pop();
        }
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }
    }
    k_sum(root->left,k);
    k_sum(root->right,k);
    sum=sum-(root->data);
    s.pop();
}
stack <struct node *> s1,s2;
void zigzag(struct node * root)
{
    s1.push(root);
    struct node *cur;
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            cur=s1.top();
            s1.pop();
            cout<<" "<<cur->data;
            if(cur->right)
            s2.push(cur->right);
            if(cur->left)
            s2.push(cur->left);
        }
        while(!s2.empty())
        {
            cur=s2.top();
            s2.pop();
            cout<<" "<<cur->data;
            if(cur->left)
            s1.push(cur->left);
            if(cur->right)
            s1.push(cur->right);
        }
    }
}

int k_leafs(struct node *root,int k)
{
    if(root->right==NULL && root->left==NULL)
        return 1;
    int lc,rc,tlc;
    lc=k_leafs(root->left,k);
    rc=k_leafs(root->right,k);
    tlc=lc+rc;
    if(tlc==k)
    {
        cout<<root->data<< " ";
    }
    return tlc;
}
struct node* lca(struct node * root,int p,int q) // lowest common ancestor
{
    struct node* la,*ra;
    if(p==q)
    {
        cout<<"ancestor found: "<<p;
        return NULL;
    }
    if(root==NULL)
    {
        return NULL;
    }

    la=lca(root->left,p,q); //left ancestor
    ra=lca(root->right,p,q); //right ancestor
    if(la && ra)
    {
        cout<<"Ancestor found: "<<root->data;
        return root;
    }

    if((ra || la && root->data==p) || (ra || la && root->data==q))
    {
        cout<<"Ancestor found : "<<root->data;
        return root;
    }
    if(p==root->data || q==root->data)
    {
        return root;
    }
    return la?la:ra;
}
void diagonal_sum(struct node * root)
{
    queue<struct node*> q;
    q.push(root);
    q.push(NULL);
    struct node *cur;
    int sum=0;
    while(1)
    {
        cur=q.front();
        q.pop();
        if(cur==NULL)
        {
            cout<<sum<<" ";
            sum=0;
            q.push(NULL);
            cur=q.front();
            q.pop();
            if(cur==NULL)
                break;
        }
        //sum=0;
        while(cur!=NULL)
        {
             if(cur->left)
            q.push(cur->left);
            sum+=cur->data;
            cur=cur->right;
        }

    }
}

void levelOrder_lineWise(struct node * root)
{
    queue<struct node*> q;
    q.push(root);
    struct node *cur;
    int node_ct=0;
    do
    {
        node_ct=q.size();
        while(node_ct>0)
        {
            cur=q.front();
            cout<<" "<<cur->data;
            q.pop();
            if(cur->left){
                q.push(cur->left);
            }
            if(cur->right)
            {
                q.push(cur->right);
            }
            node_ct--;
        }
        cout<<endl;
    }while(!q.empty());
}

void inorder_threaded(struct node * root)
{
    struct node *cur=root,*pre;
    while(cur!=NULL)
    {
        if(cur->left==NULL)
        {
            cout<<" "<<cur->data;
            cur=cur->right;
        }else
        {
            //find in order predecessor
            pre=cur->left;
            while(pre->right!=NULL && pre->right!=cur)
                pre=pre->right;
            if(pre->right==NULL)
            {
                pre->right=cur;
                cur=cur->left;
            }else if(pre->right==cur)
            {
                pre->right=NULL;
                cout<<" "<<cur->data;
                cur=cur->right;
            }
        }
    }
}

int identical_trees(struct node *t1,struct node *t2)
{
    if(t1==NULL && t2==NULL)
    {
        return 1;
    }
    if(t1->data==t2->data && identical_trees(t1->left,t1->left) && identical_trees(t1->right,t2->right))
    {
        return 1;
    }
    return 0;
}
int max_depth(struct node * root)
{
    if(root==NULL)
        return 0;
        int depth=max(max_depth(root->left),max_depth(root->right))+1;
        return depth;
}
struct node * mergeDLL(struct node* l1,struct node * l2)
{
    struct node *b1,*b2;
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    b1=l1->left;
    b2=l2->left;
    b1->right=l2;
    l2->left=b1;
    b2->right=l1;
    l1->left=b2;
    return l1;
}
void printCDLL(struct node *head)
{
   struct node *cur=head;
   cout<<"CDLL \n";
   do
   {
       printf(" %d ",cur->data);
       cur=cur->right;
   }while(cur!=head);
   cout<<"\n";
}

struct node* tree_to_CDLL(struct node * root)
{
    struct node* right,*left;
    if (!root)
    {
        return NULL;
    }
    left=tree_to_CDLL(root->left);
    right=tree_to_CDLL(root->right);
    root->left=root;
    root->right=root;
    return mergeDLL(mergeDLL(root,left),right); // change the order here to inorder / preorder/ postorder traversal
}
int lop=0,ml=0;//len of path nd max len;
int height(struct node *root)
{
    if(root==NULL)
        return 0;
    lop++;
    height(root->left);
    height(root->right);
    if(lop>ml)
        ml=lop;
    lop--;
    return ml;
}
int diameter(struct node *root)
{
    if(!root)
        return 0;
    int ld=0,rd=0;
    ld=diameter(root->left);
    rd=diameter(root->right);
    int lh=0,rh=0;
    lh=height(root->left);
    rh=height(root->right);
    return max(lh+rh+1,max(ld,rd));
}
int main()
{
    struct node *root,*parent,*childL,*childR,*temp;
    root=new_node(1);
    parent=root;
    childL=new_node(2);
    childR=new_node(3);

    parent->left=childL;
    parent->right=childR;

    parent=childL;
    temp=childR;
    childL=new_node(4);
    childR=new_node(5);

    parent->left=childL;
    parent->right=childR;

    parent=temp;
    temp=childR;
    childL=new_node(6);
    childR=new_node(7);

    parent->left=childL;
    parent->right=childR;

    //postorder(root);
   // postorder_nr(root);
    //k_sum(root,10);
    //zigzag(root);
    //k_leafs(root,2);
    //inorder_threaded(root);
   // cout<<identical_trees(root,root->right);
   struct node* l1=new_node(1);
   struct node *l2=new_node(2);
   //l1->right=l2->left=l1;
   //l2->right=l2->left=l2;
    /*l1->right=l1;
    l2->right=l2;
    l1->left=l1;
    l2->left=l2;
    struct node *temp1=mergeDLL(l1,l2);
    printCDLL(temp1);
    temp1=tree_to_CDLL(root);
    printCDLL(temp1);*/
    cout<<diameter(root);
    return 0;
}
