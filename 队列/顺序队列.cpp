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

//��ʼ������ 
void InitQueue(SeqQueue *SQ){
	SQ->rear=SQ->front=0;
}

//�п�
bool IsEmpty(SeqQueue *SQ){
	if(SQ->front==SQ->rear){
		flag=0;
		return true;
	}else{
		return false;
	}
} 

//����
bool IsFull(SeqQueue *SQ){
	if(SQ->rear-SQ->front+1==MAXSIZE){
		return true;
	}else{
		return false;
	}
} 

//������
void EnterQueue(SeqQueue *SQ,DataType data){
	if(IsFull(SQ)){
		cout<<"��������������ʧ��"<<endl;
		return;
	}
	SQ->Queue[SQ->rear]=data;
	SQ->rear++;
	flag=1;
} 

//������
DataType DeleteQueue(SeqQueue *SQ){
	if(IsEmpty(SQ)){
		cout<<"�����ѿգ�ɾ��ʧ��"<<endl;
		return -1;
	}
	DataType temp=SQ->Queue[SQ->front];
	SQ->front++;
	return temp;
} 

//��ȡ��ͷԪ��
DataType GetHead(SeqQueue *SQ){
	return SQ->Queue[SQ->front];
} 

//��ն���
void ClearQueue(SeqQueue *SQ){
	SQ->front=SQ->rear=0;
} 

//��ӡ����
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
		cout<<"�����ѿգ���ȡͷԪ��ʧ��"<<endl; 
	}else{
		cout<<"ͷԪ��Ϊ:"<<GetHead(SQ)<<endl;
	}
	DeleteQueue(SQ);
	PrintQueue(SQ);
	ClearQueue(SQ);
	PrintQueue(SQ);
}
