#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
 
 
template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if(sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }
 
	ModInt &operator+=(ModInt that) { if((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
 
	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
 
	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while(b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if(u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while(k) {
		if(k & 1) r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}
typedef ModInt<1163962801> mint;
 
struct NTT {
	vector<mint> roots;
 
	void init() {
		const int maxN = 22;
		const mint primRoot = 46;
		const int phi = mint::Mod - 1;
		roots.resize(maxN + 1);
		for(int n = 1; n <= maxN; ++ n) {
			assert(phi % n == 0);
			roots[n] = primRoot ^ (phi / n);
		}
	}
 
	void ntt(mint *data, int n, int stride, int sign) const {
		mint x[22];
		for(int i = 0; i < n; ++ i)
			x[i] = data[i * stride];
		mint w = roots[n], coeff = 1;
		if(sign == -1) {
			w = w.inverse();
			coeff = mint(n).inverse();
		}
		mint wi = 1;
		for(int i = 0; i < n; ++ i) {
			mint sum, wij = 1;
			for(int j = 0; j < n; ++ j) {
				sum += wij * x[j];
				wij *= wi;
			}
			sum *= coeff;
			data[i * stride] = sum;
			wi *= w;
		}
	}
} ntt;
 
struct Block {
	int n;
	vector<mint> poly;
 
	Block() : n(0) {}
	explicit Block(int n) : n(n), poly(n * (n - 1)) {}
 
	int size() const { return n; }
 
	int getlogn() const {
		int logn = 0;
		while((1 << logn) < n * (n - 1) * 4) ++ logn;
		return logn;
	}
 
	static Block identity(int n) {
		Block res(n);
		res.poly[0 * (n - 1) + 0] = 1;
		return res;
	}
 
	void transform() {
		rep(i, n)
			ntt.ntt(poly.data() + (n - 1) * i, n - 1, 1, +1);
		rep(i, n - 1)
			ntt.ntt(poly.data() + i, n, n - 1, +1);
	}
 
	void inverse_transform() {
		rep(i, n - 1)
			ntt.ntt(poly.data() + i, n, n - 1, -1);
		rep(i, n)
			ntt.ntt(poly.data() + (n - 1) * i, n - 1, 1, -1);
	}
 
	void add_product(const Block &a, const Block &b) {
		assert(n == a.n && n == b.n);
		rep(i, n * (n - 1))
			poly[i] += a.poly[i] * b.poly[i];
	}
};
 
struct BlockMatrix {
	vector<vector<Block>> blocks;
	explicit BlockMatrix(int height, int width, int blockSize) {
		blocks.assign(height, vector<Block>(width, Block(blockSize)));
	}
	int height() const { return (int)blocks.size(); }
	int width() const { return (int)blocks[0].size(); }
	int blockSize() const { return blocks[0][0].size(); }
	Block& at(int i, int j) { assert(0 <= i && i < height() && 0 <= j && j < width()); return blocks[i][j]; }
	const Block& at(int i, int j) const { assert(0 <= i && i < height() && 0 <= j && j < width()); return blocks[i][j]; }
	static BlockMatrix identity(int numBlocks, int blockSize) {
		BlockMatrix A(numBlocks, numBlocks, blockSize);
		rep(i, numBlocks)
			A.at(i, i) = Block::identity(blockSize);
		return A;
	}
	static BlockMatrix identity(const BlockMatrix& A) {
		return identity(A.height(), A.at(0, 0).size());
	}
 
	BlockMatrix operator*(const BlockMatrix& that) const {
		if(this == &that) {
			BlockMatrix A = *this;
			return product(A, A);
		} else {
			BlockMatrix A = *this, B = that;
			return product(A, B);
		}
	}
 
	void transform() {
		rep(i, height()) rep(j, width())
			at(i, j).transform();
	}
 
	void inverse_transform() {
		rep(i, height()) rep(j, width())
			at(i, j).inverse_transform();
	}
 
private:
	static BlockMatrix product(BlockMatrix &A, BlockMatrix &B) {
		int N = A.height(), M = B.width(), P = B.height();
		assert(P == A.width());
		assert(A.blockSize() == B.blockSize());
		BlockMatrix res(N, M, A.blockSize());
		rep(i, N) rep(j, M) {
			rep(k, P)
				res.at(i, j).add_product(A.at(i, k), B.at(k, j));
		}
		return res;
	}
 
};
 
BlockMatrix operator^(const BlockMatrix &A, ll k) {
	if(k == 0)
		return BlockMatrix::identity(A);
	if(k == 1)
		return A;
	if(k % 2 == 0)
		return (A * A) ^ (k / 2);
	else
		return (A ^ (k - 1)) * A;
}
 
int main() {
	ntt.init();
	int n; int m; int t;
	while(~scanf("%d%d%d", &n, &m, &t)) {
		BlockMatrix A(n, n, n);
		vector<tuple<int, int, int, int>> roads(m);
		rep(i, m) {
			int s; int e; int f; int r;
			scanf("%d%d%d%d", &s, &e, &f, &r), -- s, -- e;
			f %= n, r %= n - 1;
			A.at(s, e).poly[f * (n - 1) + r] += 1;
			roads[i] = make_tuple(s, e, f, r);
		}
 
		A.transform();
		A = A ^ t;
		A.inverse_transform();
		rep(k, n) {
			rep(i, n) {
				rep(j, n - 1) {
					if(j != 0) putchar(' ');
					mint ans = A.at(k, k).poly[i * (n - 1) + j];
					printf("%d", ans.get());
				}
				puts("");
			}
		}
	}
	return 0;
}