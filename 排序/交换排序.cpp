#include<iostream>
using namespace std;

//冒泡排序
template<class T>
void BubbleSort(T data[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=1;j<n-i;j++){
			if(data[j-1]>data[j]){
				T temp=data[j-1];
				data[j-1]=data[j];
				data[j]=temp;
			}
		}
	}
}

//冒泡排序改进版
template<class T>
void BubblePlusSort(T data[],int n){
	for(int i=0;i<n-1;i++){
		int flag=0;
		for(int j=0;j<n-i-1;j++){
			if(data[j]>data[j+1]){
				T temp=data[j];
				data[j]=data[j+1];
				data[j+1]=temp;
				flag=1;
			}
		} 
		if(flag==0){
			return;
		}
	}
} 

//快速排序
template<class T>
int Partition1(T data[],int left,int right){
	T pivot=data[left];
	while(left<right){
		while(left<right&&data[right]>pivot){
			right--;
		}
		data[left]=data[right];
		while(left<right&&data[left]<pivot){
			left++;
		}
		data[right]=data[left];
	}
	data[left]=pivot;
	return left;
} 

template<class T>
int Partition2(T data[],int start,int end){
	int left=start,right=end;
	T pivot=data[start];
	while(left<=right){
		while(left<=right&&data[left]<=pivot){
			left++;
		}
		while(left<=right&&data[right]>=pivot){
			right--;
		}
		if(left<right){
			swap(data[left],data[right]);
			left++;
			right--;
		}
	}
	swap(data[start],data[right]);
	return right;
} 

template<class T>
void QuickSort(T data[],int left,int right){
	if(left<right){
		//int p=Partition1(data,left,right);
		int p=Partition2(data,left,right);
		QuickSort(data,left,p-1);
		QuickSort(data,p+1,right);
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
//	BubbleSort(data,n);
//	BubblePlusSort(data,n);
	QuickSort(data,0,n-1);
	Print(data,n);
}
