#define _CRT_SECURE_NO_WARNINGS
#define MAX_V 2001
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// in order from left,
// vertex, edge, destination options, artist origin, the road passed
int v, e, t, s, g, h;
vector<pair<int, int>> graph[MAX_V];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	
	cin >> T;

	while (T--) {
		cin >> v >> e >> t;
		cin >> s >> g >> h;

		for (int i = 0; i < e; i++) {

		}
	}

	return 0;
}