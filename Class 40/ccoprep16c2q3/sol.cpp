#include <iostream>
using namespace std;

const int MN = 2e5+5, BS = 512;
int N, Q, power[MN], jumps[MN], where[MN];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> power[i];

	// pre-compute jumps[i] and where[i]
	for(int i = N - 1; i >= 0; i--){
		if(i + power[i] >= i/BS*BS + BS || i + power[i] >= N){
			jumps[i] = 1;
			where[i] = i + power[i];
		}
		else{
			jumps[i] = jumps[i + power[i]] + 1;
			where[i] = where[i + power[i]];
		}
	}

	cin >> Q;
	for(int j = 0; j < Q; j++){
		int type;
		cin >> type;
		if(type == 1){
			int x;
			cin >> x;

			int total = 0;
			while(x < N){
				total += jumps[x];
				x = where[x];
			}

			cout << total << '\n';
		}
		else{ // type == 2
			int x, v;
			cin >> x >> v;

			power[x] = v;
			int left = x/BS*BS, right = min(left + BS - 1, N - 1);

			for(int i = right; i >= left; i--){
				if(i + power[i] >= i/BS*BS + BS || i + power[i] >= N){
					jumps[i] = 1;
					where[i] = i + power[i];
				}
				else{
					jumps[i] = jumps[i + power[i]] + 1;
					where[i] = where[i + power[i]];
				}
			}
		}
	}
}
