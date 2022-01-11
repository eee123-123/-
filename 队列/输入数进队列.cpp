#include<iostream>
using namespace std;
template<class T>
class LinkNode{
	public:
		T data;
		LinkNode<T> *next;
		LinkNode(T data){
			this->data=data;
		}
};

template<class T>
class LinkQueue{
	private:
		LinkNode<T> *front;
		LinkNode<T> *rear;
		int size;
	public:
		LinkQueue(int size=0){
			this->front=this->rear=NULL;
			this->size=size;
		}	
		bool IsEmpty(){
			if(size==0){
				return true;
			}
			return false;
		}
		void PrintQueue(){
			LinkNode<T> *p=front;
			if(p==NULL){
				cout<<"队列为空";
				return;
			}else{
				for(;p!=rear->next;p=p->next){
					cout<<p->data<<" ";
				}
			}
		}
		void EnterQueue(T data);
		void EnterQueue(LinkNode<T> *p);
		LinkNode<T> *OutQueue();
		void ChangeQueue(LinkQueue<T> Q);
};

template<class T>
void LinkQueue<T>::EnterQueue(T data){
	LinkNode<T> *temp=new LinkNode<T>(data);
	if(rear==NULL){
		this->rear=this->front=temp;
	}else{
		this->rear->next=temp;
		this->rear=temp;
	}
	this->size++;
}

template<class T>
void LinkQueue<T>::EnterQueue(LinkNode<T> *p){
	if(this->rear==NULL){
		this->rear=this->front=p;
	}else{
		this->rear->next=p;
		this->rear=p;
	}
	this->size++;
}

template<class T>
LinkNode<T>* LinkQueue<T>::OutQueue(){
	if(this->front==NULL){
		cout<<"队列为空，无法出队"<<endl;
		return NULL;
	}else{
		LinkNode<T> *temp=this->front;
		this->front=this->front->next;
		this->size--;
		return temp;
	}
}

template<class T>
void LinkQueue<T>::ChangeQueue(LinkQueue<T> p){
	LinkNode<T> *temp=NULL;
	while(!p.IsEmpty()){
		temp=p.OutQueue();
		EnterQueue(temp);
	}
}

int main(){
	int n;
	LinkQueue<int> result[11];
	cout<<"输入0~9之间的数字，输入-1停止输入:"<<endl;
	cin>>n;
	while(n>=0&&n<=9&&n!=-1){
		result[n].EnterQueue(n);
		cin>>n;
	}
	for(int i=0;i<10;i++){
		if(!result[i].IsEmpty()){
			result[10].ChangeQueue(result[i]);
		}
	}
	cout<<"结果为:"<<endl;
	result[10].PrintQueue();
	return 0;
}


