#include <iostream>
#include <algorithm>
using namespace std;

const int MN = 2e5+5;
int N, Q, arr[MN], seg[4 * MN]; // or 524288

void build(int l, int r, int p){
	if(l == r) seg[p] = arr[l]; // or arr[r]
	else{
		int m = (l + r) / 2;
		build(l, m, p * 2);
		build(m + 1, r, p * 2 + 1);
		seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
	}
}

void update(int i, int v, int l, int r, int p){
	if(l == r) seg[p] = v;
	else{
		int m = (l + r) / 2;
		if(i <= m){ // i belongs in [l, m]
			update(i, v, l, m, p * 2);
		}
		else{ // i belongs [m + 1, r]
			update(i, v, m + 1, r, p * 2 + 1);
		}

		seg[p] = min(seg[p * 2], seg[p * 2 + 1]);
	}
}

int query(int ql, int qr, int l, int r, int p){
	int ZERO = 2e9;

	if(ql <= l && r <= qr){
		return seg[p];
	}
	else if(r < ql || l > qr){
		return ZERO;
	}
	else{
		int m = (l + r) / 2;
		int lres = query(ql, qr, l, m, p * 2);
		int rres = query(ql, qr, m + 1, r, p * 2 + 1);
		return min(lres, rres);
	}
}

int main(){
	cin >> N >> Q;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	build(1, N, 1);

	for(int i = 0; i < Q; i++){
		int optype;
		cin >> optype;
		if(optype == 1){
			int k, u;
			cin >> k >> u;
			update(k, u, 1, N, 1);
		}
		else{
			int a, b;
			cin >> a >> b;
			cout << query(a, b, 1, N, 1) << '\n';
		}
	}
}
