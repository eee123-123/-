#include<bits/stdc++.h>
using namespace std;
//������һ����
struct TreeNode{
	int weight;
	int parent;
	int left;
	int right;
}; 
//�������Ԫ��
struct TreeCode{
	char data;
	string code;
};
class Huffman{
	private:
		int N;//Ҷ�ӽڵ����� 
		TreeCode* CodeTable;//�洢�����
		TreeNode* HTree;//�������� 
	public:
		Huffman(char ch){
			InitHuffman(ch);
		}//�вι��캯��
		void InitHuffman(char ch){//ͳ�Ƹ��ַ�������ͬʱ�������������ͱ���� 
			int n=0;
			int count[127]={0};//�洢���ַ��������ַ����е�����
			int temp[127]={0};//����ɢ�ڸ�����count��Ӧ���ַ���0�������У�����ʹ��,������ΪȨ�� 
			char save[127];//����������ַ����в�ͬ���ַ�
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
			}//��ʼ�����������ͱ����ĸ��ַ�
			int s1=0,s2=0;
			for(int i=N;i<2*N-1;i++){
				SelectMin(s1,s2,HTree,i);
				HTree[s1].parent=HTree[s2].parent=i;
				HTree[i].weight=HTree[s1].weight+HTree[s2].weight;
				HTree[i].left=s1;
				HTree[i].right=s2;
				HTree[i].parent=-1;
			}
			Code(2*N-2,"");//��������� 
		} 
		void SelectMin(int &s1,int &s2,TreeNode* HT,int n){
			int min=10000;
			for(int i=0;i<n;i++){
				if(HT[i].parent==-1&&HT[i].weight<min){//HT[i].parent==-1��Ϊ��ɸѡ����Ҷ�ڵ� 
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
		void Code(int i,string str){//���ݱ�����������ַ������룬�����������ַ������
			if(HTree[i].left==-1){
				CodeTable[i].code=str;
				cout<<CodeTable[i].data<<"�ı���Ϊ:"<<CodeTable[i].code<<endl; 
			}else{
				Code(HTree[i].left,str+'0');
				Code(HTree[i].right,str+'1');
			}
		} 
		void CreateCodeTable(){//���ɱ���� 
			Code(2*N-2,"");
		}
		void EnCoding(char *s,string str){//���ݱ�����������ַ������б��룬�����������ַ������ 
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
		void DeCoding(char* s,char* str){//���ù��������Ա������ַ����������룬����������� 
			while(*s!='\0'){
				int parent=2*N-2;
				while(HTree[parent].left!=-1){
					if(*s=='0'){
						parent=HTree[parent].left;
					}else{
						parent=HTree[parent].right;
					}
					s++;//���Ͻ�Ҫ����Ķ���������ǰ�ƽ���ֱ��ǡ�ö���һ���ַ��������˲�ѭ�� 
				}
				*str=CodeTable[parent].data;
				cout<<*str;//�����ʱ���ַ���ͨ����str��ַ����Ϊ��һ���ַ��洢���̵� 
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
	cout<<"�����ַ���:"<<endl;
	char c=cin.get();
	Huffman ht(c);
	while(true){
		cout<<"*************�˵�**************"<<endl; 
		cout<<"1.���룬2.���룬3.�鿴ѹ��Ч�ʣ�4.�˳�"<<endl;
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
