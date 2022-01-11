//判断是否为运算符
bool isOptMark(char op){
	switch(op){
		case '+':case '-':case '*':case '/':case '^':
			return true;
			break;
		default:
			return false;
	}
} 

//运算符优先级
int prior(char op){
	switch(op){
		case '#':
			return -1;
			break;
		case '(':
			return 0;
			break;
		case '+':case '-':
			return 1;
			break;
		case '*':case '/':
			return 2;
			break;
		case '^':
			return 3;
			break;
		default:
			return -1;
	}
} 

//中缀表达式转后缀表达式
string convert(string infixExp,string &RSP){
	stack<char>stk;//存储操作符
	stk.push('#');//结束符
	
	int length=(int)infixExp.length();
	for(int i=0;i<length;i++){
		if(infixExp[i]>='0'&&infixExp[i]<='9'){
			RSP+=infixExp[i];
		}else if(infixExp[i]=='('){
			stk.push(infixExp[i]);
		}else if(infixExp[i]==')'){
			while(stk.top()!='('){
				RSP+=stk.top();
				stk.pop();
			}
			stk.pop();//将左括号弹出栈 
		}else if(isOptMark(infixExp[i])){
			RSP+=' ';
			while(prior(infixExp[i])<=prior(stk.top())){
				RSP+=stk.top();
				stk.pop();
			}
			stk.push(infixExp[i]);
		}
	}
	while(!stk.IsEmpty()){
		RSP+=stk.top();
		stk.pop();
	}
	return RSP;
}

//字符串转化为数字
int readNum(string exp,int &i){
	int result=0;
	while(exp[i]>='0'&&exp[i]<='9'){
		result=result*10+(exp[i]-'0');
		i++;
	}
	return result;
} 

//计算后缀表达式
int calculate(string RSP){
	int i=0;
	stack<int>optNum;//操作数栈
	int x1,x2;
	
	while(RSP[i]!='#'){
		if(RSP[i]>='0'&&RSP[i]<='9'){
			optNum.push(readNum(RSP,i));
		}else if(RSP[i]==' '){
			i++;
		}else if(RSP[i]=='+'){
			x1=optNum.top();
			optNum.pop();
			x2=optNum.top();
			optNum.pop();
			optNum.push(x2+x1);
			i++;
		}else if(RSP[i]=='-'){
			x1=optNum.top();
			optNum.pop();
			x2=optNum.top();
			optNum.pop();
			optNum.push(x2-x1);
			i++;
		}else if(RSP[i]=='*'){
			x1=optNum.top();
			optNum.pop();
			x2=optNum.top();
			optNum.pop();
			optNum.push(x2*x1);
			i++;
		}else if(RSP[i]=='/'){
			x1=optNum.top();
			optNum.pop();
			x2=optNum.top();
			optNum.pop();
			if(x1==0){
				flag==0;
				cout<<"除数不能为零"<<endl;
			}
			optNum.push(x2/x1);
			i++;
		}else if(RSP[i]=='^'){
			x1=optNum.top();
			optNum.pop();
			x2=optNum.top();
			optNum.pop();
			optNum.push(pow(x2,x1));
			i++;
		}
	} 
	return optNum.top();
} 
