#include<bits/stdc++.h>
using namespace std;

class BinarySearchTree{
	private:
		int data;
		BinarySearchTree* lchild;
		BinarySearchTree* rchild;
	public:
		//插入
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
		//创建
		BinarySearchTree* Create(int *data,int size){
			BinarySearchTree* BST=NULL; 
			for(int i=0;i<size;i++){
				BST=BST->Insert(BST,data[i]);
			}
			return BST;
		} 
		//查找
		BinarySearchTree* Find(BinarySearchTree* BST,int data){
			if(!BST){
				return BST;
			}
			BinarySearchTree* pointer=BST;
			while(pointer){
				if(data==pointer->data){
					return pointer;
				}else if(data<pointer->data){
					pointer=pointer->lchild;
				}else{
					pointer=pointer->rchild;
				}
			}
			return NULL;
		} 
		//删除最小值
		BinarySearchTree* DeleteMin(BinarySearchTree* BST){
			if(!BST){
				return NULL;
			}
			BinarySearchTree* root=BST;
			BinarySearchTree* temp=BST;
			if(!root->lchild&&!root->rchild){
				delete root;
				return NULL;
			}
			while(root->lchild){
				temp=root;
				root=root->lchild;
			}
			if(!root->lchild){
				temp->lchild=root->rchild;
				delete root;
			}
			return BST;
		} 
		//删除最大值
		BinarySearchTree* DeleteMax(BinarySearchTree* BST){
			if(!BST){
				return NULL;
			}
			BinarySearchTree* root=BST;
			BinarySearchTree* temp=BST;
			if(!root->lchild&&!root->rchild){
				delete root;
				return NULL;
			}
			while(root->rchild){
				temp=root;
				root=root->rchild;
			}
			if(!root->rchild){
				temp->rchild=root->lchild;
				delete root;
			}
			return BST;
		} 
		//中序遍历
		void InorderTraversal(BinarySearchTree* BST){
			if(!BST){
				return;
			}
			BST->InorderTraversal(BST->lchild);
			cout<<BST->data<<" ";
			BST->InorderTraversal(BST->rchild);
		}
		//合并删除
		BinarySearchTree* DeleteByMerging(BinarySearchTree *BST,int data){
			if(!BST){
				return BST;
			}
			if(data<BST->data){
				BST=BST->DeleteByMerging(BST->lchild,data);
			}else if(data>BST->data){
				BST=BST->DeleteByMerging(BST->rchild,data);
			}else{
				if(BST){
					BinarySearchTree* temp=BST->lchild;
					if(!BST->lchild){
						BST=BST->rchild;
					}else if(!BST->rchild){
						BST=BST->lchild;
					}else{
						while(temp->rchild){
							temp=temp->rchild;
						}
						temp->rchild=BST->rchild;
						temp=BST;
						BST=BST->lchild;
					}
					delete temp;
				}
			}
			return BST;
		}
		//复制删除
		BinarySearchTree* DeleteByCopying(BinarySearchTree* BST,int data){
			if(!BST){
				return BST;
			}
			if(data<BST->data){
				BST->lchild=BST->DeleteByCopying(BST->lchild,data);
			}else if(data>BST->data){
				BST->rchild=BST->DeleteByCopying(BST->rchild,data);
			}else{
				if(BST->lchild&&BST->rchild){
					BinarySearchTree* temp=BST->rchild;
					BinarySearchTree* q=BST;
					while(temp->lchild){
						q=temp;
						temp=temp->lchild;
					}
					BST->data=temp->data;
					if(q==BST){
						q->rchild=temp->rchild;
					}else{
						q->lchild=temp->rchild;
					}
					delete temp;
				}else{
					BinarySearchTree* temp=BST;
					if(!BST->lchild){
						BST=BST->rchild;
					}else if(!BST->rchild){
						BST=BST->lchild;
					}
					delete temp;
				}
			}
			return BST;
		}		 
};

int main(){
	
}
