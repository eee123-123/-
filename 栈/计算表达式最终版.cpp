#include<iostream>
using namespace std;
template<class T>
struct Node
{
	T data;
	Node<T>* link;
};
template<class T>
class LinkStack
{
private:
	Node<T>* top;    //栈顶指针 
public:
	LinkStack() { top = NULL; }   //初始化一个空栈  
	~LinkStack();
	LinkStack<T>& Push(T x);        //入栈操作
	LinkStack<T>& Pop(T& x);        //出栈操作
	bool IsEmpty() { if (top == NULL) return true; else return false; }   //   判空操作，判断链栈是否为空栈
	T Top()//取栈顶元素（并不删除）
	{
		if (!IsEmpty())
			return top->data;
		else
		{
			cout << "栈内为空" << endl;
			return -1;
		}
	}
	void print()//输出栈
	{
		if (IsEmpty())
			cout << "栈内为空" << endl;
		else
		{
			Node<T>* p = top;
			while (top)
			{
				cout << top->data << " ";
				top = top->link;
			}
			cout << endl;
			top = p;
		}
	}
};

template<class T>
LinkStack<T>::~LinkStack()
{
	Node<T>* next;
	while (top)
	{
		next = top->link;
		delete top;
		top = next;
	}
}

template<class T>
LinkStack<T>& LinkStack<T>::Push(T x)
{
	Node<T>* p = new Node<T>;
	p->data = x;
	p->link = top;
	top = p;
	return *this;
}

template<class T>
LinkStack<T>& LinkStack<T>::Pop(T& x)
{
	if (IsEmpty())
	{
		cout << "栈为空" << endl;
		return *this;
	}
	Node<T>* p = top;
	x = top->data;
	top = top->link;
	delete p;
	return *this;
}
LinkStack<double> numbers; //存储操作数
LinkStack<char> operations; //存储运算符
/* 设定运算符的优先级，其中以'#'作为operations的栈底元素（便于之后操作) */
int level(char operate)
{
    switch (operate)
    {
    case '#':case '\n':
        return 0;
    case '(':case ')': 
        return 1;
    case '+':case '-': 
        return 2;
    case '*':case '/': 
        return 3;
    }
}

void counter(char);

int main()
{
    cout << "输入代数表达式以计算或输入“e”以退出" << endl << endl;
    char command = cin.get();
    while (command != 'e') {
        counter(command);
        command = cin.get();
    }
    return 0;
}

void counter(char command)
{
    double num, leftnum, rightnum, result;
    double p;
    char q;
    switch (command)
    {
        /* 如果输入是数字，则将该double类型的数据存入栈中 */
    case '0':case'1':case '2':case'3':case '4':case'5':case '6':case'7':case '8':case'9':
        cin.putback(command);
        cin >> num;
        numbers.Push(num);
        break;

    case '(':case ')':case '+':case '-':case '*':case '/':case '\n':
        /* 初始化栈底元素为'#'*/
        if (operations.IsEmpty())
            operations.Push('#');

        /* 若现在输入的运算符优先级较高或是输入‘（’，则应该存储现在的操作符，不执行之前的运算符 */
        if (level(command) > level(operations.Top()) || command == '(')
            operations.Push(command);

        /* 若之前输入的运算符优先级较高，则之前的运算符应该被执行 */
        else {
            while (level(command) <= level(operations.Top()))
            {
                /* 当运算符完全实现后，露出栈底元素‘#’，输入“\n”则打印结果 */
                if (operations.Top() == '#' && command == '\n') 
                {
                    numbers.Pop(result);//result = numbers.Top();
                    cout << "= " << result << endl << endl;
                    operations.Pop(q);
                    break;
                }

                /* 当括号内运算符完全实现后，去除括号,读入下一个字符 */
                else if (operations.Top() == '(' && command == ')') 
                {
                    operations.Pop(q);
                    cin >> command;
                }

                /* 若非上述两种情况，则完成前一个运算符 */
                else
                {
                    //rightnum = numbers.Top();
                    numbers.Pop(rightnum);
                    if (numbers.IsEmpty())
                    {
                        leftnum = 0;
                    }
                    else
                    {
                        //leftnum = numbers.Top();
                        numbers.Pop(leftnum);
                    }
                    
                    operations.Pop(q);
                    switch (q)
                    {
                    case '+':
                        numbers.Push(leftnum + rightnum);
                        break;
                    case '-':
                        numbers.Push(leftnum - rightnum);
                        break;
                    case '*':
                        numbers.Push(leftnum * rightnum);
                        break;
                    case '/':
                        if (rightnum == 0)
                        {
                            cout << "出现分母为零情况(默认结果为0)" << endl;
                            numbers.Push(0);
                        }
                        else
                        {
                            numbers.Push(leftnum / rightnum);
                        }    
                        break;
                    }
                }
            }
            /* 完成前面高优先级的运算后，当前的运算符（除了‘\n’以外）变成最高优先级，所以应存储下来 */
            if (command != '\n')
                operations.Push(command);
        }
        break;
    }
}
