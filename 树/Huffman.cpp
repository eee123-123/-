#include<bits/stdc++.h>
using namespace std;
//首先是一个树
struct TreeNode{
	int weight;
	int parent;
	int left;
	int right;
}; 
//编码表中元素
struct TreeCode{
	char data;
	string code;
};
class Huffman{
	private:
		int N;//叶子节点数量 
		TreeCode* CodeTable;//存储编码表
		TreeNode* HTree;//哈夫曼树 
	public:
		Huffman(char ch){
			InitHuffman(ch);
		}//有参构造函数
		void InitHuffman(char ch){//统计各字符数量，同时建立哈夫曼树和编码表 
			int n=0;
			int count[127]={0};//存储各字符在输入字符串中的数量
			int temp[127]={0};//将分散在各处的count对应的字符从0依次排列，便于使用,后续作为权重 
			char save[127];//保存输入的字符串中不同的字符
			while(ch!='\n'){
				count[int(ch)]++;
				ch=cin.get(); 
			} 
			for(int i=0;i<127;i++){
				if(count[i]!=0){
					save[n]=(char)i;
					temp[n]=count[i];
					n++;
				}
			}
			N=n;
			HTree=new TreeNode[2*N-1];
			CodeTable=new TreeCode[N];
			for(int i=0;i<N;i++){
				HTree[i].weight=temp[i];
				HTree[i].right=HTree[i].left=-1;
				HTree[i].parent=-1;
				CodeTable[i].data=save[i];
			}//初始化哈夫曼树和编码表的各字符
			int s1=0,s2=0;
			for(int i=N;i<2*N-1;i++){
				SelectMin(s1,s2,HTree,i);
				HTree[s1].parent=HTree[s2].parent=i;
				HTree[i].weight=HTree[s1].weight+HTree[s2].weight;
				HTree[i].left=s1;
				HTree[i].right=s2;
				HTree[i].parent=-1;
			}
			Code(2*N-2,"");//建立编码表 
		} 
		void SelectMin(int &s1,int &s2,TreeNode* HT,int n){
			int min=10000;
			for(int i=0;i<n;i++){
				if(HT[i].parent==-1&&HT[i].weight<min){//HT[i].parent==-1是为了筛选掉非叶节点 
					min=HT[i].weight;
					s1=i;
				}
			}
			min=10000;
			for(int i=0;i<n;i++){
				if(HT[i].parent==-1&&HT[i].weight<min&&i!=s1){
					min=HT[i].weight;
					s2=i;
				}
			}
		}
		void Code(int i,string str){//根据编码表对输入的字符串编码，并将编码后的字符串输出
			if(HTree[i].left==-1){
				CodeTable[i].code=str;
				cout<<CodeTable[i].data<<"的编码为:"<<CodeTable[i].code<<endl; 
			}else{
				Code(HTree[i].left,str+'0');
				Code(HTree[i].right,str+'1');
			}
		} 
		void CreateCodeTable(){//生成编码表 
			Code(2*N-2,"");
		}
		void EnCoding(char *s,string str){//根据编码表对输入的字符串进行编码，并将编码后的字符串输出 
			while(*s!='\0'){
				for(int i=0;i<N;i++){
					if(*s==CodeTable[i].data){
						str=CodeTable[i].code;
						cout<<str;
						break;
					}
				}
				s++;
			}
		}
		void DeCoding(char* s,char* str){//利用哈夫曼树对编码后的字符串进行译码，并输出译码结果 
			while(*s!='\0'){
				int parent=2*N-2;
				while(HTree[parent].left!=-1){
					if(*s=='0'){
						parent=HTree[parent].left;
					}else{
						parent=HTree[parent].right;
					}
					s++;//不断将要译码的二进制数向前推进，直到恰好读出一个字符，结束此层循环 
				}
				*str=CodeTable[parent].data;
				cout<<*str;//输出此时的字符并通过将str地址后移为下一个字符存储做铺垫 
				str++;
			} 
		}
		double Compare(){
			double newweight=0;
			double oldweight=0;
			for(int i=0;i<N;i++){
				newweight+=HTree[i].weight*(CodeTable[i].code.length());
				oldweight+=HTree[i].weight*8;
			}
			return oldweight/newweight;
		}
		~Huffman(){
			delete []HTree;
			delete []CodeTable;
		}
}; 

int main(){
	cout<<"输入字符串:"<<endl;
	char c=cin.get();
	Huffman ht(c);
	while(true){
		cout<<"*************菜单**************"<<endl; 
		cout<<"1.编码，2.解码，3.查看压缩效率，4.退出"<<endl;
		cin>>c;
		if(c=='1'){
			char ch[100];
			cin>>ch;
			string str;
			ht.EnCoding(ch,str);
			cout<<endl;
		}else if(c=='2'){
			char ch[200];
			cin>>ch;
			char str[200];
			ht.DeCoding(ch,str);
			cout<<endl;
		}else if(c=='3'){
			cout<<ht.Compare()<<endl;
		}else{
			return 0;
		}
	}
}
