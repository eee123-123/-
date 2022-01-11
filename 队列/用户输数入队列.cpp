#include<iostream>
using namespace std;
template<class T>
class LinkNode{
public:
    T data;
    LinkNode<T> *pNext;
    LinkNode(T data){
    this->data = data;
    }
};
template<class T>
class LinkQueue{
private:
    LinkNode<T> *pfront;
    LinkNode<T> *prear;
    int size;
public:
    LinkQueue(int size = 0){
        this->pfront = prear = NULL;
        this->size = 0;
    }
    bool Isempty(){
        if(size == 0)
            return true;
        else
            return false;
    }
    void Show(){
        LinkNode<T> *p = pfront;
        if(p == NULL){
            cout  << "�ӿ�";
            return ;
        }
        else
        for(p;p!=prear->pNext;p = p->pNext)
            cout << p->data << "   ";
    }
    void Enqueue(T data);
    void Enqueue2(LinkNode<T> *p);
    LinkNode<T>* Outqueue();
    void Zhuanyi(LinkQueue<T> start);
};
 
template<class T>
void LinkQueue<T> :: Enqueue(T data){
    LinkNode<T> *p = new LinkNode<T>(data);
    if(prear == NULL)
        this->prear = pfront = p;
    else{
        prear->pNext = p;
        prear = p;
    }
    size += 1;
}
template<class T>
void LinkQueue<T> :: Enqueue2(LinkNode<T> *p){
    if(prear == NULL)
        this->prear = pfront = p;
    else{
        prear->pNext = p;
        prear = p;
    }
    size += 1;
}
template<class T>
LinkNode<T>* LinkQueue<T> :: Outqueue(){
    if(pfront != NULL){
        LinkNode<T> *p = pfront;
        pfront = p->pNext;
        size -= 1;
        return p;
    }
    else{
        cout << "����Ϊ�գ��޷����ӣ�" << endl;
 
        return NULL;
    }
}
template<class T>
void LinkQueue<T> :: Zhuanyi(LinkQueue<T> start){
    LinkNode<T> *p = NULL;
    while(!start.Isempty()){
        p = start.Outqueue();
        Enqueue2(p);
    }
}
int main()
{
    LinkQueue<int> que[11] ;//= new[LinkQueue<char>](10); �������զд����
    cout << "������0��9֮����������֣��м��ÿո������������������ֵ��������" << endl;
    int x;
    cin >> x;
    while(x>=0 && x<=9)
    {
        que[x].Enqueue(x);
        cin >> x;
    }
    for(int i = 0;i<=9;i++){
        cout << "��" << i << "�����У�";
        que[i].Show();
        cout << endl ;
    }
    for(int i=0;i<=9;i++){
        if(!que[i].Isempty())
        que[10].Zhuanyi(que[i]);
    }
    cout << "���Ӻ�" << endl;
    que[10].Show();
return 0;
}
