#include<iostream>
#include<string>
#include<stack>
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

BiTree *CopyTree(BiTree *root,BiTree *T){
	if(root==NULL){
		T=NULL;
		return T;
	}else{
		T=new BiTree;
		T->data=root->data;
		T->lchild=CopyTree(root->lchild,T->lchild);
		T->rchild=CopyTree(root->rchild,T->rchild);
	}
}//复制二叉树（对应先序序列）

int TreeDepth(BiTree *root){
	int left=0,right=0;
	if(root==NULL){
		return 0;
	}else{
		left=TreeDepth(root->lchild);
		right=TreeDepth(root->rchild);
		if(left>=right)return left+1;
		if(left<right)return right+1;
	}
}//二叉树深度 

void Levelorder(BiTree *root){
	BiNode *p,*Q[MAXSIZE];
	int front=-1,rear=-1;
	rear+=1;
	Q[rear]=root;
	while(front!=rear){
		front=(front+1)%MAXSIZE;
		p=Q[front];
		cout<<p->data;
		if(p->lchild!=NULL){
			rear=(rear+1)%MAXSIZE;
			Q[rear]=p->lchild;
		}
		if(p->rchild!=NULL){
			rear=(rear+1)%MAXSIZE;
			Q[rear]=p->rchild;
		}
	}
}//层次遍历 

void PreOrderTraverse(BiTree *root){
	if(root){
		cout<<root->data<<endl;
		PreOrderTraverse(root->lchild);
		PreOrderTraverse(root->rchild);
	}else{
		return;
	}
}//先序遍历(递归)

void InOrderTraverse(BiTree *root){
	if(root){
		InOrderTraverse(root->lchild);
		cout<<root->data<<endl;
		InOrderTraverse(root->rchild);
	}else{
		return;
	}
}//中序遍历(递归)

void PostOrderTraverse(BiTree *root){
	if(root){	
		PostOrderTraverse(root->lchild);
		PostOrderTraverse(root->rchild);
		cout<<root->data<<endl;
	}else{
		return;
	}
}//后序遍历(递归)


int GetNode(BiTree *T){
	if(T==NULL){
		return 0;
	}else{
		return GetNode(T->lchild)+GetNode(T->rchild)+1; 
	}
}//计算结点数 

int LeadCount(BiTree *T){
	if(T==NULL){
		return 0;
	}
	if(T->lchild==NULL&&T->rchild==NULL){
		return 1;
	}else{
		return LeadCount(T->lchild)+LeadCount(T->rchild);
	}
}//计算二叉树叶子结点数 

//void PreOrder(BiTree *root){
//	BiNode *St[MAXSIZE],*p;
//	int top=-1;
//	if(root!=NULL){
//		top++;
//		St[top]=root;
//		while(top>-1){
//			p=St[top];
//			top--;
//			cout<<p->data<<"\t";
//			if(p->rchild!=NULL){
//				top++;
//				St[top]=p->rchild;
//			}
//			if(p->lchild!=NULL){
//				top++;
//				St[top]=p->lchild;
//			}
//		}
//		cout<<endl;
//	}
//}//先序遍历（非递归）
void PreOrder(BiTree *root){
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
} //先序遍历（非递归）

//void InOrder(BiTree *root){
//	BiNode *St[MAXSIZE],*p;
//	int top=-1;
//	if(root!=NULL){
//		p=root;
//		while(top>-1||p!=NULL){
//			while(p!=NULL){
//				top++;
//				St[top]=p;
//				p=p->lchild;
//			}
//			
//			if(top>-1){
//				p=St[top];
//				top--;
//				cout<<p->data<<"\t";
//				p=p->rchild; 
//			}
//		}
//		cout<<endl;
//	}
//}//中序遍历（非递归） 

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
}//中序遍历（非递归）

//void PostOrder(BiTree *root){
//	BiNode *St[MAXSIZE],*q=root;
//	BiNode *p;
//	int flag,top=-1;
//	if(q!=NULL){
//		do{
//			while(q!=NULL){
//				top++;
//				St[top]=q;
//				q=q->lchild;
//			}
//			p=NULL;
//			flag=1;
//			while(top!=-1&&flag){
//				q=St[top];
//				if(q->rchild==p){
//					cout<<q->data<<"\t";
//					top--;
//					p=q;
//				}else{
//					q=q->rchild;
//					flag=0;
//				}
//			}
//		}while(top!=-1); 
//		cout<<endl;
//	}
//}//后序遍历（非递归）

void PostOrder(BiTree* root){
	BiTree* temp;
	stack<BiTree*>st1;
	stack<BiTree*>st2;
	st1.push(root);
	while(!st1.empty()){
		temp=st1.top();
		st1.pop();
		st2.push(temp);
		if(temp->lchild){
			st1.push(temp->lchild);
		}
		if(temp->rchild){
			st1.push(temp->rchild);
		}
	}
	while(!st2.empty()){
		cout<<st2.top()->data<<" ";
		st2.pop();
	}
} //后序遍历（非递归）

//后序
//void PostOrder(BiTree* root){
//	stack<BiTree*>st;
//	BiTree* p=root;
//	BiTree* q=root;
//	while(p){
//		while(p->lchild){
//			st.push(p);
//			p=p->lchild;
//		} 
//		while(!p->rchild||p->rchild==q){
//			cout<<p->data<<" ";
//			q=p;
//			if(st.empty()){
//				return ;
//			}
//			p=st.top();
//			st.pop();
//		}
//		st.push(p);
//		p=p->rchild;
//	}
//} 

BiTree *PreInBuild(const char *pre,const char *in,int size){
	if(size<=0)return NULL;
	int root_value=0;
	for(root_value=0;root_value<size;root_value++){
		if(in[root_value]==pre[0]){
			break;
		}
	}
	if(root_value==size){
		cout<<"先序遍历和中序遍历不匹配"<<endl;
		return NULL;
	}
	BiTree *root=new BiTree;
	root->data=pre[0];
	root->lchild=PreInBuild(pre+1,in,root_value);
	root->rchild=PreInBuild(pre+root_value+1,in+root_value+1,size-root_value-1);
	return root;
}//先序中序求树

BiTree *InPostBuild(const char *in,const char *post,int size){
	if(size<=0)return NULL;
	int root_value=0;
	for(root_value=0;root_value<size;root_value++){
		if(in[root_value]==post[size-1]){
			break;
		} 
	}
	BiTree *root=new BiTree;
	root->data=post[size-1];
	root->lchild=InPostBuild(in,post,root_value);
	root->rchild=InPostBuild(in+root_value+1,post+root_value,size-1-root_value);
	return root; 
}//中序后序求树

bool searchBNode(BiTree *root,char c){
	if(root==NULL){
		return false;
	}
	if(root->data==c){
		return true;
	}
	return searchBNode(root->lchild,c)||searchBNode(root->rchild,c);
}//查找

void ChangePos(BiTree *root){
	if(root==NULL){
		return;
	}
	BiTree *temp;
	temp=root->lchild;
	root->lchild=root->rchild;
	root->rchild=temp;
	ChangePos(root->lchild);
	ChangePos(root->rchild);
}//交换左右子树 

void Postchange(BiTree *root){
	if(root!=NULL){
		return;
	}
	cout<<root->data<<" ";
	Postchange(root->rchild);
	Postchange(root->lchild);
}//反序输出后序 

int main(){
	BiTree *root,*T;
	root=CreateBiTree(root);
	//PreOrderTraverse(root);
	//InOrderTraverse(root);
	//PostOrderTraverse(root);
	//Levelorder(root);
	//cout<<GetNode(root)<<endl;
	//cout<<LeadCount(root)<<endl;
	//PreOrder(root);
	//InOrder(root);
	//PostOrder(root);
	//T=CopyTree(root,T);
	/*T=PreInBuild("ABDECFG","DBEAFCG",7);
	PostOrder(T);*/
	/*T=InPostBuild("DBEAFCG","DEBFGCA",7);
	PreOrder(T);*/
	//cout<<searchBNode(root,'D')<<endl;
	/*Levelorder(root);
	ChangePos(root);
	cout<<endl;
	Levelorder(root);*/
	//Postchange(root); 
} 
