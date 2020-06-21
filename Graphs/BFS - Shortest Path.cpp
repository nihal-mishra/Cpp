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
        V=v;
        adjList = new list<int>[V];
    }

    void addEdge(int u, int v, bool bi=true)
    {
        adjList[u].push_back(v);
        if(bi)
            adjList[v].push_back(v);
    }

    void print()
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

    void bfs(int source, int destination)
    {
        queue<int> qu;
        int *parent = new int[V]{-1};
        bool *visited = new bool[V]{0};
        int *distance = new int[V]{0};
        qu.push(source);
        visited[source]=true;
        parent[source]=-1;

        while (!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            for(int neighbour : adjList[node])
            {
                if(!visited[neighbour])
                {
                    qu.push(neighbour);
                    visited[neighbour]=true;
                    distance[neighbour]=distance[node]+1;
                    parent[neighbour]=node;
                }
            }
        }
        //Distances from source to that node;
        for(int i=0;i<V;i++)
        {
            cout<<i<<" --Distance-> "<<distance[i]<<endl;
        }
        
        //Shortest Distance from source to destination
        cout<<"\nShortest Distance from "<<source<<" to "<<destination<<" :- "<<distance[destination]<<endl;

        //Shortest path from source to destination
        int temp=destination;
        while(temp!=-1)
        {
            cout<<temp;
            if(parent[temp]!=-1)
            {
               cout<<" <-- ";
            }
            temp=parent[temp];
        }
        cout<<endl;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(3,2);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);
	g.bfs(0,5);
}