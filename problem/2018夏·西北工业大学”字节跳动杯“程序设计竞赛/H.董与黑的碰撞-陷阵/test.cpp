#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1000000;

/**********************getdata***********************/

void getdata()
{
    freopen("in.txt","w",stdout);
    srand((unsigned)time(NULL));

    int T;
    T=1000;
    printf("%d\n",T);
    for(int kase=1;kase<=T;kase++)
    {
        int n,x,y;
        if(kase<=20)
        {
            n=MAXN-rand()%(MAXN/10);
            x=rand()%n;
            y=0;
        }
        else if(kase<=40)
        {
            n=MAXN-rand()%(MAXN/10);
            x=rand()%n;
            y=n-x;
        }
        else
        {
            n=MAXN-rand()%(MAXN/10);
            x=rand()%n;
            y=rand()%(n-x);
        }
        printf("%d %d %d\n",n,x,y);
    }
}

/***********************solve************************/

bool check[MAXN+10];
int prime[MAXN+10];
int mu[MAXN+10];

void Moblus()
{
    memset(check,false,sizeof(check));
    mu[1]=1;
    int tot=0;
    for(int i=2;i<=MAXN;i++)
    {
        if(!check[i])
        {
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<tot;j++)
        {
            if(i*prime[j]>MAXN) break;
            check[i*prime[j]]=true;
            if(i%prime[j]==0)
            {
                mu[i*prime[j]]=0;
                break;
            }
            else
            {
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
}

int sum[MAXN+10];

long long solve(int n,int m) //[1,n],[1,m]�ڻ������Ķ���
{
    long long ans=0;
    if(n>m) swap(n,m);
    for(int i=1,la=0;i<=n;i=la+1)
    {
        la=min(n/(n/i),m/(m/i));
        ans+=(long long)(sum[la]-sum[i-1])*(n/i)*(m/i);
    }
    return ans;
}

long long f4(int n,int m) //n*mƽ���ı��ο�Ĵ�
{
    return solve(n,m)+2;
}

long long f3(int n) //n�������ǿ�Ĵ�
{
    return (solve(n,n)-1)/2+2;
}

void getans()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int st=clock();

    Moblus();
    sum[0]=0;
    for(int i=1;i<=MAXN;i++)
    {
        sum[i]=sum[i-1]+mu[i];
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,x,y;
        scanf("%d%d%d",&n,&x,&y);
        int z=n-x-y;
        long long ans=0;
        if(x&&y&&z) ans=f4(x,y)+f4(x,z)+f4(y,z)+f3(x)+f3(y)+f3(z)-6;
        else if(x&&y&&!z) ans=f4(x,y)+f3(x)+f3(y)-2;
        else if(x&&!y&&z) ans=f4(x,z)+f3(x)+f3(z)-2;
        else if(!x&&y&&z) ans=f4(y,z)+f3(y)+f3(z)-2;
        else if(x&&!y&&!z) ans=f3(x);
        else if(!x&&y&&!z) ans=f3(y);
        else if(!x&&!y&&z) ans=f3(z);
        printf("%lld\n",ans);
    }

    int en=clock();
    freopen("/dev/tty","w",stdout);
    printf("time: %d ms\n",1000*(en-st)/CLOCKS_PER_SEC);
}


int main()
{
    //getdata();
    getans();
    return 0;
}
