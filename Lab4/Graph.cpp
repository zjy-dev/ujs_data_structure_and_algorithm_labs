#include<bits/stdc++.h>
using namespace std;

struct Edge
{   
    char idx;
    int weight;
    Edge* next;
};

struct Vertex{
    char idx;
    Edge* head;
};

unordered_map<char, Vertex*> graph;
unordered_map<char, bool> vis;

void init()
{
    vis.clear();
    auto A = new Vertex({'A', NULL});   
    auto B = new Vertex({'B', NULL});   
    auto C = new Vertex({'C', NULL});   
    auto D = new Vertex({'D', NULL});   
    auto E = new Vertex({'E', NULL});   
    auto F = new Vertex({'F', NULL});   
    auto G = new Vertex({'G', NULL});   
    auto H = new Vertex({'H', NULL});   
    auto I = new Vertex({'I', NULL});   
    A->head = new Edge({'B', 12, new Edge({'E', 9, new Edge({'C', 3, NULL})})});
    B->head = new Edge({'E', 6, new Edge({'D', 2, NULL})});
    C->head = new Edge({'F', 6, NULL});
    D->head = new Edge({'C', 2, new Edge({'E', 4, new Edge({'G', 5, NULL})})});
    E->head = new Edge({'F', 4, NULL});
    F->head = new Edge({'A', 10, new Edge({'D', 7, NULL})});
    G->head = new Edge({'B', 8, NULL});
    H->head = new Edge({'G', 12, new Edge({'I', 10, NULL})});
    graph['A'] = A;
    graph['B'] = B;
    graph['C'] = C;
    graph['D'] = D;
    graph['E'] = E;
    graph['F'] = F;
    graph['G'] = G;
    graph['H'] = H;
    graph['I'] = I;
}