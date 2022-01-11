#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;

int flag=1;

template <class T>
class Stack{
public:
	Stack(int MaxStackSize=10);
	~Stack() { delete [] stack;}
	bool IsEmpty() const {return top==-1;}
	bool IsFull() const {return top==MaxTop-1;}
	T Top() const;
	Stack<T>& Push(const T& x);
	Stack<T>& Pop();
	void Clear(){top=-1;} //清空栈
	void Print();
	
private:
	int top;//栈顶
	int MaxTop;//最大的栈顶值
	T *stack;//堆栈元素数组
};
 
template<class T>
Stack<T>::Stack(int MaxStackSize){
	MaxTop=MaxStackSize-1;
	stack=new T[MaxStackSize];
	top=-1;
}

template<class T>
T Stack<T>::Top()const{
	return stack[top];
}

template<class T>
Stack<T>& Stack<T>::Push(const T& x){
	if(IsFull()) {
	cout<<"栈满"<<endl;
           return *this;
            }
	top=top+1;
	stack[top]=x;
	return *this;    
}

template<class T>
Stack<T>& Stack<T>::Pop(){
	if(IsEmpty()) {
	cout<<"栈空"<<endl;
    return *this;
      }
	top=top-1;
	return *this;
}

template<class T>
void Stack<T>::Print(){
	for(int i=top;i>=0;i--)
	{
		cout<<stack[i]<<"\t";
	}
}

//中缀表达式转化为后缀表达式, RSP代表逆波兰表达式

bool isOptMark(char op){
    switch(op){
        case '+':case '-':case '*':case '/':case '(':case '^':case '%':
            return 1;
            break;
        default:
            return 0;
    }
}//判断是否为运算符

int prior(char op){
    switch (op) {
        case '#':
            return -1;
            break;
        case '(':
            return 0;
            break;
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
        case '%':
            return 2;
            break;
        case '^':
        	return 3;
        	break;
        default:
            return -1;
    }
}//求运算符优先级

string convert(string infixExp,string &RSP){
    
        Stack<char>stk;//存储操作符栈
    
        stk.Push('#');//必须要有这个末尾识别符号，否则栈为空的话，会报错！！！
    
        int length=(int)infixExp.length();//获取表达式的长度
        for(int i=0;i<length;i++){
            if(infixExp[i]>='0'&&infixExp[i]<='9'){
                //读入数字，直接输出
                RSP+=infixExp[i];
            }else if(infixExp[i]=='('){
                //遇到左括号直接入栈
                stk.Push(infixExp[i]);
            }else if(infixExp[i]==')'){
                //如果遇到右括号的话，就把一直到最近的左括号之间的都弹出来加入RPN中
                while(stk.Top()!='('){
                    RSP+=stk.Top();
                    stk.Pop();
                }
                stk.Pop();//把左括号弹出栈
            }else if(isOptMark(infixExp[i])){
                //用空格把数字和运算符分开，这样就可以计算多位数字了
                RSP+=' ';
                //如果是运算符的话，比较他们的优先级再决定是否入栈
                while(prior(infixExp[i])<= prior(stk.Top())){
                    //如果当前的优先级小于等于栈顶操作符的话，栈顶操作符弹出，加入RSP
                    RSP+=stk.Top();
                    stk.Pop();
                }
                //如果当前的优先级大于栈顶操作符的话，入栈
                stk.Push(infixExp[i]);       
            }
        }
        //如果已经扫描到中缀表达式的末尾，就把栈中的操作符都弹出来加入到RSP中
        while(!stk.IsEmpty()){
            RSP += stk.Top();
            stk.Pop();
        }
    
    return RSP;
}//中缀表达式转后缀表达式

int readNum(string exp, int&i){
    int result=0;
    while(exp[i]>='0'&&exp[i]<='9'){
        result=result*10+(exp[i]-'0');
        i++;
    }
    return result;
}//字符串转为数字 

int calulate(string RSP){
    int i=0;
    Stack<int>optNum;//操作数栈
    int x1,x2=0;
    
    while(RSP[i]!='#'){//没有遇到结束标志#，即进行表达式的计算
        if(RSP[i]>='0'&&RSP[i]<='9'){
            optNum.Push(readNum(RSP,i));//字符串转整数
        }else if(RSP[i]==' '){
            i++;
        }else if(RSP[i]=='+'){
            x1=optNum.Top();
            optNum.Pop();
            x2=optNum.Top();
            optNum.Pop();
            optNum.Push(x1+x2);
            i++;
        }else if(RSP[i]=='-'){
            x1=optNum.Top();
            optNum.Pop();
            x2=optNum.Top();
            optNum.Pop();
            optNum.Push(x2-x1);
            i++;
        }else if(RSP[i]=='*'){
            x1=optNum.Top();
            optNum.Pop();
            x2=optNum.Top();
            optNum.Pop();
            optNum.Push(x1*x2);
            i++;
        }else if(RSP[i]=='/'){
            x1=optNum.Top();
            optNum.Pop();
            x2=optNum.Top();
            optNum.Pop();
            if(x1==0){
            	flag=0;
            	cout<<"除数不能为零，错误"<<endl;
			} 
            optNum.Push(x2/x1);
            i++;
        }else if(RSP[i]=='^'){
        	x1=optNum.Top();
            optNum.Pop();
            x2=optNum.Top();
            optNum.Pop();
            optNum.Push(pow(x2,x1));
            i++;
		}else if(RSP[i]=='%'){
			x1=optNum.Top();
            optNum.Pop();
            x2=optNum.Top();
            optNum.Pop();
            optNum.Push(x2%x1);
            i++;
		}
    }
    return optNum.Top();//返回最终的计算结果
}//计算后缀表达式的最终数值

int main(){
    string infixExp="";
    cout<<"输入中缀表达式:"<<endl;
    cin>>infixExp;
    string RSP="";
    string postFix=convert(infixExp,RSP);//后缀表达式
    cout<<"RSP为: "<<postFix<<endl;
	int result=calulate(postFix);
    if(flag==0){
		return 0;	
	}
    cout<<"Result: "<<result<<endl;
    return 0;
}


