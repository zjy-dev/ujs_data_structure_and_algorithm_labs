/*
3. 针对带头结点的单链表，试编写下列函数：
    （a）定位函数：在单链表中寻找第i个结点。若找到，则返回第i个结点的地址，否则返回空指针。
    （b）统计函数：统计单链表中等于给定值e的元素个数。
*/

#include<bits/stdc++.h>
using namespace std;

//结点类
template<class ElemType>
class Node
{
public:
    //next指针
    Node<ElemType>* ne;
    //数据域
    ElemType val;
public:
    Node<ElemType>(ElemType val = 0);
};

//链表类
template<class ElemType>
class LinkedList
{
public:
    //头结点指针
    Node<ElemType>* head;

public:
    LinkedList();

    //头插
    void insertAtHead(ElemType val);

    //定位函数：在单链表中寻找第i个结点。若找到，则返回第i个结点的地址，否则返回空指针, O(n)
    Node<ElemType>* find(int i) const;

    //统计函数：统计单链表中等于给定值e的元素个数, O(n)
    long long statistics(ElemType val);
    
    //遍历打印函数, 便于调试, O(n)
    void traverse();

    ~LinkedList();
};

template<class ElemType>
LinkedList<ElemType>::LinkedList()
{
    this->head = new Node<ElemType>();
}

template<class ElemType>
void LinkedList<ElemType>::insertAtHead(ElemType val)
{
    Node<ElemType>* p = new Node<ElemType>(val);
    p->ne = head->ne;
    this->head->ne = p;
}

template<class ElemType>
void LinkedList<ElemType>::traverse()
{
    auto p = this->head->ne;
    while(p)
    {
        cout << p->val << " ";
        p = p->ne;
    }
    puts("");
}

template<class ElemType>
Node<ElemType>* LinkedList<ElemType>::find(int i) const
{
    auto p = this->head->ne;//p初始化为头结点的指针域

    //p迭代i次, 若期间其为空则说明链表长度不足
    while(i--)
    {
        if(!p)
            return NULL;
        p = p->ne;
    }
    return p;
}

template<class ElemType>
long long LinkedList<ElemType>::statistics(ElemType val)
{
    auto p = this->head->ne;
    long long ans = 0;

    //找到值为val的结点就更新ans
    while(p)
    {
        if(p->val == val)
            ans++;
        p = p->ne;
    }
    return ans;
}

template<class ElemType>
LinkedList<ElemType>::~LinkedList()
{
    //析构时要有临时指针记录当前要析构的结点
    auto p = this->head;
    while(p)
    {
        auto t = p;
        p = p->ne;
        delete t;
    }
}

template<class ElemType>
Node<ElemType>::Node(ElemType val)
{
    this->val = val;
    this->ne = NULL;
}

int main()
{
    srand((unsigned)time(NULL));

    LinkedList<int> l;
    for(int i = 0; i < 30; i++)
        l.insertAtHead(rand() % 20);
    cout << "The Original LinkedList is: " << endl;
    l.traverse();
    puts("");

    cout << "The 10th Node's Address: " << endl;
    cout << l.find(10) << endl;
    puts("");

    cout << "The 0xfffffth Node's Address: " << endl;
    cout << l.find(0xfffff) << endl;
    puts("");

    cout << "The Number of '10' in this List is: " << endl;
    cout << l.statistics(10) << endl;
}


