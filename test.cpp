#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
 
vector<int> primes;
vector<int> smallestPrimeFactor;
void linearSieve(int n) {
	if(n < 1) n = 1;
	if((int)smallestPrimeFactor.size() >= n + 1) return;
	int primePiBound = n < 20 ? n - 1 : (int)(n / (log(n * 1.) - 2) + 2);
	primes.assign(primePiBound + 1, numeric_limits<int>::max());
	int P = 0;
	smallestPrimeFactor.assign(n + 1, 0);
	smallestPrimeFactor[1] = 1;
	int n2 = n / 2, n3 = n / 3, n5 = n / 5;
	if(n >= 2)
		primes[P ++] = 2;
	if(n >= 3)
		primes[P ++] = 3;
	for(int q = 2; q <= n; q += 2)
		smallestPrimeFactor[q] = 2;
	for(int q = 3; q <= n; q += 6)
		smallestPrimeFactor[q] = 3;
	for(int q = 5; q <= n5; q += 2) {
		if(smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
		int bound = smallestPrimeFactor[q];
		for(int i = 2; ; ++ i) {
			int p = primes[i];
			if(p > bound) break;
			int pq = p * q;
			if(pq > n) break;
			smallestPrimeFactor[pq] = p;
		}
	}
	for(int q = (n5 + 1) | 1; q <= n; q += 2) {
		if(smallestPrimeFactor[q] == 0)
			primes[P ++] = smallestPrimeFactor[q] = q;
	}
	primes.resize(P);
}
 
int main() {
	int T;
	scanf("%d", &T);
	const int MaxA = (int)1e7;
	linearSieve(MaxA);
	int P = 0;
	vector<int> primeIndex(MaxA + 1, -1);
	for(int p : primes)
		primeIndex[p] = P ++;
	for(int ii = 0; ii < T; ++ ii) {
		int N;
		scanf("%d", &N);
		vector<int> a(N);
		for(int i = 0; i < N; ++ i)
			scanf("%d", &a[i]);
		vector<int> dp(P, 0);
		vector<int> factors;
		int ans = 0;
		rep(i, N) {
			int x = a[i];
			factors.clear();
			while(x != 1) {
				int p = smallestPrimeFactor[x];
				factors.push_back(primeIndex[p]);
				do x /= p; while(x % p == 0);
			}
			int cur = 1;
			for(int pi : factors)
				amax(cur, dp[pi] + 1);
			amax(ans, cur);
			for(int pi : factors)
				amax(dp[pi], cur);
		}
		printf("%d\n", ans);
	}
	return 0;
}