// 3.在循环队列中，以front和length分别表示循环队列中的队头位置和队列中所含元素的个数。
// 试完成循环队列判断队空、判断队满入队和出队函数的实现。

#include<bits/stdc++.h>
using namespace std;

const int DEFAULT_SIZE = 10;
#define SUB(x) (x) % this->size

template<class T>
class CircularQueue
{
protected:
    //fields:
    int length;
    int front, rear;
    int size;
    T* data;
public:
    //methods:
    CircularQueue(int size = DEFAULT_SIZE) : size(size), length(0), front(0), rear(0)
    {
        this->data = new T[size];
    }

    bool isEmpty()
    {
        return this->rear == this->front;
    }

    bool isFull()
    {
        return SUB(rear + 1) == front;
    }

    void push(T val)
    {
        if(isFull())
            return;
        this->data[SUB(this->rear++)] = val;
        this->rear %= size;
        this->length++;
    }

    T pop()
    {
        if(this->isEmpty())
            return INT_MIN;
    
        T ans = this->data[SUB(this->front++)];
        this->front %= size;
        this->length--;

        return ans;
    }

    void traverse(void (*visit) (T val))
    {
        for(int i = 0; i < this->length; i++)
            visit(this->data[SUB(i + front)]);
        puts("");
    }

    ~CircularQueue()
    {
        delete[] this->data;
    }
};

template<typename T>
void visit(T val)
{
    cout << val << " ";
}

int main(int argc, char const *argv[])
{
    auto q = CircularQueue<int>(DEFAULT_SIZE);

    cout << "The Queue is now " << (q.isEmpty() ? "Empty\n" : "not Empty\n") << endl;

    printf("After Push 1-15 into the Queue:\n\n");
    for(int i = 1; i <= 15; i++)
        q.push(i);
    
    q.traverse(visit);

    cout << "\nThe Queue is now " << (q.isEmpty() ? "Empty\n" : "not Empty\n") << endl;

    printf("After Pop 5 Elements from the Queue\n\n");
    for(int i = 0; i < 5; i++)
        cout << q.pop() << " has been poped" << endl;
    puts("");
    q.traverse(visit);
    printf("\nAfter Push 10-20 into the Queue:\n\n");
    for(int i = 10; i <= 20; i++)
        q.push(i);
    q.traverse(visit);

    return 0;
}
