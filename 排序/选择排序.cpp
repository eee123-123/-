#include<iostream>

using namespace std;

//简单选择排序 
template<class T>
void SelectSort(T data[],int n){
	for(int i=0;i<n-1;i++){
		int k=i;
		for(int j=i+1;j<n;j++){
			if(data[j]<data[k]){
				k=j;
			}
		}
		T temp=data[i];
		data[i]=data[k];
		data[k]=temp;
	}
}

//堆排序
template<class T>
void ShiftDown(T data[],int i,int n){
	int left=i*2+1,right=i*2+2,min=i;
	if(left<n&&data[left]>data[min]){
		min=left;
	} 
	if(right<n&&data[right]>data[min]){
		min=right;
	}
	if(min!=i){
		T temp=data[i];
		data[i]=data[min];
		data[min]=temp;	
	}
	ShiftDown(data,min,n);
}//用以保持最大堆的性质
template<class T>
void BuildHeap(T data[],int n){
	for(int i=n/2-1;i>=0;i--){
		ShiftDown(data,i,n);
	}
}//创建最大堆 
template<class T>
void MaxHeap(T data[],int m,int n){
	for(int i=n/2-1;i>=m;i--){
		ShiftDown(data,i,n);
	}
}//调整取出最大元素后的堆
template<class T>
void HeapSort(T data[],int n){
	BuildHeap(data,n);
	for(int i=n-1;i>0;i--){
		T temp=data[0];
		data[0]=data[i];
		data[i]=temp;
		MaxHeap(data,0,i);
	}
}

template<class T>
void Print(T data[],int n){
	for(int i=0;i<n;i++){
		cout<<data[i]<<" ";
	}
}

int main(){
	int n;
	cout<<"输入元素个数"<<endl;
	cin>>n;
	int data[n];
	cout<<"输入数组元素"<<endl;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
//	SelectSort(data,n);
	HeapSort(data,n);
	Print(data,n);
}
