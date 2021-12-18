#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

const int MN = 2e5+5, BS = 447;
struct query{
	int l, r, i;
};
int N, Q, distinct, arr[MN], sorted[MN], freq[MN], ans[MN];
query queries[MN];

void add(int ind){
	int val = arr[ind];
	if(freq[val] == 0)
		distinct += 1;
	freq[val] += 1;
}

void rem(int ind){
	int val = arr[ind];
	freq[val] -= 1;
	if(freq[val] == 0)
		distinct -= 1;
}

int main(){
	cin >> N >> Q;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		sorted[i] = arr[i];
	}

	sort(sorted, sorted + N);

	for(int i = 0; i < N; i++)
		arr[i] = lower_bound(sorted, sorted + N, arr[i]) - sorted;

	for(int i = 0; i < Q; i++){
		int l, r;
		cin >> l >> r;
		l -= 1; r -= 1;

		queries[i] = { l, r, i };
	}

	sort(queries, queries + Q, [] (query a, query b){
		if(a.l / BS == b.l / BS)
			return a.r < b.r;
		return a.l / BS < b.l / BS;
	});

	int wl = 0, wr = -1;
	for(int i = 0; i < Q; i++){
		int ql = queries[i].l, qr = queries[i].r;

		while(wl > ql){
			wl -= 1;
			add(wl); 
		}
		while(wr < qr){
			wr += 1;
			add(wr);
		}
		while(wl < ql){
			rem(wl);
			wl += 1;
		}
		while(wr > qr){
			rem(wr);
			wr -= 1;
		}

		ans[queries[i].i] = distinct;
	}

	for(int i = 0; i < Q; i++)
		cout << ans[i] << '\n';
}
