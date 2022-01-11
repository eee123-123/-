#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 20

typedef char ElemType;
typedef struct BiNode{
	ElemType data;
	BiNode *lchild;
	BiNode *rchild;
}BiTree;

BiTree* CreateBiTree(BiTree *root){
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
}//创建二叉树 （此创建对应先序序列）

int LeadCount(BiTree *root){
	if(root==NULL){
		return 0;
	}
	if(root->lchild==NULL&&root->rchild==NULL){
		return 1;
	}else{
		return LeadCount(root->lchild)+LeadCount(root->rchild);
	}
}//计算二叉树叶子结点数 

int Count1(BiTree *root){
	if(!root){
		return 0;
	}
	if(root->lchild&&!root->rchild){
		return 1+Count1(root->lchild);
	}else if(root->rchild&&!root->lchild){
		return 1+Count1(root->rchild);
	}else{
		return Count1(root->lchild)+Count1(root->rchild);
	}
} //计算度为1的结点数

int Count2(BiTree *root){
	if(!root){
		return 0;
	}	
	if(root->lchild&&root->rchild){
		return Count2(root->lchild)+Count2(root->rchild)+1;
	}else{
		return Count2(root->lchild)+Count2(root->rchild);
	}
} //计算度为2的结点数

int TreeHeight(BiTree *root){
	int left=0,right=0;
	if(!root){
		return 0;
	}else{
		left=TreeHeight(root->lchild);
		right=TreeHeight(root->rchild);
		if(left>=right)return left+1;
		if(left<right)return right+1;
	}
}//二叉树高度 

char MaxBiNode(BiTree *root){
	if(!root){
		return '0';
	}else{
		char maxl=MaxBiNode(root->lchild);
		char maxr=MaxBiNode(root->rchild);
		char max=maxl>maxr?maxl:maxr;
		return max>root->data?max:root->data;
	}
}//结点最大值

int TreeLevelSize(BiTree *root,int n){
	if((!root)||n<1){
		return 0;
	}
	if(n==1){
		return 1;
	}else{
		return TreeLevelSize(root->lchild,n-1)+TreeLevelSize(root->rchild,n-1);
	}
} //二叉树某层宽度 

int TreeMaxSize(BiTree *root,int n){
	int max=0;
	for(int i=1;i<=n;i++){
		max=max>TreeLevelSize(root,i)?max:TreeLevelSize(root,i);
	}
	return max;
}//二叉树最大宽度 

void ChangePos(BiTree *root){
	if(!root){
		return;
	}
	BiTree* temp;
	temp=root->lchild;
	root->lchild=root->rchild;
	root->rchild=temp;
	ChangePos(root->lchild);
	ChangePos(root->rchild); 
}//交换每个节点的左右孩子 

void DelLeafNode(BiTree *root){
	if(!root){
		return;
	}
	if(root->lchild){
		BiTree *temp=root->lchild;
		if(temp->lchild==NULL&&temp->rchild==NULL){
			delete temp;
			root->lchild=NULL;
		}
	}
	if(root->rchild){
		BiTree *temp=root->rchild;
		if(temp->lchild==NULL&&temp->rchild==NULL){
			delete temp;
			root->rchild=NULL;
		}
	}
	DelLeafNode(root->lchild);
	DelLeafNode(root->rchild);
//	if(root->lchild==NULL&&root->rchild==NULL){
//		delete root;
//		return;
//	}else{
//		DelLeafNode(root->lchild);
//		DelLeafNode(root->rchild);
//	}
}//删除所有叶子结点 

void PreOrderTraverse(BiTree *root){
	if(root){
		cout<<root->data<<endl;
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}else{
		return;
	}
}//先序遍历(递归)

int main(){
	BiTree *root;
	root=CreateBiTree(root);
	PreOrderTraverse(root);
//	cout<<LeadCount(root)<<endl;
//	cout<<Count1(root)<<endl;
//	cout<<Count2(root)<<endl;
//	cout<<TreeHeight(root)<<endl;
//	ChangePos(root);
//	DelLeafNode(root);
//	PreOrderTraverse(root);
//	cout<<MaxBiNode(root)<<endl;
//	cout<<TreeLevelSize(root,3)<<endl;
	cout<<TreeMaxSize(root,3)<<endl;
} 
