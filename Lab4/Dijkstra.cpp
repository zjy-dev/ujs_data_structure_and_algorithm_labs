// (3). 以邻接表为存储结构实现从源点到其余各顶点的最短路径的Dijkstra算法，要求输出最短路径及其长度
#include "Graph.cpp"

char st;
int n;
unordered_map<char, long long> dist;
unordered_map<char, vector<char>> path;
unordered_map<char, char> pre;

void printPath(char ed)
{
    if(dist[ed] == INT_MAX)
    {
        cout << ed << " isn't accessible from " << st << "\n\n";
        return;
    }
    printf("The Shortest Path(from %c to %c) is :\n", st, ed);
    stack<char> stk;
    auto t = ed;
    while(t != '$')
        stk.push(t), t = pre[t];
    cout << "    ";
    while(stk.size())
    {
        cout << stk.top() << " ", stk.pop();
        if(stk.size())
            printf("-> ");
    }
    puts("");
    printf("The Val of this Path is : %d\n", dist[ed]);
    puts("");
}

void Dijkstra()
{
    for(int i = 0; i < n; i++)
        dist['A' + i] = INT_MAX, pre['A' + i] = '$';
    dist[st] = 0;
    for(int i = 0; i < n; i++)
    {
        char t = '$';
        for(const auto& p : graph)
            if(!vis[p.first] and (t == '$' or dist[p.first] < dist[t]))
                t = p.first;
        vis[t] = true;
        for(auto edge = graph[t]->head; edge; edge = edge->next)
            if(!vis[edge->idx] and dist[edge->idx] > dist[t] + edge->weight)
                dist[edge->idx] = dist[t] + edge->weight, pre[edge->idx] = t;  
    }

    for(int i = 0; i < n; i++)
    {
        char ed = 'A' + i;
        printPath(ed);
    }
}   


int main(int argc, char const *argv[])
{
    init();
    n = graph.size();
    printf("Please Input the index of Source vertex\n");
    cin >> st;
    Dijkstra();
    return 0;
}
