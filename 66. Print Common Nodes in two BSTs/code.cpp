// Through Simple Iterative inorder traversal

vector <int> printCommon(Node *root1, Node *root2)
{
     //Your code here
     stack<Node*> s1;
     stack<Node*> s2;
     if(root1==NULL||root2==NULL)
     {
         return {};
     }
     vector<int> vect;
     Node* curr1=root1;
     Node* curr2=root2;
     while((curr1!=NULL||s1.empty()==false)&&(curr2!=NULL||s2.empty()==false))
     {
         while(curr1!=NULL)
         {
             s1.push(curr1);
             curr1=curr1->left;
         }
         while(curr2!=NULL)
         {
             s2.push(curr2);
             curr2=curr2->left;
         }
         curr1=s1.top();
         curr2=s2.top();
         if(curr1->data==curr2->data)
         {
             vect.push_back(curr1->data);
             s1.pop();
             s2.pop();
             curr1=curr1->right;
             curr2=curr2->right;
         }
         else if(curr1->data < curr2->data)
         {
             curr1=curr1->right;
             s1.pop();
             curr2=NULL;
         }
         else
         {
             curr2=curr2->right;
             s2.pop();
             curr1=NULL;
         }
     }
     return vect;
}