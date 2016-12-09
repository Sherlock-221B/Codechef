/**	
** Problem: https://www.codechef.com/DEC16/problems/ANKTRAIN
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



int main(){

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int x=N%8;
        if(x==0) x=8;
        switch(x){
            case 1: case 2: case 3:
                cout<<N+3;
            break;
            case 4: case 5: case 6:
                cout<<N-3;
            break;
            case 7:
                cout<<N+1;
            break;
            case 8:
                cout<<N-1;
            break;
        }
        switch(x){
            case 1: case 4:
                cout<<"LB";
            break;
            case 2: case 5:
                cout<<"MB";
            break;
            case 3: case 6:
                cout<<"UB";
            break;
            case 7:
                cout<<"SU";
            break;
            case 8:
                cout<<"SL";
        }
        cout<<endl;
    }

    return 0;
}
