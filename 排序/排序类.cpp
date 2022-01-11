#include<bits/stdc++.h>
using namespace std;

template<class T>
class Sort{
	private:
		int num;
		T* array;
	public:
		Sort(int n,T* array){num=n;this->array=array;}
		/*��������*/
		//ֱ�Ӳ�������
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
		//�۰�������򣨶��Ѿ��ź���Ŀ���ʹ�ã�
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
		//ϣ������
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
		/*��������*/
		//ð������
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
		//ð������Ľ���
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
		//��������1
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
		//��������2
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
		/*ѡ������*/
		//��ѡ������
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
		//������
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
		}//������������
		void BuildHeap(T* array,int n){
			for(int i=n/2-1;i>=0;i--){
				ShiftDown(array,i,n);
			}
		}//��������
		void HeapSort(T* array,int n){
			BuildHeap(array,n);
			for(int i=n-1;i>0;i--){
				swap(array[0],array[i]);
				ShiftDown(array,0,i);
			}
		} 
		/*�鲢����*/
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
			cout<<"���ս��:"<<endl;
			for(int i=0;i<num;i++){
				cout<<array[i]<<" ";
			}
			cout<<endl;
		}
};

const int RADIX=10;//��������������ֲ�ͬ����
template<class T>
struct LinkNode{//������ʽ�ṹ�ڵ� 
	T data;
	LinkNode* next;
}; 
template<class T>
struct TubNode{//�����������ڵ� 
	LinkNode<T>* rear;
	LinkNode<T>* front;
};
/*
�������
���룺Data[]�������飬n Ԫ�ظ���, ith��i�η������
�����ִ�з������֮���һ���������顣
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
�ռ���������tube�������ռ���Data������
���룺Data�������飬tubeִ����������֮��Ķ�������
�������
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
�������򣬶�Data[]�����ݽ������򣬲���������뵽Data[]��
���룺Data[]���ݣ�nԪ�ظ�����keys�ؼ��ָ���
�������
*/
template<class T>
void RadixSort(T data[], int n, int keys)//��������
{
	TubNode<T>* tube;
	for (int i = 0; i<keys; i++)			//ѭ��ִ��keys�η�����ռ�����
	{
		tube = Distribute<T>(data, n, i + 1);
		Collect<T>(data, tube);
	}
}

int main(){
	int n;
	cout<<"�������������"<<endl;
	cin>>n;
	cout<<"����Ԫ�أ�"<<endl;
	int *array;
	array=new int[n];
	for(int i=0;i<n;i++){
		cin>>array[i];
	} 
	Sort<int> s(n,array);
//	cout<<"ֱ�Ӳ�������:"<<endl;
//	s.InsertSort(array,n);
//	s.SortPrint();
//	cout<<"�۰��������:"<<endl;
//	s.BinaryInsertSort(array,n);
//	s.SortPrint();
//	cout<<"ϣ������:"<<endl;
//	s.ShellSort(array,n);
//	s.SortPrint();
	cout<<"ð������:"<<endl;
	s.BubbleSort(array,n);
	s.SortPrint();
//	cout<<"ð������Ľ���:"<<endl;
//	s.BubblePlusSort(array,n);
//	s.SortPrint();
//	cout<<"��������1:"<<endl;
//	s.QuickSort1(array,0,n-1);
//	cout<<"��������2:"<<endl;
//	s.QuickSort2(array,0,n-1);
//	s.SortPrint();
//	cout<<"��ѡ������:"<<endl;
//	s.SelectSort(array,n);
//	s.SortPrint();
//	cout<<"������:"<<endl;
//	s.HeapSort(array,n);
//	s.SortPrint(); 
//	cout<<"�鲢����:"<<endl;
//	s.MergeSort(array,0,n-1);
//	s.SortPrint();

//	int temp[8]={1,9,6,3,5,4,7,0};
//	RadixSort(temp, 8, 1);
//	for(int i=0;i<8;i++){
//		cout<<temp[i]<<" ";
//	}
} 
 
