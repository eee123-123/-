#include<iostream>
using namespace std;

class MaxHeap{
	private:
		int *data;
		int size;//当前规模
		int capacity;//最大容量
	public:
		MaxHeap(int MaxSize){
			this->data=new int[MaxSize];
			this->size=0;
			this->capacity=MaxSize;
		} 
		//将下标为n的元素调节成最大堆 ,辅助功能 
		void Predown(int n){
			int x=data[n];
			int parent,child;
			for(parent=n;parent*2<=this->size;parent=child){
				child=parent*2;
				if((child!=this->size)&&this->data[child]<this->data[child+1]){
					child++;
				}
				if(x>this->data[child]){
					break;
				}else{
					this->data[parent]=this->data[child];
				}
			}
			this->data[parent]=x;
		}
		//创建最大堆
		void Create(int *data,int n){
			for(int i=0;i<n;i++){
				this->data[++size]=data[i];
			}
			for(int i=size/2;i>0;i--){
				this->Predown(i);
			}
		} 
		//判满
		bool IsFull(){
			return this->size==this->capacity;
		}
		//判空
		bool IsEmpty(){
			return this->size==0;
		}
		//插入操作
		bool Insert(int num){
			if(this->IsFull()){
				cout<<"堆已满，插入失败"<<endl;
				return false;
			} 
			int i=++size;
			for(;this->data[i/2]<num&&i>0;i/=2){
				this->data[i]=this->data[i/2];
			}
			this->data[i]=num;
			return true;
		}
		//删除最大值操作
		int Delete(){
			if(this->IsEmpty()){
				cout<<"堆已空，删除失败"<<endl;
				return 10000;
			} 
			int max=this->data[1];
			this->data[1]=this->data[size];
			this->size--;
			Predown(1);
			return max;
		} 
		//打印最大堆
		void Print(){
			for(int i=1;i<=size;i++){
				cout<<this->data[i]<<" ";
			}
			cout<<endl;
		} 
};

int main(){
	int capacity,size,num;
	int *data;
	cout<<"输入最大堆容量:"<<endl;
	cin>>capacity;
	MaxHeap maxheap(capacity);
	cout<<"输入初始化最大堆元素个数:"<<endl;
	cin>>size;
	data=new int[size];
	cout<<"初始化元素:"<<endl;
	for(int i=0;i<size;i++){
		cin>>data[i];
	}
	maxheap.Create(data,size);
	cout<<"最大堆为:"<<endl;
	maxheap.Print();
	cout<<"输入要插入的数:"<<endl;
	cin>>num;
	maxheap.Insert(num);
	cout<<"进行删除操作"<<endl;
	num=maxheap.Delete();
	cout<<"删除的元素为:"<<num<<endl;
	cout<<"最大堆为:"<<endl;
	maxheap.Print();
	
	return 0;
}
