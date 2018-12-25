//All Data: 269.339000 s
//Big Data: 76.499000 s
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define mem(W) memset(W,0,sizeof(W))
typedef long long ll;
const int N = 1e5 + 100;
using namespace std;
int n, m, a[N], sum[N];
ll ask3(int l,int r) {
    ll ans=0;
    rep(L,l,r)if((sum[r]-sum[L-1])&1)++ans;
    return ans;
}
int main() {
    freopen("ex_in.txt","r",stdin);
    freopen("ex_out.txt","w",stdout);
    clock_t start, stop;
    start = clock();
    while(scanf("%d%d", &n,&m)!=EOF){
        rep(i,1,n)scanf("%d",&a[i]),sum[i]=a[i];
        rep(i,2,n)sum[i]+=sum[i-1];
        rep(i,1,m){int l,r;
            scanf("%d%d",&l,&r);
//            ask3(l,r);
            printf("%lld\n",ask3(l,r));
        }
    }
    stop = clock();
    printf("bao li: %f s\n", (double)(stop - start) / CLOCKS_PER_SEC);
}
