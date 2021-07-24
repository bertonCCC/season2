#include <iostream>
using namespace std;

const int MN = 2e5+5;
int N, M, Q, arr[MN];
long long seg[MN * 4], lazy[MN * 4];

void build(int l, int r, int p){
	if(l == r) seg[p] = arr[l];
	else{
		int m = (l + r) / 2;
		build(l, m, p * 2);
		build(m + 1, r, p * 2 + 1);
		seg[p] = seg[p * 2] + seg[p * 2 + 1];
	}
}

void updRange(long long v, int l, int r, int p){
	seg[p] += 1LL * v * (r - l + 1);
	if(l != r){
		lazy[p * 2] += v;
		lazy[p * 2 + 1] += v;
	}
}

void update(int ul, int ur, int v, int l, int r, int p){
	if(lazy[p] != 0){
		updRange(lazy[p], l, r, p);
		lazy[p] = 0;
	}

	if(ul <= l && r <= ur){
		updRange(v, l, r, p);
	}
	else if(r < ul || l > ur) return;
	else{
		int m = (l + r) / 2;
		update(ul, ur, v, l, m, p * 2);
		update(ul, ur, v, m + 1, r, p * 2 + 1);
		seg[p] = seg[p * 2] + seg[p * 2 + 1];
	}
}

long long query(int ql, int qr, int l, int r, int p){
	if(lazy[p] != 0){
		updRange(lazy[p], l, r, p);
		lazy[p] = 0;
	}

	if(ql <= l && r <= qr) return seg[p];
	else if(r < ql || l > qr) return 0;
	else{
		int m = (l + r) / 2;
		return query(ql, qr, l, m, p * 2) + query(ql, qr, m + 1, r, p * 2 + 1);
	}
}

int main(){
	cin >> M >> N >> Q;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	build(1, N, 1);

	for(int i = 0; i < Q; i++){
		int optype;
		cin >> optype;
		if(optype == 1){
			int l, r, x;
			cin >> l >> r >> x;
			update(l, r, x, 1, N, 1);
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << query(l, r, 1, N, 1) % M << '\n';
		}
	}
}
