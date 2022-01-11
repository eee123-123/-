#include<iostream>
using namespace std;

//ֱ�Ӳ�������
template<class T>
void InsertSort(T array[],int n){
	T temp;
	for(int i=1;i<n;i++){
		temp=array[i];
		int j=i-1;
		while(j>=0&&temp<array[j]){
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=temp;
	}
} 
//�۰��������(���Ѿ��ź���Ŀ���ʹ��)
template<class T>
void BinaryInsertSort(T array[],int n){
	int right,left,mid,p;
	for(p=1;p<n;p++){
		T temp=array[p];
		left=0;
		right=p-1;
		while(left<=right)
		{
			mid=(right+left)/2;
			if(array[mid]>temp){
				right=mid-1;
			}else{
				left=mid+1;
			}
		}
		for(int i=p-1;i>=left;i--){
			array[i+1]=array[i];	
		}
		array[left]=temp;
	}
}

//ϣ������ 
template<class T>
void ShellSort(T data[],int n){
	int d=n/2;
	while(d){
		for(int k=0;k<d;k++){
			for(int i=k+d;i<n;i+=d){
				T temp=data[i];
				int j=i-d;
				while(j>=k&&temp<data[j]){
					data[j+d]=data[j];
					j-=d;
				}
				data[j+d]=temp;
			}
		}
		d/=2;
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
	cout<<"����Ԫ�ظ���"<<endl;
	cin>>n;
	int data[n];
	cout<<"��������Ԫ��"<<endl;
	for(int i=0;i<n;i++){
		cin>>data[i];
	}
//	InsertSort(data,n);
//	BinaryInsertSort(data,n);
	ShellSort(data,n);
	Print(data,n);
}
