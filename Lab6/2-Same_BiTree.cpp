//2. 假设二叉树采用二叉链表存储结点，设计递归算法判断两棵二叉树是否同构

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
};

bool dfs(Node<int>* a, Node<int>* b)
{
    int cntNull = (a == NULL) + (b == NULL);
    if(cntNull == 1)
        return false;
    else if(cntNull == 2)
        return true;
    
    if(a->val != b->val)
        return false;
    return dfs(a->left, b->left) and dfs(a->right, b->right);
}

bool judge(const BiTree<int>& tree1, const BiTree<int>& tree2)
{
    return dfs(tree1.root, tree2.root);
}

int main(int argc, char const *argv[])
{
    BiTree<int> tree1(1);
    tree1.root->left = new Node<int>({2, 
    new Node<int>({4, NULL, NULL}), NULL});

    tree1.root->right = new Node<int>({3, 
    new Node<int>({6, NULL, NULL}), new Node<int>({7, 
    new Node<int>({15, NULL, NULL}), NULL})});
    tree1.bfs();

    BiTree<int> tree2(1);
    tree2.root->left = new Node<int>({2, 
    new Node<int>({4, NULL, NULL}), NULL});

    tree2.root->right = new Node<int>({3, 
    new Node<int>({6, NULL, NULL}), new Node<int>({7, 
    new Node<int>({15, NULL, NULL}), NULL})});
    tree2.bfs();

    auto ans = judge(tree1, tree2);
    if(ans)
        cout << "Tree1 = Tree2!!!";
    else
        cout << "Tree1 != Tree2!!!";
    return 0;
}