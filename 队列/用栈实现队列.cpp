#include<iostream>
#include<stack>
using namespace std;

template<class T>
class MyQueue{
	private:
		stack<T>head;
		stack<T>tail;
	public:
		bool empty(){
			return head.empty()&&tail.empty();
		}//�п�
		void push(T data){
			head.push(data);
		}//�����
		void pop(){
			if(empty()){
				cout<<"����Ϊ��"<<endl;
				return;
			} 
			while(!head.empty()){
				tail.push(head.top());
				head.pop();
			}
			tail.pop();
			while(!tail.empty()){
				head.push(tail.top());
				tail.pop();
			}
		}//������ 
		T rear(){
			if(head.empty()){
				cout<<"����Ϊ��"<<endl;
				return -1;
			}
			return head.top(); 
		}//�������һ��Ԫ�� 
		T front(){
			T top;
			if(head.empty()){
				cout<<"����Ϊ��"<<endl;
				return -1;
			}
			while(!head.empty()){
				tail.push(head.top());
				head.pop();
			} 
			top=tail.top();
			while(!tail.empty()){
				head.push(tail.top());
				tail.pop();
			}
			return top;
		}//���ص�һ��Ԫ�� 
};

int main(){
	MyQueue<int> Q;
	for(int i=0;i<5;i++){
		Q.push(i+1);
	}
	cout<<"front:"<<Q.front()<<endl;
	cout<<"rear:"<<Q.rear()<<endl;
	Q.pop();
	cout<<"front:"<<Q.front()<<endl;
}
