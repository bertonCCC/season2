#include <iostream>
using namespace std;

const int MN = 1.5e5+5, MF = 2 * MN + 1;
int N, arr[MN], fen[MF], psa[MN];

void add(int n, int v){
	n += N + 1;
	for(int i = n; i < MF; i += i & -i)
		fen[i] += v;
}

int query(int n){
	n += N + 1;
	int sum = 0;
	for(int i = n; i > 0; i -= i & -i)
		sum += fen[i];
	return sum;
}

int main(){
	cin >> N;

	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	for(int i = 1; i <= N; i++){
		if(arr[i] == 1) arr[i] = +1;
		if(arr[i] == 2) arr[i] = -1;
	}

	for(int i = 1; i <= N; i++)
		psa[i] = psa[i - 1] + arr[i];

	// for each r, find the number of psa values so far that are less
	// than psa[r]
	long long int total = 0;
	for(int r = 0; r <= N; r++){
		total += query(psa[r] - 1);
		add(psa[r], 1);
	}

	cout << total << '\n';
}
