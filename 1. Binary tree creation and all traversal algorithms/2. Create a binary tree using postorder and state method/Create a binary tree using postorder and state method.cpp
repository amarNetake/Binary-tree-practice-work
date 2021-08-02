/*
Given a postorder traversal array result. Convert it into a tree.You will also be given with the states as follows
CONDITIONS:-
	0.Postorder=> left->right->root. Hence root will be at end of vector so traverse array in reverse direction.
	1. Let postorder be ={NULL,NULL,NULL,4,NULL,NULL,5,6,7}. Then 7 will be the root and 6 will be the right child of 7. Similarly 6 
	will be the parent and 5 will be the right child of 6. Similarly 5 will be the parent with right child=NULL and left Child=NULL 
	implies 5 is leaf node. 4 is the left child of 6. 4 is leaf as its right and left child is NULL.Now left child of root 7
	is NULL.
	2. Traverse the vector or array in reverse direction for postorder.
	2. When you visit the item in vector create a node of it and push the node into the stack with state 1.
	3. When you find status of top node's state in stack is 1 then push the 
	previous array element as right child of that node with state 1 and make the state of the node 2.
	3. When the state of node at top of stack is 2 then push the next node from array as left 
	child and make the state of node as 3.
	4. When the state of node at top of stack is 3 then pop the top of stack
	5. To insert NULL or to represent NULL data use 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int data)
	{
		this->data=data;
		left=right=NULL;
	}
};

void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
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
		vector<int> vect(n);
		for(int i=0;i<n;i++)
		{
			cin>>vect[i];
		}

		/*
			Since in postorder:- LEFT->RIGHT->ROOT. Hence to infer a tree traverse the vector in reverse direction
			with the order of computation as root then root->right then root->left.
		*/
		Node* root=new Node(vect[n-1]);
		pair<Node*,int> pa=make_pair(root,1);
		stack<pair<Node*,int>> st;
		st.push(pa);
		int idx=n-1; //To traverse through the preorder vector 'vect'.
		while(st.empty()!=true)
		{
			if(st.top().second==1)
			{
				idx--;
				Node* temp=st.top().first;
				if(vect[idx]!=0)  //Here 0 =>NULL
				{
				    Node* new_node=new Node(vect[idx]);
				    temp->right=new_node;
				    st.top().second++;
				    st.push(make_pair(new_node,1));
				}
				else if(vect[idx]==0)   //Here 0 =>NULL
				{
				    st.top().second++;
				}
			}
			else if(st.top().second==2)
			{
				idx--;
				Node * temp=st.top().first;
				if(vect[idx]!=0)       //Here 0 =>NULL
				{
				    Node* new_node=new Node(vect[idx]);
				    temp->left=new_node;
				    st.top().second++;
				    st.push(make_pair(new_node,1));
				}
				else if(vect[idx]==0)  //Here 0 =>NULL
				{
				    st.top().second++;
				}
			}
			else if(st.top().second==3)
			{
				st.pop();
			}
		}
		cout<<"Preorder: ";
		preorder(root);
		cout<<"\n\n";
		cout<<"Inorder: ";
		inorder(root);
		cout<<"\n\n";
		cout<<"Postorder: ";
		postorder(root);
	}
	return 0;
}