//All Data: 5.685000 s
//Big Data: 0.372000 s
#include <cstdio>
#define rep(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;
const int N = 1e5 + 100;
using namespace std;
int n, m, L, R, a[N], sum[N];
struct seg{int l, r; ll rs;} tree[N << 2];
void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if(l == r) {
        tree[p].rs = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p<<1, l, mid), build(p<<1|1, mid+1, r);
    tree[p].rs = tree[p<<1|1].rs;
    if((sum[r] - sum[mid]) & 1) tree[p].rs += (mid-l+1 - tree[p<<1].rs);
    else tree[p].rs += tree[p<<1].rs;
}
ll ask(int p, int l, int r, int R) {
    if(tree[p].l == l && tree[p].r == r) {
        if((sum[R] - sum[tree[p].r]) & 1) return (tree[p].r-tree[p].l+1 - tree[p].rs);
        else return tree[p].rs;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if(r <= mid) return ask(p<<1, l, r, R);
    else if(l > mid) return ask(p<<1|1, l, r, R);
    else return ask(p<<1, l, mid, R)+ask(p<<1|1, mid+1, r, R);
}
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    while(scanf("%d%d", &n, &m) != EOF) {
        rep(i, 1, n) scanf("%d", &a[i]), sum[i] = a[i];
        rep(i, 2, n) sum[i] += sum[i-1];
        build(1, 1, n);
        rep(i, 1, m) {
            scanf("%d%d", &L, &R);
            printf("%lld\n", ask(1,L,R,R));
        }
    }
}
