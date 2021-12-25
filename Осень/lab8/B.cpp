#include <iostream>
#include <vector>
#include <queue>

struct Node{
	int val;
	Node* left;
	Node* right;
	int l_child,r_child;
};


void insert(Node** root,int data,int l_child,int r_child){
	if(*root==nullptr){
		*root=new Node;
		(*root)->left=nullptr;
		(*root)->right=nullptr;
		(*root)->l_child=l_child;
		(*root)->r_child=r_child;
		(*root)->val=data;
		return;
	}
	if((*root)->val<data)
		insert(&(*root)->right,data,l_child,r_child);
	else if((*root)->val>data)
		insert(&(*root)->left,data,l_child,r_child);
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

void clear(Node* root){
	if(root==nullptr)
		return;
	clear(root->left);
	clear(root->right);
	delete root;
}


bool check(Node *root){
	return true;
}

int main(){
	int n;
	Node *root=nullptr;
	std::cin>>n;
	std::vector<std::vector<int>> v(n,std::vector<int>(3));
	for(int i=0;i<n;++i){
		//std::cout<<i<<" ";
		std::cin>>v[i][0]>>v[i][1]>>v[i][2];
	}
	bool ans=true;
	for(int i=0;i<n;++i){
		if(not ans) break;
		int x=v[i][1];
		int y=v[i][2];
		int val=v[i][0];
		while(x!=-1){
			if(v[x][0]>val){
				ans=false;
				break;
			}
			x=v[x][1];
		}
		while(y!=-1){
			if(v[y][0]<val){
				ans=false;
				break;
			}
			y=v[y][1];
		}
	}
	ans?std::cout<<"YES":std::cout<<"NO";
	clear(root);
}
