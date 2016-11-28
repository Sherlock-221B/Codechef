/**
** Author: Vijay J.
** URL: http://codechef.com/users/vijay008	
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


class cmp{
    public:
    bool operator() (const PII &a,const PII &b){
        return a.first<b.first;
    }
};

//gddxvv

int main(){

    LL N;
    cin>>N;
    VI v(N);
    priority_queue<PII,VPII,cmp> pq_left,pq_right;
    LOOP(i,N){
         cin>>v[i];
         pq_left.push(MP(v[i]+i+1,i));
    }
    LL answer,shift=0;
    LL j=N-1;
    LOOP(i,N){
        while(pq_left.top().second>j) pq_left.pop();
        answer=max(pq_left.top().first, pq_right.empty()?numeric_limits<int>::min():pq_right.top().first)+shift;
        cout<<answer<<" ";
        pq_right.push(MP(v[j]-shift,j));
        j--,shift++;
    }

    return 0;
}

/**
https://www.codechef.com/IOIPRAC/problems/INOI1202

You are given a table with 2 rows and N columns. Each cell has an integer in it. The score of such a table is defined as follows: for each column, consider the sum of the two numbers in the column; the maximum of the N numbers so obtained is the score. For example, for the table

7162
1234
 
the score is max(7 + 1, 1 + 2, 6 + 3, 2 + 4) = 9.


The first row of the table is fixed, and given as input. N possible ways to fill the second row are considered:

1,2,...,N
2,3,...,N,1
3,4,...,N,1,2
···
N, 1, ... , ,N − 1
 
For instance, for the example above, we would consider each of the following as possibilities for the second row.

1234
2341
3412
4123
 
Your task is to find the score for each of the above choices of the second row. In the example above, you would evaluate the following four tables,

 7162 7162 7162 7162
 1234 2341 3412 4123
 
and compute scores 9, 10, 10 and 11, respectively.

Input format

The first line of the input has a single integer, N. The second line of the input has N integers, representing the first row, from left to right.

Output format

The output should consist of a single line with N integers. For 1 ² k ² N, the kth number in the output should be the score when the second row of the table is taken to be k,k+1,...,N,1,...,k−1.

Test Data

The testdata is grouped into two subtasks with the following constraints on the inputs.

• Subtask 1 [30 points] : 1 ≤ N ≤ 3000.

• Subtask 2 [70 points] : 1 ≤ N ≤ 200000.

In both the subtasks, all the integers in the first row of the table are between 1 and 100000, inclusive.

Example

Here is the sample input and output corresponding to the example above.

Sample input

4
7 1 6 2
Sample output

9 10 10 11

**/