#include<iostream>
using namespace std;

typedef struct StackNode{
	int data;
	StackNode *next;
}StackNode,*LinkStack;

void InitStack(LinkStack &S){
	S=new StackNode;
	S->next=NULL;
}//��ջ��ʼ��

bool IsEmpty(LinkStack S){
	if(!S){
		return true;
	}
	return false;
}//�п�

void Push(LinkStack &S,int data){
	StackNode *p;
	p=new StackNode;
	p->data=data;
	p->next=S;
	S=p;
}//��ջ

void Pop(LinkStack &S){
	StackNode *p;
	if(IsEmpty(S)){
		cout<<"��ջ������ʧ��"<<endl;
		return;
	}
	p=S;
	cout<<p->data<<"��ջ"<<endl;
	S=S->next;
	delete p; 
}//��ջ

int GetTop(LinkStack S){
	if(IsEmpty(S)){
		cout<<"ջ�գ��޷�ȡ��"<<endl;
		return 0;
	}
	return S->data;
}//��ȡջ��Ԫ��

void PrintStack(LinkStack S){
	while(S->next){
		cout<<S->data<<"\t";
		S=S->next;
	}
}//��ӡ

int main(){
	StackNode *S;
	InitStack(S);
	Push(S,1); 
	Push(S,2); 
	Push(S,3); 
	Push(S,4); 
	PrintStack(S);
	Pop(S);
	cout<<GetTop(S)<<endl;
	PrintStack(S);
	return 0;
} 

