#include<iostream>
#include<list>
#include<queue>
using namespace std;

template <typename T>
class Graph
{
    T V;
    list<T> *adjList;

    public:
    Graph(T v)
    {
        V=v;
        adjList = new list<T>[V];
    }

    void addEdge(T u, T v, bool bi = true)
    {
        adjList[u].push_back(v);
        if(bi)
            adjList[v].push_back(u);
    }

    void bfs(int source, int destination)
    {
        queue<T> qu;
        bool *visited = new bool[V]{0};
        int *parent= new int[V]{-1};
        int *distance =  new int[V]{0};
        distance[source]=0;
        parent[source]=-1;
        qu.push(source);
        visited[source]=true;
        
        while(!qu.empty())
        {
            T node = qu.front();
            qu.pop();

            for(auto neighbour : adjList[node])
            {
                if(!visited[neighbour])
                {
                    qu.push(neighbour);
                    distance[neighbour]=distance[node]+1;
                    parent[neighbour]=node;
                    visited[neighbour]=true;
                }
            }
        }

        cout<<"\nMinimum No. of steps required to finish : "<<distance[destination]<<endl;

        int temp=destination;
        while (temp!=parent[source])
        {
            cout<<temp;
            if(parent[temp]!=parent[source])
            {
                cout<<" <-- ";
            }
            temp = parent[temp];
        }
    }
};

int main()
{
    int board[42] = {0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    Graph graph1(42);

    for(int u=0; u<36; u++)
    {
        for(int dice=1;dice<=6;dice++)
            {
                int v = u + dice + board[u+dice];
                graph1.addEdge(u,v,false);
            }
    }
    graph1.bfs(0,36);
    cout<<endl;

}