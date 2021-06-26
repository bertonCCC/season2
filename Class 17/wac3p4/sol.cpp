#include <stdio.h>

const int MN = 1e5+5;
int N, Q, deg[MN], par[MN];
bool seen[MN];
int comp;

int root(int cur){
	if(par[cur] == cur) return cur;
	else return par[cur] = root(par[cur]);
}

void join(int u, int v){
	int r = root(u), s = root(v);
	if(r == s) return;

	comp -= 1;
	par[r] = s;
}

int main(){
	int odds = 0, numSeen = 0;

	scanf("%d %d", &N, &Q);
	comp = N;
	for(int i = 1; i <= N; i++)
		par[i] = i;

	for(int i = 0; i < Q; i++){
		int a, b, x;
		scanf("%d %d %d", &a, &b, &x);
		x = x % 2;
		int aold = (deg[a] % 2 == 1), bold = (deg[b] % 2 == 1);
		deg[a] += x;
		deg[b] += x;
		int anew = (deg[a] % 2 == 1), bnew = (deg[b] % 2 == 1);
		odds += (anew - aold) + (bnew - bold);

		if(!seen[a]) numSeen += 1;
		if(!seen[b]) numSeen += 1;
		seen[a] = seen[b] = true;

		join(a, b);

		if((odds == 0 || odds == 2) && (numSeen + comp == N + 1))
			printf("YES\n");
		else
			printf("NO\n");
	}
}
