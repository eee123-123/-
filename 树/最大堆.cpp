#include<iostream>
using namespace std;

class MaxHeap{
	private:
		int *data;
		int size;//��ǰ��ģ
		int capacity;//�������
	public:
		MaxHeap(int MaxSize){
			this->data=new int[MaxSize];
			this->size=0;
			this->capacity=MaxSize;
		} 
		//���±�Ϊn��Ԫ�ص��ڳ����� ,�������� 
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
		//��������
		void Create(int *data,int n){
			for(int i=0;i<n;i++){
				this->data[++size]=data[i];
			}
			for(int i=size/2;i>0;i--){
				this->Predown(i);
			}
		} 
		//����
		bool IsFull(){
			return this->size==this->capacity;
		}
		//�п�
		bool IsEmpty(){
			return this->size==0;
		}
		//�������
		bool Insert(int num){
			if(this->IsFull()){
				cout<<"������������ʧ��"<<endl;
				return false;
			} 
			int i=++size;
			for(;this->data[i/2]<num&&i>0;i/=2){
				this->data[i]=this->data[i/2];
			}
			this->data[i]=num;
			return true;
		}
		//ɾ�����ֵ����
		int Delete(){
			if(this->IsEmpty()){
				cout<<"���ѿգ�ɾ��ʧ��"<<endl;
				return 10000;
			} 
			int max=this->data[1];
			this->data[1]=this->data[size];
			this->size--;
			Predown(1);
			return max;
		} 
		//��ӡ����
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
	cout<<"������������:"<<endl;
	cin>>capacity;
	MaxHeap maxheap(capacity);
	cout<<"�����ʼ������Ԫ�ظ���:"<<endl;
	cin>>size;
	data=new int[size];
	cout<<"��ʼ��Ԫ��:"<<endl;
	for(int i=0;i<size;i++){
		cin>>data[i];
	}
	maxheap.Create(data,size);
	cout<<"����Ϊ:"<<endl;
	maxheap.Print();
	cout<<"����Ҫ�������:"<<endl;
	cin>>num;
	maxheap.Insert(num);
	cout<<"����ɾ������"<<endl;
	num=maxheap.Delete();
	cout<<"ɾ����Ԫ��Ϊ:"<<num<<endl;
	cout<<"����Ϊ:"<<endl;
	maxheap.Print();
	
	return 0;
}
