#include <iostream>
#include <vector>
using namespace std;
typedef long long int lli;

const int MN = 1e5+5, MOD = 1e9+7;
int N, M, tot[MN], num[MN];
bool in[MN];
vector<int> adj[MN];

void dfs(int u){
	if(num[u]) return;

	if(adj[u].size() == 0)
		num[u] = 1;

	for(int v : adj[u]){
		dfs(v);
		tot[u] = (0LL + tot[u] + tot[v] + num[v]) % MOD;
		num[u] = (num[u] + num[v]) % MOD;
	}
}

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		in[b] = true;
	}

	int ans = 0;

	for(int i = 1; i <= N; i++){
		dfs(i);
		if(!in[i]){
			dfs(i);
			ans = (ans + tot[i]) % MOD;
		}
	}

	cout << ans << '\n';
}
