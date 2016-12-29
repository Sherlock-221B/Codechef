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
    vector<vector<pair<int, int> > > ways(R,vector<pair<int, int> >(C,MP(0,0))); //"first" for row, "second" for column
    
    ways[0][0]=MP(1,1);
    //first row
    LOOP(j,1,C-1){
        if(j>d || ways[0][j-1].first==0 || !road[0][j]) ways[0][j]=MP(0,0);
        else ways[0][j]=MP(1,0);
    }
    //first column
    LOOP(i,1,R-1){
        if(i>d || ways[i-1][0].second==0 || !road[i][0]) ways[i][0]=MP(0,0);
        else ways[i][0]=MP(1,0);
    }
    //rest
    LOOP(i,1,R-1){
        LOOP(j,1,C-1){
            if(!road[i][j]){
                ways[i][j]=MP(0,0);
            }else{
                //vertically
                if(!road[i-1][j]) ways[i][j].second=0;
                else{
                    ways[i][j].second=(ways[i-1][j].first+ways[i-1][j].second)%MOD;
                    if(i>d){
                        int k=0;
                        while(++k<=d) if(!road[i-k][j]) break;
                        if(k>d) ways[i][j].second=(MOD+MOD+ways[i][j].second-ways[i-d-1][j].first-ways[i-d-1][j].second)%MOD;
                    }
                }
                //horizontally
                if(!road[i][j-1]) ways[i][j].first=0;
                else{
                    ways[i][j].first=(ways[i][j-1].first+ways[i][j-1].second)%MOD;
                    if(j>d){
                        int k=0;
                        while(++k<=d) if(!road[i][j-k]) break;
                        if(k>d) ways[i][j].first=(MOD+MOD+ways[i][j].first-ways[i][j-d-1].first-ways[i][j-d-1].second)%MOD;
                    }
                }
            }
        }
    }
    cout<<(ways[R-1][C-1].first+ways[R-1][C-1].second)%MOD;
    return 0;
}
