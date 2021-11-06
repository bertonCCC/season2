#include <iostream>
using namespace std;

struct point{
	int x, y;
};

int T;

point sub(point a, point b){
//point operator - (point a, point b){
	return {a.x - b.x, a.y - b.y};
}

long long cross(point a, point b){
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

void solve(){
	int p1x, p1y, p2x, p2y, p3x, p3y;
	cin >> p1x >> p1y >> p2x >> p2y >> p3x >> p3y;

	point p1 = {p1x, p1y}, p2 = {p2x, p2y}, p3 = {p3x, p3y};

	point p1p2 = sub(p2, p1), p1p3 = sub(p3, p1);
	//point p1p2 = p2 - p1, p1p3 = p3 - p1;

	long long prod = cross(p1p2, p1p3);

	if(prod > 0)
		cout << "LEFT";
	else if(prod < 0)
		cout << "RIGHT";
	else
		cout << "TOUCH";

	cout << "\n";
}

void clean(){

}

int main(){
	cin >> T;
	for(int i = 0; i < T; i++){
		solve();
		clean();
	}
}
