#include <stdio.h>
#include <vector>
using namespace std;

const int MN = 2005;
int N, M, A, B;
vector<int> adj[MN];
bool vist[MN];

void dfs(int cur){
	vist[cur] = true;
	// set up cur

	for(int to : adj[cur]){
		if(vist[to]) continue;

		// do things before you go in
		dfs(to);
		// do things after you come back
	}
}

int main(){
	scanf("%d %d %d %d", &N, &M, &A, &B);
	for(int i = 0; i < M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(A);
	if(vist[B]) printf("GO SHAHIR!\n");
	else printf("NO SHAHIR!\n");
}
