#include<iostream>
using namespace std;

class BinarySearchTree{
	private:
		int data;
		BinarySearchTree *lchild;
		BinarySearchTree *rchild;
	public:
		//插入函数 
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
		//创建二叉搜索树 
		BinarySearchTree* Create(int* data,int size){
			BinarySearchTree* bst=NULL;
			for(int i=0;i<size;i++){
				bst=bst->Insert(bst,data[i]);
			}
			return bst;
		}
		//按值查找
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
		//删除最小值
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
		
		//删除最大值
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
		
		//中序遍历
		void InorderTraversal(BinarySearchTree* BST){
			if(!BST){
				return;
			}
			BST->InorderTraversal(BST->lchild);
			cout<<BST->data<<" ";
			BST->InorderTraversal(BST->rchild);
		}
		
		//删除结点
		//合并删除
		BinarySearchTree* DeleteByMerging(BinarySearchTree *BST,int data){
			if(!BST){//树空时，直接返回NULL 
				return BST;
			}else if(data < BST->data){
				//data小于根节点时，到左子树去删除data 
				BST->lchild = this->DeleteByMerging(BST->lchild,data);
			}else if(data > BST->data){
				//data大于根节点时，到右子树去删除data 
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
	 	//复制删除 
		BinarySearchTree* DeleteByCopying(BinarySearchTree* BST,int data){
			if(!BST){//树空时，直接返回NULL 
				return BST;
			}else if(data < BST->data){
				//data小于根节点时，到左子树去删除data 
				BST->lchild = this->DeleteByCopying(BST->lchild,data);
			}else if(data > BST->data){
				//data大于根节点时，到右子树去删除data 
				BST->rchild = this->DeleteByCopying(BST->rchild,data); 
			}else{//data等于根节点时 
				if(BST->lchild && BST->rchild){
					//左右子树都不空时，用右子树的最小来代替根节点
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
				}else{//当左右子树都为空或者有一个空时 
					BinarySearchTree* tmp = BST;
					if(!BST->lchild){//左子树为空时 
						BST = BST->rchild;
					}else if(!BST->rchild){//右子树为空时 
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

