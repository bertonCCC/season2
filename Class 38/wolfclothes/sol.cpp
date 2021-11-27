#include <iostream>
using namespace std;

const int MN = 1e5+5;
// wherea[val] = the index i where arr[i] = val
int N, D, arr[MN], brr[MN], wherea[MN], whereb[MN];

struct event{
	// 
	int type, x1, y1, y2;
};

int main(){
	cin >> N >> D;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	for(int i = 0; i < N; i++)
		cin >> brr[i];

	for(int i = 0; i < N; i++)
		wherea[arr[i]] = i;
	for(int i = 0; i < N; i++)
		whereb[brr[i]] = i;

	for(int i = 1; i <= N; i++){
		// wherea[i], whereb[i] is a point
	}
}
