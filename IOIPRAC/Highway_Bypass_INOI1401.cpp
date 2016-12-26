/**
** Problem: https://www.codechef.com/IOIPRAC/problems/INOI1401
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

#define MOD 20011

int main(){
    int R,C,d;
    cin>>R>>C>>d;
    bool road[R][C];
    LOOP(i,0,R-1) LOOP(j,0,C-1) cin>>road[i][j];
    //input done
    vector<vector<pair<int, int> > > ways(R,vector<pair<int, int> >(C)); //"first" for row, "second" for column
    vector<vector<pair<int, int> > > limit(R,vector<pair<int, int> >(C));
    
    ways[0][0]=MP(1,1);
    limit[0][0]=MP(0,0);
    //first row
    LOOP(j,1,C-1){
        if(ways[0][j-1].first==0 || road[0][j]==false || limit[0][j-1].first=d){
            ways[0][j]=MP(0,0);
            
        }else{
            ways[0][j]=MP(1,0);
        }
    }
    //first column
    LOOP(i,1,R-1){
        if(ways[i-1][0].second==0 || road[i][0]==false) ways[i][0]=MP(0,0);
        else ways[i][0]=MP(1,0);
    }
    //rest
    LOOP(i,1,R-1){
        LOOP(j,1,C-1){
            if(road[i][j]==false){

                ways[i][j]=MP(0,0);
            }
        }
    }

    return 0;
}
