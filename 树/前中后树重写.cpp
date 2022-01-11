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
	cout<<"����ڵ�ֵ��"<<endl;
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
}//ǰ����� 

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
}//�������

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
}//������� 

BiTree* PreInBuild(const char *pre,const char *in,int size){
	if(size<=0)return NULL;
	int value=0;
	for(value=0;value<size;value++){
		if(pre[0]==in[value]){
			break;
		}
	}
	if(value==size){
		cout<<"ǰ������ƥ��"<<endl;
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
//	cout<<"�����ɹ�����������:"<<endl;
//	InOrder(root);
	BiTree* prein=PreInBuild("ABDECF","DBEACF",6);
	cout<<"ǰ�����򴴽���Ķ������ĺ������:"<<endl;
	PostOrder(prein);
	cout<<endl;
	BiTree* inpost=InPostBuild("DBEACF","DEBFCA",6);
	cout<<"������򴴽���Ķ�������ǰ�����:"<<endl;
	PreOrder(inpost); 
	return 0;
}
