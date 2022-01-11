#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Edge{//边类 
	public:
		int start,end,weight;
		Edge(){
			start=end=weight=0;
		}
		Edge(int start,int end,int weight){
			this->start=start;
			this->end=end;
			this->weight=weight;
		}
		void show(){
			cout<<"<"<<start<<","<<end<<">"<<" ";
			cout<<"权重："<<weight<<endl;
		}
		bool operator>(Edge e){
			return weight>e.weight;
		}
		bool operator<(Edge e){
			return weight<e.weight;
		}
		bool operator==(Edge e){
			return (start==e.start)&&(end==e.end)&&(weight==e.weight);
		}
};

class Graph{
	private:
		int V;//节点 
		int E;//边 
		int *visited;//是否访问标志数组 
		int **G;//图邻接矩阵 
	public:
		//构造函数 
		Graph(int v){
			V=v;
			E=0;
			visited=new int[V];
			G=new int*[V];
			for(int i=0;i<V;i++){
				visited[i]=0;
			}
			for(int i=0;i<V;i++){
				G[i]=new int[V];
			}
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					G[i][j]=0;
				}
			}
		}
		//析构函数 
		~Graph(){
			for(int i=0;i<V;i++){
				delete []G[i];
			}
			delete []G;
			delete []visited;
		}
		Edge Firstedge(int v){//顶点v的第一条边 
			Edge e;
			e.start=v;
			for(int i=0;i<V;i++){
				if(G[v][i]!=0&&visited[i]==0){
					e.end=i;
					e.weight=G[v][i];
					break;
				}
			}
			return e;
		} 
		Edge Nextedge(Edge e){//与边e有相同的起点的边 
			Edge temp;
			temp.start=e.start;
			for(int i=e.end+1;i<V;i++){
				if(G[e.start][i]!=0&&visited[i]==0){
					temp.end=i;
					temp.weight=G[e.start][i];
					break;
				}
			}
			return temp;
		}
		bool IsEdge(Edge e){//判断当前边是否存在
			return e.weight>0&&e.end>=0;
		}
		void setEdge(int st, int en, int w){//为图设置新的一条边
			if(w>0){
				E++;	
			}
			G[st][en]=w;
		} 
		void DelEdge(int st, int en){//删除边
			if(G[st][en]!=0){
				E--; 
			}
			G[st][en]=0;
		}  
		void Print(){
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					cout<<G[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		void DFS(int v){
			visited[v]=1;//标记已访问 
			cout<<v<<" ";
			for(Edge e=Firstedge(v);IsEdge(e);e=Nextedge(e)){
				if(visited[e.end]==0){
					DFS(e.end);
				}
			}
		}
		void DFS(){
			for(int i=0;i<V;i++){
				visited[i]=0;
			}
			for(int i=0;i<V;i++){
				if(visited[i]==0){
					DFS(i);
				}		
			}
		} 
		void DFSNoReverse(){
			int num=0;//访问过的顶点数
			int temp=0;//起始访问节点
			stack<int>st; 
			for(int i=0;i<V;i++){
				visited[i]=0;
			} 
			for(num=0;num<V;num++){
				if(visited[num]==0){
					st.push(num);
					visited[num]=1;
					cout<<num<<" ";
					while(!st.empty()){
						temp=st.top();
						st.pop();
						for(Edge e=Firstedge(temp);IsEdge(e);e=Nextedge(e)){
							if(visited[e.end]==0){
								st.push(e.end);
								visited[e.end]=1;
								cout<<e.end<<" ";
								break;
							}
						}
					}
				}
			}
		}
		void BFS(int v){
			queue<int>q;
			q.push(v);
			visited[v]=1;
			cout<<v<<" ";
			while(!q.empty()){
				int temp=q.front();
				q.pop();
				for(Edge e=Firstedge(temp);IsEdge(e);e=Nextedge(e)){
					if(visited[e.end]==0){
						q.push(e.end);
						visited[e.end]=1;
						cout<<e.end<<" ";
					}else{
						temp=q.front();
						q.pop();
					}
				}
			}
		}
		void BFS(){
			for(int i=0;i<V;i++){
				visited[i]=0;
			}
			for(int i=0;i<V;i++){
				if(visited[i]==0){
					BFS(i); 
				}
			}
		}
		void BFSNoReverse(){
			int num=0;
			for(int i=0;i<V;i++){
				visited[i]=0;
			}
			queue<int>q;
			int index=0;
			for(num=index;num<V;num++){
				q.push(index);
				while(!q.empty()){
					if(visited[index]==0){
						cout<<index<<" ";
						visited[index]=1;
						for(Edge e=Firstedge(index);IsEdge(e);e=Nextedge(e)){
							q.push(e.end);
						}
					}else{
						index=q.front();
						q.pop();
					}
				}
			}
		}
		Edge *Prim(Graph &G,int v){//从顶点v出发进行Prim算法得到最小生成树 
			Edge *MST=new Edge[V-1];//存储最小生成树的边
			int *neighbor=new int[V];//表示已经在生成树中的某个顶点编号
			int *nearest=new int[V];//表示生成树中点到i点最小边权值
			for(int i=0;i<V;i++){
				neighbor[i]=v;
				nearest[i]=INT_MAX;
			}//初始化
			for(Edge e=Firstedge(v);IsEdge(e);e=Nextedge(e)){
				nearest[e.end]=e.weight;//更新权值 
			}//将与v相接的顶点的权值作为其距离生成树集合的最短路径 
			nearest[v]=-1;//将已经加入到最小生成树中的最近距离设为-1，意味着其已经在生成树中
			for(int i=0;i<V;i++){
				int min=INT_MAX;
				for(int j=0;j<V;j++){
					if(nearest[j]<min&&nearest[j]!=-1){
						min=nearest[j];
						v=j;
					}
				}
				if(v>=0){//将符合条件的顶点加入到生成树集合中 
					Edge temp(neighbor[v],v,nearest[v]);
					MST[i]=temp;
					nearest[v]=-1;
					for(Edge e=Firstedge(v);IsEdge(e);e=Nextedge(e)){
						if(neighbor[e.end]!=-1&&nearest[e.end]>e.weight){
							neighbor[e.end]=v;
							nearest[e.end]=e.weight;
						}
					}
				}
			} 
			delete[] neighbor; //释放空间
			delete[] nearest;
			return MST;
		} 
};

int main(){
	Graph graph(6);
    int D[6], Path[6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            graph.setEdge(i, j, 0);
    }
    graph.setEdge(0, 1, 6);
    graph.setEdge(0, 2, 1);
    graph.setEdge(0, 3, 5);
    graph.setEdge(1, 0, 6);
    graph.setEdge(1, 4, 3);
    graph.setEdge(2, 0, 1);  
    graph.setEdge(2, 3, 5);
    graph.setEdge(2, 4, 6);
    graph.setEdge(2, 5, 4);
    graph.setEdge(3, 0, 5);
    graph.setEdge(3, 2, 5);
    graph.setEdge(3, 5, 2);
    graph.setEdge(4, 1, 3);
    graph.setEdge(4, 2, 6);
    graph.setEdge(4, 5, 6);
    graph.setEdge(5, 2, 4);
    graph.setEdge(5, 3, 2);
    graph.setEdge(5, 4, 6);
    graph.Print();
    cout << "\nDFS遍历:" << endl;
    graph.DFSNoReverse();
    cout << "\nBFS遍历:" << endl;
    graph.BFSNoReverse();
    //graph.BFS();
//    Edge *e=graph.Prim(graph,0);
//    for(int i=0;i<5;i++){
//    	e[i].show();
//	}
    return 0;
}
