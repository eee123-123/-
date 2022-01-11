#include<iostream>
using namespace std;

typedef struct StackNode{
	int data;
	StackNode *next;
}StackNode,*LinkStack;

void InitStack(LinkStack &S){
	S=new StackNode;
	S->next=NULL;
}//链栈初始化

bool IsEmpty(LinkStack S){
	if(!S){
		return true;
	}
	return false;
}//判空

void Push(LinkStack &S,int data){
	StackNode *p;
	p=new StackNode;
	p->data=data;
	p->next=S;
	S=p;
}//入栈

void Pop(LinkStack &S){
	StackNode *p;
	if(IsEmpty(S)){
		cout<<"空栈，操作失败"<<endl;
		return;
	}
	p=S;
	cout<<p->data<<"出栈"<<endl;
	S=S->next;
	delete p; 
}//出栈

int GetTop(LinkStack S){
	if(IsEmpty(S)){
		cout<<"栈空，无法取得"<<endl;
		return 0;
	}
	return S->data;
}//获取栈顶元素

void PrintStack(LinkStack S){
	while(S->next){
		cout<<S->data<<"\t";
		S=S->next;
	}
}//打印

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

