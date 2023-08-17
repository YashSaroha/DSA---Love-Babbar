#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

// Ek generic template bna skte hai ye line likh kr and typename kuch bhi daal skte hai
// main ke andr ab graph jb bnaege to data type specify krna pdega like   graph<int> g
// to ye template int type ki ho jayegi
template <typename Type>

// REPRESENTATION OF GRAPHS USING ADJACENCY LIST (MAPPING)

class graph {
    public:
    // int values ko change krke Type krdia...jo bhi datatype graph me specified hoga whi datatype apne aap aa jaega
        unordered_map <Type, list<Type> > adj ;

        void addEdge(Type u, Type v, bool direction) {
        
            adj[u].push_back(v);

            if(direction == 0)
                adj[v].push_back(u);
            
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
    
    graph<int> g;

    // creating an undirected graph with m edges
    for(int i=0 ; i<m ; i++){
        int u , v;
        cin >> u >> v;
        g.addEdge(u , v , 0);
    }

    g.printAdjList();

}