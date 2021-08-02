//Using iterative level order traversal

vector<int> leftView(Node *root)
{
   // Your code here
   if(root==NULL)
   {
       return;
   }
   queue<Node*> q;
   vector<int> vect;
   q.push(root);
   int countNodes=0;
   while(1)
   {
       countNodes=q.size();
       if(countNodes==0)
       {
           break;
       }
       vect.push_back(q.front()->data); //Print the first node of each level
       while(countNodes>0)
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
           countNodes--;
       }
   }
   return vect;
}