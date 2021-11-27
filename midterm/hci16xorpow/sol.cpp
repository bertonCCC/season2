#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int MN = 1e5+5, MT = 127;
int N, K, arr[MN];

int main(){
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		arr[i] ^= arr[i - 1];
	}

	map<int, int> freq;
	vector<int> diff;

	for(long long i = K; i <= MT; i *= K)
		diff.push_back(i);

	long long ans = 0;
	for(int i = 0; i <= N; i++){
		for(int n : diff){
			if(freq.count(n ^ arr[i]))
				ans += freq[n ^ arr[i]];
		}
		++freq[arr[i]];
	}

	cout << ans << '\n';
}
