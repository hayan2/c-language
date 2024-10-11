#define _CRT_SECURE_NO_WARNINGS
#define INF 1e9
#define MAX_V 2001
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// in order from left,
// vertex, edge, destination options, artist origin, the road passed
int V, E, t, s, g, h;

int sol(vector<pair<int, int>> *graph, int u, int v) {
	vector<int> ret(MAX_V, INF);
	priority_queue<pair<int, int>> heap;



	return ret[v];
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	
	cin >> T;

	while (T--) {
		vector<pair<int, int>> graph[MAX_V];
		cin >> V >> E >> t;
		cin >> s >> g >> h;
		int u, v, w;

		for (int i = 0; i < E; i++) {
			cin >> u >> v >> w;
			
			graph[u].push_back({ v, w });
			graph[v].push_back({ u, w });
		}
		
				
	}

	return 0;
}