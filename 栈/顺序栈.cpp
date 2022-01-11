#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef int SElemType;
typedef struct SqStack{
	SElemType data[MAXSIZE];
	int top;//ָ��ջ��Ԫ�� 
}SqStack;

void InitStack(SqStack &S){
	S.top=0;
}//��ʼ����ջ

bool IsEmpty(SqStack S){
	if(S.top==0){
		cout<<"��ջ"<<endl;
		return true;
	}else{
		return false;
	} 
}//�п� 

bool IsFull(SqStack S){
	if(S.top==MAXSIZE){
		return true;
	}else{
		return false;
	}
}//����

int GetSize(SqStack S){
	return S.top;
}//����ջ��ʵ�ʳ��� 

void GetTop(SqStack S,SElemType &e){
	if(!IsEmpty(S)){
		e=S.data[S.top-1];
	}else{
		cout<<"ջ�գ��޷�ȡ��"<<endl;
	}
}//ȡջ��Ԫ��

void Push(SqStack &S,SElemType e){
	if(IsFull(S)){
		cout<<"ջ������ջʧ��"<<endl; 
	}else{
		S.data[S.top++]=e;
	} 
}//��ջ

void Pop(SqStack &S){
	if(IsEmpty(S)){
		cout<<"ջ�գ���ջʧ��"<<endl;
	}else{
		cout<<"��ջԪ��Ϊ:"<<S.data[S.top-1]<<endl;
		S.top--; 
	}
}//��ջ

void CreateStack(SqStack &S,int n){
	cout<<"�����������ջ�ڵ�Ԫ�أ�"<<endl;
	for(int i=0;i<n;i++){
		SElemType e;
		cin>>e;
		Push(S,e);
	}
	cout<<endl;
}//����һ����ʼջ

void PrintStack(SqStack S){
	cout<<"��ӡջ��"<<endl;
	for(int i=S.top-1;i>=0;i--){
		cout<<S.data[i]<<"\t"; 
	}
	cout<<endl;
}//��ӡջ

void ClearStack(SqStack &S){
	S.top=-1;
}//���ջ
//ע��˳��ջջ��ջ��ʵ�ּ�D��code��
int main(){
	SqStack S;
	InitStack(S);
	
	CreateStack(S,5);
	PrintStack(S);
	
	cout<<"������ջԪ��:"<<endl;
	SElemType e;
	cin>>e;
	Push(S,e);
	PrintStack(S);
	
	Pop(S);
	PrintStack(S);
	
	GetTop(S,e);
	cout<<"ջ��Ԫ��Ϊ:"<<e<<endl;
	cout<<"ջ��Ϊ:"<<GetSize(S)<<endl;
	
	return 0; 
} 
