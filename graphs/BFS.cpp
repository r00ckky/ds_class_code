#include<iostream>
#include<vector>
#include<list>
using namespace std;


class Graph {
    private:
	    int V;
	    vector<list<int> > adj;
    public:
    	Graph(int V){
    	    this->V = V;
    	    adj.resize(V);
        }
    	void addEdge(int v, int w){
    	    adj[v].push_back(w);
        }   
    	void BFS(int s){
        	vector<bool> visited;
        	visited.resize(V, false);
        	list<int> queue;
        	visited[s] = true;
        	queue.push_back(s);

        	while (!queue.empty()) {
        		s = queue.front();
        		cout << s << " ";
        		queue.pop_front();
        		for (auto adjacent : adj[s]) {
        			if (!visited[adjacent]) {
        				visited[adjacent] = true;
        				queue.push_back(adjacent);
        			}
        		}
        	}
        }
};

int main()
{
	Graph gtg(4);
	gtg.addEdge(0, 1);
	gtg.addEdge(0, 2);
	gtg.addEdge(1, 2);
	gtg.addEdge(2, 0);
	gtg.addEdge(2, 3);
	gtg.addEdge(3, 3);
	cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
	gtg.BFS(2);
	return 0;
}
