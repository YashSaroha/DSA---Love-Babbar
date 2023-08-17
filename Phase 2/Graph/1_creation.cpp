#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// REPRESENTATION OF GRAPHS USING ADJACENCY LIST (MAPPING)

class graph {
    public:
        unordered_map<int, list<int> > adj ;

        void addEdge(int u, int v, bool direction) {
            // direction 0 -> undirected graph
            // direction 1 -> directed graph

            // create an edge between u and v
            adj[u].push_back(v);

            // if undirected, create edge between v and u also
            if(direction == 0)
            {
                adj[v].push_back(u);
            }
        }

        void printAdjList() 
        {
            for(auto i: adj) 
            {
                cout << i.first << " -> " ;
                for(auto j: i.second)
                {
                    cout << j << ", " ;
                }
                cout << endl;
            }
        }

};


int main()
{

    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges" << endl;
    cin >> m;
    
    graph g;

    // creating an undirected graph with m edges
    for(int i=0 ; i<m ; i++){
        int u , v;
        cin >> u >> v;
        g.addEdge(u , v , 0);
    }

    g.printAdjList();

}