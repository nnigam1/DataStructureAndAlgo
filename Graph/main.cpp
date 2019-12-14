#include <iostream>
#include <list>
#include <vector>
using namespace std;

using namespace std;

class Graph {
public:
    Graph ( int v ) : V (v) {
        adj = new list<int>[V];
    }

    void addEdge ( int u, int v ) {
        adj[ u ] . push_back (v);
        adj[ v ] . push_back (u);
    }
    void AP();
    void APUtil(int u , vector<bool> &visited, vector<int> &parent ,vector<bool> &ap, vector<int> &disc,
            vector<int> &low);

private:
    int V;
    list<int> *adj;
};

void Graph::AP(){
    vector<bool> visited(V , false);
    vector<int> parent(V , -1);
    vector<bool> ap(V , false);
    vector<int> disc(V);
    vector<int> low(V);

    for( int i =0 ; i <V ; i++) {
        if( visited[i] == false) {
            APUtil(i , visited , parent , ap , disc , low);
        }
    }

    for(int i = 0 ; i <V ; i++)
    {
        if( ap[i] == true) {
            cout<<i <<" ";
        }
    }
    cout<<endl;
}

void
Graph::APUtil(int u, vector<bool> &visited, vector<int> &parent, vector<bool> &ap, vector<int> &disc, vector<int> &low) {

    static int time = 0;
    disc[u] = low[u] = ++time;
    visited[u] = true;
    int child = 0;

    for( auto itr : adj[u])
    {
        if(!visited[itr]){
            parent[itr] = u;
            child++;
            APUtil(itr , visited, parent , ap, disc, low);
            // this will only happen when no back edge from this u.
            // lowest discovery time achieved from u or the lowest discovery time
            // achieved from any of its child

            low[u] = min(low[u] , low[itr]);

            if(parent[u] == -1 && child > 1)
            {
                ap[u] = true;
            }

            if(parent[u] != -1 && low[itr] >= disc[u])
            {
                ap[u] = true;
            }

        }
        // this will only happen when there is a back edge,
        // lowest discovery time of u and disc time if its adjacent vertex.
        else if(parent[u] != itr)
        {
            low[u] = min( low[u] , disc[itr]);
        }
    }

}

int main () {
    std::cout << "Hello, World!" << std::endl;
    // Create graphs given in above diagrams
    cout << "\nArticulation points in first graph \n";
    Graph g1 (5);
    g1 . addEdge (1, 0);
    g1 . addEdge (0, 2);
    g1 . addEdge (2, 1);
    g1 . addEdge (0, 3);
    g1 . addEdge (3, 4);
    g1.AP();

    cout << "\nArticulation points in second graph \n";
    Graph g2 (4);
    g2 . addEdge (0, 1);
    g2 . addEdge (1, 2);
    g2 . addEdge (2, 3);
    g2.AP();

    cout << "\nArticulation points in third graph \n";
    Graph g3 (7);
    g3 . addEdge (0, 1);
    g3 . addEdge (1, 2);
    g3 . addEdge (2, 0);
    g3 . addEdge (1, 3);
    g3 . addEdge (1, 4);
    g3 . addEdge (1, 6);
    g3 . addEdge (3, 5);
    g3 . addEdge (4, 5);
    g3.AP();

    return 0;
}