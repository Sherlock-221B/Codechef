/**
** Problem: https://www.codechef.com/ZCOPRAC/problems/ZCO14002
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

int main(){

    LL answer,n;
    cin>>n;
    vector<LL> v(n+1),dp(n+1);
    LOOP(i,1,n) cin>>v[i];
    if(n>=1) dp[1]=v[1];
    if(n>=2) dp[2]=v[2];
    if(n>=3) dp[3]=v[3];
    LOOP(i,4,n) dp[i]=v[i]+min(dp[i-1],min(dp[i-2],dp[i-3]));
    answer=dp[n];
    if(n>1) answer=min(answer,dp[n-1]);
    if(n>2) answer=min(answer,dp[n-2]);
    cout<<answer;
    return 0;
}
