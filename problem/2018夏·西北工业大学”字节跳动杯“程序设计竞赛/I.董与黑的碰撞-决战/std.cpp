#include <bits/stdc++.h>
using namespace std;
#define NMAX 1010
#define MAXN 2010010
#define SLEN 11
int n, m;
char name[NMAX][SLEN]; //存储每一个编号对应的名称
int input[MAXN*3];   //所有字符串拼接成一个字符串
int book[NMAX * 2];    //每一个原来的字符串在总字符串中的首地址
int len;
int leng[2][NMAX];

int Rank[MAXN];
int sa[MAXN*3];
int height[MAXN];
vector<int>vec[30];

#define F(x) ((x) / 3 + ((x) % 3 == 1 ? 0 : tb))
#define G(x) ((x) < tb ? (x)*3 + 1 : ((x)-tb) * 3 + 2)
int wa[MAXN * 3], wb[MAXN * 3], wv[MAXN * 3], wss[MAXN * 3];
int c0(int *r, int a, int b)
{
    return r[a] == r[b] && r[a + 1] == r[b + 1] && r[a + 2] == r[b + 2];
}
int c12(int k, int *r, int a, int b)
{
    if (k == 2)
        return r[a] < r[b] || (r[a] == r[b] && c12(1, r, a + 1, b + 1));
    else
        return r[a] < r[b] || (r[a] == r[b] && wv[a + 1] < wv[b + 1]);
}
void sort(int *r, int *a, int *b, int n, int m)
{
    int i;
    for (i = 0; i < n; i++)
        wv[i] = r[a[i]];
    for (i = 0; i < m; i++)
        wss[i] = 0;
    for (i = 0; i < n; i++)
        wss[wv[i]]++;
    for (i = 1; i < m; i++)
        wss[i] += wss[i - 1];
    for (i = n - 1; i >= 0; i--)
        b[--wss[wv[i]]] = a[i];
}
void dc3(int *r, int *sa, int n, int m)
{
    int i, j, *rn = r + n;
    int *san = sa + n, ta = 0, tb = (n + 1) / 3, tbc = 0, p;
    r[n] = r[n + 1] = 0;
    for (i = 0; i < n; i++)
        if (i % 3 != 0)
            wa[tbc++] = i;
    sort(r + 2, wa, wb, tbc, m);
    sort(r + 1, wb, wa, tbc, m);
    sort(r, wa, wb, tbc, m);
    for (p = 1, rn[F(wb[0])] = 0, i = 1; i < tbc; i++)
        rn[F(wb[i])] = c0(r, wb[i - 1], wb[i]) ? p - 1 : p++;
    if (p < tbc)
        dc3(rn, san, tbc, p);
    else
        for (i = 0; i < tbc; i++)
            san[rn[i]] = i;
    for (i = 0; i < tbc; i++)
        if (san[i] < tb)
            wb[ta++] = san[i] * 3;
    if (n % 3 == 1)
        wb[ta++] = n - 1;
    sort(r, wb, wa, ta, m);

    for (i = 0; i < tbc; i++)
        wv[wb[i] = G(san[i])] = i;
    for (i = 0, j = 0, p = 0; i < ta && j < tbc; p++)
        sa[p] = c12(wb[j] % 3, r, wa[i], wb[j]) ? wa[i++] : wb[j++];
    for (; i < ta; p++)
        sa[p] = wa[i++];
    for (; j < tbc; p++)
        sa[p] = wb[j++];
}
//str和sa也要三倍
void da(int str[], int sa[], int rank[], int height[], int n, int m)
{
    for (int i = n; i < n * 3; i++)
        str[i] = 0;
    dc3(str, sa, n + 1, m);
    int i, j, k = 0;
    for (i = 0; i <= n; i++)
        rank[sa[i]] = i;
    for (i = 0; i < n; i++)
    {
        if (k)
            k--;
        j = sa[rank[i] - 1];
        while (str[i + k] == str[j + k])
            k++;
        height[rank[i]] = k;
    }
}

int RMQ[MAXN];  
int mm[MAXN];//mm[x]=log(2,x);
int best[25][MAXN];//st表
void initRMQ(int n) {     //调用da后，初始化RMQ（求LCP用）  
    for(int i=1;i<=n;i++)RMQ[i]=height[i];  
    mm[0]=-1;  
    for(int i=1; i<=n; i++)  
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];
    for(int i=1; i<=n; i++)best[0][i]=i;
    for(int i=1; i<=mm[n]; i++)  
        for(int j=1; j+(1<<i)-1<=n; j++) {  
            int a=best[i-1][j];  
            int b=best[i-1][j+(1<<(i-1))];  
            if(RMQ[a]<RMQ[b])best[i][j]=a;
            else best[i][j]=b;
        }  
}  
int askRMQ(int a,int b) {  
    int t;  
    t=mm[b-a+1];  
    b-=(1<<t)-1;
    a=best[t][a];  
    b=best[t][b];
    return RMQ[a]<RMQ[b]?a:b;
}
int lcp(int a,int b) {  
    a=Rank[a];  
    b=Rank[b];  
    if(a>b)swap(a,b);
    return height[askRMQ(a+1,b)];  
}  

void init()
{
    scanf("%d%d", &n, &m);
    int ii, jj;
    for (ii = 1; ii <= n; ii++)
    {
        scanf("%s", name[ii]);
        book[ii] = len;
        int c;
        scanf("%d", &c);
        leng[0][ii] = c;
        for (jj = 1; jj <= c; jj++)
        {
            int x;
            scanf("%d", &x);
            vec[x].push_back(len);
            input[len++] = x;
        }
    }
    for (ii = 1; ii <= m; ii++)
    {
        int d;
        scanf("%d", &d);
        leng[1][ii] = d;
        book[ii + n] = len;
        for (jj = 1; jj <= d; jj++)
        {
            int x;
            scanf("%d", &x);
            vec[x].push_back(len);
            input[len++] = x;
        }
    }
    book[ii + n] = len;
    input[len]=0;
    //input[len++]=0;
    da(input,sa,Rank,height,len,30);
    initRMQ(len);
    return;
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    init();
    //for(int i=0;i<=len;i++)printf("input[%d]=%d,sa[%d]=%d,rank[%d]=%d\n",i,input[i],i,sa[i],i,Rank[i]);
    //for(int i=0;i<=len;i++)printf("height[%d]=%d\n",i,height[Rank[i]]);
    for (int ii = 1; ii <= m; ii++)
    {
        for (int jj = 1; jj <= n; jj++)
        {
            for (
            int head=input[book[ii+n]],
            kk = lower_bound
                (
                    vec[head].begin(),
                    vec[head].end(),
                    book[jj]
                )
                -vec[head].begin();
                kk<vec[head].size()&&vec[head][kk] + leng[1][ii] <= book[jj+1]; kk++)
            {
                if (lcp(vec[head][kk], book[ii + n]) >= leng[1][ii])
                {
                    printf("%s\n", name[jj]);
                    goto a;
                }
            }
        }
        printf("shenmegui\n");
        a:;
    }
    return 0;
}
