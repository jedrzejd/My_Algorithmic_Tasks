#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <sys/time.h>
using namespace std;
string in,out;
fstream wyjscie,wejscie;
int n=100;
int main(){
    timeval tp;
    gettimeofday(&tp,0);
    srand(tp.tv_sec*1000+tp.tv_usec/1000);
    for(int i=1;i<=n;i++){
        in="FIM"+to_string(i)+".in";
        out="FIM"+to_string(i)+".out";
        cout<<in<<endl;
        cout<<out<<endl;
        wejscie.open(in);
        wyjscie.open(out);
        wejscie<<1;
        wejscie.close();
        wyjscie.close();
    }
    return 0;
}
