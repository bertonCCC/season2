#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

const int MN = 1e4+5;
int N, C, K, cherries[MN], totalC[MN], totalW[MN];
int ans = 0;
vector<pair<int, int>> adj[MN];

// totalC[u] = cherries[u] + sum(totalC[v])
// totalW[u] = <u -- parent(u)> + sum(totalW[v])

void dfs(int cur, int par, int parWeight){
	totalC[cur] = cherries[cur];
	totalW[cur] = parWeight;

	for(auto [to, weight] : adj[cur]){
		if(par == to) continue;
		dfs(to, cur, weight);
		totalC[cur] += totalC[to];
		totalW[cur] += totalW[to];
	}

	if(cur != 1 && totalC[cur] >= C && totalW[cur] <= K)
		++ans;
}

int main(){
	cin >> N >> C >> K;
	for(int i = 1; i <= N; i++)
		cin >> cherries[i];
	for(int i = 0; i < N - 1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dfs(1, -1, 0);
	cout << ans << '\n';
}
