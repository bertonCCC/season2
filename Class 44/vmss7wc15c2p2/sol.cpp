#include <iostream>
using namespace std;

typedef long long int lli;
const int MN = 5e4+5, BASE = 12345, MOD = 1e9+7;
int N;
string temp, str = "#";
lli fhash[MN], rhash[MN], power[MN];

bool ispalin(int left, int right){
	if(left < 0 || right >= N) return false;

	lli forward, backward;
	if(left == 0) forward = fhash[right];
	else forward = (fhash[right] + MOD - fhash[left - 1] * power[right - left + 1] % MOD) % MOD;

	if(right == N - 1) backward = rhash[left];
	else backward = (rhash[left] + MOD - rhash[right + 1] * power[right - left + 1] % MOD) % MOD;

	return forward == backward;
}

int main(){
	cin >> N >> temp;

	for(int i = 0; i < N; i++)
		str += string{""} + temp[i] + "#";

	N = N * 2 + 1;

	fhash[0] = str[0];
	power[0] = 1;

	for(int i = 1; i < N; i++){
		fhash[i] = (fhash[i - 1] * BASE + str[i]) % MOD;
		power[i] = power[i - 1] * BASE % MOD;
	}

	rhash[N - 1] = str[N - 1];
	for(int i = N - 2; i >= 0; i--){
		rhash[i] = (rhash[i + 1] * BASE + str[i]) % MOD;
	}

	int best = 0, bestIdx = 0;

	for(int i = 0; i < N; i++){
		int left = 0, right = N, mid;
		while(left < right){
			mid = (left + right + 1) / 2;

			if(ispalin(i - mid, i + mid))
				left = mid;
			else
				right = mid - 1;
		}

		if(left > best){
			best = left;
			bestIdx = i;
		}
	}

	for(int i = bestIdx - best; i <= bestIdx + best; i++){
		if(str[i] != '#')
			cout << str[i];
	}
	cout << '\n' << best << '\n';
}
