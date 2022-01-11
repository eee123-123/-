#include<bits/stdc++.h>
using namespace std;

#define N 4  //带权值的叶子节点数
#define M 2*N-1  //n个叶子节点构造的哈夫曼树有2n-1个结点

typedef struct{
	unsigned int weight;
	int lchild;
	int rchild;
	int parent;
}HTNode;

typedef HTNode HuffmanTree[M+1];//0不使用

typedef char* HuffmanCode[N+1];//存储每个字符的哈夫曼编码表，是一个字符指针数组，每个数组元素是指向字符指针的指针

void select(HuffmanTree HT,int n,int &s1,int &s2){
	int temp=100000;
	for(int i=1;i<=n;i++){
		if(HT[i].parent==0&&HT[i].weight<temp){
			temp=HT[i].weight;
			s1=i;
		}
	}
	temp=100000;
	for(int i=1;i<=n;i++){
		if(HT[i].parent==0&&HT[i].weight<temp&&i!=s1){
			temp=HT[i].weight;
			s2=i;
		}
	}
}

void CreateHuffmanTree(HuffmanTree &HT,int w[],int n){
	if(n<=1){
		return;
	}
	//初始化
	for(int i=1;i<=M;i++){
		HT[i].weight=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
		HT[i].parent=0;
	} 
	//对于前n个数权重赋值
	for(int i=1;i<=n;i++){
		HT[i].weight=w[i];
	} 
	//对n+1后续节点进行合并赋权值
	for(int i=n+1;i<=M;i++){
		int s1,s2;
		select(HT,i-1,s1,s2);
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		HT[i].lchild=s1;
		HT[i].rchild=s2;
		HT[s1].parent=i;
		HT[s2].parent=i;
	} 
}

void PrintHT(HuffmanTree HT,char ch[]){
	cout<<"value"<<"  "<<"parent"<<"  "<<"lchild"
				<<"  "<<"rchild"<<"  "<<"weight"<<endl;	
	for(int i=1;i<=M;i++){
		if(i<=N){
			cout<<ch[i]<<"        "<<HT[i].parent<<"        "<<HT[i].lchild
				<<"       "<<HT[i].rchild<<"       "<<HT[i].weight<<endl;		
		}else{
			cout<<"-"<<"        "<<HT[i].parent<<"        "<<HT[i].lchild
				<<"       "<<HT[i].rchild<<"       "<<HT[i].weight<<endl;		
		}
	}
}

void EncodingHuffmanCode(HuffmanTree HT,HuffmanCode &HC){
	char temp[N];
	temp[N-1]='\0';//编码结束符 
	for(int i=1;i<=N;i++){
		int p=HT[i].parent;
		int ch=i;
		int start=N-1;
		
		while(p){//当parent不为0即根节点时 
			if(HT[p].lchild==ch){
				temp[--start]='0';
			}else{
				temp[--start]='1';
			}
			
			ch=p;
			p=HT[p].parent;
		}
		HC[i]=(char*)malloc((N-start)*sizeof(char));
		strcpy(HC[i],&temp[start]);
	}
} 

void HuffmanCodePrint(HuffmanCode HC,char *c){
	for(int i=1;i<=N;i++){
		cout<<c[i]<<":"<<HC[i]<<endl;
	}
}

string DecodingHuffmanCode(HuffmanTree HT,char *c,string test,int len,string res){
	int p=M;
	int i=0;
	while(i<len){
		if(test[i]=='0'){
			p=HT[p].lchild;
		}
		if(test[i]=='1'){
			p=HT[p].rchild;
		}
		if(p<=N){
			res+=c[p];
			p=M;
		}
		i++;
	}
	return res;
}

int main(){
	HuffmanTree HT;
	int w[N+1];
	char ch[N+1];
	cout<<"输入元素及对应的权重:(格式为a 10)"<<endl;
	for(int i=1;i<=N;i++){
		cin>>ch[i]>>w[i];
	}
	CreateHuffmanTree(HT,w,N);
	PrintHT(HT,ch);
	
	HuffmanCode HC;
	EncodingHuffmanCode(HT,HC);
	cout<<"哈夫曼编码为:"<<endl;
	HuffmanCodePrint(HC,ch);
	string test,res;
	cout<<"输入需要解码的字符串:"<<endl;
	cin>>test;
	res=DecodingHuffmanCode(HT,ch,test,test.size(),res);
	cout<<"解码为:"<<res<<endl;
	
	return 0; 
}
