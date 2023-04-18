#include <iostream>
#include <map>
#include <list>
using namespace std;


class Graph {
    public:
    	map<int, bool> visited;
    	map<int, list<int> > adj;
    	void addEdge(int v, int w){
        	adj[v].push_back(w);
        }

    	void DFS(int v){
        	visited[v] = true;
        	cout << v << " ";
        	list<int>::iterator i;
        	for (i = adj[v].begin(); i != adj[v].end(); ++i)
        		if (!visited[*i])
        			DFS(*i);
        }
};

int main(){
	Graph gtg;
	gtg.addEdge(0, 1);
	gtg.addEdge(0, 2);
	gtg.addEdge(1, 2);
	gtg.addEdge(2, 0);
	gtg.addEdge(2, 3);
	gtg.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
    " (starting from vertex 2) \n";
	gtg.DFS(2);

	return 0;
}
