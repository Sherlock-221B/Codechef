#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
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
template<typename T, typename U> inline void MIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void MAX(T &x, U y) { if(x < y) x = y; }

int check(int i,int j,int K, VVI &vvi){
    int x=0,y=0,count=0;
    while(x<vvi[i].size() && y<vvi[j].size()){
        if(vvi[i][x]<vvi[j][y]) x++;
        else if(vvi[i][x]>vvi[j][y]) y++;
        else{
            count++;
            if(count>=K) return 1;
            x++,y++;
        }
    }
    return 0;
}

int main(){
    int N,K,x;
    VVI vvi;
    cin>>N>>K;
    LOOP(z,N){
        cin>>x;
        VI v(x);
        LOOP(i,x) cin>>v[i];
        sort(ALL(v));
        vvi.PB(v);
    }
    bool visited[N]={false};
    VI family;
    family.PB(0); //the president
    visited[0]=true;
    LOOP(i,family.size()){
        LOOPL(j,1,N){
            if(i!=j && !visited[j] && check(i,j,K,vvi)){
                visited[j]=true;
                family.PB(j);
            }
        }
    }
    cout<<family.size();

    return 0;
}

/**
https://www.codechef.com/IOIPRAC/problems/INOI1302

N people live in Sequence Land. Instead of a name, each person is identified by a sequence of integers, called his or her id. Each id is a sequence with no duplicate elements. Two people are said to be each other’s relatives if their ids have at least K elements in common. The extended family of a resident of Sequence Land includes herself or himself, all relatives, relatives of relatives, relatives of relatives of relatives, and so on without any limit.

Given the ids of all residents of Sequence Land, including its President, and the number K, find the number of people in the extended family of the President of Sequence Land.

For example, suppose N = 4 and K = 2. Suppose the President has id (4, 6, 7, 8) and the other three residents have ids (8, 3, 0, 4), (0, 10), and (1, 2, 3, 0, 5, 8). Here, the President is directly related to (8, 3, 0, 4), who in turn is directly related to (1, 2, 3, 0, 5, 8). Thus, the President’s extended family consists of everyone other than (0, 10) and so has size 3.

Input format

• Line 1: Two space-separated integers, N followed by K.

• Lines 2 to N + 1: Each line describes an id of one of the residents of Sequence Land, beginning with the President on line 2. Each line consists of an integer p, followed by p distinct integers, the id.

Output format

The output consists of a single integer, the number of people in the extended family of the President.

Test Data

The testdata is grouped into two subtasks. In both subtasks, 1 ≤ N ≤ 300 and 1 ≤ K ≤ 300. Each number in each id is between 0 and 109 inclusive.

• Subtask 1 [30 points]: The number of elements in each id is between 1 and 10 inclusive.

• Subtask 2 [70 points]: The number of elements in each id is between 1 and 300 inclusive.

Example

Here is the sample input and output corresponding to the example above.

Sample input 

4 2
4 4 6 7 8
4 8 3 0 4
2 0 10
6 1 2 3 0 5 8
Sample output

3

*/