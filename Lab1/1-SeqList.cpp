/*
1. 在顺序表中设计函数实现以下操作：
    （a）从顺序表中删除具有最小值的元素（假设顺序表中元素都不相同），并由函数返回被删元素的值，空出的位置由最后一个元素填补。
    （b）从顺序表中删除具有给定值e的所有元素。
    （c）在一个顺序表中如果一个数据值有重复出现，则留下第一个这样的数据值，并删除其他所有重复的元素，使表中所有元素的值均不相同。
*/
#include<bits/stdc++.h>
using namespace std;

const int DEFAULT_SIZE = 1e+3;

template<class ElemType>
class SeqList
{
protected:
    int len, maxLen;
    ElemType* data;

public:
    SeqList(int size = DEFAULT_SIZE);
    SeqList(ElemType* data, int n, int size = DEFAULT_SIZE);

    //从顺序表中删除具有最小值的元素, 并返回最小值, 空位由最后一位填补, O(n)
    ElemType deleteMin();

    //从st开始, 删除全部值为v的元素, O(n^2)
    void deleteAll(ElemType v, int st = 0);

    //去重, 时间复杂度O(n^2)(扫描O(n), 删除O(n)), 哈希表额外需要空间复杂度O(m)(m为不重复的元素个数)
    void unique();
    void traverse();

    virtual ~SeqList();
};

template<class ElemType>
SeqList<ElemType>::SeqList(int size)
{
    this->len = 0;
    this->maxLen = size;
    this->data = new ElemType[size];
}

template<class ElemType>
SeqList<ElemType>::SeqList(ElemType data[], int n, int size)
{
    this->data = new ElemType[size];
    this->len = n;
    for(int i = 0; i < n; i++)
        this->data[i] = data[i];
    this->maxLen = size;
}

template<class ElemType>
ElemType SeqList<ElemType>::deleteMin()
{
    //寻找最小值下标
    int p = 0;
    for(int i = 1; i < this->len; i++)
        if(this->data[i] < this->data[p])
            p = i;
    
    //用最后一个元素覆盖最小值
    int ans = this->data[p];//记录一下最小值便于返回
    this->data[p] = this->data[this->len - 1];
    this->len--;

    return ans;
}

template<class ElemType>
void SeqList<ElemType>::deleteAll(ElemType v, int st)
{
    for(int i = st; i < this->len; i++)
        //遇到值等于v的元素就删除该元素
        if(this->data[i] == v)
        {
            for(int j = i + 1; j < this->len; j++)
                this->data[j - 1] = this->data[j];
            this->len--;

            //删除之后就自动迭代了一次, 无需更新i
            i--;
        }
}

template<class ElemType>
void SeqList<ElemType>::unique()
{
    unordered_map<ElemType, bool> hash;
    for(int i = 0; i < this->len; )
        if(hash[this->data[i]])
            this->deleteAll(this->data[i], i);
        else
            hash[this->data[i++]] = true;
}

template<class ElemType>
void SeqList<ElemType>::traverse()
{
    for(int i = 0; i < this->len; i++)
        cout << this->data[i] << " ";
    printf("Current Len is: %d\n", this->len);

    puts("");
}

template<class ElemType>
SeqList<ElemType>::~SeqList()
{
    delete[] this->data;
}

int main()
{
    int arr[] = {3, 3, 3, 1, 2, 2, 2, 7, 2, 6, 6, 2, 5, 6, 2, 5, 7, 3, 3, 5, 4};
    SeqList<int> s(arr, 21);

    cout << "The Original SeqList is: " << endl;
    s.traverse();

    int ret = s.deleteMin();
    printf("The Minimum is %d\n", ret);
    cout << "After Delete Min: " << endl;
    s.traverse();

    s.deleteAll(2);
    cout << "After Delete All Elem '2'" << endl;
    s.traverse();

    s.unique();
    cout << "After Unique" << endl;
    s.traverse();
}
