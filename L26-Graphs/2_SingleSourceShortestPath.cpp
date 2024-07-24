#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
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

	void SSSP(T src, T des) {
		unordered_map<T, bool> visited;
		unordered_map<T, int> distance;
		unordered_map<T, T> parent;
		queue<T> q;

		q.push(src);
		distance[src] = 0;
		parent[src] = src;
		visited[src] = true;
		while (!q.empty()) {
			auto pr = q.front();
			q.pop();

			for (auto ch : adj[pr]) {
				if (!visited[ch]) {
					q.push(ch);
					visited[ch] = true;
					parent[ch] = pr;
					distance[ch] = distance[pr] + 1;
				}
			}
		}

		cout << "Shortest distance from " << src << " to " << des << " : " << distance[des] << endl;
		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout  << des << endl;

	}
};

int main() {

	Graph<char> g;
	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('D', 'C');
	g.addEdge('E', 'C');
	g.addEdge('D', 'B');

	// g.print();
	g.SSSP('A', 'D');






	return 0;
}
















