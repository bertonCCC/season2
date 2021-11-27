#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MN = 1e5+5, MT = 127;
int N, K, pxa[MN];

int main(){
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> pxa[i];
		pxa[i] ^= pxa[i - 1];
	}

	map<int, int> freq;
	vector<int> M;

	for(long long i = K; i <= MT; i *= K)
		M.push_back(i);

	long long ans = 0;
	freq[0] = 1;
	for(int R = 1; R <= N; R++){
		for(int m : M){
			if(freq.count(m ^ pxa[R]))
				ans += freq[m ^ pxa[R]];
		}
		freq[pxa[R]] += 1;
	}

	cout << ans << '\n';
}
