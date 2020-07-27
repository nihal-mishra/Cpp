#include<iostream>
#include<vector>

using namespace std;

class Graph
{
    int V;
    vector<int> *adjList;
    bool *visited;
    public:
    Graph(int v)
    {
        V=v;
        adjList = new vector<int>[V];
        visited = new bool[V]{0};
    }

    void addEdge(int u, int v, bool bi=true)
    {
        adjList[u].push_back(v);
        if(bi)
            adjList[v].push_back(u);
    }

    void print_adjList()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<" -> ";
            for(int connected : adjList[i])
            {
                cout<<connected<<", ";
            }
            cout<<endl;
        }
    }

    bool CycleCheckDFS(int source, int parent)
    {
        visited[source]=true;
        cout<<source<<" ";
        for(int connection : adjList[source])
        {
            if(visited[connection] && connection!=parent)
            {
                return true;
            }
            if(!visited[connection])
            {
                CycleCheckDFS(connection,source);
            }
        }
        return false;
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
    cout<<"Checking for cycle using Depth First Search : "<<endl;
    if(graph1.CycleCheckDFS(0,0))
        cout<<"Cycle is there"<<endl;
    else
        cout<<"Cycle is not there"<<endl;
    cout<<endl;
    cout<<endl;
}