class Solution{
    
    public:
    void connect(Node *root)
    {
        if(root==NULL)  return;
        int countNodes;
        queue<Node*> q;
        q.push(root);
        while(1)
        {
            countNodes=q.size();
            if(countNodes==0)   break;
            while(countNodes>0)
            {
                Node* curr=q.front();
                q.pop();
                if(countNodes==1)  curr->nextRight=NULL;
                else curr->nextRight=q.front();
                if(curr->left!=NULL)  q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
                countNodes--;
            }
        }
    }    
};