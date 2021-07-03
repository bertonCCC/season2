#include <iostream>
#include <vector>
using namespace std;

const int MN = 4e5+5;
int N, sub[MN], value[MN];
vector<int> adj[MN];

void dfs(int u){
	sub[u] = value[u];
	for(int v : adj[u]){
		dfs(v);
		sub[u] += sub[v];
	}
}

int main(){
	cin >> N;
	for(int i = 0; i < N - 1; i++){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for(int i = 1; i <= N; i++)
		cin >> value[i];
	dfs(1);

	int ans = sub[1];
	for(int i = 2; i <= N; i++)
		ans = max(ans, sub[i]);
	cout << ans << '\n';
}
