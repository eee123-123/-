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
//��ʼ�����У���Ϊ�� 
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
 
 
//��Ӳ���,ͨ��strcpy()�������и��ƣ��ڶ�β��������
void InQueue(LinkQueue *Q,char *x)
{
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	if(p==NULL)
	{
		printf("�ڴ治��!");
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
		printf("�ڴ治��!");
		exit(1);
	}
	strcpy(p->data,x);
	p->next=NULL;
	FQ->rear->next=p;
	FQ->rear=p;
} 
 
 
//ͨ��strcpy()�������и��ƣ���ͨ��ָ���ڶ�ͷ����ͻ���
void HeadInQueue(LinkQueue *Q,const char *x)
{
	QNode *p;
	p=(QNode *)malloc(sizeof(QNode));
	strcpy(p->data,x);           //�����½ڵ㲢���ͻ�������������data�� 
	p->next=Q->front->next;      //�޸�frontָ�룬�ڶ�ͷ���� 
	Q->front->next=p;
} 
 
 
//���Ӳ���
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
 
 
//�ж�����Ϊ�գ����ǿ���ѵ�һ��ɾ�����������һ��Ԫ��
int QueueEmpty(LinkQueue *Q)
{
	if(Q->front==Q->rear)
		return 1;
	else
		return 0;
} 
 
 
//ͨ��while()ѭ���������������ʾ��������
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
 
//ͨ��while()ѭ��������Ԫ���������������бȽϣ����鵽��Ԫ�ص�λ�����
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
	 {printf("ǰ����%d�����ڵȴ�\n",i);
	  free(p);
	  return 1;}
	
} 
 
 
 
//ͨ��while����ѭ�������б�����������������Ԫ��ͨ��ָ��ɾ��
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
//�Բ˵���ʽ��ʾ�����б����ն˶�ȡ���룬ִ�ж�Ӧ�Ĺ��� 
int main()
{
	char sel,x,flag='m';
	char name[10];
	LinkQueue *Q=InitQueue();
	LinkQueue *FQ=InitQueue();
	while(1)
	{
		printf("\n***********************\n");
		printf("  1.�Ŷӹ���     \n");
		printf("  2.���пͻ�     \n");
		printf("  3.��ӡ�ͻ���Ϣ \n");
		printf("  4.���ҿͻ�     \n");
		printf("  5.ɾ���ͻ�     \n");
		printf("  0.��ն���     \n");
		printf("\n***********************\n  ��ѡ��(���������):");
		scanf("%c",&sel);_flushall();
		switch(sel)
		{
			case '0':
				if(!(QueueEmpty(Q)||QueueEmpty(FQ)))
					printf("���ŶӵĿͻ���������\n");
			    break;
	    	case '1':
	    	  while(flag!='y')
	    		{
				printf("����ͻ���������");
	    		scanf("%s",name);
	    		_flushall();
	    		printf("�Ƿ�����?(y/n):");
	    		scanf("%c",&x);
	    		getchar();
	    		if(x=='y')
    		 		InFQueue(FQ,name);
  		 		else
  		 			InQueue(Q,name);
 			    printf("�Ƿ��������(��y����)\n");
				 scanf("%c",&flag); 
			   }
	 			break;
 			case '2':
 				
				    if(OutQueue(FQ,name)==1)
					    printf("��VIP�ͻ�%s����\n",name);
					else if(OutQueue(Q,name)==1)
				    {  
					   printf("��ͻ�%s����\n",name);
				    }
					else
					 printf("���ŶӵĿͻ�!\n");	
				
				
					
				break;
			case '3':
				if(QueueEmpty(Q))
				{
					printf("û���ŶӵĿͻ�\n");
				}
				else
				{
					printf("��ͨ�Ŷ���:");
					QueueTraverse(Q);
					printf("�����Ŷ���:");
					QueueTraverse(FQ);
				}
				break;
			case '4':
				printf("����ͻ�������\n");
				scanf("%s",name);
				_flushall();
				if(Search(Q,name)==1)
						printf("��������ͨ�Ķ����У�\n");
            	else if(Search(FQ,name)==1)
						printf("���������ȵĶ����У�\n");
				else
						printf("û�������\n");	
				break;
			case '5':
				printf("����ͻ���������");
				scanf("%s",name);
				_flushall();
				if(Delete(Q,name)==1||Delete(FQ,name)==1)
					printf("��ȡ��\n");
				else
					printf("δ�ҵ�����\n");
				break;
			
			
			default:
				printf("ѡ�����,������ѡ��.\n");
				break;
		} 
	}	
}
