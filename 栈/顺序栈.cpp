#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int SElemType;
typedef struct SqStack{
	SElemType data[MAXSIZE];
	int top;//指向栈顶元素 
}SqStack;

void InitStack(SqStack &S){
	S.top=0;
}//初始化空栈

bool IsEmpty(SqStack S){
	if(S.top==0){
		cout<<"空栈"<<endl;
		return true;
	}else{
		return false;
	} 
}//判空 

bool IsFull(SqStack S){
	if(S.top==MAXSIZE){
		return true;
	}else{
		return false;
	}
}//判满

int GetSize(SqStack S){
	return S.top;
}//返回栈的实际长度 

void GetTop(SqStack S,SElemType &e){
	if(!IsEmpty(S)){
		e=S.data[S.top-1];
	}else{
		cout<<"栈空，无法取出"<<endl;
	}
}//取栈顶元素

void Push(SqStack &S,SElemType e){
	if(IsFull(S)){
		cout<<"栈满，入栈失败"<<endl; 
	}else{
		S.data[S.top++]=e;
	} 
}//入栈

void Pop(SqStack &S){
	if(IsEmpty(S)){
		cout<<"栈空，出栈失败"<<endl;
	}else{
		cout<<"出栈元素为:"<<S.data[S.top-1]<<endl;
		S.top--; 
	}
}//出栈

void CreateStack(SqStack &S,int n){
	cout<<"依次输入放入栈内的元素："<<endl;
	for(int i=0;i<n;i++){
		SElemType e;
		cin>>e;
		Push(S,e);
	}
	cout<<endl;
}//创建一个初始栈

void PrintStack(SqStack S){
	cout<<"打印栈："<<endl;
	for(int i=S.top-1;i>=0;i--){
		cout<<S.data[i]<<"\t"; 
	}
	cout<<endl;
}//打印栈

void ClearStack(SqStack &S){
	S.top=-1;
}//清空栈
//注：顺序栈栈底栈顶实现见D盘code中
int main(){
	SqStack S;
	InitStack(S);
	
	CreateStack(S,5);
	PrintStack(S);
	
	cout<<"输入入栈元素:"<<endl;
	SElemType e;
	cin>>e;
	Push(S,e);
	PrintStack(S);
	
	Pop(S);
	PrintStack(S);
	
	GetTop(S,e);
	cout<<"栈顶元素为:"<<e<<endl;
	cout<<"栈长为:"<<GetSize(S)<<endl;
	
	return 0; 
} 
