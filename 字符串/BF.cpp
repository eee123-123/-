#include<iostream>
#include<string>
using namespace std;

int BF(const string T,const string S){
	int i=0,j=0;
	int tlen=T.length(),slen=S.length();
	while(tlen<slen){
		return -1;
	}
	while(i<tlen&&j<slen){
		if(T[i]==S[j]){
			i++;
			j++;
		}else{	
			i=i-j+1;
			j=0;
		}
		if(j==slen){
			return i-j;
		}	
	}
	return -1;
} 

int main(){
	cout<<BF("bchabscbskac","ac")<<endl;
}//BFÆ¥Åä
