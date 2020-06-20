#include<iostream>
#include<map>
#include<list>
using namespace std;

template <typename T>
class Graph
{
    map<T,list<T> > adjList;
    
    public:
    Graph(){}

    void addEdge(T u, T v, bool bi=true)
    {
        adjList[u].push_back(v);
        if(bi)
            adjList[v].push_back(u);
    }

    void print()
    {
        for(auto row : adjList)
        {
            cout<<row.first<<" -> ";
            for(auto ele : row.second)
                cout<<ele<<",";
            cout<<endl;
        }
    }

};

int main()
{
                //leh
        //amritsar
            //delhi
                    //kanpur
                //bhopal
            //mumbai

    Graph<string> city;
    city.addEdge("Leh","Amritsar");
    city.addEdge("Amritsar","Delhi");
    city.addEdge("Delhi","Kanpur");
    city.addEdge("Kanpur","Bhopal");
    city.addEdge("Delhi","Bhopal");
    city.addEdge("Delhi","Mumbai");
    city.addEdge("Mumbai","Bhopal");
    city.print();
}
