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

	void bfs(T src) {
		unordered_map<T, bool> visited;
		queue<T> q;

		q.push(src);
		visited[src] = true;
		while (!q.empty()) {
			auto pr = q.front();
			q.pop();
			cout << pr << " ";
			for (auto ch : adj[pr]) {
				if (!visited[ch]) {
					q.push(ch);
					visited[ch] = true;
				}
			}
		}

		cout << endl;
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
	g.bfs('A');


	/*
	Graph<string> g;

	g.addEdge("Putin", "Modi", false);
	g.addEdge("Putin", "Trump", false);
	g.addEdge("Putin", "Pope", false);
	g.addEdge("Trump", "Modi"); // By default bidirectional edge hai
	g.addEdge("Yogi", "Modi"); // By default bidirectional edge hai
	g.addEdge("Prabhu", "Modi", false);
	g.addEdge("Yogi", "Prabhu", false);

	g.print();
	*/

	/*
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(0, 2);
	g.addEdge(2, 1);
	g.addEdge(2, 3);

	g.print();
	*/




	return 0;
}
















