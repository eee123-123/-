#include<iostream>
using namespace std;

class BinarySearchTree{
	private:
		int data;
		BinarySearchTree *lchild;
		BinarySearchTree *rchild;
	public:
		//���뺯�� 
		BinarySearchTree* Insert(BinarySearchTree* BST,int data){
			if(!BST){
				BST=new BinarySearchTree;
				BST->data=data;
				BST->lchild=BST->rchild=NULL;
			}else{
				if(data<BST->data){
					BST->lchild=BST->Insert(BST->lchild,data);
				}else if(data>BST->data){
					BST->rchild=BST->Insert(BST->rchild,data);
				}
			}
			return BST;
		}
		//�������������� 
		BinarySearchTree* Create(int* data,int size){
			BinarySearchTree* bst=NULL;
			for(int i=0;i<size;i++){
				bst=bst->Insert(bst,data[i]);
			}
			return bst;
		}
		//��ֵ����
		BinarySearchTree* Find(BinarySearchTree* BST,int data){
			BinarySearchTree* root=BST;
			if(!root){
				return NULL;
			}
			while(root){
				if(root->data==data){
					return root;
				}else if(root->data>data){
					root=root->lchild;
				}else{
					root=root->rchild;
				}
			}
			return NULL;
		}
		//ɾ����Сֵ
		BinarySearchTree* DeleteMin(BinarySearchTree* BST){
			BinarySearchTree* root=BST,*parent=BST;
			if(!root){
				return NULL;
			}
			if(!root->lchild&&!root->rchild){
				delete root;
				return NULL;
			}
			while(root->lchild){
				parent=root;
				root=root->lchild;
			}
			if(!root->lchild){
				parent->lchild=NULL;
				delete root;
			}
			return BST;
		} 
		
		//ɾ�����ֵ
		BinarySearchTree* DeleteMAX(BinarySearchTree* BST){
			BinarySearchTree* root=BST,*parent=BST;
			if(!root){
				return NULL;
			}
			if(!root->lchild&&!root->rchild){
				delete root;
				return NULL;
			}
			while(root->rchild){
				parent=root;
				root=root->rchild;
			}
			if(!root->rchild){
				parent->rchild=NULL;
				delete root;
			}
			return BST;
		} 
		
		//�������
		void InorderTraversal(BinarySearchTree* BST){
			if(!BST){
				return;
			}
			BST->InorderTraversal(BST->lchild);
			cout<<BST->data<<" ";
			BST->InorderTraversal(BST->rchild);
		}
		
		//ɾ�����
		//�ϲ�ɾ��
		BinarySearchTree* DeleteByMerging(BinarySearchTree *BST,int data){
			if(!BST){//����ʱ��ֱ�ӷ���NULL 
				return BST;
			}else if(data < BST->data){
				//dataС�ڸ��ڵ�ʱ����������ȥɾ��data 
				BST->lchild = this->DeleteByMerging(BST->lchild,data);
			}else if(data > BST->data){
				//data���ڸ��ڵ�ʱ����������ȥɾ��data 
				BST->rchild = this->DeleteByMerging(BST->rchild,data); 
			}else{
				BinarySearchTree* temp=BST;
				if(BST){
					if(!BST->lchild){
						BST=BST->rchild;
					}else if(!BST->rchild){
						BST=BST->lchild;
					}else{
						temp=BST->lchild;
						while(temp->rchild){
							temp=temp->rchild;
						}
						temp->rchild=BST->rchild;
						temp=BST;
						BST=BST->lchild;
					}
					delete temp;
				}
				return BST;
			}
			
		}
	 	//����ɾ�� 
		BinarySearchTree* DeleteByCopying(BinarySearchTree* BST,int data){
			if(!BST){//����ʱ��ֱ�ӷ���NULL 
				return BST;
			}else if(data < BST->data){
				//dataС�ڸ��ڵ�ʱ����������ȥɾ��data 
				BST->lchild = this->DeleteByCopying(BST->lchild,data);
			}else if(data > BST->data){
				//data���ڸ��ڵ�ʱ����������ȥɾ��data 
				BST->rchild = this->DeleteByCopying(BST->rchild,data); 
			}else{//data���ڸ��ڵ�ʱ 
				if(BST->lchild && BST->rchild){
					//��������������ʱ��������������С��������ڵ�
					BinarySearchTree* tmp = BST->rchild,*pre=BST;
					while(tmp->lchild){
						pre=tmp;
						tmp=tmp->lchild;
					}
					BST->data=tmp->data;
					if(pre==BST){
						pre->rchild=tmp->rchild;
					}else{
						pre->lchild=tmp->rchild;
					}
					delete tmp;
				}else{//������������Ϊ�ջ�����һ����ʱ 
					BinarySearchTree* tmp = BST;
					if(!BST->lchild){//������Ϊ��ʱ 
						BST = BST->rchild;
					}else if(!BST->rchild){//������Ϊ��ʱ 
						BST = BST->lchild; 
					}
					delete tmp; 
				}
			}
			return BST;
		} 
		
};

int main(){
	int size;
	cin>>size;
	int *data=new int[size];
	for(int i=0;i<size;i++){
		cin>>data[i];
	}
	BinarySearchTree* BST=new BinarySearchTree;
	BST=BST->Create(data,size);
//	BST=BST->DeleteMAX(BST); 
	BST=BST->DeleteByMerging(BST,6);
	BST=BST->DeleteByCopying(BST,6);
	BST->InorderTraversal(BST);
}

