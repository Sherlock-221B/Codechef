//Our Base is Under Attack

#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
 
int main() {
	int T;
	scanf("%d", &T);
	const ll MaxN = (ll)1e12;
	vector<ll> powers;
	for(int x = 2; ; ++ x) {
		ll y = (ll)x * x;
		if(y > MaxN) break;
		do {
			powers.push_back(y);
			y *= x;
		} while(y <= MaxN);
	}
	sort(powers.begin(), powers.end());
	for(int ii = 0; ii < T; ++ ii) {
		long long N;
		scanf("%lld", &N);
		if(N == 1) {
			puts("INFINITY");
			continue;
		}
		//1 <= N / b^k < 2
		//b^k <= N, N / 2 < b^k
		ll L = (N + 2) / 2, R = N;
		ll ans = R + 1 - L;
		ans += upper_bound(powers.begin(), powers.end(), R) - lower_bound(powers.begin(), powers.end(), L);
		printf("%lld\n", ans);
	}
	return 0;
}