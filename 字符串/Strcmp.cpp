#include<iostream>
#include<string>
using namespace std;

int Strcmp(string s,string t){
	int slen=s.length();
	int tlen=t.length();
	int i=0,j=0;
	while(true){
		if(s[i]==t[j]&&i!=slen&&j!=tlen){
			i++;
			j++;
		}else if((s[i]!='\0'&&t[j]=='\0')||s[i]>t[j]){
			return 1;
		}else if((s[i]=='\0'&&t[j]!='\0')||s[i]<t[j]){
			return -1;
		}else{
			return 0;
		}
	}
} 

int main(){
	cout<<Strcmp("asdaf","gregqg")<<endl;
}
