//1. 对于一个不带头结点的单链表，设计递归算法逆置所有结点

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* ne;
};

Node* reverse(Node* head)
{
    if(!head or !head->ne)
        return head;

    auto tail = head->ne;
    auto ans = reverse(head->ne);
    tail->ne = head;
    head->ne = NULL;
    return ans;
}


int main(int argc, char const *argv[])
{   
    auto head = new Node({1, new Node({2, new Node({3, new Node({4, NULL})})})});
    auto p = head;
    while(p)
    {
        cout << p->val << " ";
        p = p->ne;
    }
    puts("");
    head = reverse(head);
    p = head;
    while(p)
    {
        cout << p->val << " ";
        p = p->ne;
    }
}