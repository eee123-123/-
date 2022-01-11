#include<iostream>
using namespace std;

class MinHeap{
	private:
		int *data;
		int size;//当前规模
		int capacity;//最大规模
	public:
		MinHeap(int MaxSize){
			data=new int[MaxSize];
			size=0;
			capacity=MaxSize;
		} 
	//将下标为n的元素调节成最小堆，辅助功能
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
	//创建最小堆
	void Create(int *data,int n){
		for(int i=0;i<n;i++){
			this->data[++size]=data[i];
		}
		for(int i=size/2;i>0;i--){
			Preup(i);
		}
	} 
	//判满
	bool IsFull(){
		if(size==capacity){
			return true;
		}
		return false;
	} 
	//判空
	bool IsEmpty(){
		if(size==0){
			return true;
		}
		return false;
	} 
	//插入操作
	bool Insert(int num){
		if(IsFull()){
			cout<<"最小堆已满"<<endl;
			return false;
		}
		int n=++size;
		for(;data[n/2]>data[n];n/=2){
			data[n]=data[n/2];
		}
		data[n]=num;
		return true;
	} 
	//删除最小值
	int Delete(){
		if(IsEmpty()){
			cout<<"最小堆已空"<<endl;
			return -10000;
		} 
		int min=data[1];
		data[1]=data[size--];
		Preup(1);
		return min;
	} 
	//打印最小堆
	void Print(){
		for(int i=1;i<=size;i++){
			cout<<data[i]<<" "; 
		}
		cout<<endl;
	}	
};

int main(){
	int size,capacity,num;
	cout<<"输入最小堆容量:"<<endl;
	cin>>capacity;
	MinHeap minheap(capacity);
	cout<<"输入最小堆初始个数:"<<endl;
	cin>>size;
	int *data=new int[size];
	cout<<"输入初始化元素:"<<endl;
	for(int i=0;i<size;i++){
		cin>>data[i];
	}
	minheap.Create(data,size);
	cout<<"最小堆为:"<<endl;
	minheap.Print();
	cout<<"输入要插入的数:"<<endl;
	cin>>num;
	minheap.Insert(num);
	cout<<"进行删除操作:"<<endl;
	num=minheap.Delete();
	cout<<"删除的元素（最小元素）为: "<<num<<endl;
	cout<<"此时最小堆为:"<<endl;
	minheap.Print();
	
	return 0;
}
