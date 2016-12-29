/**
** Problem: https://www.codechef.com/KOL16MOS/problems/KOL16B
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

    int t,Case=0;
    cin>>t;
    while(t--){
        Case++;
        int n;
        cin>>n;
        VI v(n);
        LOOP(i,0,n-1) cin>>v[i];
        VI A(n),B(n);
        unsigned int m=256*256-1;
        LOOP(i,0,n-1){
            A[i]=v[i] & m;
            B[i]=(v[i] & ~m)>>16;
        }
        cout<<"Case "<<Case<<":"<<endl;
        LOOP(i, 0, n-1) cout<<A[i]<<" ";
        cout<<endl;
        LOOP(i, 0, n-1) cout<<B[i]<<" ";
        cout<<endl;
    }

    return 0;
}
