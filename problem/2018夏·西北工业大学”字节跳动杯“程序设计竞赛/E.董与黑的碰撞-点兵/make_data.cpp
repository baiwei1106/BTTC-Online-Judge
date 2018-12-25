#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
using namespace std;
int main() {
    srand((unsigned int)time(NULL));
    freopen("ex_in.txt","w",stdout);
    int n=100000, m=100000;
    printf("%d %d\n",n,m);
    rep(i,1,n)cout << rand()%2 <<' ';puts("");
    rep(i,1,m)printf("1 100000\n");
}
