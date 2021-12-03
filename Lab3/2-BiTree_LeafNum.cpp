//(2). 以二叉链表作存储结构，设计算法求二叉树中叶子结点的数目

#include<bits/stdc++.h>
using namespace std;

template <class T>
struct Node
{
    T val;
    Node* left, *right;
};

template <class T>
class BiTree
{
public:
    Node<T> *root;

public:
    BiTree(T val)
    {
        this->root = new Node<T>({val, NULL, NULL});
    }

    void bfs()
    {
        queue<Node<T>*> q;
        q.push(root);
        Node<T>* curLast = root, *nextLast = NULL;
        cout << "Breath First Search Result:\n";
        while(q.size())
        {
            Node<T>* t = q.front();
            q.pop();
            cout << t->val << " ";

            if(t->left)
                q.push(t->left), nextLast = t->left;
            
            if(t->right)
                q.push(t->right), nextLast = t->right;
            
            if(t == curLast)
                puts(""), curLast = nextLast;
        }

        puts("");
    }

    int leafNum()
    {
        auto ans = 0;
        queue<Node<T>*> q;
        q.push(root);

        while(q.size())
        {
            auto t = q.front();
            q.pop();
            
            if(!t->left and !t->right)
            {
                ans++;
                continue;
            }

            if(t->left)
                q.push(t->left);
            
            if(t->right)
                q.push(t->right);
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    BiTree<int> tree(1);
    tree.root->left = new Node<int>({2, 
    new Node<int>({4, NULL, NULL}), NULL});
    
    tree.root->right = new Node<int>({3, 
    new Node<int>({6, NULL, NULL}), new Node<int>({7, 
    new Node<int>({15, NULL, NULL}), NULL})});

    tree.bfs();
    cout << "Leaf Num is: " << tree.leafNum() << endl;
}