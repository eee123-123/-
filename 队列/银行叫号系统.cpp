#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define false 0
 
typedef struct QNode
{
 	char data[10];
	 struct QNode *next;	
}QNode;
 
typedef struct
{
	QNode *front,*rear;
}LinkQueue;
 
typedef LinkQueue Flist;
//初始化队列，置为空 
LinkQueue* InitQueue()
{
	LinkQueue *queue;
	QNode *node;
	queue=(LinkQueue*)malloc(sizeof(LinkQueue));
	node=(QNode*)malloc(sizeof(QNode));
	node->next=NULL;
	queue->front=queue->rear=node;
	return queue;
}
 
 
//入队操作,通过strcpy()函数进行复制，在队尾插入姓名
void InQueue(LinkQueue *Q,char *x)
{
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	if(p==NULL)
	{
		printf("内存不足!");
		exit(1);
	}
	strcpy(p->data,x);
	p->next=NULL;
	Q->rear->next=p;
	Q->rear=p;
} 
void InFQueue(Flist *FQ,char *x)
{
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	if(p==NULL)
	{
		printf("内存不足!");
		exit(1);
	}
	strcpy(p->data,x);
	p->next=NULL;
	FQ->rear->next=p;
	FQ->rear=p;
} 
 
 
//通过strcpy()函数进行复制，并通过指针在队头插入客户名
void HeadInQueue(LinkQueue *Q,const char *x)
{
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	strcpy(p->data,x);           //创建新节点并将客户名存入数据域data中 
	p->next=Q->front->next;      //修改front指针，在对头插入 
	Q->front->next=p;
} 
 
 
//出队操作
int OutQueue(LinkQueue *Q,char *x)
{
	QNode *p;
	if(Q->front==Q->rear) return 0;
	p=Q->front->next;
	strcpy(x,p->data);
	Q->front->next=p->next;
	if(p->next==NULL)
		Q->rear=Q->front;
	free(p);
	return 1;
} 
 
 
//判定队列为空，不是空则把第一个删除，及办理第一个元素
int QueueEmpty(LinkQueue *Q)
{
	if(Q->front==Q->rear)
		return 1;
	else
		return 0;
} 
 
 
//通过while()循环将队列输出，显示队列内容
void QueueTraverse(LinkQueue *Q)
{
	QNode *p=Q->front->next;
	while(p!=NULL)
	{
		printf("%s	",p->data);
		p=p->next;
	}
	printf("\n");
} 
 
//通过while()循环将队列元素与输入姓名进行比较，将查到的元素的位置输出
int Search(LinkQueue *Q,char x[])
{
	QNode *p;
	int  i=0;
	p=Q->front->next;
	while(strcmp(p->data,x)!=0&&p->next!=NULL)
	{
		p=p->next;
		i++;
	}
	if(strcmp(p->data,x)!=0)
	   {
	   	free(p);
	     return 0;
		 }
	else
	 {printf("前面有%d个人在等待\n",i);
	  free(p);
	  return 1;}
	
} 
 
 
 
//通过while（）循环将队列遍历，将输入姓名的元素通过指针删除
int Delete(LinkQueue *Q,char x[])
{
	QNode *p,*q;
	int bfound=false;
	p=Q->front->next;
	q=Q->front;
	while(p!=NULL)
	{
		if(strcmp(p->data,x)==0)
		{
			q->next=p->next;
			free(p);
			p=NULL;
			return 1;
		}
		else
		{
			q=p;
			p=p->next;
		}
	}
} 
//以菜单方式显示功能列表，从终端读取输入，执行对应的功能 
int main()
{
	char sel,x,flag='m';
	char name[10];
	LinkQueue *Q=InitQueue();
	LinkQueue *FQ=InitQueue();
	while(1)
	{
		printf("\n***********************\n");
		printf("  1.排队管理     \n");
		printf("  2.呼叫客户     \n");
		printf("  3.打印客户信息 \n");
		printf("  4.查找客户     \n");
		printf("  5.删除客户     \n");
		printf("  0.清空队列     \n");
		printf("\n***********************\n  请选择(操作的序号):");
		scanf("%c",&sel);_flushall();
		switch(sel)
		{
			case '0':
				if(!(QueueEmpty(Q)||QueueEmpty(FQ)))
					printf("请排队的客户明天再来\n");
			    break;
	    	case '1':
	    	  while(flag!='y')
	    		{
				printf("输入客户的姓名：");
	    		scanf("%s",name);
	    		_flushall();
	    		printf("是否优先?(y/n):");
	    		scanf("%c",&x);
	    		getchar();
	    		if(x=='y')
    		 		InFQueue(FQ,name);
  		 		else
  		 			InQueue(Q,name);
 			    printf("是否结束输入(按y结束)\n");
				 scanf("%c",&flag); 
			   }
	 			break;
 			case '2':
 				
				    if(OutQueue(FQ,name)==1)
					    printf("请VIP客户%s办理\n",name);
					else if(OutQueue(Q,name)==1)
				    {  
					   printf("请客户%s办理\n",name);
				    }
					else
					 printf("无排队的客户!\n");	
				
				
					
				break;
			case '3':
				if(QueueEmpty(Q))
				{
					printf("没有排队的客户\n");
				}
				else
				{
					printf("普通排队者:");
					QueueTraverse(Q);
					printf("优先排队者:");
					QueueTraverse(FQ);
				}
				break;
			case '4':
				printf("输入客户姓名：\n");
				scanf("%s",name);
				_flushall();
				if(Search(Q,name)==1)
						printf("并且在普通的队列中！\n");
            	else if(Search(FQ,name)==1)
						printf("并且在优先的队列中！\n");
				else
						printf("没有这个人\n");	
				break;
			case '5':
				printf("输入客户的姓名：");
				scanf("%s",name);
				_flushall();
				if(Delete(Q,name)==1||Delete(FQ,name)==1)
					printf("已取消\n");
				else
					printf("未找到该人\n");
				break;
			
			
			default:
				printf("选择错误,请重新选择.\n");
				break;
		} 
	}	
}
