#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* l, *r;
};

class BiSearchTree
{
public:
    Node* root;
    BiSearchTree(){}
    BiSearchTree(vector<int> arr)
    {
        this->root = new Node({arr[0], NULL, NULL});
        for(int i = 1; i < arr.size() - 1; i++)
            insert(root, arr[i]);
    }   

    void printTree()
    {
        cout << "Tree: " << endl;
        dfs(this->root);
        puts("");
    }

    void dfs(Node* root)
    {
        if(!root)
            return;
        dfs(root->l);
        cout << root->val << " ";
        dfs(root->r);
    }

    Node* insert(Node* root, int val)
    {
        if(!root)
        {
            root = new Node({val, NULL, NULL});
            return root;
        }
        
        if(root->val > val)
            root->l = insert(root->l, val);
        else
            root->r = insert(root->r, val);
    }

    Node* find(Node* root, int val)
    {
        if(!root)
            return NULL;
        if(root->val == val)
            return root;
        
        if(root->val < val)
            return find(root->r, val);
        else
            return find(root->l, val);
    }

    Node* getParent(Node* root, Node* p)
    {
        if(root->l == p or root->r == p)
            return root;
        if(p->val > root->val)
            return getParent(root->r, p);
        else
            return getParent(root->l, p);
    }

    Node* getMin(Node* root)
    {
        if(root->r)
            return getMin(root->l);
        
        return root;
    }

    void deleteElem(Node* root, int val)
    {
        auto p = find(root, val);
        auto parent = getParent(this->root, p);
        int cnt = !p->l + !p->r;
        if(cnt == 2)
            parent->l == p ? parent->l = NULL : parent->r = NULL;
        else if(cnt == 1)
        {
            if(parent->l == p)
                parent->l = (p->l ? p->l : p->r);
            else
                parent->r = (p->l ? p->l : p->r);
        }
        else
        {
            auto t = getMin(p->r);
            auto v = t->val;
            deleteElem(p->r, v);
            p->val = v;
        }
    }
};

void printUI()
{
    printf("1. 建立一棵二叉排序树\n");
    printf("2. 中序遍历，输出遍历结果\n");
    printf("3. 查找：输入一个关键字，进行查找\n");
    printf("4. 插入：输入一个关键字，进行插入\n");
    printf("5. 删除：输入一个关键字，进行删除\n");
    printf("6. 从大到小输出二叉排序树中所有关键字不小于x的数据元素\n");
}

int main(int argc, char const *argv[])
{
    printUI();
    int choice, t = 0, val;
    bool flag = true;
    BiSearchTree tree;
    vector<int> arr{39, 11, 68, 46, 75, 23, 71, 8, 86, 34, -1};
    while(flag)
    {
        cout << "\n请输入选择: " << endl;
        cin >> choice;
        switch(choice)
        {
        case 1:
            arr.clear();
            t = 0;
            while(t != -1)
            cin >> t, arr.push_back(t);
            tree = BiSearchTree(arr);
            break;
        case 2:
            tree.printTree();
            break;
        case 3:
            cout << "请输入要查找的元素:" << endl;
            cin >> val;
            if(tree.find(tree.root, val))
                cout << "找到!!!" << endl;
            else
                cout << "未找到!!!" << endl;
            break;
        case 4:
            cout << "请输入要插入的元素:" << endl;
            cin >> val;
            tree.insert(tree.root, val);
            tree.printTree();
            break;
        case 5:
            cout << "请输入要删除的元素:" << endl;
            cin >> val;
            tree.deleteElem(tree.root, val);
            tree.printTree();
            break;
        case 6:
            cout << "请输入x:" << endl;
            cin >> val;
            cout << val << " ";
            tree.dfs(tree.find(tree.root, val)->r);
            break;
        default:
            flag = false;
            break;
        }
    }

    cout << "欢迎使用!!!" << endl;
}