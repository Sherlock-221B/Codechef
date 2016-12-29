/**
** Problem: https://www.codechef.com/ZCOPRAC/problems/ZCO12004
**/
#include <bits/stdc++.h>
using namespace std;
#define LOOP(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPR(i,u,l) for(int (i)=(int)(u);(i)>=(int)(l);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB push_back
#define MP make_pair
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define LL long long int
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }
template<class T1> void DEBUG(T1 e1){    cout << e1 << endl;}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2){    cout << e1 << ", " << e2 << endl;}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3){    cout << e1 << ", " << e2 << ", " << e3 << endl;}

LL compute(vector<LL> &v,LL N){
    LL include,exclude;
    include=exclude=v[0];
    LOOP(i,1,N-1){
        int temp=include;
        include=min(include,exclude)+v[i];
        exclude=temp;
    }
    return min(include,exclude);
}

int main(){
    LL N;
    cin>>N;
    vector<LL> v(N);
    LOOP(i,0,N-1) cin>>v[i];
    LL answer=compute(v,N);
    reverse(ALL(v));
    cout<<min(answer,compute(v,N));
    return 0;
}
