#include<iostream>
using namespace std;
#define MAXSIZE 10

typedef int DataType;
typedef struct CircleQueue{
	DataType *data;
	int front;
	int rear;
}SqQueue;

//初始化队列
void InitQueue(SqQueue &Q){
	Q.data=new DataType[MAXSIZE];
	if(!Q.data){
		cout<<"初始化失败"<<endl;
		return;
	}
	Q.front=Q.rear=0;
} 

//获取队列当前长度
int QueueLength(SqQueue Q){
	return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
} 

//判满
bool IsFull(SqQueue Q){
	if((Q.rear+1)%MAXSIZE==Q.front){
		return true;
	}else{
		return false;
	}
} 

//判空
bool IsEmpty(SqQueue Q){
	if(Q.front==Q.rear){
		return true;
	}else{
		return false;
	}
} 

//入队列
void EnterQueue(SqQueue &Q,DataType elem){
	if(IsFull(Q)){
		cout<<"队列已满，插入失败"<<endl;
		return;
	}
	Q.data[Q.rear]=elem;
	Q.rear=(Q.rear+1)%MAXSIZE;
} 

//出队列
void DeleteQueue(SqQueue &Q,DataType &n){
	if(IsEmpty(Q)){
		cout<<"队列为空，无法出队列"<<endl;
		return;
	}
	n=Q.data[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
} 

//遍历队列 
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
	cout<<"出队元素:"<<delet<<endl;
	cout<<"当前队列长度:"<<QueueLength(Q)<<endl;
	PrintQueue(Q);
} 
