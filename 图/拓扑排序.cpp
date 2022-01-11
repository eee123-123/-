#include<bits/stdc++.h>
using namespace std;

class Graph{
	private:
		int **G;
		int *Indegree;
		int V;
		int *visited;
		vector<int>Topology;
	public:
		Graph(int v,int e){
			V=v;
			Indegree=new int[v];
			for(int i=0;i<v;i++){
				Indegree[i]=0;
			}
			visited=new int[v];
			for(int i=0;i<v;i++){
				visited[i]=0;
			}
			G=new int*[v];
			for(int i=0;i<v;i++){
				G[i]=new int[v];
			}
			for(int i=0;i<e;i++){
				int start=0,end=0;
				cout<<"输入边的起始点与终点:"<<endl;
				cin>>start>>end;
				G[start][end]=1;
				Indegree[end]++;
			}
		}
		bool TopSort(){
			queue<int>q;
			for(int i=0;i<V;i++){
				if(Indegree[i]==0&&visited[i]==0){
					q.push(i);
					visited[i]=1;
				}
			}
			while(!q.empty()){
				int temp=q.front();
				q.pop();
				Topology.push_back(temp);
				for(int i=0;i<V;i++){
					if(G[temp][i]!=0){
						Indegree[i]--;
						if(Indegree[i]==0){
							q.push(i);
						}
					}
				}
			}
			if(Topology.size()!=V){
				return false;
			}else{
				return true;
			}
		}
		void TopSortPrint(){
			for(int i=0;i<V;i++){
				cout<<Topology[i]<<" ";
			}
			cout<<endl;
		}
}; 

int main(){
	cout<<"输入图的顶点数和边数:"<<endl;
	int v,e;
	cin>>v>>e;
	Graph graph(v,e);
	if(graph.TopSort()){
		cout<<"无环，其拓扑排序为："<<endl;
		graph.TopSortPrint();
	}else{
		cout<<"有环"<<endl;
	}
	return 0;
}
