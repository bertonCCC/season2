#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MN = 1e5+5;
// wherea[val] = the index i where arr[i] = val, similarly for whereb
int N, D, arr[MN], brr[MN], wherea[MN], whereb[MN];
int fen[MN], ans[MN]; // ans[i] will have the number of points in rectangle i, in the order of input given

struct event{
	// left edge = 0, point = 1, right edge = 2
	int type, x, y1, y2, idx;
};

void add(int n){
	for(int i = n; i < MN; i += i & -i)
		fen[i] += 1;
}

int sum(int n){
	int res = 0;
	for(int i = n; i > 0; i -= i & -i)
		res += fen[i];
	return res;
}

int sum(int l, int r){
	return sum(r) - sum(l - 1);
}

int main(){
	cin >> N >> D;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];
	for(int i = 1; i <= N; i++)
		cin >> brr[i];

	for(int i = 1; i <= N; i++)
		wherea[arr[i]] = i;
	for(int i = 1; i <= N; i++)
		whereb[brr[i]] = i;

	vector<event> events;

	for(int i = 1; i <= N; i++){
		// wherea[i], whereb[i] is a point
		int x = wherea[i], y = whereb[i];
		events.push_back({1, x, y, -1, -1});
	}

	for(int i = 0; i < D; i++){
		int x1, x2, y1, y2;
		cin >> x1 >> x2 >> y1 >> y2;
		events.push_back({0, x1, y1, y2, i});
		events.push_back({2, x2, y1, y2, i});
	}

	sort(events.begin(), events.end(), [] (event a, event b){
		// if(a.x == b.x) return a.type < b.type;
		// return a.x < b.x;
		return a.x < b.x || (a.x == b.x && a.type < b.type);
	});

	for(event e : events){
		if(e.type == 0){
			ans[e.idx] -= sum(e.y1, e.y2);
		}
		else if(e.type == 1){
			add(e.y1);
		}
		else{ // e.type == 2
			ans[e.idx] += sum(e.y1, e.y2);
		}
	}

	for(int i = 0; i < D; i++){
		if(ans[i] > 0) cout << "Y";
		else cout << "N";
	}
}
