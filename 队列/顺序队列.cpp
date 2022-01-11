#include<iostream>
using namespace std;
#define MAXSIZE 10 

typedef int DataType;
typedef struct Queue{
	DataType Queue[MAXSIZE];
	int rear;
	int front;
}SeqQueue;

bool flag=1;

//初始化队列 
void InitQueue(SeqQueue *SQ){
	SQ->rear=SQ->front=0;
}

//判空
bool IsEmpty(SeqQueue *SQ){
	if(SQ->front==SQ->rear){
		flag=0;
		return true;
	}else{
		return false;
	}
} 

//判满
bool IsFull(SeqQueue *SQ){
	if(SQ->rear-SQ->front+1==MAXSIZE){
		return true;
	}else{
		return false;
	}
} 

//进队列
void EnterQueue(SeqQueue *SQ,DataType data){
	if(IsFull(SQ)){
		cout<<"队列已满，插入失败"<<endl;
		return;
	}
	SQ->Queue[SQ->rear]=data;
	SQ->rear++;
	flag=1;
} 

//出队列
DataType DeleteQueue(SeqQueue *SQ){
	if(IsEmpty(SQ)){
		cout<<"队列已空，删除失败"<<endl;
		return -1;
	}
	DataType temp=SQ->Queue[SQ->front];
	SQ->front++;
	return temp;
} 

//获取队头元素
DataType GetHead(SeqQueue *SQ){
	return SQ->Queue[SQ->front];
} 

//清空队列
void ClearQueue(SeqQueue *SQ){
	SQ->front=SQ->rear=0;
} 

//打印队列
void PrintQueue(SeqQueue *SQ){
	int i=SQ->front;
	while(i!=SQ->rear){
		cout<<SQ->Queue[i]<<" ";
		i++;
	}
	cout<<endl;
} 

int main(){
	SeqQueue *SQ=new SeqQueue;
	InitQueue(SQ);
	EnterQueue(SQ,1); 
	EnterQueue(SQ,2);
	EnterQueue(SQ,3);
	EnterQueue(SQ,4);
	PrintQueue(SQ);
	if(flag==0){
		cout<<"队列已空，获取头元素失败"<<endl; 
	}else{
		cout<<"头元素为:"<<GetHead(SQ)<<endl;
	}
	DeleteQueue(SQ);
	PrintQueue(SQ);
	ClearQueue(SQ);
	PrintQueue(SQ);
}
