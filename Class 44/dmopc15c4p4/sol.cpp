#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long int lli;

const int MN = 1e5+5;
int N, K, Q, arr[MN];
lli psa[MN];
unordered_map<int, vector<int>> occur;

bool exists(int l, int r, int val){
	int first = lower_bound(occur[val].begin(), occur[val].end(), l) - occur[val].begin();
	return first < occur[val].size() && occur[val][first] <= r;
}

int main(){
	cin >> N >> K >> Q;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		occur[arr[i]].push_back(i);
		psa[i] = psa[i - 1] + arr[i];
	}

	for(int i = 0; i < Q; i++){
		int l, r, a, b;
		cin >> a >> b >> l >> r;

		if(psa[r] - psa[l - 1] > K && exists(l, r, a) && exists(l, r, b))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}
