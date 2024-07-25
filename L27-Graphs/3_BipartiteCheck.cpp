#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;
template<typename T>
class Graph {
public:
	unordered_map<T, list<T> > adj;

	void addEdge(T u, T v, bool bidir = true) {
		adj[u].push_back(v);
		if (bidir) adj[v].push_back(u);
	}

	void print() {
		for (auto p : adj) {
			cout << p.first << " : ";
			for (auto neighbour : p.second) {
				cout << neighbour << ", ";
			}
			cout << endl;
		}
	}

	bool bipartiteHelper(T src, T parent, int color[], int c = 1) {
		// code
		// current node par color fill kardo
		color[src] = c;
		for (auto child : adj[src]) {
			if (color[child] == 0) {
				bool kyaChotaGraphBipartiteHai = bipartiteHelper(child, src, color, 3 - c);
				if (kyaChotaGraphBipartiteHai == false) {
					return false;
				}
			}
			else if (child != parent and c == color[child]) {
				return false;
			}
		}

		return true;
	}

	bool bipartite() {
		// every index represents the node, and all nodes have default color 0
		// this simply means meine abhi tak kisi node par color nahi kia
		int color[100000] = {0};

		for (auto p : adj) {
			if (color[p.first] == 0) {
				bool ans = bipartiteHelper(p.first, -1, color);
				if (!ans) return false;
			}
		}

		return true;
	}


};

int main() {

	Graph<char> g;
	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('A', 'D');
	g.addEdge('D', 'C');
	g.addEdge('E', 'C');
	g.addEdge('D', 'B');

	g.addEdge('X', 'Y');
	g.addEdge('X', 'Z');


	bool x = g.bipartite();
	if (x)cout << "Bipartite\n";
	else cout << "Not Bipartite\n";




	cout << endl;
	return 0;
}
















