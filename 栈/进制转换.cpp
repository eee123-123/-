//#include<iostream>
//#include<Stack>
//using namespace std;
//
//void BaseChange(int n,int r){
//	stack<int>nums;
//	while(n!=0){
//		nums.push(n%r);
//		n=n/r;
//	}
//	while(!nums.empty()){
//		cout<<nums.top();
//		nums.pop();
//	} 
//}
//
//int main(){
//	int n;
//	int r;
//	cout<<"����Ҫת�����������:"<<endl;
//	cin>>n>>r;
//	BaseChange(n,r);
//}


/*�κ�ϰ��1.8-g

		g.	����㷨��һ��ʮ��������ת��Ϊ�����Ž���֮�����������������
			void Binaryconv(int n, int m)
*/
#include <iostream>
using namespace std;
class stack {
private:
    int maxsize;
    int top;
    int* st;

public:
    stack(int size)
    {
        maxsize = size;
        st = new int[maxsize];
        top = -1;
    }

    void push(int num)
    {
        st[++top] = num;
    }

    void pop()
    {
        int item;
        while (top != -1) {
            item = st[top--];
            cout << item;
        }
    }
};

/*
TODO:����㷨��һ��ʮ��������ת��Ϊ�����Ž���֮�����������������
���У�nΪҪת����10���������� mΪ���ƣ�ȡֵΪ2��9��
��ʾ������ջ���
 */
void Binaryconv(int n, int m) //����ת��
{
    stack s(32);
    while(n!=0){
        s.push(n%m);
        n=n/m;
    }
    cout << "����" << n << "ת��" << m << "���ƺ�Ľ����:";
    s.pop();
}
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    Binaryconv(n, m);
    return 0;
}


//#include<iostream>
//using namespace std;
//
//int returnb(int n){
//	if(!n){
//		return 0;
//	}else{
//		returnb(n/2);
//		cout<<n%2;
//	}
//}
//
//int main(){
//	int n;
//	cin>>n;
//	returnb(n);
//}//�ݹ�ʵ��
 
