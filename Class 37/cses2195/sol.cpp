#ifdef LOCAL
	#define d(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
	#define d(...)
#endif
#include <stdio.h>
#include <algorithm>
using namespace std;
 
typedef long long int lli;
const int MN = 2e5+5;
struct point{
	int x, y;
};
int N, H;
point pt[MN], hull[MN];
 
point operator - (point a, point b){
	return { a.x - b.x, a.y - b.y };
}
 
lli cross(point a, point b){
	return 1LL * a.x * b.y - 1LL * b.x * a.y;
}
 
lli cross(point a, point b, point c){
	return cross(b - a, c - a);
}
 
int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		pt[i] = {x, y};
	}
 
	sort(pt, pt + N, [] (point a, point b){
		return a.x < b.x || (a.x == b.x && a.y < b.y);
	});
 
	for(int k = 0; k < 2; k++){
		for(int i = k; i < N; i++){
			while(H >= 2 && cross(hull[H - 2], hull[H - 1], pt[i]) > 0)
				--H;
			hull[H++] = pt[i];
		}
		reverse(pt, pt + N);
	}
 
	printf("%d\n", H - 1);
	for(int i = 0; i < H - 1; i++)
		printf("%d %d\n", hull[i].x, hull[i].y);
}
