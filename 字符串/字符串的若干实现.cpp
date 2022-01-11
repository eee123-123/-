#include<iostream>
using namespace std;
#define MAXSIZE 10

//˳��
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
}//����ֵ

void StrCopy(SqString &S,SqString T){
	for(int i=0;i<T.length;i++){
		S.data[i]=T.data[i];
	}
	S.length=T.length;
}//������

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
}//�ж��Ƿ����

int StrLength(SqString S){
	int len=0;
	for(len=0;S.data[len]!='\0';len++){
		len++;
	}
	return len;
}//������

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
}//������ 

SqString SubStr(SqString S,int start,int len){//���㿪ʼ 
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
}//ȡ�Ӵ�

SqString InStr(SqString S,int start,SqString T){//start��1��ʼ 
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
}//������

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
}//��ɾ�� 

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
}//���滻

void PrintStr(SqString S){
	for(int i=0;i<S.length;i++){
		cout<<S.data[i];
	}
}//�����

