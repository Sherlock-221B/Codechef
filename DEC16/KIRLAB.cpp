/**
** Author: Vijay J.
** URL: http://codechef.com/users/vijay008	
** Problem: https://www.codechef.com/DEC16/problems/KIRLAB
**/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <limits>
#include <functional>
using namespace std;
#define LOOP(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define LOOPE(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define LOOPL(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#define LOOPR(i,l,u) for(int (i)=(int)(l);(i)>=(int)(u);--(i))
#define ITERATE(it,object) for(auto (it)=(object).begin();(it)!=(object).end();++(it))
#define ALL(object) (object).begin(),(object).end()
#define PB(item) push_back(item)
#define MP(item1,item2) make_pair((item1),(item2))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define ULL unsigned long long int
#define LL long long int
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VPII;
typedef list<pair<int,int> > LPII;
typedef vector<list<pair<int,int> > > VLPII;
typedef unordered_map<int,int> UMII;
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }

template<class T1> void DEBUG(T1 e1){    cout << e1 << endl;}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2){    cout << e1 << ", " << e2 << endl;}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3){    cout << e1 << ", " << e2 << ", " << e3 << endl;}
template<class T1,class T2,class T3,class T4> void DEBUG(T1 e1, T2 e2, T3 e3, T4 e4){    cout << e1 << ", " << e2 << ", " << e3 << ", " << e4 << endl;}

int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}

int main(){
    int T,N;
    cin>>T;
    while(T--){
        cin>>N;
        vector<int> A(N),m(N,0);  //m--> index,its gcd count from that number onwards
        LOOP(i,N) cin>>A[i];
        int answer=0;
        LOOPR(i,N-2,0){
            LOOPL(j,i+1,N){
                if(gcd(A[i],A[j])>1){
                    m[i]=max(m[i],1+m[j]);
                }
            }
            if(m[i]>answer) answer=m[i];
        }
        cout<<answer+1<<endl;
    }
    return 0;
}
