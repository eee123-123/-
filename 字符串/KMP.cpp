#include<iostream>
#include<string>
using namespace std;
void Next(string S,int* next){
	if(S.length()==0)
		return;
	int len=S.length(); 
	next[0]=0; 
	for(int i=1,k=0;i<len;i++){
		while(k>0&&S[i]!=S[k]){
			k=next[k-1];
		}
		if(S[i]==S[k]){
			k++;
		}
		next[i]=k;
	}
}

int KMP(string T,string S){
	int len1=T.length();
	int len2=S.length();
	int next[len2];
	Next(S,next);
	for(int i=0,j=0;i<len1;i++){		
		while(j>0&&T[i]!=S[j]){
			j=next[j-1];
		}
		if(T[i]==S[j]){
			j++;
		}
		if(j==len2){
			return i-j+1;
		}
	}
	return -1;
}
int main(){
	//cout<<KMP("bchabscbskac","ac")<<endl;
	string q,p;
	cin>>p;
	cin>>q;
	int plen=p.length();
	int next[plen];
	Next(p,next);
	for(int i=0;i<plen;i++){
	 	cout<<next[i]<<" ";
	}
	cout<<endl;
	cout<<KMP(q,p)<<endl;
}

