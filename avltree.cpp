#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left;
    node *right;
    int height;
};

int Height(node *root){
    if(root==NULL)
    return -1;
    else
    return root->height;
}
node* newnode(int data){
    node *p = new node;
    if(!p)
    {
        cout<<"memory error"<<endl;
        return NULL;
    }
    p->data=data;
    p->left = p->right=NULL;
    p->height=0;
    return p;
}

node* LR(node *root)
{
    node *temp=root->right;
    root->right=temp->left;
    temp->left  = root;
    root->height=max(Height(root->left),Height(root->right))+1;
    temp->height= max(Height(temp->right),root->height)+1;
    return temp;

}
node* RR(node *root){
    node *temp= root->left;
    root->left = temp->right;
    temp->right=root;
    root->height = max(Height(root->left),Height(root->right))+1;
    temp->height = max(Height(temp->left),root->height)+1;
    return temp;
}

node*  DRR(node *root){
    root->left=LR(root->left);
    return RR(root);
}
node* DLR(node *root){
    root->right=RR(root->right);
    return LR(root);
}

node* insert(node* root,int data)
{
   if(root==NULL)
   {
       root=newnode(data);
       return root;
   }
   else if(data<root->data)
   {
       root->left=insert(root->left,data);
       if(Height(root->left)-Height(root->right)==2)
       {
           if(data<root->left->data)
           root=RR(root);
           else
           root=DRR(root);

       }
   }
   else if(data>root->data)
   {
       root->right = insert(root->right,data);
       if(Height(root->right)-Height(root->left)==2)
       {
           if(data>root->right->data)
           root=LR(root);
           else
           root= DLR(root);
       }
   }
   root->height = max(Height(root->left),Height(root->right))+1;
   return root;
}
void inorder(node* root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(NULL);
    int n;
    cout<<"enter the number of elements to be inserted"<<endl;
    cin>>n;
    int x;
    node *root=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        root=insert(root,x);
    }
    inorder(root);
    // cout<<root->right->data<<" ";
    // // cout<<root->right->right->data<<" ";
    // cout<<root->data<<" "<<endl;
    return 0;
}
