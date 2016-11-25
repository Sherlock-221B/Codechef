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

template<class T1> void DEBUG(T1 e1)
{
    cout << e1 << endl;
}
template<class T1,class T2> void DEBUG(T1 e1, T2 e2)
{
    cout << e1 << ", " << e2 << endl;
}
template<class T1,class T2,class T3> void DEBUG(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << ", " << e2 << ", " << e3 << endl;
}
template<class T1,class T2,class T3,class T4> void DEBUG(T1 e1, T2 e2, T3 e3, T4 e4)
{
    cout << e1 << ", " << e2 << ", " << e3 << ", " << e4 << endl;
}


// class cmp{
//     public:
//     bool operator() (const object &a,const object &b){
//         return a<b;
//     }
// };



int main(){
    LL N,M;
    cin>>N>>M;
    LL mod=1;
    LOOP(i,N) mod=(mod*2)%M;
    
    UMII m; 
    m[1]=2;//N and its periodic strings count
    LL p=1; //current power of 2
    if(N==1) cout<<"2";
    else{
        LOOPE(i,1,N/2){
            p=(p*2)%M;
            if(N%i==0){
                LL count=p;
                LOOPE(j,1,i/2){
                    if(i%j==0){
                        count-=m[j];
                    }
                }
                m[i]=count;
            }
        }
        LL periodic=0;
        ITERATE(it,m){
            periodic=(periodic+it->second)%M;
        }
        LL answer=(mod-periodic+M)%M;
        cout<<answer;
    }

    return 0;
}

/*
https://www.codechef.com/IOIPRAC/problems/INOI1502

A string is any nonempty sequence of 0s and 1s. Examples of strings are 00, 101, 111000, 1, 0, 01. The length of a string is the number of symbols in it. For example, the length of 111000 is 6. If u and v are strings, then uv is the string obtained by concatenating u and v. For example if u = 110 and v = 0010 then uv = 1100010.

A string w is periodic if there exists a string v such that w = vn = vv · · · v (n times), for some n ≥ 2. Note that in this case the length of v is strictly less than that of w. For example, 110110 is periodic, because it is vv for v = 110.

Given a positive integer N , find the number of strings of length N which are not periodic. Report the answer modulo M . The non-periodic strings of length 2 are 10 and 01. The non- periodic strings of length 3 are 001, 010, 011, 100, 101, and 110.

Input format

A single line, with two space-separated integers, N and M .

Output format

A single integer, the number of non-periodic strings of length N , modulo M .

Test Data

In all subtasks, 2 ≤ M ≤ 108. The testdata is grouped into 4 subtasks.

Subtask 1 (10 marks) 1 ≤ N ≤ 4000. N is the product of two distinct prime numbers.

Subtask 2 (20 marks) 1 ≤ N ≤ 4000. N is a power of a prime number.

Subtask 3 (35 marks) 1 ≤ N ≤ 4000.

Subtask 4 (35 marks) 1 ≤ N ≤ 150000.

Example

Here is the sample input and output corresponding to the example above:

Sample input

3 176
Sample output

6

*/