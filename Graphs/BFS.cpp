/*
Application of BFS :

1. Routing
2. Shortest Path (Unweighted Graph) and Minimum Spanning Tree for unweighted graph
3. Path Finding
4. Finding all nodes within one connected component
5. Dijkstra’s Single Source Shortest Path (Uses similar structure as BFS)

*/

#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph
{
    int V;
    list<int> *adjList;

    public:
    Graph(int v)
    {
        V = v;
        adjList = new list<int>[V];
    }

    void addEdge(int u,int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout<<i<<"->";
            for(int node: adjList[i])
            {
                cout<<node<<",";
            }
            cout<<endl;
        }
        
    }

    void bfs(int s)
    {
        queue<int> qu;
        bool *vis = new bool[V]{0};
        qu.push(s);
        vis[s]=true;

        while(!qu.empty())
        {
            int node = qu.front();
            cout<<node<<" ";
            qu.pop();
            for(auto neighbour : adjList[node])
            {
                if(!vis[neighbour])
                {
                    vis[neighbour]=true;
                    qu.push(neighbour);
                }
            }
        }
    }

};

int main()
{
    Graph graph1(5);
    graph1.addEdge(4,1);
    graph1.addEdge(0,1);
    graph1.addEdge(0,2);
    graph1.addEdge(0,3);
    graph1.addEdge(1,3);
    graph1.addEdge(3,2);
    
    //graph1.print();
    cout<<endl;
    graph1.bfs(0);
    cout<<endl;
}