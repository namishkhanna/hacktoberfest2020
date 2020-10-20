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

bool findpath(Node *root, vector<Node*> p,int n)
{
	if(root==NULL) return false;
	p.push_back(root);
	if(root->data==n) return true;
	if(findpath(root->left,p,n) || findpath(root->right,p,n))
	return true;
	
	p.pop_back();
	return false;
}

Node* lca(Node *root, int n1, int n2)
{
	vector<Node*>path1,path2;
	if(findpath(root,path1,n1)==false || findpath(root,path2,n2)==false)
	return NULL;
	
	for(int i=0;i<path1.size()-1 && i<path2.size()-1; i++)
	{
		if(path1[i+1]!=path2[i+1])
		return path1[i];
	}
	return NULL;
	
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(15);
	root->right=new Node(20);
	root->left->left=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	root->right->left->left=new Node(60);
	root->right->left->right=new Node(70);
	//spiralorder(root);
	int n1,n2;
	cin>>n1>>n2;
	Node *temp=lca(root,n1,n2);
	cout<<"LCA:"<<temp->data<<endl;	
}
