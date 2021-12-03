// (2). 基于图的广度优先搜索策略写一个算法，判别以邻接表方式存储的有向图中是否存在由顶点vi到顶点vj的路径（i != j)
#include "Graph.cpp"

char ed;

bool bfs(char st)
{
    queue<char> q;
    q.push(st);
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        vis[t] = true;
        if(vis[ed])
            return true;
        for(auto edge = graph[t]->head; edge; edge = edge->next)
        {
            if(vis[edge->idx])
                continue;
            q.push(edge->idx);
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    init();
    char st;
    cout << "Please Input start and end idx: \n";
    cin >> st >> ed;
    if(st == ed)
    {
        cout << "Self-Loop!" << endl;
        return 0;
    }

    if(bfs(st))
        cout << ed << " is accessible from " << st << endl;
    else
        cout << ed << " isn't accessible from " << st << endl;
}