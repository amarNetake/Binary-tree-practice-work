// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
   //Which comes first for that we need some pointer but which comes last can be maintained
   //by regular flow of program.
   //So bottom view will be the nodes that will come in the bottom most in each level
   if(root==NULL)  return {};
   vector<int> result;
   map<int,Node*> temp;
   queue<pair<Node*,int>> q;
   q.push(make_pair(root,0));
   int countNodes;
   while(1)
   {
       countNodes=q.size();
       if(countNodes==0)  break;
       while(countNodes>0)
       {
           pair<Node*,int> curr=q.front();
           q.pop();
           temp[curr.second]=curr.first;
           if(curr.first->left!=NULL)  q.push(make_pair(curr.first->left,curr.second-1));
           if(curr.first->right!=NULL) q.push(make_pair(curr.first->right,curr.second+1));
           countNodes--;
       }
   }
   for(auto x: temp)
   {
       result.push_back(x.second->data);
   }
   return result;
}