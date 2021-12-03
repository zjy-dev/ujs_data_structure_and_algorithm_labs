/*
（2）设计一个有序顺序表类，即表中的数据元素按数据元素值递增有序。实现以下函数：
    （a）把给定值e插入有序表中。
    （b）删除值为e的所有数据元素。
    （c）合并两个有序表，得到一个新的有序表。
    （d）从有序顺序表中删除其值在给定值s与t之间（s＜t）的所有元素，如果s≥t或顺序表为空，则显示出错信息，并退出运行。
*/
#include<bits/stdc++.h>
using namespace std;

const int DEFAULT_SIZE = 1e+2;

template<class ElemType>
class OrderedList
{
public:
    int len, maxLen;
    ElemType* data;
public:
    OrderedList(int size = DEFAULT_SIZE);

    //二分查找表中大于等于v的第一个位置, O(logn)
    //工具函数, 服务其他成员方法
    int find(ElemType v);

    //把给定值v插入有序表中, 利用二分查找O(logn)
    void insert(ElemType v);

    //删除全部值为v的元素, 利用二分查找O(nlogn)(删除复杂度O(n))
    void deleteAll(ElemType v);

    //归并另外一个新表, 并返回该新表
    OrderedList* merge(const OrderedList& o);

    //删除[s, t]范围内的所有数, 利用二分查找O(nlogn)(删除复杂度O(n))
    void deleteS2T(ElemType s, ElemType t);

    //遍历, O(n)
    void traverse();

    virtual ~OrderedList();
};


template<class ElemType>
OrderedList<ElemType>::OrderedList(int size)
{
    this->data = new ElemType[size];
    this->maxLen = size;
    this->len = 0;
}

template<class ElemType>
void OrderedList<ElemType>::traverse()
{
    for(int i = 0; i < this->len; i++)
        cout << this->data[i] << " ";
    printf("Current Len is: %d\n", this->len);

    puts("");
}

//二分查找第一个大于等于v的位置
template<class ElemType>
int OrderedList<ElemType>::find(ElemType v)
{
    int l = 0, r = this->len - 1, mid;

    //二分
    while(l < r)
        if(this->data[mid = l + r >> 1] >= v)
            r = mid;
        else
            l = mid + 1;
    
    //l就是答案
    return l;
}

template<class ElemType>
void OrderedList<ElemType>::insert(ElemType v)
{
    if(this->len + 1 > this->maxLen)
    {
        cout << "The List is Already Full!!!" << endl;
        return;
    }
    
    //l就是要插入的位置
    int l = this->find(v);

    //尾插要Special Judge
    if(this->data[l] < v)
    {
        this->data[this->len++] = v;
        return;
    }

    //把l后的元素全部后移, 给l腾出空间
    for (int i = len - 1; i >= l; i--)
        this->data[i + 1] = this->data[i];
    
    //插入
    this->data[l] = v;

    //更新长度
    this->len++;
}


template<class ElemType>
void OrderedList<ElemType>::deleteAll(ElemType v)
{
    int l = this->find(v);

    //找不到就返回
    if(this->data[l] != v)
        return;

    int r = l;

    while(r < this->len and this->data[r] == v)
        r++;

    int offset = r - l;

    while(r < len)    
        this->data[l++] = this->data[r++];

    this->len -= offset;
}

template<class ElemType>
OrderedList<ElemType>* OrderedList<ElemType>::merge(const OrderedList& o)
{
    //新建一个有序表
    auto ans = new OrderedList(this->len + o.len + DEFAULT_SIZE);

    //双指针归并, O(m + n)
    int i = 0, j = 0;
    for(; i < this->len and j < o.len; ans->len++)
            ans->data[ans->len] = this->data[i] < o.data[j] ? this->data[i++] : o.data[j++];

    while(i < this->len)
        ans->data[ans->len++] = this->data[i++];

    while(j < o.len)
        ans->data[ans->len++] = o.data[j++];

    return ans;
}

template<class ElemType>
void OrderedList<ElemType>::deleteS2T(ElemType s, ElemType t)
{
    if(s >= t or !this->len)
    {
        cout << "Error!!!" << endl;
        exit(1);
    }

    //l是第一个大于等于s的位置
    int l = this->find(s);

    //s太大, 无需要删除元素, 直接返回
    if(this->data[l] < s)
        return;

    //寻找区间末尾
    int r = l;
    while(this->data[r] <= t)
        r++;
    
    //删除
    int offset = r - l;
    while(r < this->len)
        this->data[l++] = this->data[r++];
    
    this->len -= offset;
}

template<class ElemType>
OrderedList<ElemType>::~OrderedList()
{
    delete[] this->data;
}

int main()
{
    OrderedList<int> o;
    srand((unsigned)time(NULL));
    cout << "The Original data Generated Randomly: " << endl;
    for(int i = 0; i < 20; i++)
    {
        int t;
        cout << (t = rand() % 50) << " ";
        o.insert(t);
    }
    cout << "\n\n";
    cout << "Insert Them All into the List: " << endl;
    o.traverse();

    printf("After Delete All Elem '%d':\n", o.data[5]);
    o.deleteAll(o.data[5]);
    o.traverse();

    OrderedList<int> t;
    for(int i = 0; i < 10; i++)
        t.insert(i);
    cout << "When Merged with a Sequence ranged[0, 9]" << endl;
    auto ret = o.merge(t);
    ret->traverse();
    delete ret;

    printf("After Delete %d to %d:\n", o.data[5], o.data[10]);
    o.deleteS2T(o.data[5], o.data[10]);
    o.traverse();
}   