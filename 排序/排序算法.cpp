#include<stdio.h>
//冒泡排序
void print(int Array[],int length)
{
    for(int i=0;i<length;i++)
    {
        printf("%d ",Array[i]);
    }
}
/*int main()
{
    int array[]={49,38,65,97,76,13,27,49};
    int i,j,tem;
    int length=sizeof(array)/sizeof(int);
    printf("待排数组为:\n");
    print(array,length);
    for(i=0;i<length-1;i++)
    {
        for(j=0;j<length-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                tem=array[j];
                array[j]=array[j+1];
                array[j+1]=tem;
            }
        }
    }
    printf("\n排序后结果为:\n");
    print(array,length);
}*/
//选择排序
/*int main()
{
    int array[]={49,38,65,97,76,13,27,49};
    int i,j,tem,min;
    int length=sizeof(array)/sizeof(int);
    printf("待排数组为:\n");
    print(array,length);
    for(i=0;i<length-1;i++)
    {
        min=i;
        for(j=i+1;j<length;j++)
        {
            if(array[j]<array[min])
                min=j;
        }
        if(min!=i)
        {
            tem=array[i];
            array[i]=array[min];
            array[min]=tem;
        }
    }
    printf("\n排序后结果为:\n");
    print(array,length);
}*/
//插入排序
/*int main()
{
    int array[]={49,38,65,97,76,13,27,49};
    int i,j,tem;
    int length=sizeof(array)/sizeof(int);
    printf("待排数组为:\n");
    print(array,length);
    for(i=1;i<length;i++)
    {
        tem=array[i];
        j=i-1;
        while(j>=0&&tem<array[j])
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=tem;
    }
    printf("\n排序后结果为:\n");
    print(array,length);
}*/
//希尔排序
/*
int main()
{
    int array[]={49,38,65,97,76,13,27,49};
    int i,j,tem,n;
    int length=sizeof(array)/sizeof(int);
    printf("待排数组为:\n");
    print(array,length);
    for(n=length/2;n>0;n/=2)
    {
        for(i=n;i<length;i++)
        {
            tem=array[i];
            j=i-n;
            while(j>=0&&tem<array[j])
            {
                array[j+n]=array[j];
                j-=n;
            }
            array[j+n]=tem;
        }
    }
    printf("\n排序后结果为:\n");
    print(array,length);
}*/
//归并排序
/*void merge(int arr[],int L,int M,int R)
{
    int Left_size=M-L;
    int Right_size=R-M+1;
    int L_arr[Left_size],R_arr[Right_size];
    int i,j,k=L;
    for(i=0;i<Left_size;i++)
    {
        L_arr[i]=arr[k++];
    }
    for(j=0;j<Right_size;j++)
    {
        R_arr[j]=arr[k++];
    }
    i=0;j=0;k=L;
    while(i<Left_size&&j<Right_size)
    {
        if(L_arr[i]<R_arr[j])
        {
            arr[k++]=L_arr[i++];
        }
        else
        {
            arr[k++]=R_arr[j++];
        }
    }
    while(i<Left_size)
    {
        arr[k++]=L_arr[i++];
    }
    while(j<Right_size)
    {
        arr[k++]=R_arr[j++];
    }
}
void mergesort(int arr[],int L,int R)
{
    int M=(L+R)/2;
    if(L==R)
        return;
    else
    {
        mergesort(arr,L,M);
        mergesort(arr,M+1,R);
        merge(arr,L,M+1,R);
    }
}
int main()
{
    int array[]={49,38,65,97,76,13,27,49};
    int i,j,tem;
    int length=sizeof(array)/sizeof(int);
    printf("待排数组为:\n");
    print(array,length);
    mergesort(array,0,length-1);
    printf("\n排序后结果为:\n");
    print(array,length);
}
*/
//快速排序
/*int partition(int a[],int first,int end)
{
    int i=first,j=end,temp;
    while(i<j)
    {
        while(i<j&&a[i]<=a[j])
        {
            j--;
        }
        if(i<j)//前面已经退出循环，即有a[i]>a[j]
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
        }
        while(i<j&&a[i]<=a[j])
        {
            i++;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            j--;
        }
    }
    return i;
}
void quickSort(int a[],int first,int end)
{
    if(first<end)
    {
        int position=partition(a,first,end);
        quickSort(a,first,position-1);
        quickSort(a,position+1,end);
    }
}
int main()
{
    int array[]={49,38,65,97,76,13,27,49};
    int i,j,tem;
    int length=sizeof(array)/sizeof(int);
    printf("待排数组为:\n");
    print(array,length);
    quickSort(array,0,length-1);
    printf("\n排序后结果为:\n");
    print(array,length);
}*/
/*优化快排
#include<iostream>
using namespace std;
int a[10001];
void quick_sort(int left,int right)
{
    int i=left,j=right,temp;
    int mid=a[(left+right)/2];
    while(i<=j)
    {
        while(mid<a[j])
        {
            j--;
        }
        while(a[i]<mid)
        {
            i++;
        }
        if(i<=j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;j--;
        }
    }
    if(left<j)
    {
        quick_sort(left,j);
    }
    if(i<right)
    {
        quick_sort(i,right);
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    quick_sort(0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}

*/
//堆排序
//计数排序
//桶排序
//基数排序
