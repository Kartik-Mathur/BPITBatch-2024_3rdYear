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

	void dfsHelper(T src, unordered_map<T, bool> &visited) {
		cout << src << " ";
		visited[src] = true;
		for (auto ch : adj[src]) {
			if (!visited[ch])
				dfsHelper(ch, visited);
		}
	}

	void dfs() {
		unordered_map<T, bool> visited;
		int component = 0;
		for (auto p : adj) {
			if (!visited[p.first]) {
				dfsHelper(p.first, visited);
				component++;
			}
		}
		cout << "\nNumber of components: " << component;
	}
};

int main() {

	Graph<char> g;
	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('D', 'C');
	g.addEdge('E', 'C');
	g.addEdge('D', 'B');

	g.addEdge('X', 'Y');
	g.addEdge('Z', 'Y');

	// g.print();
	g.dfs();




	cout << endl;
	return 0;
}
















