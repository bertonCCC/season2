#include <stdio.h>
#include <vector>
#include <tuple>
using namespace std;

const int MN = 1e5+5, MM = 2e5+5;
int N, M, deg[MN];
vector<pair<int, int>> adj[MN];
vector<int> path;
bool used[MM];

void dfs(int u){
	while(adj[u].size() > 0){
		int v, eid;
		tie(v, eid) = adj[u].back();
		if(used[eid]){
			adj[u].pop_back();
			continue;
		}

		used[eid] = true;
		adj[u].pop_back();
		dfs(v);
	}

	path.push_back(u);
}

int main(){
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
		deg[u] += 1;
		deg[v] += 1;
	}

	for(int i = 1; i <= N; i++){
		if(deg[i] % 2 == 1){
			printf("IMPOSSIBLE\n");
			return 0;
		}
	}

	dfs(1);

	if(path.size() < M + 1){
		printf("IMPOSSIBLE\n");
		return 0;
	}

	for(int n : path)
		printf("%d ", n);
}
