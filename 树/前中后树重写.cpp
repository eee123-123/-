#include<iostream>
#include<string>
#include<stack> 
using namespace std;

#define MAXSIZE 20

typedef struct BiNode{
	char data;
	BiNode* lchild;
	BiNode* rchild;
}BiTree;

BiTree* Create(BiTree* root){
	char ch;
	cout<<"输入节点值："<<endl;
	cin>>ch;
	if(ch=='#'){
		root=NULL;
		return root;
	}else{
		root=new BiNode;
		root->data=ch;
		root->lchild=Create(root->lchild);
		root->rchild=Create(root->rchild);
	}
}

void PreOrder(BiTree* root){
	if(!root){
		return;
	}
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
}//前序遍历 

void InOrder(BiTree* root){
	if(!root){
		return;
	}
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
}//中序遍历

void PostOrder(BiTree* root){
	if(!root){
		return;
	}
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
				return;
			}
			p=st.top();
			st.pop();
		}
		st.push(p);
		p=p->rchild;
	}
}//后序遍历 

BiTree* PreInBuild(const char *pre,const char *in,int size){
	if(size<=0)return NULL;
	int value=0;
	for(value=0;value<size;value++){
		if(pre[0]==in[value]){
			break;
		}
	}
	if(value==size){
		cout<<"前序中序不匹配"<<endl;
		return NULL;
	}
	BiTree* root=new BiNode;
	root->data=pre[0];
	root->lchild=PreInBuild(pre+1,in,value);
	root->rchild=PreInBuild(pre+value+1,in+value+1,size-value-1);
	return root;
}

BiTree* InPostBuild(const char *in,const char *post,int size){
	if(size<=0){
		return NULL;
	}
	int value=0;
	for(value=0;value<size;value++){
		if(post[size-1]==in[value]){
			break;
		}
	}
	BiTree* root=new BiNode;
	root->data=post[size-1];
	root->lchild=InPostBuild(in,post,value);
	root->rchild=InPostBuild(in+value+1,post+value,size-value-1);
	return root;
}

int main(){
//	BiTree* root;
//	root=Create(root);
//	cout<<"创建成功后的中序遍历:"<<endl;
//	InOrder(root);
	BiTree* prein=PreInBuild("ABDECF","DBEACF",6);
	cout<<"前序中序创建后的二叉树的后序遍历:"<<endl;
	PostOrder(prein);
	cout<<endl;
	BiTree* inpost=InPostBuild("DBEACF","DEBFCA",6);
	cout<<"中序后序创建后的二叉树的前序遍历:"<<endl;
	PreOrder(inpost); 
	return 0;
}
