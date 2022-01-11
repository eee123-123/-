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
//	cout<<"������Ŵ�:"<<endl;
//	cin>>s;
//	cout<<Islegal(s)<<endl;
//}

/*�κ�ϰ��1.8-h

	h.	������ʽ���������3�����ţ�Բ���š������źʹ����š�
		���һ���㷨����˳��ջ�жϱ��ʽ�е������Ƿ���ȷ��ԡ�
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
TODO:��һ���㷨����˳��ջ�жϱ��ʽc�е������Ƿ���ȷ��ԡ�
�����1. �������ʽc�����У�ƥ����� cout << c[i] << "  ƥ�����" << endl;
      2. ����֮��ջΪ�գ���ƥ����ȷ��cout << "ƥ����ȷ��" << endl;
               ����Ϊ�գ���  cout << s1.top1() << "  ƥ�����" << endl;
 */
void Bracketmatch(const char* c) //����ƥ��
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
                cout << c[i] << "  ƥ�����" << endl;
                return;
            }else{
                temp=s1.top1();
                if(temp=='('&&c[i]==')'||temp=='['&&c[i]==']'||temp=='{'&&c[i]=='}'){
                    s1.pop();
                }else{
                    cout << c[i] << "  ƥ�����" << endl;
                    return;
                }
            }
		}   
    }
    if(s1.empty()){
        cout << "ƥ����ȷ��" << endl;
    }else{
        cout << s1.top1() << "  ƥ�����" << endl;
    }
}

int main()
{

	string s;
	getline(cin, s);
	Bracketmatch(s.c_str());
	return 0;
}

