#include<iostream>
using namespace std;

class MinHeap{
	private:
		int *data;
		int size;//��ǰ��ģ
		int capacity;//����ģ
	public:
		MinHeap(int MaxSize){
			data=new int[MaxSize];
			size=0;
			capacity=MaxSize;
		} 
	//���±�Ϊn��Ԫ�ص��ڳ���С�ѣ���������
	void Preup(int n){
		int x=data[n];
		int parent,child;
		for(parent=n;parent*2<=size;parent=child){
			child=parent*2;
			if(child!=size&&data[child+1]<data[child]){
				child++;
			}
			if(x<data[child]){
				break;
			}else{
				data[parent]=data[child];
			}
		}
		data[parent]=x;
	}	
	//������С��
	void Create(int *data,int n){
		for(int i=0;i<n;i++){
			this->data[++size]=data[i];
		}
		for(int i=size/2;i>0;i--){
			Preup(i);
		}
	} 
	//����
	bool IsFull(){
		if(size==capacity){
			return true;
		}
		return false;
	} 
	//�п�
	bool IsEmpty(){
		if(size==0){
			return true;
		}
		return false;
	} 
	//�������
	bool Insert(int num){
		if(IsFull()){
			cout<<"��С������"<<endl;
			return false;
		}
		int n=++size;
		for(;data[n/2]>data[n];n/=2){
			data[n]=data[n/2];
		}
		data[n]=num;
		return true;
	} 
	//ɾ����Сֵ
	int Delete(){
		if(IsEmpty()){
			cout<<"��С���ѿ�"<<endl;
			return -10000;
		} 
		int min=data[1];
		data[1]=data[size--];
		Preup(1);
		return min;
	} 
	//��ӡ��С��
	void Print(){
		for(int i=1;i<=size;i++){
			cout<<data[i]<<" "; 
		}
		cout<<endl;
	}	
};

int main(){
	int size,capacity,num;
	cout<<"������С������:"<<endl;
	cin>>capacity;
	MinHeap minheap(capacity);
	cout<<"������С�ѳ�ʼ����:"<<endl;
	cin>>size;
	int *data=new int[size];
	cout<<"�����ʼ��Ԫ��:"<<endl;
	for(int i=0;i<size;i++){
		cin>>data[i];
	}
	minheap.Create(data,size);
	cout<<"��С��Ϊ:"<<endl;
	minheap.Print();
	cout<<"����Ҫ�������:"<<endl;
	cin>>num;
	minheap.Insert(num);
	cout<<"����ɾ������:"<<endl;
	num=minheap.Delete();
	cout<<"ɾ����Ԫ�أ���СԪ�أ�Ϊ: "<<num<<endl;
	cout<<"��ʱ��С��Ϊ:"<<endl;
	minheap.Print();
	
	return 0;
}
