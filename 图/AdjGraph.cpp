/*图的邻接矩阵表示类定义、等价类定义*/
#include<iostream>
#include<stack>
#include<queue>
#define AFFINITY 999999
using namespace std;
class UFSets      //等价类
{
private:
    int n;       //等价类中元素个数
    int* root;   //root[i]表示元素i所在的等价类的代表元素编号
    int* next;   //next[i]表示在等价类中，i的后面元素编号
    int* length; //length[i]表示i所代表的等价类的元素个数
public:
    UFSets(int size)
    {//初始size个元素的等价类
        n=size;
        root=new int[n];
        next=new int[n];
        length=new int[n];
        for(int i=0;i<n;i++)
        {
            root[i]=next[i]=i;
            length[i]=1;
        }
    }
    int Find(int v)
    {
        return root[v];
    }
    void Union(int v,int u)
    {//合并u和v所在的等价类，将元素多的合并到元素少的等价类中
        if(root[u]==root[v])
            return;
        else if(length[root[v]]<length[root[u]])
        {//将v所在等价类元素合并到u所在等价类，并将u所在等价类的代表元素作为合并后的等价类的代表元
            int rt=root[v];                //获取v所在等价类的代表元素
            length[root[u]]+=length[rt];   //修改u所在等价类的元素个数
            root[rt]=root[u];              //修改v所在等价类的各个元素的代表元素信息
            for(int j=next[rt];j!=rt;j=next[j])
                root[j]=root[u];
            swap(next[rt],next[root[u]]);  //连接两个等价类的元素
        }
        else
        {//将u所在等价类元素合并到v所在等价类，并将v所在等价类的代表元素作为合并后的等价类的代表元
            int rt=root[u];                //获取u所在等价类的代表元素
            length[root[v]]+=length[rt];   //修改v所在等价类的元素个数
            root[rt]=root[v];              //修改u所在等价类的各个元素的代表元素信息
            for(int j=next[rt];j!=rt;j=next[j])
                root[j]=root[v];
            swap(next[rt],next[root[v]]);  //连接两个等价类的元素
        }
    }
};
template<class EdgeType>
class Edge    //边类型
{
public:
    int start,end,weight;    //start为边的始点，end为边的终点，weight为边的权重
    Edge()      //构造边
    {
        start=end=weight=0;
    }
    Edge(int st,int en,int w)     //构造边(st,en)，权重为w
    {
        start=st;
        end=en;
        weight=w;
    }
    void show()//边的输出
    {
        cout<<'<'<<start<<','<<end<<'>'<<endl;
        cout<<"权重:"<<weight<<endl;
    }
    bool operator >(Edge oneEdge)     //重载运算符>，通过权重比较边的大小
    {
        if(this->weight>oneEdge.weight)
            return true;
        else
            return false;
    }
    bool operator <(Edge oneEdge)     //重载运算符<，通过权重比较边的大小
    {
        if(this->weight<oneEdge.weight)
            return true;
        else
            return false;
    }
    bool operator == ( Edge<EdgeType> oneEdge )
    {
        if( start == oneEdge.start && end == oneEdge.end )
            return true;
        else
            return false;
    }
};
template <class T>
class MinHeap//最小堆类
{
    T* headArray;//堆存储数组
    int MaxSize;//堆的最大容量
    int CurrentNum;//当前堆中元素个数
    void Swap( int i , int j )//交换堆中下标为i和j的元素
    {
        T temp = headArray[i];
        headArray[i] = headArray[j];
        headArray[j] = temp;
    }

public:

    int get_num()//返回堆中元素个数
    { return CurrentNum; }

    int get_father( int i )//返回父节点的下标
    { return ( i - 1 ) / 2; }

    int get_leftChild( int i )//返回左孩子下标
    { return 2*i + 1 ; }

    int get_rightChild( int i )//返回右孩子下标
    { return 2*i + 2 ; }

    T remove_min()//删除最小元素，并返回最小值
    {
        int index ;
        T fro;
        fro = headArray[0];
        delete_value( headArray[0] , index );
        return fro;
    }

    MinHeap( const int n )//构造大小为n的堆
    {
        headArray = new T[n];//开辟空间
        MaxSize = n;
        CurrentNum = 0;//初始堆中元素个数为0
    }

    ~MinHeap(){ delete [] headArray ; }//析构函数

    bool Is_empty()//判断堆是否为空
    {
        if( CurrentNum )
            return false;
        else
            return true;
    }

    void Siftup( int pos )//自下向上调整,将完全二叉树化为堆,pos指开始调整的元素下标
    {
        while( pos > 0 && headArray[pos] < headArray[get_father( pos )] )
        {
            Swap( pos , get_father( pos ) );
            pos = get_father( pos );
        }
    }

    void Siftdown( int pos )//自上向下调整,pos指开始调整的元素下标
    {
        int l = get_leftChild( pos );//左孩子下标
        while( l < CurrentNum )
        {
            if( l + 1 < CurrentNum && headArray[l] > headArray[l + 1] )
                l++;
            if( headArray[pos] > headArray[l] )
            {
                Swap( pos , l );//将目标点与左右孩子中大的一个交换
                pos = l;
                l = get_leftChild( pos );//左孩子下标
            }
            else
                break;
        }
    }

    bool Insert( const T value )//向堆中插入元素
    {
        if( CurrentNum == MaxSize )
            return false;
        else
        {
            headArray[CurrentNum] = value;//将值传入
            Siftup( CurrentNum );//向上调整
            CurrentNum ++;//尾部指针向后移
            return true;
        }
    }

    bool delete_value( T value , int& index )//删除指定元素
    {
        int flag = 0;
        if( Is_empty() )
            return false;
        else
        {
            for( int i = 0 ; i < CurrentNum ; i++ )//寻找该值
            {
                if( headArray[i] == value )//找到值
                {
                    if( i == CurrentNum - 1 )//删除值在尾部
                    {
                        index = i;
                        --CurrentNum;
                        flag = 1;
                    }
                    else
                    {
                        index = i;
                        headArray[i] = headArray[--CurrentNum];//删除位置赋给尾部值
                        Siftdown( i );//向下调整
                        flag = 1;
                    }
                }
            }
            if( flag )
                return true;
            else
                return false;
        }
    }

    void show()//堆的输出
    {
        for( int i = 0 ; i < CurrentNum ; i++ )
            headArray[i].show();
        cout<<'\n';
    }
};
template<class EdgeType>
class AdjGraph         //图的邻接矩阵类定义
{
private:
    int vertexNum;     //图的顶点数
    int edgeNum;       //图的边数
    int *Mark;         //标记某顶点是否已被访问
    int **matrix;      //图的邻接矩阵指针
public:
    AdjGraph(int v)
    {//构造函数
        vertexNum=v;
        edgeNum=0;
        Mark=new int[vertexNum];
        for(int i=0;i<vertexNum;i++)       //初始化Mark数组
            Mark[i]=0;
        matrix=(int**) new int*[vertexNum];
        for(int i=0;i<vertexNum;i++)
            matrix[i]=new int[vertexNum];
        for(int i=0;i<vertexNum;i++)
            for(int j=0;j<vertexNum;j++)    //初始化matrix数组
                matrix[i][j]=0;
    }
    ~AdjGraph()
    {//析构函数
        for(int i=0;i<vertexNum;i++)
            delete [] matrix[i];
        delete [] matrix;
    }
    Edge<EdgeType> FirstEdge(int oneVertex)
    {//返回顶点oneVertex的第一条边
        Edge<EdgeType> temEdge;
        temEdge.start=oneVertex;
        for(int i=0;i<vertexNum;i++)
        {
            if(matrix[oneVertex][i]!=0)
            {
                temEdge.end=i;
                temEdge.weight=matrix[oneVertex][i];
                break;
            }
        }
        return temEdge;
    }
    Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)
    {//返回与边oneEdge有相同始点的下一条边
        Edge<EdgeType> temEdge;
        temEdge.start=oneEdge.start;
        for(int i=oneEdge.end+1;i<vertexNum;i++)
        {
            if(matrix[oneEdge.start][i]!=0)
            {
                temEdge.end=i;
                temEdge.weight=matrix[oneEdge.start][i];
                break;
            }
        }
        return temEdge;
    }
    bool IsEdge(Edge<EdgeType> oneEdge)    //判断当前边是否存在
    {
        if(oneEdge.weight>0&&oneEdge.end>=0)
            return true;
        else
            return false;
    }
    void setEdge(int st,int en,int w)     //为图设置新的一条边
    {
        if(w!=0)
            edgeNum++;
        matrix[st][en]=w;
    }
    void delEdge(int st,int en)       //删除边
    {
        if(matrix[st][en]!=0)
            edgeNum--;
        matrix[st][en]=0;
    }
    void DFSNoReverse()      //非递归实现深度优先遍历
	{
	    int num_visit = 0;//访问过的顶点数
	    int index = 0;//顶点访问'指针'，默认从v0开始访问
	    using std::stack;
	    stack<int> vertexstack;//存未访问过的顶点的栈
	    for(int i=0;i<vertexNum;i++)       //初始化Mark数组
            Mark[i]=0;
	    for( num_visit = 0 ; num_visit < vertexNum ; num_visit ++ )//若访问过的顶点数目小于总顶点数目则继续访问,考虑有的顶点无边
        {
            if( Mark[num_visit] == 0 )//该点未访问过
            {
                vertexstack.push( num_visit );//该顶点入栈
                visit( num_visit );//访问该顶点
                Mark[num_visit] = 1;//标记访问过
                while( !vertexstack.empty() )//如果栈不空执行循环
                {
                    index = vertexstack.top();//弹栈并读取栈顶元素
                    vertexstack.pop();
                    for( Edge<EdgeType> e = FirstEdge( index ) ; IsEdge( e ) ; e = NextEdge( e ) )//与该顶点相邻结点均入栈
                    {
                        if( Mark[e.end] == 0 )//如果该边尾顶点未访问过
                        {
                            vertexstack.push( e.end );//顶点入栈
                            visit( e.end );//访问该顶点
                            Mark[e.end] = 1;//标记改为访问过
                            break;//跳出循环
                        }
                    }
                }
            }
        }
        cout<<endl;
	}
	void BFS(int v)         //非递归实现广度优先遍历
    {
        int num_visit = 0;//访问过的顶点数
        for(int i=0;i<vertexNum;i++)       //初始化Mark数组
            Mark[i]=0;
        using std::queue;
	    queue<int> vertexqueue;//存未访问过的顶点的栈
	    int index = v;//从用户指定顶点处访问
	    for( num_visit = v ; num_visit < v + vertexNum ; num_visit ++)//若访问过的顶点数目小于总顶点数目则继续访问,考虑有的顶点无边
        {
            if( num_visit > vertexNum )
                index = num_visit % vertexNum;
            vertexqueue.push( index );//该顶点入队列
            while( !vertexqueue.empty() )//当队列不空时执行循环体
            {
                if( Mark[index] )//如果该节点访问过
                {
                    index = vertexqueue.front();//读取队列元素
                    vertexqueue.pop();//出队列
                }
                else//若该顶点未访问过
                {
                    visit( index );//访问该顶点
                    Mark[index] = 1;//标记
                    for( Edge<EdgeType> e = FirstEdge( index ) ; IsEdge( e ) ; e = NextEdge( e ) )//该顶点所有相邻顶点入队列
                        vertexqueue.push( e.end );
                }
            }
        }
        cout<<endl;
    }

    Edge<EdgeType>* Prim( int s )
    {	//应用Prim算法从s顶点出发得到的最小生成树
        int i, j;
        Edge<EdgeType> *MST; 	//存储最小生成树的边
        //各个顶点到生成树中的各个顶点的最短的边
        EdgeType *nearest;  	//nearest[i]表示生成树中点到i点的最小边权值
        int *neighbor;      		//neighbor[i]表示生成树中与i点最近的点编号，
        //-1表示i点已经在生成树集合中

        nearest = new EdgeType[vertexNum];
        neighbor = new int[vertexNum];
        MST = new Edge<EdgeType>[vertexNum - 1];
        for (i = 0; i<vertexNum; i++)    		//初始化neighor数组和nearest数组
        {
            neighbor[i] = s;
            nearest[i] = FirstEdge( s ).weight;
        }
        //与s相邻接的顶点的边权值 作为这些点 距离生成树集合的最短边长
        for (Edge<EdgeType> e = FirstEdge(s); IsEdge(e); e = NextEdge(e))
        {
            nearest[e.end] = e.weight;
        }

        neighbor[s] = -1;//将已加入到生成树的点的最近邻设置为-1
        for (i = 1; i < vertexNum; i++)
        { //i标记已经加入到生成树中的点个数
            EdgeType min = FirstEdge( s ).weight;//记录最小权值
            int v = s;//记录下一个将要加入到集合中的点
            for (j = 0; j<vertexNum; j++)
            {//确定一个顶点在生成树集合，一个顶点不在生成树集合且权值最小的
                //边所关联的顶点
                if (nearest[j]<min && neighbor[j]>-1)
                {
                    min = nearest[j];
                    v = j;
                }
            }//for(j)
            if (v >= 0)
            {//将v加入到生成树集合中,更新到生成树外的各个点最小权值的边信息
                Edge<EdgeType> tempEdge(neighbor[v], v, nearest[v]);
                MST[i-1] = tempEdge;//将边加入到生成树集合中
                neighbor[v] = -1;
                for (Edge<EdgeType> e = FirstEdge(v); IsEdge(e); e = NextEdge(e))
                {
                    int u = e.end;
                    if (neighbor[u] != -1 && nearest[u]>e.weight)
                    {//用与v关联的边更新生成树之外顶点到生成树集合的最小权值边
                        neighbor[u] = v;
                        nearest[u] = e.weight;
                    }
                }//for(e)
            }//if(v>=0)
        }//for(i)
        delete[] neighbor; //释放空间
        delete[] nearest;
        cout<<"\n最小生成树(Prim):"<<endl;
        for( int t = 0 ; t < vertexNum - 1 ; t ++ )//边信息输出
            MST[t].show();
        return MST;
    }

    /*void Prim(int s)     //最小生成树的Prim算法
    {
        int* nearest = new int[vertexNum];//在最小生成树集合中的最小代价情况数组，nearest[i] 表示Vi 到最小生成树中权值，若不在最小生成树集合中则值为-1
        for( int i = 0 ; i < vertexNum ; i++ )//数组初始化
            nearest[i] = -1;
        int* leastTreeset = new int[vertexNum];//最小生成树集合中包含的顶点，在集合中值为-1，反之为其本身
        leastTreeset[s] = -1;//初始化集合中含vs
        for( int i = 0 ; i < vertexNum ; i++)//初始化数组
        {
            if( i == s )
                continue;
            leastTreeset[i] = i;
        }
        int num = vertexNum - 1;//记录V-V1集合中还有多少顶点

        while( num )//当顶点集合中还有顶点不在V1中时继续执行循环体
        {
            Edge<EdgeType> Min = FirstEdge( s );//最小边初始化
            while(  )
        }
        Edge<EdgeType> *MST;//存储最小生成树的边
        int* nearest = new int[vertexNum];//生成树中顶点到i点最小边权值
        int* neighbor = new int[vertexNum];//生成树中顶点到i点最近点编号
        //若为-1则已存在与生成树中
        int num_tree = 1;//记录生成树中顶点数目

        for( int i = 0 ; i < vertexNum ; i++ )//为两数组赋初值
        {
            neighbor[i] = s;
            nearest[i] = -1;
        }
        neighbor[s] = -1;//s点已在生成树中

        for( ; num_tree <= vertexNum ; num_tree++ )
        {
            int Min = FirstEdge( s ).weight;//最小权值赋初值

        }
    }*/

    Edge<EdgeType>* Kruskal()//最小生成树的Kruskal算法
    {
        //求含有n个顶点、e条边的连通图G的最小生成树 返回边的集合
        UFSets sets(vertexNum);//定义n个结点的等价类
        Edge<EdgeType> *MST = new Edge<EdgeType>[vertexNum - 1];//要返回的最小生成树的边
        MinHeap< Edge<EdgeType> > MinH(this->edgeNum);//定义含有e个元素的最小堆，用于寻找权值最小的边
        Edge<EdgeType> edge;
        for (int i = 0; i < vertexNum; i++){
            for (edge = FirstEdge(i); IsEdge(edge); edge =NextEdge(edge)){
                if (edge.start < edge.end){
                    //限制起始点的编号大小顺序，防止无向图中的边被重复加入
                    MinH.Insert(edge);

                }
            }
        }
        int edgeNum = 0;//生成边的个数
        while (edgeNum < vertexNum - 1){//n个结点的连通图的生成树有n-1条边
            if (!MinH.Is_empty())
            {
                //如果堆不空
                edge = MinH.remove_min();//找到权重最小的未处理的边
                int v = edge.start;
                int u = edge.end;
                if (sets.Find(v) != sets.Find(u)){
                    //判断该边关联的顶点是否在一个连通分量
                    sets.Union(v, u);//合并两个顶点所在的等价类
                    MST[edgeNum] = edge;//将符合条件的边添加到生成树的边集合中
                    edgeNum++;
                }
            }
            else
            {
                cout<<"不存在最小生成树."<<endl;
                return NULL;
            }

        }
        cout<<"\n最小生成树(Kruscal):"<<endl;
        for( int t = 0 ; t < vertexNum - 1 ; t ++ )//边信息输出
            MST[t].show();
        return MST;
    }

    void Dijkstra( int s, EdgeType* D, int * Path)
    {
        /*Dijkstra算法，其中参数s是源点，D是最短特殊路径长度，Path[i]为路径上i的前驱顶点编号*/
        for (int i = 0; i < vertexNum; i++)
        {
            //初始化
            Mark[i] = 0;//一个路径都没有，都没有被访问过
            D[i] = AFFINITY;//从s到每个点的最短特殊路径的长度初始化为最大值
            Path[i] = s;//所有点的前驱初始为源点s
        }
        D[s] = 0;//s到自身的最短长度为0
        for (int j = 0; j < vertexNum; j++)
        {
            //每次循环就找到一个最短路径
            //找到一条最短特殊路径,即min{D[j]&&Mark[j]==UNVISITED, 0<=j<n}
            EdgeType min = AFFINITY;//min为最小权
            int k;
            for (int i = 0; i < vertexNum; i++)
            {
                if (Mark[i] == 0 && D[i] < min)
                {
                    k = i;
                    min = D[i];
                }
            }
            //已确定s到k的最短路径
            Mark[k] = 1;
            //下面修改D
            //利用k更新到其余未访问顶点的最短特殊路径
            for (Edge<EdgeType> e = FirstEdge(k); IsEdge(e); e = NextEdge(e))
            {
                int endVertex = e.end;
                if (Mark[endVertex] == 0 && D[endVertex] > (D[k] + e.weight))
                {
                    //如果出现更小的路径,就更新
                    D[endVertex] = D[k] + e.weight;//更新到endVertex的最短特殊路径
                    Path[endVertex] = k;//更新前驱节点编号
                }
            }
        }
    }

    void Floyd(EdgeType **adjArray, int **Path)
    {//带权 有向图，adjArray[i][j]为从i到j的最短路径长度，Path[i][j]为最短路径中顶点j的前驱顶点编号
        int i, j, v;
        for (i = 0; i < vertexNum; i++)
        {
            for (j = 0; j < vertexNum; j++)
            {
                if (i == j)
                {
                    adjArray[i][j] = 0;//到自身的最小路径为0
                }
                else
                {
                    adjArray[i][j] = AFFINITY;//否则是无穷大
                }
                Path[i][j] = i;//前驱顶点 编号 是自身
            }
        }//初始化
        for (v = 0; v < vertexNum; v++)
        {
            //检查各个边，将（v,end）的权值作为adjArray[v][end]
            for (Edge<EdgeType> e = FirstEdge(v); IsEdge(e); e = NextEdge(e))
            {
                adjArray[v][e.end] = e.weight;
            }
        }
        //如果两个顶点i,j之间的最短路径经过顶点v，且有adjArray[i][j]>(adjArray[i][v]+adjArray[v][j])，就更新adjArray[i][j]和Path[i][j]的值
        for (v = 0; v < vertexNum; v++)
        {
            for (i = 0; i < vertexNum; i++)
            {
                for (j = 0; j < vertexNum; j++)
                {
                    if (adjArray[i][j] >(adjArray[i][v] + adjArray[v][j]))
                    {
                        adjArray[i][j] = adjArray[i][v] + adjArray[v][j];//更新最短路径
                        Path[i][j] = v;
                    }
                }
            }
        }
    }

    /*void Kruskal()     //最小生成树的Kruskal算法
    {

    }
    void BFSTraverse()
    {

    }

    */
    void visit(int v)
    {
        cout<<v<<" ";
    }
};
int main()
{
    AdjGraph<int> graph(6);
    int D[6],Path[6];
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
            graph.setEdge(i,j,0);
    }
//    graph.setEdge(0,1,6);
//    graph.setEdge(0,2,1);
//    graph.setEdge(0,3,5);
//    graph.setEdge(1,0,6);
//    graph.setEdge(1,2,5);
//    graph.setEdge(1,4,3);
//    graph.setEdge(2,0,1);
//    graph.setEdge(2,1,5);
//    graph.setEdge(2,3,5);
//    graph.setEdge(2,4,6);
//    graph.setEdge(2,5,4);
//    graph.setEdge(3,0,5);
//    graph.setEdge(3,2,5);
//    graph.setEdge(3,5,2);
//    graph.setEdge(4,1,3);
//    graph.setEdge(4,2,6);
//    graph.setEdge(4,5,6);
//    graph.setEdge(5,2,4);
//    graph.setEdge(5,3,2);
//    graph.setEdge(5,4,6);
	graph.setEdge(0,1,12); 
	graph.setEdge(0,2,10);
	graph.setEdge(0,4,30);
	graph.setEdge(0,5,100);
	graph.setEdge(1,2,5);
	graph.setEdge(2,3,50);
	graph.setEdge(3,5,10);
	graph.setEdge(4,3,20);
	graph.setEdge(4,5,60);
    cout<<"\nDFS遍历:"<<endl;
    graph.DFSNoReverse();
    cout<<"\nBFS遍历:"<<endl;
    graph.BFS( 0 );
    graph.Prim(0);
    //cout<<"finish!"<<endl;
    //graph.BFSTraverse();
    graph.Kruskal();

    cout<<"\n最短路径(Dijkstra):"<<endl;
    graph.Dijkstra(0,D,Path);
    for(int i=1;i<6;i++)
    {
        int k=i;
        cout<<"0到"<<i<<"的最短路径为: "<<i;
        while(Path[k]!=0)
        {
            k=Path[k];
            cout<<" <- "<<k;
        }
        cout<<" <- 0"<<"\t路径长度为: "<<D[i]<<endl;
    }

    int **adjArray = new int*[6],**path = new int* [6];
    for( int i = 0 ; i < 6 ; i++ )
    {
        adjArray[i] = new int[6];
        path[i] = new int[6];
    }
    cout<<"\n最短路径(floyed):"<<endl;
    graph.Floyd( adjArray , path );//floyd最短路径
    for( int i = 0 ; i < 6 ; i++)
    {
        for( int j = 0 ; j < 6 ; j++)
        {
            int v = j;
            cout<<i<<"到"<<j<<"的最短路径为: "<<j;
            while( path[i][v] != i )
            {
                cout<<" <- "<<path[i][v];
                v = path[i][j];
            }
            cout<<" <- "<<i<<"\t路径长度为: "<<adjArray[i][j]<<endl;
        }
    }
    return 0;
}
/*测试用例

        v0
      / | \
    6/  |1 \5
    / 5 |  5\
   v1---v2---v3
   |   /  \  |
  3|  /6  4\ |2
   | /      \|
   v4-------v5
        6

*/
