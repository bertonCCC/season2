#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int MN = 1e5+5;
int N, M, curTime = 0, lowlink[MN], stamp[MN];
vector<int> adj[MN];
set<int> cut;
bool visited[MN];

void dfs(int cur, int par){
	visited[cur] = true;
	lowlink[cur] = stamp[cur] = curTime;
	++curTime;
	int children = 0;

	for(int to : adj[cur]){
		if(to == par) continue;

		if(visited[to]){ // forward or back edge
			lowlink[cur] = min(lowlink[cur], stamp[to]);
		}
		else{ // tree edge
			dfs(to, cur);
			++children;
			lowlink[cur] = min(lowlink[cur], lowlink[to]);
			if(cur != 1 && lowlink[to] >= stamp[cur])
				cut.insert(cur);
		}
	}

	if(cur == 1 && children > 1)
		cut.insert(cur);
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, -1);

	printf("%u\n", cut.size());
	for(int n : cut)
		printf("%d\n", n);
}
