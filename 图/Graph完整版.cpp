#include<iostream>
#include<stack>
#include<queue>
#define AFFINITY 999999
using namespace std;

class UFSets{//等价类 
	private:
		int n;//等价类中元素个数
		int *root;
		int *next;
		int *length;
	public:
		UFSets(int size){
			n=size;
			root=new int[n];
			next=new int[n];
			length=new int[n];
			for(int i=0;i<n;i++){
				root[i]=next[i]=i;
				length[i]=1;
			}
		}
		int Find(int v){//查找一个给定节点的根节点 
			return root[v];
		} 
		void Union(int v,int u){
			if(root[u]==root[v]){
				return ;
			}else if(length[root[v]]<length[root[u]]){
				int rt=root[v];
				length[root[u]]+=length[root[rt]];
				root[rt]=root[u];
				for(int j=next[rt];j!=rt;j=next[j]){
					root[j]=root[u];
				}
				swap(next[rt],next[root[u]]);
			}
			else
	        {
	            int rt=root[u];                
	            length[root[v]]+=length[rt];   
	            root[rt]=root[v];              
	            for(int j=next[rt];j!=rt;j=next[j])
	                root[j]=root[v];
	            swap(next[rt],next[root[v]]); 
	        }
		}
};  

template<class EdgeType>
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

template<class T>
class MinHeap{//最小堆类 
	private:
		T *headArray;
		int MaxSize;
		int CurrentNum;
		void swap(int i,int j)
	    {
	        T temp = headArray[i];
	        headArray[i]=headArray[j];
	        headArray[j]=temp;
	    }
	public:
		int getnum(){return CurrentNum;}
		int getparent(int i){return (i-1)/2;}
		int getleftchild(int i){return 2*i+1;}
		int getrightchild(int i){return 2*i+2;}
		T removemin(){
			int temp;
			T min;
			min=headArray[0];
			deletenum(headArray[0],temp);
			return min;
		}
		MinHeap(int n){
			headArray=new T[n];
			MaxSize=n;
			CurrentNum=0;
		}
		~MinHeap(){
			delete [] headArray;
		}
		bool IsEmpty(){
			return CurrentNum==0;
		}
		void Siftup(int pos){
			while(pos>0&&headArray[pos]<headArray[getparent(pos)]){
				swap(pos,getparent(pos));
				pos=getparent(pos);
			}
		}
		void Siftdown(int pos){
			int p=getleftchild(pos);
			while(p<CurrentNum){
				if(p+1<CurrentNum&&headArray[p]>headArray[p+1]){
					p=p+1;
				}
				if(headArray[p]<headArray[pos]){
					swap(p,pos);
					pos=p;
					p=getleftchild(pos);
				}else{
					break;
				}
			}
		}
		bool Insert(T value){
			if(CurrentNum>=MaxSize){
				return false;
			}else{
				headArray[CurrentNum]=value;
				Siftup(CurrentNum);
				CurrentNum++;
				return true;
			}
		}
		bool deletenum(T value,int& index){
			if(IsEmpty())return false;
			for(int i=0;i<CurrentNum;i++){
				if(headArray[i]==value){
					if(i==CurrentNum-1){
						index=i;
						CurrentNum--;
						return true;
					}else{
						index=i;
						headArray[i]=headArray[--CurrentNum];
						Siftdown(i);
						return true;
					}
				}
			}
			return false;
		}
		void show()
	    {
	        for(int i=0;i<CurrentNum;i++)
	            cout<<headArray[i]<<" ";
	        cout<<'\n';
	    }
};

template<class EdgeType>
class Graph{
	private:
		int V;
		int E;
		int *visited;
		int **G;
		int *Indegree;
		vector<int>Topology;
	public:
		Graph(int v){//初始化图的邻接矩阵 
			V=v;
			E=0;
			visited=new int[V];
			Indegree=new int[V];
			for(int i=0;i<V;i++){
				Indegree[i]=0;
			}
			G=(int**)new int*[V];
			for(int i=0;i<V;i++){
				G[i]=new int[V];
			}
			for(int i=0;i<V;i++){//标记函数初始化 
				visited[i]=0;
			}
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					G[i][j]=0;
				}
			}
		}
		~Graph(){
			delete [] visited;
			for(int i=0;i<V;i++){
				delete [] G[i];
			}
		}
		Edge<EdgeType>FirstEdge(int v){//返回以v为顶点的第一条边 
			Edge<EdgeType>temp;
			temp.start=v;
			for(int i=0;i<V;i++){
				if(G[v][i]!=0){//寻找以v为起点的权重不为零的第一个i即为第一条边的终点 
					temp.end=i;
					temp.weight=G[v][i];
					break;
				}
			}
			return temp;
		}
		Edge<EdgeType>NextEdge(Edge<EdgeType> e){//返回与边有相同起点的下一条边 
			Edge<EdgeType>temp;
			temp.start=e.start;
			for(int i=e.end+1;i<V;i++){//从此条边终点的下一个i开始寻找权重不为零的i 
				if(G[e.start][i]!=0){
					temp.end=i;
					temp.weight=G[e.start][i];
					break;
				}
			}
			return temp;
		}
		bool IsEdge(Edge<EdgeType> e){//判断此边是否存在 
			return e.end>=0&&e.weight>0;
		}
		void setEdge(int s,int e,int weight){//加边 
			if(weight!=0){
				E++;
				G[s][e]=weight;
				Indegree[e]++;
			}
		}
		void delEdge(int s,int e){//删边 
			if(G[s][e]!=0){
				E--;
				G[s][e]=0;
			}
		}
		void Print(){//打印邻接矩阵 
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					cout<<G[i][j]<<" ";
				}
				cout<<endl;
			}
		}
		//深度优先遍历 
		void DFS(int v){//递归 
			visited[v]=1;//标记已访问 
			cout<<v<<" ";
			for(Edge<EdgeType> e=FirstEdge(v);IsEdge(e);e=NextEdge(e)){
				if(visited[e.end]==0){
					DFS(e.end);
				}
			}
		}
		void DFS(){//递归 
			for(int i=0;i<V;i++){
				visited[i]=0;
			}
			for(int i=0;i<V;i++){
				if(visited[i]==0){
					DFS(i);
				}		
			}
		} 
		void DFSNoReverse(){//非递归 
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
						for(Edge<EdgeType> e=FirstEdge(temp);IsEdge(e);e=NextEdge(e)){
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
		//广度优先遍历 
		void BFS(int v){//非递归
			queue<int>q;
			q.push(v);
			visited[v]=1;
			cout<<v<<" ";
			while(!q.empty()){
				int temp=q.front();
				q.pop();
				for(Edge<EdgeType> e=FirstEdge(temp);IsEdge(e);e=NextEdge(e)){
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
		void BFS(){//递归 
			for(int i=0;i<V;i++){
				visited[i]=0;
			}
			for(int i=0;i<V;i++){
				if(visited[i]==0){
					BFS(i); 
				}
			}
		}
		void BFSNoReverse(){//非递归 
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
						for(Edge<EdgeType> e=FirstEdge(index);IsEdge(e);e=NextEdge(e)){
							q.push(e.end);
						}
					}else{
						index=q.front();
						q.pop();
					}
				}
			}
		}
		Edge<EdgeType>* Prim(int v){
			Edge<EdgeType>*MST;//最小生成树集 
			EdgeType* nearest;
			int* neighbor;
			MST=new Edge<EdgeType>[V-1];
			nearest=new EdgeType[V];
			neighbor=new int[V];
			for(int i=0;i<V;i++){//初始化邻接数组和最小权值数组，以便比较和更新 
				neighbor[i]=v;
				nearest[i]=AFFINITY;
			}
			for(Edge<EdgeType>e=FirstEdge(v);IsEdge(e);e=NextEdge(e)){//对相邻近的最小权值集进行更新 
				nearest[e.end]=e.weight;
			}
			neighbor[v]=-1;//首结点已经进入生成树集合，将其赋值为-1 
			for(int i=1;i<V;i++){//搜索与v节点相邻近节点的边权值，并进行记录最小权值对应的下标和权值 
				EdgeType min=nearest[v];
				int temp=v;
				for(int j=0;j<V;j++){
					if(nearest[j]<min&&neighbor[j]!=-1){
						min=nearest[j];
						temp=j;
					}
				}
				if(temp>=0){
					Edge<EdgeType>edg(neighbor[temp],temp,nearest[temp]);
					MST[i-1]=edg;//将上个过程中的得到的边起点终点存进最小生成树数组 
					neighbor[temp]=-1;
					for(Edge<EdgeType>e=FirstEdge(temp);IsEdge(e);e=NextEdge(e)){
						if(neighbor[e.end]!=-1&&nearest[e.end]>e.weight){
							neighbor[e.end]=temp;
							nearest[e.end]=e.weight;
						}
					}
				}
			}
			delete [] neighbor;
			delete [] nearest;
			cout<<"\n最小生成树(Prim):"<<endl;
        	for( int t = 0 ; t < V-1 ; t ++ )//边信息输出
            MST[t].show();
        	return MST;
		} 
		Edge<EdgeType>* Kruskal(){
			UFSets sets(V);//定义V个节点的等价类
			Edge<EdgeType>* MST=new Edge<EdgeType>[V-1];
			MinHeap<Edge<EdgeType> >minH(E); //定义含有E个元素的最小堆，用于寻找权值最小的边
			Edge<EdgeType>e;
			for(int i=0;i<V;i++){//首先将各边加入最小堆中 
				for(e=FirstEdge(i);IsEdge(e);e=NextEdge(e)){
					if(e.start<e.end)//防止重复加入
					{
						minH.Insert(e);
					} 
				}
			}
			int count=0;//记录最小生成树边数 
			while(count<V-1){
				if(!minH.IsEmpty()){
					e=minH.removemin();//removemin()移除双端优先队列中优先级最低的元素，并将其返回
					if(sets.Find(e.start)!=sets.Find(e.end)){//判断该边关联的顶点是否在一个连通分量中 
						sets.Union(e.start,e.end);
						MST[count]=e;
						count++;
					}else{
						return NULL;
					}
				}
			}
			cout<<"\n最小生成树(Kruskal):"<<endl;
        	for( int t = 0 ; t < V-1 ; t ++ )//边信息输出
            MST[t].show();
        	return MST;
		}
		void Dijkstra(int s,EdgeType* D,int *Path){//s为源点,D为最短特殊路径长度，Path[i]为路径i上的前驱结点编号 
			for(int i=0;i<V;i++){//初始化 
				visited[i]=0;//未被访问过
				D[i]=AFFINITY;//路径长初始化为最大
				Path[i]=s;//所有点的前驱结点都为源点s 
			}
			D[s]=0;//s到自身最短长度为0
			for(int i=0;i<V;i++){
				EdgeType min=AFFINITY;
				int temp;
				for(int j=0;j<V;j++){//每次循环选出路径最小的节点使其标记为已访问节点 
					if(visited[j]==0&&min>D[j]){
						min=D[j];
						temp=j;
					}
				}
				visited[temp]=1;
				for(Edge<EdgeType> e=FirstEdge(temp);IsEdge(e);e=NextEdge(e)){
					if(visited[e.end]==0&&D[e.end]>D[temp]+e.weight){
						D[e.end]=D[temp]+e.weight;
						Path[e.end]=temp;
					}
				}
			} 
		}
		
		void Floyd(EdgeType **Adj,int **Path){//带权有向图，Adj[i][j]为从i到j的最短路径长度，Path[i][j]为最短路径中顶点j的前驱顶点编号
			//初始化
			for(int i=0;i<V;i++){
				for(int j=0;j<V;j++){
					if(i==j){
						Adj[i][j]=0;//到自身的最短路径长度为0 
						//Path[i][j]=0;
					}else{
						Adj[i][j]=AFFINITY;//到其他节点最短路径长度初始化为无穷大 
						//Path[i][j]=-1;
					} 
					Path[i][j]=i;
				}
			} 
			//初始化各边的权值
			for(int i=0;i<V;i++){
				for(Edge<EdgeType>e=FirstEdge(i);IsEdge(e);e=NextEdge(e)){
					Adj[i][e.end]=e.weight;
				}
			} 
			for(int k=0;k<V;k++){
				for(int i=0;i<V;i++){
					for(int j=0;j<V;j++){
						if(Adj[i][j]>(Adj[i][k]+Adj[k][j])){
							Adj[i][j]=Adj[i][k]+Adj[k][j];
							Path[i][j]=k;
							//Path[k][j]=k;
							//Path[i][j]=Path[k][j];
						}
					}
				}
			}
		}

//		bool TopSort(){
//			queue<int>q;
//			for(int i=0;i<V;i++){
//				if(Indegree[i]==0&&visited[i]==0){
//					q.push(i);
//					visited[i]=1;
//				}
//			}
//			while(!q.empty()){
//				int temp=q.front();
//				q.pop();
//				Topology.push_back(temp);
//				for(int i=0;i<V;i++){
//					if(G[temp][i]!=0){
//						Indegree[i]--;
//						if(Indegree[i]==0){
//							q.push(i);
//						}
//					}
//				}
//			}
//			if(Topology.size()!=V){
//				return false;
//			}else{
//				return true;
//			}
//		}
//		void TopSortPrint(){
//			for(int i=0;i<V;i++){
//				cout<<Topology[i]<<" ";
//			}
//			cout<<endl;
//		}
};

int main(){
	Graph<int> graph(6);
    int D[6], Path[6];
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
            graph.setEdge(i, j, 0);
    }
//    graph.setEdge(0, 1, 6);
//    graph.setEdge(0, 2, 1);
//    graph.setEdge(0, 3, 5);
//    graph.setEdge(1, 0, 6);
//    graph.setEdge(1, 2, 5);
//    graph.setEdge(1, 4, 3);
//    graph.setEdge(2, 0, 1); 
//	  graph.setEdge(2, 1, 5); 
//    graph.setEdge(2, 3, 5);
//    graph.setEdge(2, 4, 6);
//    graph.setEdge(2, 5, 4);
//    graph.setEdge(3, 0, 5);
//    graph.setEdge(3, 2, 5);
//    graph.setEdge(3, 5, 2);
//    graph.setEdge(4, 1, 3);
//    graph.setEdge(4, 2, 6);
//    graph.setEdge(4, 5, 6);
//    graph.setEdge(5, 2, 4);
//    graph.setEdge(5, 3, 2);
//    graph.setEdge(5, 4, 6);

	graph.setEdge(0,1,12); 
	graph.setEdge(0,2,10);
	graph.setEdge(0,4,30);
	graph.setEdge(0,5,100);
	graph.setEdge(1,2,5);
	graph.setEdge(2,3,50);
	graph.setEdge(3,5,10);
	graph.setEdge(4,3,20);
	graph.setEdge(4,5,60);

//	graph.setEdge(0,1,2);
//	graph.setEdge(1,0,2);
//	graph.setEdge(0,5,6);
//	graph.setEdge(5,0,6);
//	graph.setEdge(1,5,3);
//	graph.setEdge(5,1,3);
//	graph.setEdge(2,3,8);
//	graph.setEdge(3,2,8);
//	graph.setEdge(4,5,1);
//	graph.setEdge(5,4,1);
	
    graph.Print();
    cout << "\nDFS遍历:" << endl;
    graph.DFSNoReverse();
    cout << "\nBFS遍历:" << endl;
    graph.BFSNoReverse();
    graph.Prim(0);
    graph.Kruskal();
    cout<<endl;
    graph.Dijkstra(0,D,Path);
    cout<<"Dijkstra算法："<<endl;
    for(int i=5;i>=1;i--){
    	int temp=i;
    	cout<<"0到"<<i<<"的最短路径为:"<<0;
    	while(Path[temp]!=0){
    		temp=Path[temp];
    		cout<<"->"<<temp;
		}
		cout<<"->"<<i<<"\n路径长为"<<D[i]<<endl;
	}
	cout<<"\nFloyed算法:"<<endl;
	int **Adj=new int*[6],**path=new int*[6];
	for(int i=0;i<6;i++){
		Adj[i]=new int[6];
		path[i]=new int[6]; 
	}
	graph.Floyd(Adj,path);
	for(int i=0;i<6;i++){
		for(int j=0;j<6;j++){
			int temp=j;
			cout<<i<<"到"<<j<<"的最短路径为: "<<j;
			while(path[i][temp]!=i){
				cout<<" <- "<<path[i][temp];
				temp=path[i][temp];
			}
			cout<<" <- "<<i<<"\n路径长度为:"<<Adj[i][j]<<endl;
			//cout<<i<<"-->"<<j<<"的最短路径长:"<<Adj[i][j]<<endl; 
		}
	}
//	for(int i=0;i<6;i++){
//		for(int j=0;j<6;j++){
//			cout<<path[i][j]<<" "; 
//		}
//		cout<<endl;
//	}

//	cout<<"拓扑排序:"<<endl;
//	if(graph.TopSort()){
//		cout<<"无环"<<endl;
//		graph.TopSortPrint();
//	}else{
//		cout<<"有环"<<endl; 
//	}
	return 0;
}
