/**
** Problem: https://www.codechef.com/KOL16MOS/problems/KOL16H
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

#define MOD 8589934592

int cmp(string &s,string &t){
    if(s.length()==t.length()){
		int k=s.compare(t);
		if(k==-1) return 2; //2 for second is big
		else if(k==1)  return 1; //1 for first is big
		else return 0; //equal
	}else if(s.length()>t.length()) return 1;
	else return 2;
}


int main(){

    int t;
    cin>>t;
    while(t--){
        string n,m="1";
        cin>>n;
        LL answer=1;
        while()
        {
            answer=(answer*2)%MOD;
        }  
        cout<<answer-1<<endl;
    }

    return 0;
}
