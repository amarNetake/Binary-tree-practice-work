void inorderTraversal(Node* root,Node** head_ref,Node** prev_ref)
{
    if(root==NULL)  return;
    inorderTraversal(root->left,head_ref,prev_ref);
    if(*head_ref==NULL)
    {
        *head_ref=root;
        *prev_ref=*head_ref;
    }
    else
    {
        root->left=*prev_ref;
        root->left->right=root;
        *prev_ref=root;
    }
    inorderTraversal(root->right,head_ref,prev_ref);
}

Node * bToDLL(Node *root)
{
    // your code here
    if(root==NULL)
    {
        return NULL;
    }
    Node* head=NULL;
    Node* prev=NULL;
    inorderTraversal(root,&head,&prev);
    return head;
}