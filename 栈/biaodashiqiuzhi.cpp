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
	void Clear(){top=-1;} //���ջ
	void Print();
	
private:
	int top;//ջ��
	int MaxTop;//����ջ��ֵ
	T *stack;//��ջԪ������
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
	cout<<"ջ��"<<endl;
           return *this;
            }
	top=top+1;
	stack[top]=x;
	return *this;    
}

template<class T>
Stack<T>& Stack<T>::Pop(){
	if(IsEmpty()) {
	cout<<"ջ��"<<endl;
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

//��׺���ʽת��Ϊ��׺���ʽ, RSP�����沨�����ʽ

bool isOptMark(char op){
    switch(op){
        case '+':case '-':case '*':case '/':case '(':case '^':case '%':
            return 1;
            break;
        default:
            return 0;
    }
}//�ж��Ƿ�Ϊ�����

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
}//����������ȼ�

string convert(string infixExp,string &RSP){
    
        Stack<char>stk;//�洢������ջ
    
        stk.Push('#');//����Ҫ�����ĩβʶ����ţ�����ջΪ�յĻ����ᱨ������
    
        int length=(int)infixExp.length();//��ȡ���ʽ�ĳ���
        for(int i=0;i<length;i++){
            if(infixExp[i]>='0'&&infixExp[i]<='9'){
                //�������֣�ֱ�����
                RSP+=infixExp[i];
            }else if(infixExp[i]=='('){
                //����������ֱ����ջ
                stk.Push(infixExp[i]);
            }else if(infixExp[i]==')'){
                //������������ŵĻ����Ͱ�һֱ�������������֮��Ķ�����������RPN��
                while(stk.Top()!='('){
                    RSP+=stk.Top();
                    stk.Pop();
                }
                stk.Pop();//�������ŵ���ջ
            }else if(isOptMark(infixExp[i])){
                //�ÿո�����ֺ�������ֿ��������Ϳ��Լ����λ������
                RSP+=' ';
                //�����������Ļ����Ƚ����ǵ����ȼ��پ����Ƿ���ջ
                while(prior(infixExp[i])<= prior(stk.Top())){
                    //�����ǰ�����ȼ�С�ڵ���ջ���������Ļ���ջ������������������RSP
                    RSP+=stk.Top();
                    stk.Pop();
                }
                //�����ǰ�����ȼ�����ջ���������Ļ�����ջ
                stk.Push(infixExp[i]);       
            }
        }
        //����Ѿ�ɨ�赽��׺���ʽ��ĩβ���Ͱ�ջ�еĲ����������������뵽RSP��
        while(!stk.IsEmpty()){
            RSP += stk.Top();
            stk.Pop();
        }
    
    return RSP;
}//��׺���ʽת��׺���ʽ

int readNum(string exp, int&i){
    int result=0;
    while(exp[i]>='0'&&exp[i]<='9'){
        result=result*10+(exp[i]-'0');
        i++;
    }
    return result;
}//�ַ���תΪ���� 

int calulate(string RSP){
    int i=0;
    Stack<int>optNum;//������ջ
    int x1,x2=0;
    
    while(RSP[i]!='#'){//û������������־#�������б��ʽ�ļ���
        if(RSP[i]>='0'&&RSP[i]<='9'){
            optNum.Push(readNum(RSP,i));//�ַ���ת����
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
            	cout<<"��������Ϊ�㣬����"<<endl;
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
    return optNum.Top();//�������յļ�����
}//�����׺���ʽ��������ֵ

int main(){
    string infixExp="";
    cout<<"������׺���ʽ:"<<endl;
    cin>>infixExp;
    string RSP="";
    string postFix=convert(infixExp,RSP);//��׺���ʽ
    cout<<"RSPΪ: "<<postFix<<endl;
	int result=calulate(postFix);
    if(flag==0){
		return 0;	
	}
    cout<<"Result: "<<result<<endl;
    return 0;
}


