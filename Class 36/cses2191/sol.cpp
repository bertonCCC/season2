#include <iostream>
#include <math.h>
using namespace std;

const int MN = 1005;
struct point{
	int x, y;
};
int N;
point pts[MN];

long long cross(point a, point b){
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}

int main(){
	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> pts[i].x >> pts[i].y;

	long long ans = 0;
	for(int i = 0; i < N; i++){
		ans += cross(pts[i], pts[(i + 1) % N]);
	}

	cout << abs(ans);
}
