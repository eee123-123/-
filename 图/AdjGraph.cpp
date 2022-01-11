/*ͼ���ڽӾ����ʾ�ඨ�塢�ȼ��ඨ��*/
#include<iostream>
#include<stack>
#include<queue>
#define AFFINITY 999999
using namespace std;
class UFSets      //�ȼ���
{
private:
    int n;       //�ȼ�����Ԫ�ظ���
    int* root;   //root[i]��ʾԪ��i���ڵĵȼ���Ĵ���Ԫ�ر��
    int* next;   //next[i]��ʾ�ڵȼ����У�i�ĺ���Ԫ�ر��
    int* length; //length[i]��ʾi������ĵȼ����Ԫ�ظ���
public:
    UFSets(int size)
    {//��ʼsize��Ԫ�صĵȼ���
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
    {//�ϲ�u��v���ڵĵȼ��࣬��Ԫ�ض�ĺϲ���Ԫ���ٵĵȼ�����
        if(root[u]==root[v])
            return;
        else if(length[root[v]]<length[root[u]])
        {//��v���ڵȼ���Ԫ�غϲ���u���ڵȼ��࣬����u���ڵȼ���Ĵ���Ԫ����Ϊ�ϲ���ĵȼ���Ĵ���Ԫ
            int rt=root[v];                //��ȡv���ڵȼ���Ĵ���Ԫ��
            length[root[u]]+=length[rt];   //�޸�u���ڵȼ����Ԫ�ظ���
            root[rt]=root[u];              //�޸�v���ڵȼ���ĸ���Ԫ�صĴ���Ԫ����Ϣ
            for(int j=next[rt];j!=rt;j=next[j])
                root[j]=root[u];
            swap(next[rt],next[root[u]]);  //���������ȼ����Ԫ��
        }
        else
        {//��u���ڵȼ���Ԫ�غϲ���v���ڵȼ��࣬����v���ڵȼ���Ĵ���Ԫ����Ϊ�ϲ���ĵȼ���Ĵ���Ԫ
            int rt=root[u];                //��ȡu���ڵȼ���Ĵ���Ԫ��
            length[root[v]]+=length[rt];   //�޸�v���ڵȼ����Ԫ�ظ���
            root[rt]=root[v];              //�޸�u���ڵȼ���ĸ���Ԫ�صĴ���Ԫ����Ϣ
            for(int j=next[rt];j!=rt;j=next[j])
                root[j]=root[v];
            swap(next[rt],next[root[v]]);  //���������ȼ����Ԫ��
        }
    }
};
template<class EdgeType>
class Edge    //������
{
public:
    int start,end,weight;    //startΪ�ߵ�ʼ�㣬endΪ�ߵ��յ㣬weightΪ�ߵ�Ȩ��
    Edge()      //�����
    {
        start=end=weight=0;
    }
    Edge(int st,int en,int w)     //�����(st,en)��Ȩ��Ϊw
    {
        start=st;
        end=en;
        weight=w;
    }
    void show()//�ߵ����
    {
        cout<<'<'<<start<<','<<end<<'>'<<endl;
        cout<<"Ȩ��:"<<weight<<endl;
    }
    bool operator >(Edge oneEdge)     //���������>��ͨ��Ȩ�رȽϱߵĴ�С
    {
        if(this->weight>oneEdge.weight)
            return true;
        else
            return false;
    }
    bool operator <(Edge oneEdge)     //���������<��ͨ��Ȩ�رȽϱߵĴ�С
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
class MinHeap//��С����
{
    T* headArray;//�Ѵ洢����
    int MaxSize;//�ѵ��������
    int CurrentNum;//��ǰ����Ԫ�ظ���
    void Swap( int i , int j )//���������±�Ϊi��j��Ԫ��
    {
        T temp = headArray[i];
        headArray[i] = headArray[j];
        headArray[j] = temp;
    }

public:

    int get_num()//���ض���Ԫ�ظ���
    { return CurrentNum; }

    int get_father( int i )//���ظ��ڵ���±�
    { return ( i - 1 ) / 2; }

    int get_leftChild( int i )//���������±�
    { return 2*i + 1 ; }

    int get_rightChild( int i )//�����Һ����±�
    { return 2*i + 2 ; }

    T remove_min()//ɾ����СԪ�أ���������Сֵ
    {
        int index ;
        T fro;
        fro = headArray[0];
        delete_value( headArray[0] , index );
        return fro;
    }

    MinHeap( const int n )//�����СΪn�Ķ�
    {
        headArray = new T[n];//���ٿռ�
        MaxSize = n;
        CurrentNum = 0;//��ʼ����Ԫ�ظ���Ϊ0
    }

    ~MinHeap(){ delete [] headArray ; }//��������

    bool Is_empty()//�ж϶��Ƿ�Ϊ��
    {
        if( CurrentNum )
            return false;
        else
            return true;
    }

    void Siftup( int pos )//�������ϵ���,����ȫ��������Ϊ��,posָ��ʼ������Ԫ���±�
    {
        while( pos > 0 && headArray[pos] < headArray[get_father( pos )] )
        {
            Swap( pos , get_father( pos ) );
            pos = get_father( pos );
        }
    }

    void Siftdown( int pos )//�������µ���,posָ��ʼ������Ԫ���±�
    {
        int l = get_leftChild( pos );//�����±�
        while( l < CurrentNum )
        {
            if( l + 1 < CurrentNum && headArray[l] > headArray[l + 1] )
                l++;
            if( headArray[pos] > headArray[l] )
            {
                Swap( pos , l );//��Ŀ��������Һ����д��һ������
                pos = l;
                l = get_leftChild( pos );//�����±�
            }
            else
                break;
        }
    }

    bool Insert( const T value )//����в���Ԫ��
    {
        if( CurrentNum == MaxSize )
            return false;
        else
        {
            headArray[CurrentNum] = value;//��ֵ����
            Siftup( CurrentNum );//���ϵ���
            CurrentNum ++;//β��ָ�������
            return true;
        }
    }

    bool delete_value( T value , int& index )//ɾ��ָ��Ԫ��
    {
        int flag = 0;
        if( Is_empty() )
            return false;
        else
        {
            for( int i = 0 ; i < CurrentNum ; i++ )//Ѱ�Ҹ�ֵ
            {
                if( headArray[i] == value )//�ҵ�ֵ
                {
                    if( i == CurrentNum - 1 )//ɾ��ֵ��β��
                    {
                        index = i;
                        --CurrentNum;
                        flag = 1;
                    }
                    else
                    {
                        index = i;
                        headArray[i] = headArray[--CurrentNum];//ɾ��λ�ø���β��ֵ
                        Siftdown( i );//���µ���
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

    void show()//�ѵ����
    {
        for( int i = 0 ; i < CurrentNum ; i++ )
            headArray[i].show();
        cout<<'\n';
    }
};
template<class EdgeType>
class AdjGraph         //ͼ���ڽӾ����ඨ��
{
private:
    int vertexNum;     //ͼ�Ķ�����
    int edgeNum;       //ͼ�ı���
    int *Mark;         //���ĳ�����Ƿ��ѱ�����
    int **matrix;      //ͼ���ڽӾ���ָ��
public:
    AdjGraph(int v)
    {//���캯��
        vertexNum=v;
        edgeNum=0;
        Mark=new int[vertexNum];
        for(int i=0;i<vertexNum;i++)       //��ʼ��Mark����
            Mark[i]=0;
        matrix=(int**) new int*[vertexNum];
        for(int i=0;i<vertexNum;i++)
            matrix[i]=new int[vertexNum];
        for(int i=0;i<vertexNum;i++)
            for(int j=0;j<vertexNum;j++)    //��ʼ��matrix����
                matrix[i][j]=0;
    }
    ~AdjGraph()
    {//��������
        for(int i=0;i<vertexNum;i++)
            delete [] matrix[i];
        delete [] matrix;
    }
    Edge<EdgeType> FirstEdge(int oneVertex)
    {//���ض���oneVertex�ĵ�һ����
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
    {//�������oneEdge����ͬʼ�����һ����
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
    bool IsEdge(Edge<EdgeType> oneEdge)    //�жϵ�ǰ���Ƿ����
    {
        if(oneEdge.weight>0&&oneEdge.end>=0)
            return true;
        else
            return false;
    }
    void setEdge(int st,int en,int w)     //Ϊͼ�����µ�һ����
    {
        if(w!=0)
            edgeNum++;
        matrix[st][en]=w;
    }
    void delEdge(int st,int en)       //ɾ����
    {
        if(matrix[st][en]!=0)
            edgeNum--;
        matrix[st][en]=0;
    }
    void DFSNoReverse()      //�ǵݹ�ʵ��������ȱ���
	{
	    int num_visit = 0;//���ʹ��Ķ�����
	    int index = 0;//�������'ָ��'��Ĭ�ϴ�v0��ʼ����
	    using std::stack;
	    stack<int> vertexstack;//��δ���ʹ��Ķ����ջ
	    for(int i=0;i<vertexNum;i++)       //��ʼ��Mark����
            Mark[i]=0;
	    for( num_visit = 0 ; num_visit < vertexNum ; num_visit ++ )//�����ʹ��Ķ�����ĿС���ܶ�����Ŀ���������,�����еĶ����ޱ�
        {
            if( Mark[num_visit] == 0 )//�õ�δ���ʹ�
            {
                vertexstack.push( num_visit );//�ö�����ջ
                visit( num_visit );//���ʸö���
                Mark[num_visit] = 1;//��Ƿ��ʹ�
                while( !vertexstack.empty() )//���ջ����ִ��ѭ��
                {
                    index = vertexstack.top();//��ջ����ȡջ��Ԫ��
                    vertexstack.pop();
                    for( Edge<EdgeType> e = FirstEdge( index ) ; IsEdge( e ) ; e = NextEdge( e ) )//��ö������ڽ�����ջ
                    {
                        if( Mark[e.end] == 0 )//����ñ�β����δ���ʹ�
                        {
                            vertexstack.push( e.end );//������ջ
                            visit( e.end );//���ʸö���
                            Mark[e.end] = 1;//��Ǹ�Ϊ���ʹ�
                            break;//����ѭ��
                        }
                    }
                }
            }
        }
        cout<<endl;
	}
	void BFS(int v)         //�ǵݹ�ʵ�ֹ�����ȱ���
    {
        int num_visit = 0;//���ʹ��Ķ�����
        for(int i=0;i<vertexNum;i++)       //��ʼ��Mark����
            Mark[i]=0;
        using std::queue;
	    queue<int> vertexqueue;//��δ���ʹ��Ķ����ջ
	    int index = v;//���û�ָ�����㴦����
	    for( num_visit = v ; num_visit < v + vertexNum ; num_visit ++)//�����ʹ��Ķ�����ĿС���ܶ�����Ŀ���������,�����еĶ����ޱ�
        {
            if( num_visit > vertexNum )
                index = num_visit % vertexNum;
            vertexqueue.push( index );//�ö��������
            while( !vertexqueue.empty() )//�����в���ʱִ��ѭ����
            {
                if( Mark[index] )//����ýڵ���ʹ�
                {
                    index = vertexqueue.front();//��ȡ����Ԫ��
                    vertexqueue.pop();//������
                }
                else//���ö���δ���ʹ�
                {
                    visit( index );//���ʸö���
                    Mark[index] = 1;//���
                    for( Edge<EdgeType> e = FirstEdge( index ) ; IsEdge( e ) ; e = NextEdge( e ) )//�ö����������ڶ��������
                        vertexqueue.push( e.end );
                }
            }
        }
        cout<<endl;
    }

    Edge<EdgeType>* Prim( int s )
    {	//Ӧ��Prim�㷨��s��������õ�����С������
        int i, j;
        Edge<EdgeType> *MST; 	//�洢��С�������ı�
        //�������㵽�������еĸ����������̵ı�
        EdgeType *nearest;  	//nearest[i]��ʾ�������е㵽i�����С��Ȩֵ
        int *neighbor;      		//neighbor[i]��ʾ����������i������ĵ��ţ�
        //-1��ʾi���Ѿ���������������

        nearest = new EdgeType[vertexNum];
        neighbor = new int[vertexNum];
        MST = new Edge<EdgeType>[vertexNum - 1];
        for (i = 0; i<vertexNum; i++)    		//��ʼ��neighor�����nearest����
        {
            neighbor[i] = s;
            nearest[i] = FirstEdge( s ).weight;
        }
        //��s���ڽӵĶ���ı�Ȩֵ ��Ϊ��Щ�� �������������ϵ���̱߳�
        for (Edge<EdgeType> e = FirstEdge(s); IsEdge(e); e = NextEdge(e))
        {
            nearest[e.end] = e.weight;
        }

        neighbor[s] = -1;//���Ѽ��뵽�������ĵ�����������Ϊ-1
        for (i = 1; i < vertexNum; i++)
        { //i����Ѿ����뵽�������еĵ����
            EdgeType min = FirstEdge( s ).weight;//��¼��СȨֵ
            int v = s;//��¼��һ����Ҫ���뵽�����еĵ�
            for (j = 0; j<vertexNum; j++)
            {//ȷ��һ�����������������ϣ�һ�����㲻��������������Ȩֵ��С��
                //���������Ķ���
                if (nearest[j]<min && neighbor[j]>-1)
                {
                    min = nearest[j];
                    v = j;
                }
            }//for(j)
            if (v >= 0)
            {//��v���뵽������������,���µ���������ĸ�������СȨֵ�ı���Ϣ
                Edge<EdgeType> tempEdge(neighbor[v], v, nearest[v]);
                MST[i-1] = tempEdge;//���߼��뵽������������
                neighbor[v] = -1;
                for (Edge<EdgeType> e = FirstEdge(v); IsEdge(e); e = NextEdge(e))
                {
                    int u = e.end;
                    if (neighbor[u] != -1 && nearest[u]>e.weight)
                    {//����v�����ı߸���������֮�ⶥ�㵽���������ϵ���СȨֵ��
                        neighbor[u] = v;
                        nearest[u] = e.weight;
                    }
                }//for(e)
            }//if(v>=0)
        }//for(i)
        delete[] neighbor; //�ͷſռ�
        delete[] nearest;
        cout<<"\n��С������(Prim):"<<endl;
        for( int t = 0 ; t < vertexNum - 1 ; t ++ )//����Ϣ���
            MST[t].show();
        return MST;
    }

    /*void Prim(int s)     //��С��������Prim�㷨
    {
        int* nearest = new int[vertexNum];//����С�����������е���С����������飬nearest[i] ��ʾVi ����С��������Ȩֵ����������С��������������ֵΪ-1
        for( int i = 0 ; i < vertexNum ; i++ )//�����ʼ��
            nearest[i] = -1;
        int* leastTreeset = new int[vertexNum];//��С�����������а����Ķ��㣬�ڼ�����ֵΪ-1����֮Ϊ�䱾��
        leastTreeset[s] = -1;//��ʼ�������к�vs
        for( int i = 0 ; i < vertexNum ; i++)//��ʼ������
        {
            if( i == s )
                continue;
            leastTreeset[i] = i;
        }
        int num = vertexNum - 1;//��¼V-V1�����л��ж��ٶ���

        while( num )//�����㼯���л��ж��㲻��V1��ʱ����ִ��ѭ����
        {
            Edge<EdgeType> Min = FirstEdge( s );//��С�߳�ʼ��
            while(  )
        }
        Edge<EdgeType> *MST;//�洢��С�������ı�
        int* nearest = new int[vertexNum];//�������ж��㵽i����С��Ȩֵ
        int* neighbor = new int[vertexNum];//�������ж��㵽i���������
        //��Ϊ-1���Ѵ�������������
        int num_tree = 1;//��¼�������ж�����Ŀ

        for( int i = 0 ; i < vertexNum ; i++ )//Ϊ�����鸳��ֵ
        {
            neighbor[i] = s;
            nearest[i] = -1;
        }
        neighbor[s] = -1;//s��������������

        for( ; num_tree <= vertexNum ; num_tree++ )
        {
            int Min = FirstEdge( s ).weight;//��СȨֵ����ֵ

        }
    }*/

    Edge<EdgeType>* Kruskal()//��С��������Kruskal�㷨
    {
        //����n�����㡢e���ߵ���ͨͼG����С������ ���رߵļ���
        UFSets sets(vertexNum);//����n�����ĵȼ���
        Edge<EdgeType> *MST = new Edge<EdgeType>[vertexNum - 1];//Ҫ���ص���С�������ı�
        MinHeap< Edge<EdgeType> > MinH(this->edgeNum);//���庬��e��Ԫ�ص���С�ѣ�����Ѱ��Ȩֵ��С�ı�
        Edge<EdgeType> edge;
        for (int i = 0; i < vertexNum; i++){
            for (edge = FirstEdge(i); IsEdge(edge); edge =NextEdge(edge)){
                if (edge.start < edge.end){
                    //������ʼ��ı�Ŵ�С˳�򣬷�ֹ����ͼ�еı߱��ظ�����
                    MinH.Insert(edge);

                }
            }
        }
        int edgeNum = 0;//���ɱߵĸ���
        while (edgeNum < vertexNum - 1){//n��������ͨͼ����������n-1����
            if (!MinH.Is_empty())
            {
                //����Ѳ���
                edge = MinH.remove_min();//�ҵ�Ȩ����С��δ����ı�
                int v = edge.start;
                int u = edge.end;
                if (sets.Find(v) != sets.Find(u)){
                    //�жϸñ߹����Ķ����Ƿ���һ����ͨ����
                    sets.Union(v, u);//�ϲ������������ڵĵȼ���
                    MST[edgeNum] = edge;//�����������ı���ӵ��������ı߼�����
                    edgeNum++;
                }
            }
            else
            {
                cout<<"��������С������."<<endl;
                return NULL;
            }

        }
        cout<<"\n��С������(Kruscal):"<<endl;
        for( int t = 0 ; t < vertexNum - 1 ; t ++ )//����Ϣ���
            MST[t].show();
        return MST;
    }

    void Dijkstra( int s, EdgeType* D, int * Path)
    {
        /*Dijkstra�㷨�����в���s��Դ�㣬D���������·�����ȣ�Path[i]Ϊ·����i��ǰ��������*/
        for (int i = 0; i < vertexNum; i++)
        {
            //��ʼ��
            Mark[i] = 0;//һ��·����û�У���û�б����ʹ�
            D[i] = AFFINITY;//��s��ÿ������������·���ĳ��ȳ�ʼ��Ϊ���ֵ
            Path[i] = s;//���е��ǰ����ʼΪԴ��s
        }
        D[s] = 0;//s���������̳���Ϊ0
        for (int j = 0; j < vertexNum; j++)
        {
            //ÿ��ѭ�����ҵ�һ�����·��
            //�ҵ�һ���������·��,��min{D[j]&&Mark[j]==UNVISITED, 0<=j<n}
            EdgeType min = AFFINITY;//minΪ��СȨ
            int k;
            for (int i = 0; i < vertexNum; i++)
            {
                if (Mark[i] == 0 && D[i] < min)
                {
                    k = i;
                    min = D[i];
                }
            }
            //��ȷ��s��k�����·��
            Mark[k] = 1;
            //�����޸�D
            //����k���µ�����δ���ʶ�����������·��
            for (Edge<EdgeType> e = FirstEdge(k); IsEdge(e); e = NextEdge(e))
            {
                int endVertex = e.end;
                if (Mark[endVertex] == 0 && D[endVertex] > (D[k] + e.weight))
                {
                    //������ָ�С��·��,�͸���
                    D[endVertex] = D[k] + e.weight;//���µ�endVertex���������·��
                    Path[endVertex] = k;//����ǰ���ڵ���
                }
            }
        }
    }

    void Floyd(EdgeType **adjArray, int **Path)
    {//��Ȩ ����ͼ��adjArray[i][j]Ϊ��i��j�����·�����ȣ�Path[i][j]Ϊ���·���ж���j��ǰ��������
        int i, j, v;
        for (i = 0; i < vertexNum; i++)
        {
            for (j = 0; j < vertexNum; j++)
            {
                if (i == j)
                {
                    adjArray[i][j] = 0;//���������С·��Ϊ0
                }
                else
                {
                    adjArray[i][j] = AFFINITY;//�����������
                }
                Path[i][j] = i;//ǰ������ ��� ������
            }
        }//��ʼ��
        for (v = 0; v < vertexNum; v++)
        {
            //�������ߣ�����v,end����Ȩֵ��ΪadjArray[v][end]
            for (Edge<EdgeType> e = FirstEdge(v); IsEdge(e); e = NextEdge(e))
            {
                adjArray[v][e.end] = e.weight;
            }
        }
        //�����������i,j֮������·����������v������adjArray[i][j]>(adjArray[i][v]+adjArray[v][j])���͸���adjArray[i][j]��Path[i][j]��ֵ
        for (v = 0; v < vertexNum; v++)
        {
            for (i = 0; i < vertexNum; i++)
            {
                for (j = 0; j < vertexNum; j++)
                {
                    if (adjArray[i][j] >(adjArray[i][v] + adjArray[v][j]))
                    {
                        adjArray[i][j] = adjArray[i][v] + adjArray[v][j];//�������·��
                        Path[i][j] = v;
                    }
                }
            }
        }
    }

    /*void Kruskal()     //��С��������Kruskal�㷨
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
    cout<<"\nDFS����:"<<endl;
    graph.DFSNoReverse();
    cout<<"\nBFS����:"<<endl;
    graph.BFS( 0 );
    graph.Prim(0);
    //cout<<"finish!"<<endl;
    //graph.BFSTraverse();
    graph.Kruskal();

    cout<<"\n���·��(Dijkstra):"<<endl;
    graph.Dijkstra(0,D,Path);
    for(int i=1;i<6;i++)
    {
        int k=i;
        cout<<"0��"<<i<<"�����·��Ϊ: "<<i;
        while(Path[k]!=0)
        {
            k=Path[k];
            cout<<" <- "<<k;
        }
        cout<<" <- 0"<<"\t·������Ϊ: "<<D[i]<<endl;
    }

    int **adjArray = new int*[6],**path = new int* [6];
    for( int i = 0 ; i < 6 ; i++ )
    {
        adjArray[i] = new int[6];
        path[i] = new int[6];
    }
    cout<<"\n���·��(floyed):"<<endl;
    graph.Floyd( adjArray , path );//floyd���·��
    for( int i = 0 ; i < 6 ; i++)
    {
        for( int j = 0 ; j < 6 ; j++)
        {
            int v = j;
            cout<<i<<"��"<<j<<"�����·��Ϊ: "<<j;
            while( path[i][v] != i )
            {
                cout<<" <- "<<path[i][v];
                v = path[i][j];
            }
            cout<<" <- "<<i<<"\t·������Ϊ: "<<adjArray[i][j]<<endl;
        }
    }
    return 0;
}
/*��������

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
