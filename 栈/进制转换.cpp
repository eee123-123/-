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
//	cout<<"输入要转换的数与进制:"<<endl;
//	cin>>n>>r;
//	BaseChange(n,r);
//}


/*课后习题1.8-g

		g.	设计算法把一个十进制整数转换为二至九进制之间的任意进制数输出。
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
TODO:设计算法把一个十进制整数转换为二至九进制之间的任意进制数输出。
其中，n为要转换的10进制整数， m为进制，取值为2到9。
提示：利用栈解决
 */
void Binaryconv(int n, int m) //进制转换
{
    stack s(32);
    while(n!=0){
        s.push(n%m);
        n=n/m;
    }
    cout << "整数" << n << "转成" << m << "进制后的结果是:";
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
//}//递归实现
 
