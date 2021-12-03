//(3). 树以孩子兄弟链表为存储结构，请设计算法求树的深度

#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Node
{
    Node* child, *bro;
    T val;
};

template<class T>
class Tree
{
public:
    Node<T>* root;
public:

    Tree(T val)
    {
        this->root = new Node<T>({NULL, NULL, val});
    }

    int maxDepth()
    {
        return dfs(this->root);
    }

    void bfs()
    {
        queue<Node<T>*> q;
        q.push(this->root);
        cout << "Breath First Search Result:\n";
        Node<T>* curLast = root, *nextLast = NULL;
        while(q.size())
        {
            auto t = q.front();
            q.pop();

            printf("%d ", t->val);
            auto p = t->child;
            while(p)
            {
                q.push(p);
                nextLast = p;
                p = p->bro;
            }

            if(t == curLast)
            {
                puts("");
                curLast = nextLast;
            }
        }

        puts("");
    }


    int dfs(Node<T>* node)
    {
        if(!node)
            return 0;
        auto t = node->child;
        auto ans = 0;
        while(t)
        {
            ans = max(ans, dfs(t));
            t = t->bro;
        }

        return ans + 1;
    }
};

int main(int argc, char const *argv[])
{
    Tree<int> tree(1);
    tree.root->child = new Node<int>({NULL, NULL, 2});
    tree.root->child->bro = new Node<int>({NULL, NULL, 3});
    tree.root->child->child = new Node<int>({NULL, NULL, 4});
    tree.bfs();
    cout << "Max Depth is: " << tree.maxDepth() << endl;
}