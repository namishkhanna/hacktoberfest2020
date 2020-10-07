#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node(int d)
	{
		data=d;
		left=right=NULL;
	}
};

void spiralorder(Node *root)
{
	if(root==NULL)
	return ;
	queue<Node*>q;
	stack<int>s;
	q.push(root);
	bool res=false;
	while(q.empty()==false)
	{
		int count=q.size();
		//res=max(res,count);
		for(int i=0;i<count;i++)
		{
			Node *temp=q.front();
			q.pop();
			if(res)
			s.push(temp->data);
			else
			cout<<temp->data<<" ";
			if(temp->left!=NULL) q.push(temp->left);
			if(temp->right!=NULL) q.push(temp->right);
		}
		if(res)
		{
			while(s.empty()==false)
			{
				cout<<s.top()<<" ";
				s.pop();
			}
			res=!res;
		}
		
	}
	
	
}

int main()
{
	Node *root=new Node(5);
	root->left=new Node(4);
	root->right=new Node(9);
	root->left->left=new Node(8);
	/*root->right->left=new Node(40);
	root->right->right=new Node(50);
	root->right->left->left=new Node(60);
	root->right->left->right=new Node(70);*/
	spiralorder(root);
		
}
