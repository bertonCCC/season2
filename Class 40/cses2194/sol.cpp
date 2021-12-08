#include <math.h>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

const int MN = 2e5+5, INF = 1e9+5;
struct point{
	int x, y;
};
int N;
point pts[MN];

long long dist_sq(point a, point b){
	return 1LL*(a.x - b.x)*(a.x - b.x) + 1LL*(a.y - b.y)*(a.y - b.y);
}

bool operator < (point a, point b){
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

int main(){
	cin >> N;

	for(int i = 0; i < N; i++)
		cin >> pts[i].x >> pts[i].y;

	sort(pts, pts + N, [] (point a, point b){
		return a.x < b.x;
	});

	long long best_sq = 9e18; // best distance so far, squared
	int left = 0; // the first point that is at most distance D from the current (x, y)
	set<point> active;

	for(int i = 0; i < N; i++){
		while(left < N && pts[left].x < pts[i].x - sqrt(best_sq)){
			active.erase(pts[left]);
			left += 1;
		}

		// want to find all active points in range [y - best, y + best] 

		// we keep finding the next largest point after the point just found
		// we start at (INF, y - best - 1), so the next largest point (if exists)
		// must be the first point at or after (y - best, -INF)

		long long currentY = pts[i].y - sqrt(best_sq) - 1, currentX = INF;
		if(currentY < -2e9) // prevent overflow when it's casted to int later
			currentY = -2e9;

		while(currentY <= pts[i].y + sqrt(best_sq)){
			auto it = active.upper_bound({(int)currentX, (int)currentY});
			// find where the next point is in the set
			if(it == active.end()) break; // if returns active.end(), means we are past the end and no such point exists
			point cur = *it; // *it gives us the actual point, not just where it is

			if(dist_sq(cur, pts[i]) < best_sq){
				best_sq = dist_sq(cur, pts[i]);
			}

			currentX = cur.x;
			currentY = cur.y;
		}
		// in C++ we can instead use just iterators, but this is the style only way in Java

		active.insert(pts[i]);
	}

	cout << best_sq << endl;
}
