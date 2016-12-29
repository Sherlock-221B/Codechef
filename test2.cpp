#include<bits/stdc++.h>

using namespace std;

#define MP make_pair

int main() {
    int n;
    string s;
    cin>>n>>s;
    unordered_set<pair<char,char> > Set;
    int maxcnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(Set.find(MP(s[i],s[j]))==Set.end() && Set.find(MP(s[j],s[i]))==Set.end()){
                Set.insert(MP(s[i],s[j]));
                int count=2;
                bool turn=true;
                for(int k=j+1;k<n;k++){
                    if(turn){
                        if(s[k]==s[i]){
                            turn=false;
                            count++;
                        }
                        else if(s[k]==s[j]){
                            count=0;
                            break;
                        }
                    }else{
                        if(s[k]==s[j]){
                            turn=false;
                            count++;
                        }
                        else if(s[k]==s[i]){
                            count=0;
                            break;
                        }
                    }
                }
                maxcnt=max(maxcnt,count);
            }
        }
    }
    cout<<maxcnt;
    return 0;
}
