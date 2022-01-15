// THIS IS INCOMPLETE

#include <iostream>
using namespace std;

bool ispalin(int left, int right){
	int forward = fhash[right] - fhash[left - 1] * pow[right - left + 1];
	int backward = rhash[left] - rhash[right + 1] * pow[right - left + 1];
	return forward == backward;
}

int main(){
	int N;
	string temp, str = "#";
	
	cin >> N >> temp;

	for(int i = 0; i < N; i++)
		str += string{""} + temp[i] + "#";

	cerr << str;

	fhash[0] = str[0];
	pow[0] = 1;

	for(int i = 1; i < N; i++){
		fhash[i] = (fhash[i - 1] * BASE + str[i]) % MOD;
		pow[i] = pow[i - 1] * BASE % MOD;
	}

	rhash[N - 1] = str[N - 1];
	for(int i = N - 2; i >= 0; i--){
		rhash[i] = (rhash[i + 1] * BASE + str[i]) % MOD;
	}

	int best = 0, bestIdx = 0;

	for(int i = 0; i < 2 * N + 1; i++){
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

	cout << best << '\n';
	for(int i = bestIdx - best; i <= bestIdx + best; i++){
		if(str[i] != '#')
			cout << str[i];
	}
}
