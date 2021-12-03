// 1.请设计两个顺序栈共享一个存储空间形成的共享栈，完成共享栈的入栈、出栈和判断栈空等三个函数。

#include<bits/stdc++.h>
using namespace std;

const int DEFAULT_SIZE = 10;

template<class T>
class DoubleSeqStack
{
protected:
    //fields:
    int t1, t2;
    int size;
    T* data;
public:
    //methods:
    DoubleSeqStack(int size = DEFAULT_SIZE)
    {
        this->data = new T[size];
        this->size = size;
        this->t1 = -1, this->t2 = size;
    }
    
    void push1(T val)
    {
        if(this->t1 + 1 >= t2)
            return;
        
        this->data[++t1] = val;
    }

    void push2(T val)
    {
        if(this->t2 - 1 <= t1)
            return;
        
        this->data[--t2] = val;
    }

    T pop1()
    {
        if(isEmpty1())
            return INT_MIN;
        
        return this->data[t1--];
    }

    T pop2()
    {
        if(isEmpty2())
            return INT_MIN;
        
        return this->data[t2++];
    }

    bool isEmpty1()
    {
        return this->t1 == -1;
    }

    bool isEmpty2()
    {
        return this->t2 == size;
    }

    void traverse(void (*visit)(T val))
    {
        printf("The First Stack:\n");
        for(int i = t1; i >= 0; )
            visit(this->data[i--]);
        printf("\nThe Second Stack:\n");
        for(int i = t2; i < size; )
            visit(this->data[i++]);
        puts("");
    }

    ~DoubleSeqStack()
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
    auto doubleStk = DoubleSeqStack<int>(DEFAULT_SIZE);
    printf("Push 1-5 in the First Stack && 6-10 in the Second Stack:\n\n");
    for(int i = 0; i < 5; i++)
        doubleStk.push1(i + 1), doubleStk.push2(6 + i);

    doubleStk.traverse(visit);
    puts("");

    printf("Push 999 into the First Stack which is already Full:\n\n");
    doubleStk.push1(9999);
    doubleStk.traverse(visit);
    printf("Nothing happend\n\n");

    printf("Pop everything in the Second Stack:\n\n");
    while(!doubleStk.isEmpty2())
        cout << doubleStk.pop2() << " has been poped\n";
    puts("");
    doubleStk.traverse(visit);

    cout << "The First Stack is now " << (doubleStk.isEmpty1() ? "Empty" : "not Empty") << endl;
    cout << "The Second Stack is now " << (doubleStk.isEmpty2() ? "Empty" : "not Empty") << endl;
    return 0;
}