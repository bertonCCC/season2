#include <iostream>
#include <tuple>
using namespace std;

const int MN = 2e5+5;
int N, Q, seg[2 * MN];

void update(int n, int v){
	seg[n + N] = v;

	for(int i = (n + N) / 2; i > 0; i /= 2)
		seg[i] = min(seg[i * 2], seg[i * 2 + 1]);
}

int query(int l, int r){
	int result = 2e9;

	for(l += N, r += N; l <= r; l /= 2, r /= 2){
		if(l % 2 == 1) result = min(result, seg[l++]);
		if(r % 2 == 0) result = min(result, seg[r--]);
	}

	return result;
}

int main(){
	cin >> N >> Q;
	for(int i = 0; i < N; i++)
		cin >> seg[i + N];

	for(int i = N - 1; i > 0; i--)
		seg[i] = min(seg[i * 2], seg[i * 2 + 1]);

	for(int i = 0; i < Q; i++){
		int op;
		cin >> op;
		if(op == 1){
			int n, v;
			cin >> n >> v;
			n -= 1;
			update(n, v);
		}
		else{
			int l, r;
			cin >> l >> r;
			l -= 1; r -= 1;
			cout << query(l, r) << '\n';
		}
	}
}
