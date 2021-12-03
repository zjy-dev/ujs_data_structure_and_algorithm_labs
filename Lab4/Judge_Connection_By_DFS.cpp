// (1). 基于图的深度优先搜索策略写一个算法，判别以邻接表方式存储的有向图中是否存在由顶点vi到顶点vj的路径（i != j)
#include "Graph.cpp"

char ed;

bool dfs(char st)
{
    vis[st] = true;
    if(vis[ed])
        return true;
    for(auto edge = graph[st]->head; edge; edge = edge->next)
    {
        if(vis[edge->idx])
            continue;
        if(dfs(edge->idx))  
            return true;
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

    if(dfs(st))
        cout << ed << " is accessible from " << st << endl;
    else
        cout << ed << " isn't accessible from " << st << endl;
}