// Using level order traversal

void findAllNodes(Node* root,int k,vector<int>& vect)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*> q;
    int nodeCount;
    int level=0;
    q.push(root);
    while(1)
    {
        nodeCount=q.size();
        if(nodeCount==0)
        {
            break;
        }
        while(nodeCount>0)
        {
            if(level<k)
            {
                Node* temp=q.front();
                q.pop();
                if(temp->left!=NULL)
                {
                    q.push(temp->left);
                }
                if(temp->right!=NULL)
                {
                    q.push(temp->right);
                }
                
            }
            else if(level==k)
            {
                Node* temp=q.front();
                q.pop();
                vect.push_back(temp->data);
            }
            else if(level>k)
            {
                return;
            }
            nodeCount--;
        }
        level++;
    }
}

vector<int> Kdistance(struct Node *root, int k)
{
  // Your code here
  if(root==NULL)
  {
      return {};
  }
  vector<int> vect;
  findAllNodes(root,k,vect);
  return vect;
}