//
// Created by Nigam, Neha on 11/2/19.
//

#include<iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
public:
    Graph(int v) : v(v) {
        adj = new list<int>[v];
    }

    void addEdge(int u , int v)
    {
        adj[u].push_back(v);
    }

    void containEdge(int u , int w , int k) {
        vector<bool> visited(v , false);
        int count = 0;
        int total = 0;

       DFSUtil(visited , u , w , k , count , total);
       cout<< "Total Number of paths are : " << total <<endl;

    }

    void DFSUtil(vector<bool> &visited , int src , int dest , int k , int count , int &total)
    {
        visited[src] = true;

        for(auto itr : adj[src]) {
            count++;
            if(!visited[itr]) {
                if (itr == dest && k == count)
                    total++;
                else {
                    DFSUtil(visited, itr, dest, k, count , total);
                    count--;
                    if(count < 0 )
                        count = 0;
                }
            }
            else if (itr == dest && k == count)
                total++;
        }
    }

    friend ostream &operator<<(ostream &os, const Graph &graph) {
        os << "v: " << graph.v << " adj: " << graph.adj;
        return os;
    }

private:
    int v;
    list<int> *adj;
};

int main(){
    Graph g(4);
    g.addEdge(0 , 1);
    g.addEdge(0 , 2);
    g.addEdge(0 , 3);
    g.addEdge(1, 3);
    g.addEdge(2 , 3);
    g.addEdge( 1, 2);
    int u = 1, w = 3, k = 2;
    g.containEdge(u , w , k);

}