#include <iostream>
using namespace std;

/*

key idea: coordinate (r, c) is on the (r + c - 2)-th diagonal 0-indexed, counted from the top-left
            r
    | 1 | 2 | 3 | 4
  --+---+---+---+---
  1 | 0 | 1 | 2 | 3
  --+---+---+---+---
c 2 | 1 | 2 | 3 | 4
  --+---+---+---+---
  3 | 2 | 3 | 4 | 5
  --+---+---+---+---
  4 | 3 | 4 | 5 | 6

*/

// fen[i][j] is the j-th index of the i-th Fenwick tree, maintained on the i-th diagonal

const int MN = 2005, MOD = 1e9+7;
int N;
long long fenwick[MN][MN];

// add v to the f-th fenwick tree and index n
void add(int f, int n, int v){
	for(int i = n; i < MN; i += i & -i)
		fenwick[f][i] += v;
}

// get the sum from index 1 to index n on the f-th fenwick tree
long long sum(int f, int n){
	long long result = 0;
	for(int i = n; i > 0; i -= i & -i)
		result += fenwick[f][i];
	return result;
}

int main(){
	cin >> N;
	long long ans = 0;

	for(int i = 0; i < N; i++){
		int type;
		cin >> type;
		if(type == 1){
			int r, c, t;
			cin >> r >> c >> t;

			int diag = r + c - 2;
			// add t to the diag-th Fenwick tree at index c
			add(diag, c, t);
		}
		else{ // type == 2
			int r, c, x;
			cin >> r >> c >> x;

			int diag = r + c - 2;
			int left = c, right = c + x; // get left and right bound of sum of the diag-th Fenwick tree

			// at the diag-th Fenwick tree, get the sum of the first "right" elements minus the sum of the first "left - 1"
			ans += sum(diag, right) - sum(diag, left - 1);

			ans %= MOD; // take modulo
		}
	}

	cout << ans;
}
