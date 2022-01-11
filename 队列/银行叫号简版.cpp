#include<iostream>
#include<string>
using namespace std;

//���Զ�����м����� 
typedef struct QNode{
	string data;
	QNode *next;
}QNode;

typedef struct{
	QNode *front,*rear;
	int size;
}LinkQueue; 

//��ʼ������
void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	if(!Q.front){
		cout<<"��ʼ������"<<endl;
		return;
	}
	Q.front->next=NULL;
	Q.size=0;
}

//��Ӳ��� 
void InQueue(LinkQueue &Q,string x){
	QNode *p=new QNode;
	p->data=x;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	Q.size++;
} 

//���Ӳ���
bool OutQueue(LinkQueue &Q,string &x){
	QNode *p;
	if(Q.front==Q.rear||Q.size==0){
		return false;
	}
	p=Q.front->next;
	x=p->data;
	Q.front->next=p->next;
	Q.size--;
	delete p;
	return true;
}

//�п�
bool QueueEmpty(LinkQueue Q){
	if(Q.front==Q.rear){
		return true;
	}
	return false;
} 

//��ӡ����
void PrintQueue(LinkQueue Q){
	Q.front=Q.front->next;
	while(Q.front!=NULL){
		cout<<Q.front->data<<" ";
		Q.front=Q.front->next;
	}
	cout<<endl;
} 

//����ʵ��
//����Ԫ�ز���
bool SearchQueue(LinkQueue Q,string name){
	int count=0;
	Q.front=Q.front->next;
	while(Q.front->data!=name&&Q.front->next!=NULL){
		Q.front=Q.front->next;
		count++;
	}
	if(Q.front->data!=name){
		return false;
	}else{
		cout<<"ǰ�滹��"<<count<<"�������Ŷӵȴ�"<<endl;
		return true; 
	}
}

//����ɾ��Ԫ��
bool DeletQueue(LinkQueue &Q,string name){
	QNode *p,*q;
	q=Q.front;
	p=Q.front->next;
	while(p!=NULL){
		if(p->data==name){
			q->next=p->next;
			delete p;
			p=q->next;
			return true;
		}else{
			q=p;
			p=p->next;
		}
	}
	return false;
} 

//������ִ��
int main(){
	string name,first,flag;
	int num;
	LinkQueue Q,VQ;
	InitQueue(Q);
	InitQueue(VQ);
	while(1){
		cout<<"************************"<<endl;
		cout<<"  1.�Ŷӹ��� 	 "<<endl;
		cout<<"  2.���пͻ�  	 "<<endl;
		cout<<"  3.��ӡ�ͻ���Ϣ  "<<endl;
		cout<<"  4.���ҿͻ�      "<<endl;
		cout<<"  5.ɾ���ͻ�      "<<endl;
		cout<<"************************"<<endl;
		cout<<"��ѡ������Ҫ�ķ���(��0�˳�����ϵͳ):"<<endl;
		cin>>num; 
		_flushall();//��ջ���
		switch(num){
			case 0:
				cout<<"лл����ʹ�ã���ӭ�´�����"<<endl;
				return 0;
			case 1:
				while(true){
					cout<<"�������Ŷӿͻ�����:"<<endl;
					cin>>name;
					cout<<"�Ƿ�ΪVIP�ͻ�(y/n):"<<endl;
					cin>>first;
					if(first=="y"){
						InQueue(VQ,name);
					}else{
						InQueue(Q,name);
					}
					cout<<"�Ƿ���������Ŷӿͻ�(y/n):"<<endl;
					cin>>flag;
					if(flag=="n"){
						break;
					}
					_flushall();
				}
				break;
			case 2:
				if(OutQueue(VQ,name)){
					cout<<"��VIP�ͻ�"<<name<<"����ҵ��"<<endl;
				}else if(OutQueue(Q,name)){
					cout<<"����ͨ�ͻ�"<<name<<"����ҵ��"<<endl;
				}else{
					cout<<"��ǰ���Ŷ��û�"<<endl;
				}
				break;
			case 3:
				if(QueueEmpty(Q)){
					cout<<"��ǰû���ŶӵĿͻ�"<<endl;
				}else{
					cout<<"VIP�ͻ���"<<endl;
					PrintQueue(VQ);
					cout<<"��ͨ�ͻ���"<<endl;
					PrintQueue(Q); 
				}
				break;
			case 4:
				cout<<"����Ҫ���ҵĿͻ�������"<<endl;
				cin>>name;
				if(SearchQueue(VQ,name)){
					cout<<name<<"��VIP�ͻ�������"<<endl; 
				}else if(SearchQueue(Q,name)){
					cout<<name<<"����ͨ�ͻ�������"<<endl;
				}else{
					cout<<name<<"���ڿͻ�������"<<endl;
				}
				break;
			case 5:
				cout<<"����Ҫɾ���ͻ�����:"<<endl;
				cin>>name;
				if(DeletQueue(VQ,name)||DeletQueue(Q,name)){
					cout<<"��ɾ���ÿͻ�"<<endl;
				}else{
					cout<<"�ͻ��������޴��ˣ�ɾ��ʧ��"<<endl;
				}
				break;
			default:
				cout<<"������������������"<<endl;
				break;
		} 
	}
} 
