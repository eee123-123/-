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
	Node<T>* top;    //ջ��ָ�� 
public:
	LinkStack() { top = NULL; }   //��ʼ��һ����ջ  
	~LinkStack();
	LinkStack<T>& Push(T x);        //��ջ����
	LinkStack<T>& Pop(T& x);        //��ջ����
	bool IsEmpty() { if (top == NULL) return true; else return false; }   //   �пղ������ж���ջ�Ƿ�Ϊ��ջ
	T Top()//ȡջ��Ԫ�أ�����ɾ����
	{
		if (!IsEmpty())
			return top->data;
		else
		{
			cout << "ջ��Ϊ��" << endl;
			return -1;
		}
	}
	void print()//���ջ
	{
		if (IsEmpty())
			cout << "ջ��Ϊ��" << endl;
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
		cout << "ջΪ��" << endl;
		return *this;
	}
	Node<T>* p = top;
	x = top->data;
	top = top->link;
	delete p;
	return *this;
}
LinkStack<double> numbers; //�洢������
LinkStack<char> operations; //�洢�����
/* �趨����������ȼ���������'#'��Ϊoperations��ջ��Ԫ�أ�����֮�����) */
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
    cout << "����������ʽ�Լ�������롰e�����˳�" << endl << endl;
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
        /* ������������֣��򽫸�double���͵����ݴ���ջ�� */
    case '0':case'1':case '2':case'3':case '4':case'5':case '6':case'7':case '8':case'9':
        cin.putback(command);
        cin >> num;
        numbers.Push(num);
        break;

    case '(':case ')':case '+':case '-':case '*':case '/':case '\n':
        /* ��ʼ��ջ��Ԫ��Ϊ'#'*/
        if (operations.IsEmpty())
            operations.Push('#');

        /* �������������������ȼ��ϸ߻������롮��������Ӧ�ô洢���ڵĲ���������ִ��֮ǰ������� */
        if (level(command) > level(operations.Top()) || command == '(')
            operations.Push(command);

        /* ��֮ǰ�������������ȼ��ϸߣ���֮ǰ�������Ӧ�ñ�ִ�� */
        else {
            while (level(command) <= level(operations.Top()))
            {
                /* ���������ȫʵ�ֺ�¶��ջ��Ԫ�ء�#�������롰\n�����ӡ��� */
                if (operations.Top() == '#' && command == '\n') 
                {
                    numbers.Pop(result);//result = numbers.Top();
                    cout << "= " << result << endl << endl;
                    operations.Pop(q);
                    break;
                }

                /* ���������������ȫʵ�ֺ�ȥ������,������һ���ַ� */
                else if (operations.Top() == '(' && command == ')') 
                {
                    operations.Pop(q);
                    cin >> command;
                }

                /* ����������������������ǰһ������� */
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
                            cout << "���ַ�ĸΪ�����(Ĭ�Ͻ��Ϊ0)" << endl;
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
            /* ���ǰ������ȼ�������󣬵�ǰ������������ˡ�\n�����⣩���������ȼ�������Ӧ�洢���� */
            if (command != '\n')
                operations.Push(command);
        }
        break;
    }
}
