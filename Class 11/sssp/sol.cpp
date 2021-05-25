#include <stdio.h>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

typedef pair<int, int> pii;
const int MN = 1001;
int N, M, dist[MN];
vector<pii> adj[MN];

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < M; i++){
		int u, v, wt;
		scanf("%d %d %d", &u, &v, &wt);
		adj[u].push_back({v, wt});
		adj[v].push_back({u, wt});
	}

	priority_queue<pii, vector<pii>, greater<pii>> heap;
	for(int i = 2; i <= N; i++)
		dist[i] = 20 * 1000 * 1000;
	heap.push({0, 1});

	while(!heap.empty()){
		int cur = heap.top().second;
		heap.pop();

		for(auto [to, wt] : adj[cur]){
			if(dist[cur] + wt < dist[to]){
				dist[to] = dist[cur] + wt;
				heap.push({dist[to], to});
			}
		}
	}

	for(int i = 1; i <= N; i++){
		if(dist[i] < 20 * 1000 * 1000)
			printf("%d\n", dist[i]);
		else
			printf("-1\n");
	}
}
