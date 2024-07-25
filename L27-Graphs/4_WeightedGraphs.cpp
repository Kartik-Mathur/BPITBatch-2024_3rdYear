#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;


template < typename T >
class Graph {
public :
	map<T, list<pair<T, int> > > adj;
	void addEdge(T u, T v, int dist, bool bidir = true) {
		adj[u].push_back({v, dist});
		if (bidir) {
			adj[v].push_back({u, dist});
		}
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << " --> ";
			for (auto p1 : p.second) {
				cout << "(" << p1.first << ", " << p1.second << ") ";
			}
			cout << endl;
		}
	}
};


int main() {

	Graph<string> g;

	g.addEdge("A", "B", 1);
	g.addEdge("C", "B", 2);
	g.addEdge("C", "D", 4);
	g.addEdge("A", "C", 5);
	g.addEdge("A", "D", 3);

	g.print();


	return 0;
}
















