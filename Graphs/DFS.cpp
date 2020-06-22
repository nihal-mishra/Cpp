#include<iostream>
#include<stack>
#include<list>
using namespace std;

class Graph
{
    int V;
    list<int> *adjList;
    bool *visited;

    public:
    Graph(int v)
    {
        V=v;
        adjList = new list<int>[V];
        visited = new bool[V]{0};
    }

    void addEdge(int u, int v, bool bi=true)
    {
        adjList[u].push_back(v);
        if(bi)
        {
            adjList[v].push_back(u);
        }
    }

    void print_adjList()
    {
        for(int i=0; i<V; i++)
        {
            cout<<i<<" -> ";
            for(int connection : adjList[i])
            {
                cout<<connection<<", ";
            }
            cout<<endl;
        }
    }

    void DFS(int source)
    {
        visited[source]=true;
        cout<<source<<" ";
        for(auto it = adjList[source].begin(); it!= adjList[source].end();it++)
        {
            if(!visited[*it])
                DFS(*it);
        }
    }

};

int main()
{
    Graph graph1(5);
    graph1.addEdge(0,1);
    graph1.addEdge(0,2);
    graph1.addEdge(1,3);
    graph1.addEdge(1,4);
    graph1.addEdge(3,4);
    cout<<endl;
    cout<<"Adjacency List Print : "<<endl;
    graph1.print_adjList();
    cout<<endl;
    cout<<"Depth First Search : "<<endl;
    graph1.DFS(0);
    cout<<endl;
    cout<<endl;
}