//#include<iostream>
//#include<string>
//#include<stack>
//#include<queue>
#include<bits/stdc++.h> 
using namespace std;

typedef struct BiNode{
	char data;
	BiNode* rchild;
	BiNode* lchild;
}BiTree;

//创建
BiTree* CreateBiTree(BiTree* root){
	char ch;
	cout<<"输入节点值:"<<endl;
	cin>>ch;
	if(ch=='#'){
		root=NULL;
		return root;
	}else{
		root=new BiTree;
		root->data=ch;
		root->lchild=CreateBiTree(root->lchild);
		root->rchild=CreateBiTree(root->rchild);
	}
} 

//复制
BiTree* CopyTree(BiTree* root,BiTree* T){
	if(root==NULL){
		T=NULL;
		return T;
	}else{
		T=new BiTree;
		T->data=root->data;
		T->lchild=CopyTree(root->lchild,T->lchild);
		T->rchild=CopyTree(root->rchild,T->rchild);
	}
} 

//深度
int TreeDepth(BiTree* root){
	int left=0,right=0;
	if(root==NULL){
		return 0;
	}else{
		left=TreeDepth(root->lchild);
		right=TreeDepth(root->rchild);
		if(left>right)return left+1;
		else return right+1;
	}
} 

//结点数
int GetNode(BiTree* root){
	if(!root){
		return 0;
	}else{
		return GetNode(root->lchild)+GetNode(root->rchild)+1;
	}
} 

//叶子数
int GetLeaf(BiTree* root){
	if(!root){
		return 0; 
	}else{
		if(!root->lchild&&!root->rchild){
			return 1;
		}else{
			return GetLeaf(root->lchild)+GetLeaf(root->rchild);
		}
	}
} 

//1度节点数
int Count1(BiTree* root){
	if(!root){
		return 0;
	}else{
		if(root->lchild&&!root->rchild){
			return Count1(root->lchild)+1;
		}else if(root->rchild&&!root->lchild){
			return Count1(root->rchild)+1;
		}else{
			return Count1(root->lchild)+Count1(root->rchild);
		}
	}
} 

//2度结点数
int Count2(BiTree* root){
	if(!root){
		return 0;
	}else{
		if(root->lchild&&root->rchild){
			return Count2(root->lchild)+Count2(root->rchild)+1;
		}else{
			return Count2(root->lchild)+Count2(root->rchild);
		}
	}
} 

char MaxBiNode(BiTree* root){
	if(!root){
		return '0';
	}else{
		char maxr=MaxBiNode(root->rchild);
		char maxl=MaxBiNode(root->lchild);
		char max=maxr>maxl?maxr:maxl;
		return max>root->data?max:root->data;
	}
}

//某层宽
int TreeLevelSize(BiTree* root,int n){
	if(!root||n<1){
		return 0;
	}else{
		if(n==1){
			return 1;
		}else{
			return TreeLevelSize(root->lchild,n-1)+TreeLevelSize(root->rchild,n-1);
		}
	}
} 

//最大宽
int TreeMaxSize(BiTree* root,int n){
	int max=0;
	for(int i=1;i<=n;i++){
		max=max>TreeLevelSize(root,i)?max:TreeLevelSize(root,i);
	}
	return max;
} 

//交换左右孩子
void ChangePos(BiTree* root){
	if(!root){
		return;
	}
	BiTree* temp;
	temp=root->lchild;
	root->lchild=root->rchild;
	root->rchild=temp;
	ChangePos(root->lchild);
	ChangePos(root->rchild);
} 

//删叶子
void DelLeafNode(BiTree* root){
	if(!root){
		return;
	}else{
		if(root->lchild){
			BiTree* temp=root->lchild;
			if(!temp->lchild&&!temp->rchild){
				delete temp;
				root->lchild=NULL;
			}
		}
		if(root->rchild){
			BiTree* temp=root->rchild;
			if(!temp->lchild&&!temp->rchild){
				delete temp;
				root->rchild=NULL;
			}
		}
	}
	DelLeafNode(root->lchild);
	DelLeafNode(root->rchild);
} 

//层次
void LevelOrder(BiTree* root){
	queue<BiTree*>Q;
	BiTree* pointer=root;
	if(pointer)
	Q.push(pointer);
	while(!Q.empty()){
		pointer=Q.front();
		cout<<pointer->data<<" ";
		Q.pop();
		if(pointer->lchild){
			Q.push(pointer->lchild);
		}
		if(pointer->rchild){
			Q.push(pointer->rchild);
		}
	}
} 

//先序
void PreOrder(BiTree* root){
	stack<BiTree*>st;
	BiTree* pointer=root;
	while(!st.empty()||pointer){
		if(pointer){
			cout<<pointer->data<<" ";
			if(pointer->rchild){
				st.push(pointer->rchild);
			}
			pointer=pointer->lchild;
		}else{
			pointer=st.top();
			st.pop();
		}
	} 
} 

//中序
void InOrder(BiTree* root){
	stack<BiTree*>st;
	BiTree* pointer=root;
	while(!st.empty()||pointer){
		if(pointer){
			st.push(pointer);
			pointer=pointer->lchild;
		}else{
			pointer=st.top();
			cout<<pointer->data<<" ";
			pointer=pointer->rchild;
			st.pop();
		}
	}
} 

//后序
void PostOrder(BiTree* root){
	stack<BiTree*>st;
	BiTree* p=root;
	BiTree* q=root;
	while(p){
		while(p->lchild){
			st.push(p);
			p=p->lchild;
		} 
		while(!p->rchild||p->rchild==q){
			cout<<p->data<<" ";
			q=p;
			if(st.empty()){
				return ;
			}
			p=st.top();
			st.pop();
		}
		st.push(p);
		p=p->rchild;
	}
} 

int main(){
	BiTree* root;
	root=CreateBiTree(root);
	PostOrder(root);
}
