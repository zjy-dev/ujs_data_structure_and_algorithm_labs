//(1). 二叉树采用二叉链表存储，编写计算二叉树最大宽度的算法(二叉树的最大宽度是指二叉树所有层中结点个数的最大值)

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

    int maxWidth()
    {
        auto ans = INT_MIN, temp = 0;
        queue<Node<T>*> q;
        q.push(root);

        Node<T>* curLast = root, *nextLast = NULL;
        while(q.size())
        {
            temp++;
            auto t = q.front();
            q.pop();
            
            if(t->left)
                nextLast = t->left, q.push(nextLast);
            
            if(t->right)
                nextLast = t->right, q.push(nextLast);
            

            if(t == curLast)
            {
                ans = max(ans, temp);
                temp = 0;
                curLast = nextLast;
            }
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
    cout << "Max Width is: " << tree.maxWidth() << endl;
}