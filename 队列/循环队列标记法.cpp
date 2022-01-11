#include<iostream>
using namespace std;

#define MAXSIZE 10

typedef struct Queue{
	int tag;
	int front;
	int rear;
	int data[MAXSIZE];
}Queue;

//初始化队列
void InitQueue(Queue &Q){
	Q.tag=0;
	Q.front=0;
	Q.rear=0;
} 

//获取队列长度
int QueueLength(Queue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 

//判空 
bool IsEmpty(Queue Q){
	if(Q.tag==0&&Q.front==Q.rear){
		return true;
	} 
	return false;
}

//判满
bool IsFull(Queue Q){
	if(Q.tag==1&&Q.front==Q.rear){
		return true;
	}
	return false;
} 

//入队
void EnterQueue(Queue &Q,int elem){
	if(IsFull(Q)){
		cout<<"队列已满，入队失败"<<endl;
		return;
	}
	Q.data[Q.rear]=elem;
	Q.rear=(Q.rear+1)%MAXSIZE;
	if(Q.rear==Q.front){
		Q.tag=1;
	}
}

//出队 
void DeletQueue(Queue &Q,int &n){
	if(IsEmpty(Q)){
		cout<<"队列已满，出队失败"<<endl;
		return;
	}
	n=Q.data[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	if(Q.front==Q.rear){
		Q.tag=0;
	}
}

//遍历队列
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
	cout<<"队列长度："<<QueueLength(Q)<<endl;
	PrintQueue(Q);
	DeletQueue(Q,temp);
	cout<<"队列长度："<<QueueLength(Q)<<endl;
	PrintQueue(Q);
}
