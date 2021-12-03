// 2.设计利用两个栈sl，s2模拟一个队列，请写出实现入队、出队和判队列空的函数的实现。

#include<bits/stdc++.h>
using namespace std;

const int DEFAULT_SIZE = 10;

template<class T>
class Stack
{
public:
    //fields:
    T* data;
    int size;
    int top;
public:
    //methods:
    Stack(int size = 100) : size(size), top(-1)
    {
        this->data = new T[size];
    }

    Stack(const Stack& s)
    {
        *this = s;
        this->data = new T[size];
        for(int i = 0; i <= top; i++)
            data[i] = s.data[i];
    }

    bool isEmpty()
    {
        return this->top == -1;
    }

    void push(T val)
    {
        if(this->top == size)
            return;
        this->data[++top] = val;
    }

    T pop()
    {
        if(isEmpty())
            return INT_MIN;
        
        return data[top--];
    }
};

template<class T>
class Queue
{
protected:
    //fields:
    Stack<T> *stk1, *stk2;
    int size, len;
public:
    //methods:
    Queue(int size = DEFAULT_SIZE) : size(size), len(0)
    {
        this->stk1 = new Stack<T>(size);
        this->stk2 = new Stack<T>(size);
    }

    Queue(const Queue& q)
    {
        *this = q;
        this->stk1 = new Stack<T>(*q.stk1);
        this->stk2 = new Stack<T>(*q.stk2);
    }

    bool isEmpty()
    {
        return stk1->isEmpty() and stk2->isEmpty();
    }

    void push(T val)
    {
        if(this->len == this->size)
            return;
        this->stk1->push(val);
        this->len++;
    }

    T pop()
    {
        if(stk2->isEmpty())
            while(!stk1->isEmpty())
                stk2->push(stk1->pop());
        
        if(stk2->isEmpty())
            return INT_MIN;
        else
        {
            this->len--;
            return stk2->pop();
        }
    }

    void traverse(void (*visit) (T val))
    {
        printf("The Queue: ");
        Queue<T> q(*this);
        while (!q.isEmpty())
            visit(q.pop());
        
        puts("");
    }

    ~Queue()
    {
        delete this->stk1;
        delete this->stk2;
    }
};

template<typename T>
void visit(T val)
{
    cout << val << " ";
}

int main(int argc, char const *argv[])
{
    auto q = Queue<int>(DEFAULT_SIZE);

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
}