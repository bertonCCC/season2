#include <stdio.h>

const int MN = 1e5+5;
int N;
struct planet{
	int x, y, z, id;
};
struct edge{
	int id1, id2, wt;
};
planet plans[MN], orig[MN];

int dist(int id1, int id2){
	return min(
		abs(orig[id1].x - orig[id2].x),
		min(
			abs(orig[id1].y - orig[id2].y),
			abs(orig[id1].z - orig[id2].z)
		)
	)
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		plans[i] = { x, y, z, i };
	}

	for(int i = 0; i < N; i++)
		orig[i] = plans[i];

	vector<edge> edges;

	sort(plans, plans + N, [] (planet a, planet b){
		return a.x < b.x;
	});
	// Arrays.sort(plans, (planet a, planet b) -> a.x - b.x);
	for(int i = 0; i < N - 1; i++)
		edges.push_back({ plans[i].id, plans[i + 1].id, dist(plans[i].id, plans[i + 1].id)});

	sort(plans, plans + N, [] (planet a, planet b){
		return a.y < b.y;
	});
	for(int i = 0; i < N - 1; i++)
		edges.push_back({ plans[i].id, plans[i + 1].id, dist(plans[i].id, plans[i + 1].id)});

	sort(plans, plans + N, [] (planet a, planet b){
		return a.z < b.z;
	});
	for(int i = 0; i < N - 1; i++)
		edges.push_back({ plans[i].id, plans[i + 1].id, dist(plans[i].id, plans[i + 1].id)});

	sort(edges.begin(), edges.end(), [] (edge a, edge b){
		return a.wt < b.wt;
	});

	int num = 0;
	for(pair<int, int> p : edges){
		int p1, p2;
		tie(p1, p2) = p;

		
	}
}
