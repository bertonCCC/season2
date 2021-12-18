// Warning: <iostream>/cin/cout may time out
// Java may also time out
// If this happens, try a different block size

#include <stdio.h>
using namespace std;

const int BS = 447, MN = 2e5+5;
int N, Q, pre[BS + 5][MN], arr[MN];

int query(int l, int r, int x){
	int count = 0, i;

	for(i = l; i % BS != 0 && i <= r; i++){
		if(arr[i] % x == 0)
			count += 1;
	}

	for(; i + BS < r; i += BS){
		count += pre[i/BS][x];
	}

	for(; i <= r; i++){
		if(arr[i] % x == 0)
			count += 1;
	}

	return count;
}

// add mult to pre[u/BS][x] for all factors x of v
void update(int u, int v, int mult){
	int b = u/BS;

	for(int i = 1; i * i <= v; i++){
		if(v % i == 0){
			pre[b][i] += mult;
			if(i * i != v)
				pre[b][v/i] += mult;
		}
	}
}

int main(){
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N; i++){
		scanf("%d", arr + i);
		update(i, arr[i], +1);
	}

	for(int i = 0; i < Q; i++){
		int type;
		scanf("%d", &type);

		if(type == 1){
			int l, r, x;
			scanf("%d %d %d", &l, &r, &x);
			--l; --r;

			printf("%d\n", query(l, r, x));
		}
		else{ // type == 2
			int u, v;
			scanf("%d %d", &u, &v);
			--u;

			update(u, arr[u], -1);
			arr[u] = v;
			update(u, arr[u], +1);
		}
	}
}
