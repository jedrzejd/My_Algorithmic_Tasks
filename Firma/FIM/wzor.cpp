#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define REPT(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
typedef long long LL;
inline void fastcin(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
LL a,b,c,wyn,wynk;
LL nwd(LL x,LL y){
    while(y)swap(x%=y,y);
    return x;
}
vector<LL>p;
int main(){
    fastcin();
    cin>>a>>b;
    if(a>b)swap(a,b);
    c=b-a;
    wyn=nwd(a,b);
    for(int i=1;i*i<=c;i++){
        if(c%i==0){
            p.pb(i);p.pb(c/i);
        }
    }
    REP(i,p.size()){
        LL d=p[i],k=0;
        if(a%d!=0){
            k=(a/d+1)*d-a;
        }
        if((a+k)%d==0&&(b+k)%d==0&&nwd(a+k,b+k)>wyn){
            wyn=nwd(a+k,b+k);
            wynk=k;
        }
    }
    cout<<wynk;
    return 0;
}
