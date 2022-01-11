/*
上机作业：
定义采用邻接矩阵存储的图结构
封装DFS、BFS算法、Prim算法、Kruskal算法、Dijstra算法、Floyd算法
P198: 9, 10
*/
#include<bits/stdc++.h>
using namespace std; 

class AdjGraph{
	private:
		int **G;//邻接矩阵
		int V;//顶点数
		int E;//边数
	 	int *visited;//访问数组
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
					G[i][j]=0;//初始化 
				}
			}
			for(int i=0;i<e;i++){
				int a,b;
				cout<<"输入边:"<<endl;
				cin>>a>>b;
				G[a][b]=1;
				G[b][a]=1; 
			}
		} 
		//某点深度优先遍历DFS递归 
		void DFS1(int vertex){
			cout<<vertex<<" ";
			visited[vertex]=1;
			for(int i=1;i<=V;i++){
				if(G[vertex][i]==1&&visited[i]==0){
					DFS1(i);
				}
			} 
		}
		//某点深度优先遍历DFS非递归
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
		//深度优先遍历DFS递归 
		void DFSTraverse1(){
			for(int i=1;i<=V;i++){
				if(visited[i]==0){
					DFS1(i);
				}
			}
		} 
		//深度优先遍历DFS非递归
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
		//广度优先遍历BFS
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
	cout<<"请输入结点总数与边数:"<<endl; 
	int nv,ne;
	cin>>nv>>ne;
	AdjGraph graph(nv,ne);
//	cout<<"请输入第一个访问的结点："<<endl;
//	int now;
//	cin>>now;
	 
//	cout<<"递归深度优先遍历（DFS）序列为："<<endl; 
//	graph.DFSTraverse2();
	//graph.DFS2(now);
	graph.BFS1(1);
	cout<<endl;
}


