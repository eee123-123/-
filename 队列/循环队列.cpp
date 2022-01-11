#include<iostream>
using namespace std;
#define MAXSIZE 10

typedef int DataType;
typedef struct CircleQueue{
	DataType *data;
	int front;
	int rear;
}SqQueue;

//��ʼ������
void InitQueue(SqQueue &Q){
	Q.data=new DataType[MAXSIZE];
	if(!Q.data){
		cout<<"��ʼ��ʧ��"<<endl;
		return;
	}
	Q.front=Q.rear=0;
} 

//��ȡ���е�ǰ����
int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 

//����
bool IsFull(SqQueue Q){
	if((Q.rear+1)%MAXSIZE==Q.front){
		return true;
	}else{
		return false;
	}
} 

//�п�
bool IsEmpty(SqQueue Q){
	if(Q.front==Q.rear){
		return true;
	}else{
		return false;
	}
} 

//�����
void EnterQueue(SqQueue &Q,DataType elem){
	if(IsFull(Q)){
		cout<<"��������������ʧ��"<<endl;
		return;
	}
	Q.data[Q.rear]=elem;
	Q.rear=(Q.rear+1)%MAXSIZE;
} 

//������
void DeleteQueue(SqQueue &Q,DataType &n){
	if(IsEmpty(Q)){
		cout<<"����Ϊ�գ��޷�������"<<endl;
		return;
	}
	n=Q.data[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
} 

//�������� 
void PrintQueue(SqQueue Q){
	int temp=Q.front;
	while(temp!=Q.rear){
		cout<<Q.data[temp]<<"";
		temp=(temp+1)%MAXSIZE;
	}
	cout<<endl;
}

int main(){
	int delet;
	SqQueue Q;
	InitQueue(Q);
	EnterQueue(Q,1);
	EnterQueue(Q,2);
	EnterQueue(Q,3);
	EnterQueue(Q,4);
	PrintQueue(Q);
	DeleteQueue(Q,delet);
	cout<<"����Ԫ��:"<<delet<<endl;
	cout<<"��ǰ���г���:"<<QueueLength(Q)<<endl;
	PrintQueue(Q);
} 
