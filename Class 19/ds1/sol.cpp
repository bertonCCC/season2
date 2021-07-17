#include <iostream>
using namespace std;

const int MN = 1e5+5;
long long fen[MN], freqfen[MN];

void add(long long f[], int n, int v){
	for(int i = n; i < MN; i += i & -i)
		f[i] += v;
}

long long sum(long long f[], int n){
	long long res = 0;
	for(int i = n; i > 0; i -= i & -i)
		res += f[i];
	return res;
}

int main(){
	int N, M;
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		int val;
		cin >> val;

		add(fen, i, val);
		add(freqfen, val, 1);
	}

	for(int i = 0; i < M; i++){
		char ch;
		cin >> ch;
		if(ch == 'C'){
			int x, v;
			cin >> x >> v;

			int old = sum(fen, x) - sum(fen, x - 1);
			add(fen, x, v - old);

			add(freqfen, old, -1);
			add(freqfen, v, 1);
		}
		else if(ch == 'S'){
			int l, r;
			cin >> l >> r;

			cout << sum(fen, r) - sum(fen, l - 1) << '\n';
		}
		else{
			int v;
			cin >> v;
			cout << sum(freqfen, v) << '\n';
		}
	}
}
