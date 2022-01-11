/*
�ϻ���ҵ��
��������ڽӾ���洢��ͼ�ṹ
��װDFS��BFS�㷨��Prim�㷨��Kruskal�㷨��Dijstra�㷨��Floyd�㷨
P198: 9, 10
*/
#include<bits/stdc++.h>
using namespace std; 

class AdjGraph{
	private:
		int **G;//�ڽӾ���
		int V;//������
		int E;//����
	 	int *visited;//��������
	public:
		AdjGraph(int v,int e){
			V=v;
			E=e;
			G=new int*[v+1];
			visited=new int[v+1];
			for(int i=0;i<v+1;i++){
				G[i]=new int[v+1]; 
			}
			for(int i=0;i<v+1;i++){
				for(int j=0;j<v+1;j++){
					G[i][j]=0;//��ʼ�� 
				}
			}
			for(int i=0;i<e;i++){
				int a,b;
				cout<<"�����:"<<endl;
				cin>>a>>b;
				G[a][b]=1;
				G[b][a]=1; 
			}
		} 
		//ĳ��������ȱ���DFS�ݹ� 
		void DFS1(int vertex){
			cout<<vertex<<" ";
			visited[vertex]=1;
			for(int i=1;i<=V;i++){
				if(G[vertex][i]==1&&visited[i]==0){
					DFS1(i);
				}
			} 
		}
		//ĳ��������ȱ���DFS�ǵݹ�
		void DFS2(int vertex){
			stack<int>st;
			st.push(vertex);
			visited[vertex]=1;
			int temp;
			while(!st.empty()){
				temp=st.top();
				st.pop();
				cout<<temp<<" ";
				for(int i=1;i<=V;i++){
					if(G[temp][i]==1&&visited[i]==0){
						st.push(i);
						visited[i]=1;
					}
				}
			}
		}
		//������ȱ���DFS�ݹ� 
		void DFSTraverse1(){
			for(int i=1;i<=V;i++){
				if(visited[i]==0){
					DFS1(i);
				}
			}
		} 
		//������ȱ���DFS�ǵݹ�
		void DFSTraverse2(){
			int temp;
			stack<int>st;
			for(int i=1;i<=V;i++){
				visited[i]=0;
			}
			for(int i=1;i<=V;i++){
				if(visited[i]==0){
					st.push(i);
					visited[i]=1;
					while(!st.empty()){
						temp=st.top();
						st.pop();
						cout<<temp<<" ";
						for(int i=1;i<=V;i++){
							if(G[temp][i]==1&&visited[i]==0){
								st.push(i);
								visited[i]=1;
								break;
							}
						}
					}
				}
			}
		}
		//������ȱ���BFS
		void BFS1(int vertex){
			queue<int>q;
			q.push(vertex);
			visited[vertex]=1;
			int temp;
			while(!q.empty()){
				temp=q.front();
				q.pop();
				cout<<temp<<" ";
				for(int i=1;i<=V;i++){
					if(G[temp][i]==1&&visited[i]==0){
						q.push(i);
						visited[i]=1;
					}
				}
			}
		} 
};
int main(){
	cout<<"�����������������:"<<endl; 
	int nv,ne;
	cin>>nv>>ne;
	AdjGraph graph(nv,ne);
//	cout<<"�������һ�����ʵĽ�㣺"<<endl;
//	int now;
//	cin>>now;
	 
//	cout<<"�ݹ�������ȱ�����DFS������Ϊ��"<<endl; 
//	graph.DFSTraverse2();
	//graph.DFS2(now);
	graph.BFS1(1);
	cout<<endl;
}


