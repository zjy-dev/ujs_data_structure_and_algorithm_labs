/*
4. 设计一个带头结点的有序单链表类。实现以下函数：
    （a）插入函数：把元素值e作为数据元素插入表中。
    （b）删除函数：删除数据元素等于e的结点。
*/
#include<bits/stdc++.h>
using namespace std;

template<class ElemType>
class Node
{
public:
    Node<ElemType>* ne;
    ElemType val;

public:
    Node<ElemType>(ElemType val = 0);
};

template<class ElemType>
class OrderedLinkedList
{
public:
    Node<ElemType>* head; 

public:
    OrderedLinkedList();

    //插入函数：把元素值val作为数据元素插入表中, O(n)
    void insert(ElemType val); 

    //删除函数：删除数据元素等于val的结点, O(n)
    void deleteVal(ElemType val);

    //遍历方便调试, O(n)
    void traverse();

    ~OrderedLinkedList();
};

template<class ElemType>
void OrderedLinkedList<ElemType>::traverse()
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
OrderedLinkedList<ElemType>::OrderedLinkedList()
{
    this->head = new Node<ElemType>();
}

template<class ElemType>
void OrderedLinkedList<ElemType>::insert(ElemType val)
{
    auto p = head;
    //寻找第一个数据域大于等于val的结点的前一个结点
    while(p->ne and p->ne->val < val)
        p = p->ne;
  
    //找到之后进行插入操作
    auto t = new Node<ElemType>(val);
    t->ne = p->ne;
    p->ne = t;
}

template<class ElemType>
void OrderedLinkedList<ElemType>::deleteVal(ElemType val)
{
    auto p = this->head;
    while(p->ne)
    {   
        //寻找第一个数据域等于val的结点的前一个结点
        if(p->ne->val == val)
        {
            auto t = p->ne;
            p->ne = p->ne->ne;
            delete t;

            //删除成功后相当于自动迭代了一次, 无需更新p
            continue;
        }
        p = p->ne;
    }
}

template<class ElemType>
OrderedLinkedList<ElemType>::~OrderedLinkedList()
{
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

    OrderedLinkedList<int> l;
       cout << "The Original data Generated Randomly: " << endl;
    for(int i = 0; i < 30; i++)
    {
        int t;
        cout << (t = rand() % 25) << " ";
        l.insert(t);
    }
    cout << "\n\n";
    cout << "After Insert them All The Original OrderedLinkedList is: " << endl;
    l.traverse();
    puts("");

    printf("After Delete %d:\n", 15);
    l.deleteVal(15);
    l.traverse();
}