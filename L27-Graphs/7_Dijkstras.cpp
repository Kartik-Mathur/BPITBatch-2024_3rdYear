#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
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

	void dijkstras(T src, T des) {
		unordered_map<T, int> dist;
		unordered_map<T, T> parent;
		for (auto p : adj) dist[p.first] = INT_MAX;
		dist[src] = 0;
		parent[src] = src;
		set<pair<int, T> > s;

		s.insert({0, src});
		while (!s.empty()) {
			auto x = *s.begin();
			s.erase(s.begin());
			T pr = x.second;
			int pr_cd = x.first;
			for (auto p : adj[pr]) {
				T child = p.first;
				int edgeDist = p.second;
				if (dist[child] > dist[pr] + edgeDist) {
					// Merko child tak pahuchne ka chota raasta mill gaya
					// agar {dist[child],child} yeh set mei hai, toh delete karo,
					// because child tak pahuchne hai aur chota distance mill gaya hai
					auto f = s.find({dist[child], child});
					if (f != s.end()) {
						s.erase(f);
					}

					dist[child] = dist[pr] + edgeDist;
					s.insert({dist[child], child});
					parent[child] = pr;
				}
			}
		}

		cout << "Shortest distance from " << src << " to " << des << " : " << dist[des] << endl;
		while (des != parent[des]) {
			cout << des << "<--";
			des = parent[des];
		}
		cout  << des << endl;
	}
};


int main() {

	Graph<string> g;

	g.addEdge("A", "B", 1);
	g.addEdge("C", "B", 2);
	g.addEdge("C", "D", 3);
	g.addEdge("A", "C", 5);
	g.addEdge("A", "D", 8);

	g.dijkstras("A", "D");


	return 0;
}
















