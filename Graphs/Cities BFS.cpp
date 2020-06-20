#include<iostream>
#include<map>
#include<queue>
#include<list>

using namespace std;

template <typename T>
class Graph
{
    map<T,list<T> > adjList;
    public:
    Graph(){}

    void addEdge(T u,T v, bool bi=true)
    {
        adjList[u].push_back(v);
        if(bi)
            adjList[v].push_back(u);
    }

    int NoOfVertices()
    {
        int count=0;
        for(auto ele : adjList)
        {
            ++count;
        }
        return count;
    }

    void print()
    {
        for(auto node : adjList)
        {   
            cout<<node.first<<" -> ";
            for(auto neigh : node.second)
            {
                cout<<neigh<<", ";
            }
            cout<<endl;
        }
    }

    void bfs(T source)
    {
        queue<T> qu;
        int v = NoOfVertices();
        map<T,bool> visited;
        for(auto city : adjList)
        {
            visited[city.first]=false;
        }
        qu.push(source);
        visited[source]=true;
        while(!qu.empty())
        {
            T node = qu.front();
            cout<<node<<" ";
            qu.pop();
            for(auto neighbour : adjList[node])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    qu.push(neighbour);
                }
            }
        }
    }

};

int main()
{
    Graph<string> cities;
    cities.addEdge("Leh","Amritsar");
    cities.addEdge("Amritsar","Delhi");
    cities.addEdge("Delhi","Kanpur");
    cities.addEdge("Kanpur","Bhopal");
    cities.addEdge("Delhi","Bhopal");
    cities.addEdge("Delhi","Mumbai");
    cities.addEdge("Mumbai","Bhopal");
    cities.addEdge("Mumbai","Banglore");
    cities.addEdge("Bhopal","Banglore");
    cities.print();
    cout<<endl;
    cout<<"\t\tBFS\n";
    cities.bfs("Leh");
    cout<<endl;
    
}