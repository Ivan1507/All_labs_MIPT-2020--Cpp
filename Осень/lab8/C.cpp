#include <iostream>
#include <queue>

struct Node{
	int val;
	Node* left;
	Node* right;
};


void insert(Node** root,int data){
	if(*root==nullptr){
		*root=new Node;
		(*root)->left=nullptr;
		(*root)->right=nullptr;
		(*root)->val=data;
		return;
	}
	if((*root)->val<data)
		insert(&(*root)->right,data);
	else if((*root)->val>data)
		insert(&(*root)->left,data);
}

void bfs(Node *root){
	std::queue<Node*> que;
	que.push(root);
	while(not que.empty()){
		Node* t=que.front();
		que.pop();
		std::cout<<t->val<<" ";
		if(t->left!=nullptr)
			que.push(t->left);
		if(t->right!=nullptr)
			que.push(t->right);
	}
}

int height(Node* root){
	if(root==nullptr){
		return 0;
	}
	return std::max(height(root->left),height(root->right))+1;
}
int main(){
	int n;
	Node *root=nullptr;
	while(std::cin>>n){
		insert(&root,n);
	}
	std::cout<<height(root);
}
