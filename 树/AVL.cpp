#include<iostream>
#include<stack>
using namespace std;

class AVL{
	private:
		int data;
		int height;
		AVL* lchild;
		AVL* rchild;
	public:
		//��Сֵ����
		AVL* FindMin(AVL* avl){
			AVL* root=avl;
			if(root==NULL){
				return NULL;
			}
			while(root){
				if(!root->lchild){
					return root;
				}else{
					root=root->lchild;
				}
			}
		} 
		//���ֵ����
		AVL* FindMax(AVL* avl){
			AVL* root=avl;
			if(root==NULL){
				return NULL;
			}
			while(root){
				if(!root->rchild){
					return root;
				}else{
					root=root->rchild;
				}
			}
		} 
		//���뺯��
		AVL* Insert(AVL* avl,int data){
			if(!avl){
				avl=new AVL;
				avl->data=data;
				avl->height=0;
				avl->lchild=avl->rchild=NULL;
			}else if(data<avl->data){
				avl->lchild=avl->Insert(avl->lchild,data);
				int rheight=this->getHeight(avl->rchild);
				int lheight=this->getHeight(avl->lchild);
				if(lheight-rheight==2){
					if(data<avl->lchild->data){
						avl=this->SingleLeftRotation(avl);
					}else{
						avl=this->DoubleLeftRightRotation(avl);
					}
				}
			}else if(data>avl->data){
				avl->rchild=avl->Insert(avl->rchild,data);
				int rheight=this->getHeight(avl->rchild);
				int lheight=this->getHeight(avl->lchild);
				if(rheight-lheight==2){
					if(data>avl->rchild->data){
						avl=this->SingleRightRotation(avl);
					}else{
						avl=this->DoubleRightLeftRotation(avl);
					}
				}
			}
			avl->height=this->getHeight(avl->lchild)>this->getHeight(avl->rchild)?this->getHeight(avl->lchild)+1:this->getHeight(avl->rchild)+1;
			return avl; 
		}
		//�������鴴������ƽ����
		AVL* CreateAVL(int *data,int size){
			AVL* avl=NULL;
			for(int i=0;i<size;i++){
				avl=this->Insert(avl,data[i]);
			} 
			return avl;
		} 
		//ɾ������
		AVL* Delete(AVL* avl,int data){
			if(!avl){
				return NULL;
			}else if(data<avl->data){
				avl->lchild=this->Delete(avl->lchild,data);
				int rheight=this->getHeight(avl->rchild);
				int lheight=this->getHeight(avl->lchild);
				if(rheight-lheight==2){
					if(data>avl->rchild->data){
						avl=this->SingleRightRotation(avl);
					}else{
						avl=this->DoubleRightLeftRotation(avl);
					}
				}
			}else if(data>avl->data){
				avl->rchild=this->Delete(avl->rchild,data);
				int rheight=this->getHeight(avl->rchild);
				int lheight=this->getHeight(avl->lchild);
				if(lheight-rheight==2){
					if(data<avl->lchild->data){
						avl=this->SingleLeftRotation(avl);
					}else{
						avl=this->DoubleLeftRightRotation(avl);
					}
				}
			}else{
				if(avl->lchild&&avl->rchild){
					AVL* temp=this->FindMin(avl->rchild);
					avl->data=temp->data;
					avl->rchild=this->Delete(avl->rchild,temp->data);
				}else{
					AVL* temp=avl;
					if(!avl->lchild){
						avl=avl->rchild;
					}else if(!avl->rchild){
						avl=avl->lchild;
					}
					delete temp;
				}
			}
			return avl; 
		} 
		//����ת
		AVL* SingleLeftRotation(AVL* avl){
			AVL* temp=avl->lchild;
			avl->lchild=temp->rchild;
			temp->rchild=avl;
			avl->height=this->getHeight(avl->lchild)>this->getHeight(avl->rchild)?this->getHeight(avl->lchild)+1:this->getHeight(avl->rchild)+1;
			temp->height=this->getHeight(temp->lchild)>this->getHeight(temp->rchild)?this->getHeight(temp->lchild)+1:this->getHeight(temp->rchild)+1;
			return temp;
		} 
		//�ҵ���ת
		AVL* SingleRightRotation(AVL* avl){
			AVL* temp=avl->rchild;
			avl->rchild=temp->lchild;
			temp->lchild=avl;
			avl->height=this->getHeight(avl->lchild)>this->getHeight(avl->rchild)?this->getHeight(avl->lchild)+1:this->getHeight(avl->rchild)+1;
			temp->height=this->getHeight(temp->lchild)>this->getHeight(temp->rchild)?this->getHeight(temp->lchild)+1:this->getHeight(temp->rchild)+1;
			return temp;
		}
		//������ת
		AVL* DoubleLeftRightRotation(AVL* avl){
			avl->lchild=this->SingleRightRotation(avl->lchild);
			return this->SingleLeftRotation(avl);
		}
		//������ת 
		AVL* DoubleRightLeftRotation(AVL* avl){
			avl->rchild=this->SingleLeftRotation(avl->rchild);
			return this->SingleRightRotation(avl);
		}
		//��ȡ���ĸ߶�
		int getHeight(AVL* avl){
			if(!avl){
				return 0;
			}
			return avl->height;
		} 
		//ǰ��������ǵݹ飩
		void PreOrder(AVL* avl){
			if(!avl){
				return;
			}
			stack<AVL*>st;
			AVL* pointer=avl;
			while(!st.empty()||pointer){
				if(pointer){
					cout<<pointer->data<<" ";
					if(pointer->rchild){
						st.push(pointer->rchild);
					} 
					pointer=pointer->lchild;
				}else{
					pointer=st.top();
					st.pop();
				}
			}
		} 
		//����������ǵݹ飩
		void InOrder(AVL* avl){
			stack<AVL*>st;
			AVL* pointer=avl;
			while(!st.empty()||pointer){
				if(pointer){
					st.push(pointer);
					pointer=pointer->lchild;
				}else{
					pointer=st.top();
					cout<<pointer->data<<" ";
					st.pop();
					pointer=pointer->rchild;
				}
			}
		} 
		//�������
		void PostOrder(AVL* avl){
			AVL* temp;
			stack<AVL*>st1;
			stack<AVL*>st2;
			st1.push(avl);
			while(!st1.empty()){
				temp=st1.top();
				st1.pop();
				st2.push(temp);
				if(temp->lchild){
					st1.push(temp->lchild);
				}
				if(temp->rchild){
					st1.push(temp->rchild);
				}
			}
			while(!st2.empty()){
				cout<<st2.top()->data<<" ";
				st2.pop();
			}
		} 
};

int main(){
	int size;
	cout<<"�������������"<<endl; 
	cin>>size;
	int* data;
	data = new int[size];
	cout<<"������ÿ������ֵ��"<<endl;
	for(int i = 0 ; i < size ; i++){
		cin>>data[i];
	}
	AVL* avl;
	avl = new AVL;
	avl = avl->CreateAVL(data,size);
	cout<<"ǰ��������ǵݹ飩��"<<endl;
	avl->PreOrder(avl);
	cout<<endl;
	
	cout<<"����������ǵݹ飩��"<<endl;
	avl->InOrder(avl);
	cout<<endl;
	
	cout<<"����������ǵݹ飩��"<<endl;
	avl->PostOrder(avl);
	cout<<endl;
//	
//	int num;
//	cout<<"������Ҫɾ���Ľ�㣺"<<endl;
//	cin>>num;
//	avl = avl->Delete(avl,num);
//	cout<<"ɾ��֮��"<<endl;
//	cout<<"ǰ��������ǵݹ飩��"<<endl;
//	avl->PreOrder(avl);
//	cout<<endl;
//	
//	cout<<"����������ǵݹ飩��"<<endl;
//	avl->InOrder(avl);
//	cout<<endl;
//	
//	cout<<"������Ҫɾ���Ľ�㣺"<<endl;
//	cin>>num;
//	avl = avl->Delete(avl,num);
//	cout<<"ɾ��֮��"<<endl;
//	cout<<"ǰ��������ǵݹ飩��"<<endl;
//	avl->PreOrder(avl);
//	cout<<endl;
//	
//	cout<<"����������ǵݹ飩��"<<endl;
//	avl->InOrder(avl);
//	cout<<endl;
//	
//	cout<<"������Ҫɾ���Ľ�㣺"<<endl;
//	cin>>num;
//	avl = avl->Delete(avl,num);
//	cout<<"ɾ��֮��"<<endl;
//	cout<<"ǰ��������ǵݹ飩��"<<endl;
//	avl->PreOrder(avl);
//	cout<<endl;
//	
//	cout<<"����������ǵݹ飩��"<<endl;
//	avl->InOrder(avl);
//	cout<<endl;
//	
//	cout<<"������Ҫɾ���Ľ�㣺"<<endl;
//	cin>>num;
//	avl = avl->Delete(avl,num);
//	cout<<"ɾ��֮��"<<endl;
//	cout<<"ǰ��������ǵݹ飩��"<<endl;
//	avl->PreOrder(avl);
//	cout<<endl;
//	
//	cout<<"����������ǵݹ飩��"<<endl;
//	avl->InOrder(avl);
//	cout<<endl;
//	
//	cout<<"����������ǵݹ飩��"<<endl;
//	avl->PostOrder(avl);
//	cout<<endl;
	
//	cout<<"������Ҫ����Ľ�㣺"<<endl;
//	cin>>num;
//	avl = avl->Insert(avl,num);
//	cout<<"����֮��"<<endl;
//	cout<<"ǰ��������ǵݹ飩��"<<endl;
//	avl->PreOrder(avl);
//	cout<<endl;
//	
//	cout<<"����������ǵݹ飩��"<<endl;
//	avl->InOrder(avl);
//	cout<<endl;
//	
//	cout<<"����������ǵݹ飩��"<<endl;
//	avl->PostOrder(avl);
//	cout<<endl;
	return 0;
}
