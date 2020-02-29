#include<iostream>
#include<list>
#include<stack>
#include<vector>
using namespace std;

class Graph{
public:
    int V;
    list<int> *adj;

    Graph(int x){
        V = x;
        adj = new list<int>[V];
    }

    void addEdge(int u , int v){
        adj[u].push_back(v);
    }

    void dfs(int start , vector<bool>& visited , stack<int>& stk) {
        if(visited[start])
            return;

        visited[start] = true;
        for( auto itr : adj[start]){
            if(!visited[itr]){
                dfs(itr , visited , stk);
            }
        }
        stk.push(start);
    }

    void topologicalSort(){
        vector<bool> visited(V , false);
        stack<int> stk;
        for(int i = 0 ; i < V ; i++) {
            if(!visited[i]) {
                dfs(i , visited , stk);
            }
        }

        while( !stk.empty()) {
            cout<<stk.top()<<" ";
            stk.pop();
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();
    return 0;
}
