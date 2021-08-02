//This is an implementation of "COMPLETE BINARY SEARCH TREE"
/*
	Complete BST:- Is is a BST in which all levels are full except the last level and iff
	the last level is not full then the nodes must be left aligned.
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

Node* LevelOrderInsertion(Node* root,int arr[],int i,int n)
{
    
    if(i<n)
    {
        Node* new_node=new Node(arr[i]);
        root=new_node;
        root->left=LevelOrderInsertion(root->left,arr,2*i+1,n);
        root->right=LevelOrderInsertion(root->right,arr,2*i+2,n);
    }
    return root;
}

void Inorder(Node* root) //It will traverse the Level order tree in inorder fashion 
{
    if(root==NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void Preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(Node* root)
{
    if(root!=NULL)
    {
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Node* root=NULL;
        root=LevelOrderInsertion(root,arr,0,n);
        cout<<"Inorder: ";
        Inorder(root);
        cout<<endl;
        cout<<"Preorder: ";
        Preorder(root);
        cout<<endl;
        cout<<"Postorder: ";
        Postorder(root);
        cout<<"\n\n";
    }
}