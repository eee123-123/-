#include<iostream>
#include<string>
using namespace std;

//先自定义队列及方法 
typedef struct QNode{
	string data;
	QNode *next;
}QNode;

typedef struct{
	QNode *front,*rear;
	int size;
}LinkQueue; 

//初始化队列
void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=new QNode;
	if(!Q.front){
		cout<<"初始化错误"<<endl;
		return;
	}
	Q.front->next=NULL;
	Q.size=0;
}

//入队操作 
void InQueue(LinkQueue &Q,string x){
	QNode *p=new QNode;
	p->data=x;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
	Q.size++;
} 

//出队操作
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

//判空
bool QueueEmpty(LinkQueue Q){
	if(Q.front==Q.rear){
		return true;
	}
	return false;
} 

//打印队列
void PrintQueue(LinkQueue Q){
	Q.front=Q.front->next;
	while(Q.front!=NULL){
		cout<<Q.front->data<<" ";
		Q.front=Q.front->next;
	}
	cout<<endl;
} 

//功能实现
//队列元素查找
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
		cout<<"前面还有"<<count<<"个人在排队等待"<<endl;
		return true; 
	}
}

//队列删除元素
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

//主程序执行
int main(){
	string name,first,flag;
	int num;
	LinkQueue Q,VQ;
	InitQueue(Q);
	InitQueue(VQ);
	while(1){
		cout<<"************************"<<endl;
		cout<<"  1.排队管理 	 "<<endl;
		cout<<"  2.呼叫客户  	 "<<endl;
		cout<<"  3.打印客户信息  "<<endl;
		cout<<"  4.查找客户      "<<endl;
		cout<<"  5.删除客户      "<<endl;
		cout<<"************************"<<endl;
		cout<<"请选择所需要的服务(按0退出服务系统):"<<endl;
		cin>>num; 
		_flushall();//清空缓存
		switch(num){
			case 0:
				cout<<"谢谢您的使用，欢迎下次再来"<<endl;
				return 0;
			case 1:
				while(true){
					cout<<"请输入排队客户姓名:"<<endl;
					cin>>name;
					cout<<"是否为VIP客户(y/n):"<<endl;
					cin>>first;
					if(first=="y"){
						InQueue(VQ,name);
					}else{
						InQueue(Q,name);
					}
					cout<<"是否继续输入排队客户(y/n):"<<endl;
					cin>>flag;
					if(flag=="n"){
						break;
					}
					_flushall();
				}
				break;
			case 2:
				if(OutQueue(VQ,name)){
					cout<<"请VIP客户"<<name<<"办理业务"<<endl;
				}else if(OutQueue(Q,name)){
					cout<<"请普通客户"<<name<<"办理业务"<<endl;
				}else{
					cout<<"当前无排队用户"<<endl;
				}
				break;
			case 3:
				if(QueueEmpty(Q)){
					cout<<"当前没有排队的客户"<<endl;
				}else{
					cout<<"VIP客户："<<endl;
					PrintQueue(VQ);
					cout<<"普通客户："<<endl;
					PrintQueue(Q); 
				}
				break;
			case 4:
				cout<<"输入要查找的客户姓名："<<endl;
				cin>>name;
				if(SearchQueue(VQ,name)){
					cout<<name<<"在VIP客户队列中"<<endl; 
				}else if(SearchQueue(Q,name)){
					cout<<name<<"在普通客户队列中"<<endl;
				}else{
					cout<<name<<"不在客户队列中"<<endl;
				}
				break;
			case 5:
				cout<<"输入要删除客户姓名:"<<endl;
				cin>>name;
				if(DeletQueue(VQ,name)||DeletQueue(Q,name)){
					cout<<"已删除该客户"<<endl;
				}else{
					cout<<"客户队列中无此人，删除失败"<<endl;
				}
				break;
			default:
				cout<<"输入有误，请重新输入"<<endl;
				break;
		} 
	}
} 
