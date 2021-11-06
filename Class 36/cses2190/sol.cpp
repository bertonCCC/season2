#ifdef LOCAL
	#define d(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
	#define d(...)
#endif
#include <stdio.h>
#include <algorithm>
using namespace std;
 
typedef long long int lli;
int T;
struct point{
	int x, y;
};
 
point operator + (point a, point b){ return { a.x + b.x, a.y + b.y }; }
point operator - (point a, point b){ return { a.x - b.x, a.y - b.y }; }
 
lli cross(point a, point b){
	return 1LL * a.x * b.y - 1LL * a.y * b.x;
}
 
// C++ 17 feature!
lli sgn(lli n){
	return clamp(n, -1LL, 1LL);
}
 
bool overlap(int a, int b, int c, int d){
	if(a > b) swap(a, b);
	if(c > d) swap(c, d);
	return max(a, c) <= min(b, d);
}
 
bool solve(){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	point a {x1, y1}, b {x2, y2}, c {x3, y3}, d {x4, y4};
	if(cross(b - a, c - a) == 0 && cross(c - a, d - a) == 0)
		return overlap(a.x, b.x, c.x, d.x) && overlap(a.y, b.y, c.y, d.y);
	else
		return sgn(cross(b - a, c - a)) != sgn(cross(b - a, d - a)) &&
		sgn(cross(d - c, a - c)) != sgn(cross(d - c, b - c));
}
 
int main(){
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
		printf(solve() ? "YES\n" : "NO\n");
}
