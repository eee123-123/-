#include<iostream>
using namespace std;
#define MAXSIZE 10

//顺序串
typedef struct{
	char data[MAXSIZE];
	int length;
}SqString;

void StrAssign(SqString &S,char chars[]){
	int i=0;
	for(i=0;chars[i]!='\0';i++){
		S.data[i]=chars[i];
	}
	S.length=i;
}//串赋值

void StrCopy(SqString &S,SqString T){
	for(int i=0;i<T.length;i++){
		S.data[i]=T.data[i];
	}
	S.length=T.length;
}//串复制

bool StrEqual(SqString S,SqString T){
	if(S.length!=T.length){
		return false;
	}
	for(int i=0;i<S.length;i++){
		if(S.data[i]!=T.data[i]){
			return false;
		}
	}
	return true;
}//判断是否相等

int StrLength(SqString S){
	int len=0;
	for(len=0;S.data[len]!='\0';len++){
		len++;
	}
	return len;
}//串长度

SqString StrCat(SqString S1,SqString S2){
	int len1=S1.length;
	int len2=S2.length;
	SqString temp;
	temp.length=len1+len2;
	for(int i=0;i<len1;i++){
		temp.data[i]=S1.data[i];
	}
	for(int i=0;i<len2;i++){
		temp.data[len1+i]=S2.data[i];
	}
	return temp;
}//串连接 

SqString SubStr(SqString S,int start,int len){//从零开始 
	SqString temp;	
	if(start+len>S.length){
		temp.length=0; 
		return temp; 
	}
	temp.length=len;
	for(int i=0;i<len;i++){
		temp.data[i]=S.data[start+i];
	}
	return temp;
}//取子串

SqString InStr(SqString S,int start,SqString T){//start从1开始 
	SqString str;
	str.length=0;
	if(start<=0||start>S.length+1){
		return str;
	}
	int i=0;
	for(i=0;i<start-1;i++){
		str.data[i]=S.data[i];
	}
	for(i=0;i<T.length;i++){
		str.data[start+i-1]=T.data[i];
	}
	for(i=start-1;i<S.length;i++){
		str.data[i+T.length]=S.data[i];
	}
	str.length=S.length+T.length;
	return str;
}//串插入

SqString DelStr(SqString S,int start,int len){
	SqString str;
	str.length=0;
	if(start<=0||start+len>S.length+1){
		return str;
	}
	str.length=S.length-len;
	int i=0;
	for(i=0;i<start-1;i++){
		str.data[i]=S.data[i];
	}
	for(i=start+len-1;i<S.length;i++){
		str.data[i-len]=S.data[i];
	}
	return str;
}//串删除 

SqString RepStr(SqString S,int start,int len,SqString T){
	SqString str;
	str.length=0;
	if(start<=0||start+len>S.length+1||start>S.length){
		return str;
	}
	int i=0;
	for(i=0;i<start-1;i++){
		str.data[i]=S.data[i];
	}
	for(i=0;i<T.length;i++){
		str.data[i+start-1]=T.data[i];
	}
	for(i=start;i<S.length;i++){
		str.data[i+T.length]=S.data[i];
	}
	str.length=S.length+T.length-len;
	return str;
}//串替换

void PrintStr(SqString S){
	for(int i=0;i<S.length;i++){
		cout<<S.data[i];
	}
}//输出串

