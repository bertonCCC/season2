#include <stdio.h>
#include <vector>
using namespace std;

const int MN = 2e5+5;
int N, M, stamp[MN], time;
vector<int> adj[MN];
bool vist[MN];

void dfs(int cur, int par){
	vist[cur] = true;
	stamp[cur] = time++;

	for(int to : adj[cur]){
		if(to == par) continue;

		if(!vist[to]){ // tree edge
			dfs(to, cur);
			printf("%d %d\n", to, cur);
		}
		else if(stamp[to] > stamp[cur]){ // forward edge
			printf("%d %d\n", to, cur);
		}
	}
}


int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i = 1; i <= N; i++)
		if(!vist[i])
			dfs(i, -1);
}
