#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#define pb push_back
#define mp make_pair
#define f first
#define s second
using namespace std;
const int MXN=1e6+5;
int n,q,a,b;
inline void fastcin(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}
vector<int>tab[MXN];
bool odw[MXN];
int pre[MXN],post[MXN],czas,k,node,h[MXN];
vector<pair<int,int> >gleb[MXN];
void dfs(int v,int gl){
    odw[v]=1;
    pre[v]=++czas;
    h[v]=gl;
    gleb[gl].pb(mp(pre[v],v));
    for(int i=0;i<tab[v].size();i++){
        int u=tab[v][i];
        if(!odw[u]){
            dfs(u,gl+1);
        }
    }
    post[v]=++czas;
}
int main(){
    fastcin();
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        tab[a].pb(b);
    }
    dfs(1,1);
    for(int i=0;i<n-1;i++)
        sort(gleb[i].begin(),gleb[i].end());
    for(int i=0;i<q;i++){
        cin>>node>>k;
        int wys=k+h[node];
        int lewo=pre[node],prawo=post[node];
        int p=0,k=gleb[wys].size()-1;
        if(k==gleb[wys].size()){
            cout<<0<<endl;
            continue;
        }
        int r1=-1,r2=-1;
        while(p<=k){
            int s=(p+k)/2;
            int co=gleb[wys][s].s;
            int index=gleb[wys][s].f;
            int l1,p1;
            l1=pre[co];p1=post[co];
            if(lewo<=l1&&prawo>=p1){
                r1=s;
                k=s-1;
            }
            else if(index<lewo)p=s+1;
            else k=s-1;
        }
        p=0;k=gleb[wys].size()-1;
        while(p<=k){
            int s=(p+k)/2;
            int co=gleb[wys][s].s;
            int index=gleb[wys][s].f;
            int l1,p1;
            l1=pre[co];p1=post[co];
            if(lewo<=l1&&prawo>=p1){
                r2=s;
                p=s+1;
            }
            else if(index<lewo)p=s+1;
            else k=s-1;
        }
        if(r1==-1&&r2==-1){
            cout<<0<<endl;
        }
        else cout<<r2-r1+1<<endl;
    }
    return 0;
}
