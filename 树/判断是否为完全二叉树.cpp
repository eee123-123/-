#include<iostream>
#include<queue> 
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

bool IsCompleteTree1(BiTree *root){
	if(!root){
		return true;
	}
	queue<BiNode*> temp;
	temp.push(root);
	bool flag = false;
	while(!temp.empty()){
		BiNode* node=temp.front();
		temp.pop();
		if(node==NULL){
			flag=true;
			continue;
		}
		if(flag){
			return false;
		}
		temp.push(node->lchild);
		temp.push(node->rchild);
	}
	return true;
}

bool IsCompleteTree2(BiTree *root){
	if(!root){
		return true;
	}
	queue<BiTree*>q;
	bool flag=true;
	q.push(root);
	while(!q.empty()){
		BiTree* temp=q.front();
		if(flag){
			if(temp->lchild&&temp->rchild){
				q.push(temp->lchild);
				q.push(temp->rchild);
			}else if(temp->lchild&&!temp->rchild){
				flag=false;
				q.push(temp->lchild);
			}else if(!temp->lchild&&temp->rchild){
				return false;
			}else{
				flag=false;
			}
		}else{
			if(!(!temp->lchild&&!temp->rchild)){
				return false;
			}
		}
		q.pop();
	}
	return true;
}

int main()
{
	BiTree *root;
	root=CreateBiTree(root);
	cout<<IsCompleteTree1(root)<<endl;
	cout<<IsCompleteTree2(root)<<endl;
}
