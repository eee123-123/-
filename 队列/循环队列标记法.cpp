#include<iostream>
using namespace std;

#define MAXSIZE 10

typedef struct Queue{
	int tag;
	int front;
	int rear;
	int data[MAXSIZE];
}Queue;

//��ʼ������
void InitQueue(Queue &Q){
	Q.tag=0;
	Q.front=0;
	Q.rear=0;
} 

//��ȡ���г���
int QueueLength(Queue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 

//�п� 
bool IsEmpty(Queue Q){
	if(Q.tag==0&&Q.front==Q.rear){
		return true;
	} 
	return false;
}

//����
bool IsFull(Queue Q){
	if(Q.tag==1&&Q.front==Q.rear){
		return true;
	}
	return false;
} 

//���
void EnterQueue(Queue &Q,int elem){
	if(IsFull(Q)){
		cout<<"�������������ʧ��"<<endl;
		return;
	}
	Q.data[Q.rear]=elem;
	Q.rear=(Q.rear+1)%MAXSIZE;
	if(Q.rear==Q.front){
		Q.tag=1;
	}
}

//���� 
void DeletQueue(Queue &Q,int &n){
	if(IsEmpty(Q)){
		cout<<"��������������ʧ��"<<endl;
		return;
	}
	n=Q.data[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	if(Q.front==Q.rear){
		Q.tag=0;
	}
}

//��������
void PrintQueue(Queue Q){
	while(Q.front!=Q.rear){
		cout<<Q.data[Q.front]<<" ";
		Q.front=(Q.front+1)%MAXSIZE;
	}
	cout<<endl;
} 

int main(){
	Queue Q;
	int temp;
	InitQueue(Q);
	EnterQueue(Q,1);
	EnterQueue(Q,2);
	EnterQueue(Q,3);
	EnterQueue(Q,4);
	cout<<"���г��ȣ�"<<QueueLength(Q)<<endl;
	PrintQueue(Q);
	DeletQueue(Q,temp);
	cout<<"���г��ȣ�"<<QueueLength(Q)<<endl;
	PrintQueue(Q);
}
