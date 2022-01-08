#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string.h>
using namespace std;

const int MN = 6005, MK = 13;
long long N, Q, dist[MN], depth[MN], jump[MK][MN];
vector<pair<int, int>> adj[MN];

void dfs(int cur, int par){
	jump[0][cur] = par;

	for(auto [ch, wt] : adj[cur]){
		if(ch == par) continue;
		depth[ch] = depth[cur] + 1;
		dist[ch] = dist[cur] + wt;
		dfs(ch, cur);
	}
}

int lca(int u, int v){
	if(depth[u] > depth[v])
		swap(u, v);

	for(int k = MK - 1; k >= 0; k--)
		if(depth[v] - (1 << k) >= depth[u])
			v = jump[k][v];

	if(u == v) return u;

	for(int k = MK - 1; k >= 0; k--){
		if(jump[k][u] != jump[k][v]){
			u = jump[k][u];
			v = jump[k][v];
		}
	}

	return jump[0][u];
}

int main(){
	cin >> N;
	for(int i = 0; i < N - 1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	// fill jump[][] with -1
	memset(jump, -1, sizeof jump);

	dfs(0, -1);

	for(int k = 1; k < MK; k++)
		for(int u = 0; u < N; u++)
			if(jump[k - 1][u] != -1)
				jump[k][u] = jump[k - 1][ jump[k - 1][u] ];

	cin >> Q;

	for(int i = 0; i < Q; i++){
		int u, v;
		cin >> u >> v;

		int l = lca(u, v);
		cout << dist[u] + dist[v] - 2 * dist[l] << '\n';
	}
}
