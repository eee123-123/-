#include<iostream>
using namespace std;
  
typedef int DataType;
typedef struct QNode{
	DataType data;
	QNode *next;
}QNode,*pQNode;
typedef struct Queue{
	int size;
	pQNode front;
	pQNode rear;
}LinkQueue; 

//初始化链队列
void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	if(!Q.front){
		return;
	}
	Q.front->next=NULL;
	Q.size=0;
} 

//销毁链队列
void DestroyQueue(LinkQueue &Q){
	pQNode temp;
	while(Q.front){
		temp=Q.front->next;
		delete Q.front;
		Q.front=temp;
	}
} 

//获得头元素
void GetHead(LinkQueue Q,DataType &n){
	if(Q.front==Q.rear){
		cout<<"队列空，无法取得";
		return;
	}
	n=Q.front->data;
} 

//获取链队列长度 
int GetLength(LinkQueue Q){
	return Q.size;
}

//判空
bool IsEmpty(LinkQueue Q){
	if(Q.front==Q.rear){
		return true;
	}
	return false;
} 

//入队列
void EnterQueue(LinkQueue &Q,DataType data){
	pQNode p=new QNode;
	p->data=data;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	Q.size++;
} 

//出队列
void DeleteQueue(LinkQueue &Q,DataType &n){
	if(IsEmpty(Q)){
		cout<<"队列空，出队失败"<<endl;
		return;
	}
	pQNode p=Q.front->next;
	n=p->data;
	Q.front->next=p->next; 
	delete p;
	Q.size--;
}

//打印队列
void PrintQueue(LinkQueue Q){
	while(Q.front!=Q.rear){
		Q.front=Q.front->next;
		cout<<Q.front->data<<" ";
	}
	cout<<endl;
} 

int main(){
	DataType temp;
	LinkQueue Q;
	InitQueue(Q);
	EnterQueue(Q,1); 
	EnterQueue(Q,2); 
	EnterQueue(Q,3); 
	EnterQueue(Q,4);
	PrintQueue(Q);
	cout<<"Length="<<GetLength(Q)<<endl;
	DeleteQueue(Q,temp);
	cout<<temp<<"出队列"<<endl;
	PrintQueue(Q);
	cout<<"Length="<<GetLength(Q)<<endl;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h> 
//
//typedef int ElemType;
//
//typedef struct Node
//{
//	ElemType data;
//	Node *next;
//}*NodePtr;
//
//typedef struct LinkQue
//{
//	NodePtr front;
//	NodePtr rear;
//}*LinkQuePtr;
//
//static NodePtr Apply_Node(ElemType val)
//{
//	NodePtr s = (NodePtr)malloc(sizeof(Node));
//	assert(s!=NULL);
//	s->data = val;
//	s->next = NULL;
//	return s;
//}
//
//int Empty_LinkQue(LinkQuePtr que)
//{
//	assert(que != NULL);
//	if(que == NULL)
//	{
//		printf("%s:%d   IsEmpty is error\n",__FILE__,__LINE__);
//		exit(0);
//	}
//
//	if(que->front == NULL)
//	{
//		return true;
//	}
//	return false;
//}
//
//int Init_LinkQue(LinkQuePtr que)
//{
//	assert(que != NULL);
//	if(que == NULL)
//	{
//		printf("%s:%d   Init is error\n",__FILE__,__LINE__);
//		exit(0);
//	}
//	que->front = que->rear = NULL;
//	return true;
//}
//
//int Push_LinkQue(LinkQuePtr que,ElemType val)
//{
//	assert(que != NULL);
//	if(que == NULL)
//	{
//		printf("%s:%d   Push is error\n",__FILE__,__LINE__);
//		exit(0);
//	}
//	NodePtr s = Apply_Node(val);
//	if(Empty_LinkQue(que))
//	{
//		que->front = s;
//		que->rear = s;
//	}
//	else
//	{
//		que->rear->next = s;
//		que->rear = s;
//	}
//	return true;
//}
//
//int Pop_LinkQue(LinkQuePtr que)
//{
//	assert(que != NULL);
//	if(que == NULL)
//	{
//		printf("%s:%d   Pop is error\n",__FILE__,__LINE__);
//		exit(0);
//	}
//	if(Empty_LinkQue(que))
//	{
//		return false;
//	}
//	NodePtr s = que->front;
//	que->front = s->next;
//	free(s);
//	return true;
//}
//
//ElemType Get_QueHead(LinkQuePtr que)
//{
//	assert(que != NULL);
//	if(que == NULL)
//	{
//		printf("%s:%d   GetHead is error\n",__FILE__,__LINE__);
//		exit(0);
//	}
//
//	if(Empty_LinkQue(que))
//	{
//		return false;
//	}
//	else
//	{
//		return que->front->data;
//	}
//}
//
//int Destroy_LinkQue(LinkQuePtr que)
//{
//	assert(que != NULL);
//	if(que == NULL)
//	{
//		printf("%s:%d   Destroy is error\n",__FILE__,__LINE__);
//		exit(0);
//	}
//
//	if(Empty_LinkQue(que))
//	{
//		return false;
//	}
//	else
//	{
//		while(que->front->next!=NULL)
//		{
//			Pop_LinkQue(que);
//		}
//		que->front = que->rear = NULL;
//		return true;
//	}
//}
//
//int main()
//{
//	//以下为测试内容-------------------
//	LinkQue que;
//	Init_LinkQue(&que);
//	for(int i=0;i<10;i++)
//	{
//		Push_LinkQue(&que,i);
//	}
//	printf("%d  ",Get_QueHead(&que));
//	//printf("%d\n",que.front->data);
//	Pop_LinkQue(&que);
//	printf("%d  ",Get_QueHead(&que));
//	//printf("%d\n",que.front->data);
//	Pop_LinkQue(&que);
//	printf("%d  ",Get_QueHead(&que));
//	Pop_LinkQue(&que);
//	printf("%d  ",Get_QueHead(&que));
//	Pop_LinkQue(&que);
//	printf("%d  ",Get_QueHead(&que));
//	Pop_LinkQue(&que);
//	printf("%d  ",Get_QueHead(&que));
//	return 0;
//}


//#include<iostream>
//using namespace std;
//
//typedef struct SqQueueNode {
//	int data;
//	SqQueueNode* next;
//}*QNode;
//typedef struct SqQueue
//{
//	int size;
//	QNode front;
//	QNode rear;
//}*LinkQueue;
//
//void InitQueue(LinkQueue Q) { 
//	Q->front =Q->rear = NULL;
//	Q->size = 0;
//}
//
//void Destroy(LinkQueue Q) {
//	QNode temp;
//	while (Q->front) {
//		temp = Q->front->next;
//		delete Q->front;
//		Q->front = temp;
//	}
//}
//
//int GetTop(LinkQueue Q) {
//	if (Q->front == Q->rear) {
//		cout << "队列空，无法取得" << endl;
//		return 0;
//	}
//	return Q->front->data;
//}
//
//int GetSize(LinkQueue Q) {
//	return Q->size;
//}
//
//void Push(LinkQueue Q, int x) {
//	QNode temp = new SqQueueNode;
//	temp->data = x;
//	temp->next = NULL;
//	if (Q->front == Q->rear) {
//		Q->front = temp;
//		Q->rear = temp;
//	}
//	else {
//		Q->rear->next = temp;
//		Q->rear = temp;
//	}
//}
//
//void Pop(LinkQueue Q) {
//	if (Q->front == Q->rear) {
//		cout << "队列空，删除失败" << endl;
//		return;
//	}
//	QNode temp = Q->front;
//	cout << Q->front->data << "出队列" << endl;
//	Q->front = Q->front->next;
//	delete temp;
//	Q->size--;
//}
//
//void Print(LinkQueue Q) {
//	while (Q) {
//		cout << Q->front->data<<" ";
//		Q->front=Q->front->next;
//	}
//	/*while (Q->front != Q->rear) {
//		cout << Q->front->data << " ";
//		Q->front = Q->front->next;
//	}*/
//	cout << endl;
//}
//
//int main() {
//	LinkQueue Q=new SqQueue;
//	InitQueue(Q);
//	Push(Q, 1);
//	Push(Q, 2);
//	Push(Q, 3);
//	Push(Q, 4);
//	Print(Q);
//	Pop(Q);
//	cout << GetSize(Q) << endl;
//	cout << GetTop(Q) << endl;
//	Print(Q);
//}
