#include<iostream>
#include<string>
using namespace std;

int FindLast(string s,string t){
	int slen=s.length();
	int tlen=t.length();
	if(slen<tlen){
		return -1;
	}
	int i=slen-1;
	int j=tlen-1;
	while(i>=0){
		for(;i>=0;i--){
			if(t[j]==s[i]){
				if(j==0){
					return i;
				} 
				j--;
			}else{
				i=i+tlen-1-j;
				j=tlen-1;
			}
		}
	}
	return -1;
}

int main(){
	cout<<FindLast("aasgfsgs","sg")<<endl;
}

//#include<iostream>
//#include<string>
//using namespace std;
//int FindLast(string s, string t) {
//	int slen = s.length();
//	int tlen = t.length();
//	if (slen < tlen)return -1;
//	int i = slen - 1;
//	int j = tlen - 1;
//	while (i >= 0) {
//		for (; i >= 0; i--) {
//			if (s[i] == t[j]) {
//				if (j == 0)return i;
//				j--;
//			}
//			else {
//				i = i + tlen - 1 + j;
//				j = tlen - 1;
//			}
//		}
//	}return -1;
//}
//
//int main() {
//	cout << FindLast("aasgfsgs", "sg")<<endl;
//}
