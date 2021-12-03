//(4). 以孩子—兄弟表示法作为树的存储结构，请设计算法求树的度

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

    int degree()
    {
        int ans = INT_MIN;
        dfs(this->root, ans);
        return ans;
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

    void dfs(Node<T>* node, int& ans)
    {
        auto cnt = 0;

        auto t = node->child;
        while(t)
        {
            cnt++;
            dfs(t, ans);
            t = t->bro;
        }

        ans = max(ans, cnt);
    }
};

int main(int argc, char const *argv[])
{
    Tree<int> tree(1);
    tree.root->child = new Node<int>({NULL, NULL, 2});
    tree.root->child->bro = new Node<int>({NULL, new Node<int>({NULL, NULL, 3}), 4});
    tree.root->child->child = new Node<int>({NULL, NULL, 5});
    tree.bfs();

    printf("Max Degree is: %d", tree.degree());
    return 0;
}
