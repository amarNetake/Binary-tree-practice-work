int maxLevelSum(Node* root) {
    // Your code here
    queue<Node*> q;
    q.push(root);
    int max=INT_MIN;
    int sum=0;
    int countNodes=0;
    while(1)
    {
        countNodes=q.size();
        if(countNodes==0)
        {
            break;
        }
        sum=0;
        while(countNodes>0)
        {
            Node* temp=q.front();
            q.pop();
            sum=sum + temp->data;
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
        if(sum>max)
        {
            max=sum;
        }
    }
    return max;
}