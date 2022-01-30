#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> tii; // dist, node, level
typedef pair<int, int> pii; // edge
const int MN = 1e5+5, INF = 0x3f3f3f3f;
int N, M, type[MN], dist[MN][5];
vector<pii> adj[MN];

int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; i++)
		cin >> type[i];

	for(int i = 0; i < M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	priority_queue<tii, vector<tii>, greater<tii>> heap;
	memset(dist, 0x3f, sizeof dist);
	dist[1][0] = 0;
	heap.push({ 0, 1, 0 });

	while(!heap.empty()){
		auto [ d, u, level ] = heap.top();
		heap.pop();

		if(type[u] == level + 1){
			dist[u][level + 1] = dist[u][level];
			heap.push({ dist[u][level + 1], u, level + 1 });
		}

		for(auto [v, w] : adj[u]){
			if(dist[u][level] + w < dist[v][level]){
				dist[v][level] = dist[u][level] + w;
				heap.push({ dist[v][level], v, level });
			}
		}
	}

	int ans = INF;
	for(int i = 1; i <= N; i++)
		ans = min(ans, dist[i][4]);

	if(ans == INF)
		cout << "-1\n";
	else
		cout << ans << "\n";
}
