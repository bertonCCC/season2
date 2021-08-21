#include <iostream>
#include <algorithm>
using namespace std;

struct two{
	int val, ind;
};

struct four{
	int left, right, atleast, ind;
};

const int MN = 1e5+5;
int N, Q, fen[MN], ans[MN]; // ans[i] is the answer to the i-th query
// in the order it was given in the input
two arr[MN];
four queries[MN];

void update(int ind, int val){
	ind += 1;
	for(int i = ind; i < MN; i += i & -i)
		fen[i] += val;
}

int query(int ind){
	ind += 1;
	int result = 0;
	for(int i = ind; i > 0; i -= i & -i)
		result += fen[i];
	return result;
}

int query(int left, int right){
	return query(right) - query(left - 1);
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		int n;
		cin >> n;
		arr[i] = {n, i};
	}

	sort(arr, arr + N, [] (two a, two b){
		return a.val > b.val;
	});

	// Arrays.sort(two, (a, b) -> b.val - a.val);

	cin >> Q;
	for(int i = 0; i < Q; i++){
		int l, r, q;
		cin >> l >> r >> q;
		queries[i] = {l, r, q, i};
	}

	sort(queries, queries + Q, [] (four a, four b){
		return a.atleast > b.atleast;
	});

	// j is the first index of array values yet to be added to the
	// Fenwick tree
	int j = 0;
	for(int i = 0; i < Q; i++){
		while(j < N && arr[j].val >= queries[i].atleast){
			update(arr[j].ind, arr[j].val);
			j += 1;
		}

		ans[queries[i].ind] = query(queries[i].left, queries[i].right);
	}

	for(int i = 0; i < Q; i++)
		cout << ans[i] << '\n';
}
