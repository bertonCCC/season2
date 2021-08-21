#include <iostream>
#include <vector>
using namespace std;

const int MN = 1e5+5;
int N, M, longest[MN];
vector<int> adj[MN];

void dfs(int u){
	if(longest[u] != -1) return;

	longest[u] = 0;
	for(int v : adj[u]){
		dfs(v);
		longest[u] = max(longest[u], longest[v] + 1);
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int u, v;
		cin >> u >> v;

		adj[u].push_back(v);
	}

	for(int i = 1; i <= N; i++)
		longest[i] = -1;

	for(int i = 1; i <= N; i++)
		dfs(i);

	int ans = 0;
	for(int i = 1; i <= N; i++)
		ans = max(ans, longest[i]);

	cout << ans;
}
