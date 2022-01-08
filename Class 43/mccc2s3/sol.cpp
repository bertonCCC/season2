#include <iostream>
using namespace std;

const int MN = 5e4+5, MK = 128;
int N, M, Q;
int par[MK][MN], rnk[MK][MN];

int findRoot(int k, int u){
	if(par[k][u] == u) return u;
	else return par[k][u] = findRoot(k, par[k][u]);
}

void add(int k, int u, int v){
	int r = findRoot(k, u), s = findRoot(k, v);
	if(r != s){
		if(rnk[k][r] > rnk[k][s])
			par[k][s] = r;
		else if(rnk[k][s] > rnk[k][r])
			par[k][r] = s;
		else{
			par[k][s] = r;
			rnk[k][r] += 1;
		}
	}
}

bool connected(int k, int u, int v){
	return findRoot(k, u) == findRoot(k, v);
}

int main(){
	cin >> N >> M >> Q;

	for(int k = 0; k < MK; k++)
		for(int i = 1; i <= N; i++)
			par[k][i] = i;

	for(int i = 0; i < M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		for(int k = 0; k < MK; k++){
			if((w | k) == k){
				add(k, u, v);
			}
		}
	}

	for(int i = 0; i < Q; i++){
		int u, v;
		cin >> u >> v;
		for(int k = 0; k < MK; k++){
			if(connected(k, u, v)){
				cout << k << '\n';
				break;
			}
		}
	}
}
