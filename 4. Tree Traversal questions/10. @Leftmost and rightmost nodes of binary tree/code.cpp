void printCorner(Node *root)
{
    // Your code goes here  
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);
    int countNodes=0;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0)
        {
            break;
        }
        /*
            If countNodes>1 at any level then there will be two extreme point
            nodes one will be one extreme left in that level and one will be on
            extreme right in that level. We will print the extreme right node
            when countNode will reach to 1 as it will signify it is the last or
            the rightmost node in that level but for leftmost node we have to 
            print it before the loop begins. If there is only one node in that
            level it will be taken care by cout inside the below while loop.
        */
        if(countNodes!=1)  
        {
            cout<<q.front()->data<<" ";
        }
        while(countNodes>0)
        {
            Node* temp=q.front();
            q.pop();
            if(countNodes==1)
            {
                cout<<temp->data<<" ";
            }
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            countNodes--;
        }
    }
}