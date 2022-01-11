//#include<iostream>
//#include<String>
//#include<Stack>
//using namespace std;
//
//bool Islegal(string s){
//	stack<char>c;
//	char temp;
//	for(int i=0;i<s.length();i++){
//		if(s[i]=='('||s[i]=='['||s[i]=='{'){
//			c.push(s[i]);
//		}else{
//			if(s.empty()){
//				return false;
//			}else{
//				temp=c.top();
//				if(temp=='('&&s[i]==')'||temp=='['&&s[i]==']'||temp=='{'&&s[i]=='}'){
//					c.pop();
//				}else{
//					return false;
//				}
//			}
//		}
//	}
//	return s.empty();
//} 
//
//int main(){
//	string s;
//	cout<<"输入符号串:"<<endl;
//	cin>>s;
//	cout<<Islegal(s)<<endl;
//}

/*课后习题1.8-h

	h.	假设表达式中允许包含3中括号：圆括号、方括号和大括号。
		设计一个算法采用顺序栈判断表达式中的括号是否正确配对。
		void Bracketmatch(const char* c)

*/
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
class stack {
private:
	int maxsize;
	int top;
	char* st;

public:
	stack(int size)
	{
		maxsize = size;
		top = -1;
		st = new char[maxsize];
	}

	void push(char item)
	{
		st[++top] = item;
	}

	char top1()
	{
		return st[top];
	}

	void pop()
	{
		top--;
	}

	bool empty()
	{
		return top == -1;
	}
};
/*
TODO:计一个算法采用顺序栈判断表达式c中的括号是否正确配对。
输出：1. 遍历表达式c过程中，匹配错误 cout << c[i] << "  匹配错误" << endl;
      2. 遍历之后，栈为空，则匹配正确，cout << "匹配正确！" << endl;
               若不为空，则  cout << s1.top1() << "  匹配错误" << endl;
 */
void Bracketmatch(const char* c) //括号匹配
{
    stack s1(strlen(c));
    char temp;
    for(int i=0;i<strlen(c);i++){
        if(c[i]=='('||c[i]=='['||c[i]=='{'){
            s1.push(c[i]);
        }else if(c[i]>='0'&&c[i]<='9'||c[i]>='a'&&c[i]<='z'||c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/'||c[i]=='^'||c[i]=='!'||c[i]=='%'||c[i]=='='||c[i]==' '){
        	continue;
		}else{
            if(s1.empty()){
                cout << c[i] << "  匹配错误" << endl;
                return;
            }else{
                temp=s1.top1();
                if(temp=='('&&c[i]==')'||temp=='['&&c[i]==']'||temp=='{'&&c[i]=='}'){
                    s1.pop();
                }else{
                    cout << c[i] << "  匹配错误" << endl;
                    return;
                }
            }
		}   
    }
    if(s1.empty()){
        cout << "匹配正确！" << endl;
    }else{
        cout << s1.top1() << "  匹配错误" << endl;
    }
}

int main()
{

	string s;
	getline(cin, s);
	Bracketmatch(s.c_str());
	return 0;
}

