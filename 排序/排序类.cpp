#include<bits/stdc++.h>
using namespace std;

template<class T>
class Sort{
	private:
		int num;
		T* array;
	public:
		Sort(int n,T* array){num=n;this->array=array;}
		/*插入排序*/
		//直接插入排序
		void InsertSort(T* array,int n){
			T temp;
			for(int i=1;i<n;i++){
				temp=array[i];
				int j=i-1; 
				while(j>=0&&temp<array[j]){
					array[j+1]=array[j];
					j--;
				}
				array[j+1]=temp;
				for(int i=0;i<n;i++){
					cout<<array[i]<<" ";
				}
				cout<<endl;
			}
		} 
		//折半插入排序（对已经排好序的可以使用）
		void BinaryInsertSort(T* array,int n){
			int start,end,mid;
			for(int i=1;i<n;i++){
				T temp=array[i];
				start=0;
				end=i-1;
				while(start<=end){
					mid=(end-start)/2+start;
					if(temp<array[mid]){
						end=mid-1;
					}else{
						start=mid+1;
					}
				}
				for(int j=i-1;j>=start;j--){
					array[j+1]=array[j];
				}
				array[start]=temp;
			}
		} 
		//希尔排序
		void ShellSort(T* array,int n){
			int d=n/2;
			while(d){
				for(int i=0;i<d;i++){
					for(int j=i+d;j<n;j+=d){
						T temp=array[j];
						int k=j-d;
						while(k>=0&&temp<array[k]){
							array[k+d]=array[k];
							k-=d;
						}
						array[k+d]=temp;
					}
				}
				d/=2;
			}
		} 
		/*交换排序*/
		//冒泡排序
		void BubbleSort(T* array,int n){
			for(int i=0;i<n-1;i++){
				for(int j=1;j<n-i;j++){
					if(array[j-1]>array[j]){
						T temp=array[j-1];
						array[j-1]=array[j];
						array[j]=temp;
					}	
				}
			}
		} 
		//冒泡排序改进版
		void BubblePlusSort(T *array,int n){
			for(int i=0;i<n-1;i++){
				int flag=0;
				for(int j=1;j<n-i;j++){
					if(array[j-1]>array[j]){
						T temp=array[j-1];
						array[j-1]=array[j];
						array[j]=temp;
						flag=1;
					}
				}
				if(flag==0){
					return;
				}
			} 
		} 
		//快速排序1
		int Partition1(T *array,int left,int right){
			T pivot=array[left];
			while(left<right){
				while(left<right&&array[right]>pivot){
					right--;
				}
				array[left]=array[right];
				while(left<right&&array[left]<pivot){
					left++;
				}
				array[right]=array[left];
			}
			array[left]=pivot;
			return left;
		}
		void QuickSort1(T *array,int left,int right){
			if(left<right){
				int position=Partition1(array,left,right);
				QuickSort1(array,left,position-1);
				QuickSort1(array,position+1,right);
			}
		}
		//快速排序2
		int Partition2(T *array,int start,int end){
			T pivot=array[start];
			int left=start,right=end;
			while(left<=right){
				while(left<=right&&array[left]<=pivot){
					left++;
				}
				while(left<=right&&array[right]>=pivot){
					right--;
				}
				if(left<right){
					swap(array[left],array[right]);
					right--;
					left++;
				}
			}
			swap(array[start],array[right]);
			return right;
		}
		void QuickSort2(T *array,int left,int right){
			if(left<right){
				int position=Partition2(array,left,right);
				QuickSort2(array,left,position-1);
				QuickSort2(array,position+1,right);
			}
		}
		/*选择排序*/
		//简单选择排序
		void SelectSort(T *array,int n){
			for(int i=0;i<n-1;i++){
				int k=i;
				for(int j=i+1;j<n;j++){
					if(array[j]<array[k]){
						k=j;
					} 
				}
				if(k!=i){
					swap(array[i],array[k]);
				}
			}
		}
		//堆排序
		void ShiftDown(T *array,int i,int n){
			int parent=i;
			int child=parent*2+1;
			while(child<n){
				if(child+1<n&&array[child]<array[child+1]){
					child++;
				}
				if(array[parent]<array[child]){
					swap(array[child],array[parent]);
					parent=child;
				}
				child=child*2+1;
			}
		}//保持最大堆性质
		void BuildHeap(T* array,int n){
			for(int i=n/2-1;i>=0;i--){
				ShiftDown(array,i,n);
			}
		}//创建最大堆
		void HeapSort(T* array,int n){
			BuildHeap(array,n);
			for(int i=n-1;i>0;i--){
				swap(array[0],array[i]);
				ShiftDown(array,0,i);
			}
		} 
		/*归并排序*/
		void merge(T* array,int left,int mid,int right){
			int lenl=mid-left+1,lenr=right-mid;
			int i,j,k;
			T* lefttemp=new T[lenl];
			T* righttemp=new T[lenr];
			for(i=0;i<lenl;i++){
				lefttemp[i]=array[i+left];
			}
			for(i=0;i<lenr;i++){
				righttemp[i]=array[i+mid+1];
			}
			i=0;j=0;k=left;
			while(i<lenl&&j<lenr){
				if(lefttemp[i]<righttemp[j]){
					array[k++]=lefttemp[i++];
				}else{
					array[k++]=righttemp[j++];
				}
			}
			while(i<lenl){
				array[k++]=lefttemp[i++];
			}
			while(j<lenr){
				array[k++]=righttemp[j++];
			}
		}
		void MergeSort(T* array,int left,int right){
			if(left<right){
				int mid=(left+right)/2;
				MergeSort(array,left,mid);
				MergeSort(array,mid+1,right);
				merge(array,left,mid,right);
			}
		}
		void SortPrint(){
			cout<<"最终结果:"<<endl;
			for(int i=0;i<num;i++){
				cout<<array[i]<<" ";
			}
			cout<<endl;
		}
};

const int RADIX=10;//定义基数用于区分不同进制
template<class T>
struct LinkNode{//定义链式结构节点 
	T data;
	LinkNode* next;
}; 
template<class T>
struct TubNode{//定义队列数组节点 
	LinkNode<T>* rear;
	LinkNode<T>* front;
};
/*
分配操作
输入：Data[]数据数组，n 元素个数, ith第i次分配操作
输出：执行分配操作之后的一个队列数组。
*/
template<class T>
TubNode<T>* Distribute(T data[],int n,int ith){
	TubNode<T>* tube=new TubNode<T>[RADIX];
	memset(tube,0,sizeof(TubNode<T>)*RADIX);
	LinkNode<T>* temp;
	for(int i=0;i<n;i++){
		T v=data[i];
		int j=ith-1;
		while(j--){
			v=v/RADIX;
		}
		v=v%RADIX;
		temp=new LinkNode<T>;
		temp->data=v;
		temp->next=NULL;
		if(tube[v].front){
			tube[v].rear->next=temp;
			tube[v].rear=temp;
		}else{
			tube[v].front=tube[v].rear=temp;
		}
	}
	return tube;
} 
/*
收集操作，将tube中数据收集到Data数组中
输入：Data数据数组，tube执行完分配操作之后的队列数组
输出：无
*/
template<class T>
void Collect(T data[],TubNode<T>* tube){
	LinkNode<T>*t,*p;
	int index=0;
	for(int i=0;i<RADIX;i++){
		p=t=tube[i].front;
		while(t){
			data[index++]=t->data;
			t=t->next;
			delete p;
			p=t;
		}
	}
	delete [] tube;
}
/*
基数排序，堆Data[]中数据进行排序，并将结果放入到Data[]中
输入：Data[]数据，n元素个数，keys关键字个数
输出：无
*/
template<class T>
void RadixSort(T data[], int n, int keys)//基数排序
{
	TubNode<T>* tube;
	for (int i = 0; i<keys; i++)			//循环执行keys次分配和收集操作
	{
		tube = Distribute<T>(data, n, i + 1);
		Collect<T>(data, tube);
	}
}

int main(){
	int n;
	cout<<"输入排序个数："<<endl;
	cin>>n;
	cout<<"输入元素："<<endl;
	int *array;
	array=new int[n];
	for(int i=0;i<n;i++){
		cin>>array[i];
	} 
	Sort<int> s(n,array);
//	cout<<"直接插入排序:"<<endl;
//	s.InsertSort(array,n);
//	s.SortPrint();
//	cout<<"折半插入排序:"<<endl;
//	s.BinaryInsertSort(array,n);
//	s.SortPrint();
//	cout<<"希尔排序:"<<endl;
//	s.ShellSort(array,n);
//	s.SortPrint();
	cout<<"冒泡排序:"<<endl;
	s.BubbleSort(array,n);
	s.SortPrint();
//	cout<<"冒泡排序改进版:"<<endl;
//	s.BubblePlusSort(array,n);
//	s.SortPrint();
//	cout<<"快速排序1:"<<endl;
//	s.QuickSort1(array,0,n-1);
//	cout<<"快速排序2:"<<endl;
//	s.QuickSort2(array,0,n-1);
//	s.SortPrint();
//	cout<<"简单选择排序:"<<endl;
//	s.SelectSort(array,n);
//	s.SortPrint();
//	cout<<"堆排序:"<<endl;
//	s.HeapSort(array,n);
//	s.SortPrint(); 
//	cout<<"归并排序:"<<endl;
//	s.MergeSort(array,0,n-1);
//	s.SortPrint();

//	int temp[8]={1,9,6,3,5,4,7,0};
//	RadixSort(temp, 8, 1);
//	for(int i=0;i<8;i++){
//		cout<<temp[i]<<" ";
//	}
} 
 
