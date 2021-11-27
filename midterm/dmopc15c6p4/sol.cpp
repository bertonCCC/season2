#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

const int MN = 1e5+5;
// weight, node1, node2 (will sort by weight first)
vector<tuple<int, int, int>> edges;
int N, K, dsu[MN];

int findRoot(int u){
	if(dsu[u] == u) return u;
	return dsu[u] = findRoot(dsu[u]);
}

int main(){
	cin >> N >> K;
	for(int i = 1; i <= N - 1; i++){
		int wt;
		cin >> wt;
		edges.push_back({wt, i, i + 1});

		if(i + K <= N)
			edges.push_back({0, i, i + K});
	}

	for(int i = 1; i <= N; i++)
		dsu[i] = i;

	sort(edges.begin(), edges.end());

	int count = 0, sum = 0;
	for(auto [wt, u, v] : edges){
		int r = findRoot(u), s = findRoot(v);

		if(r == s) continue;

		count += 1;
		sum += wt;
		dsu[r] = s;

		if(count == N - 1) break;
	}

	cout << sum;
}
