#include <iostream>
#include <vector>
using namespace std;

const int MN = 1e6+5;
int N, arr[MN], jumps[MN], ans[MN];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	for(int i = 0; i < N; i++)
		cin >> jumps[i];

	vector<int> next;
	for(int i = N - 1; i >= 0; i--){
		while(!next.empty() && arr[i] >= next.back())
			next.pop_back();

		if(jumps[i] > next.size())
			ans[i] = -1;
		else
			ans[i] = next[next.size() - jumps[i]];

		next.push_back(arr[i]);
	}

	for(int i = 0; i < N; i++)
		cout << ans[i] << " ";
}
