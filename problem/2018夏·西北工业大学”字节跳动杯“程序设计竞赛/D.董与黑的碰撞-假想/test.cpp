#include<bits/stdc++.h>
using namespace std;

const int MAXN=1000+5;
const int MOD=100000000;

int T,N;
int a[MAXN],b[MAXN];

/**********************getdata***********************/

bool isprime[50000];
int prime[50000];
int tot;

void getprime(int MAXP)
{
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=0;
    tot=0;
    for(int i=2;i<MAXP;i++)
    {
        if(isprime[i])
        {
            prime[tot++]=i;
            for(int j=i;j<=MAXP/i;j++)
            {
                isprime[i*j]=0;
            }
        }
    }
}

void getdata()
{
    freopen("in.txt","w",stdout);
    srand((unsigned)time(NULL));
    getprime(40000);

    T=8;
    printf("%d\n",T);
    for(int kase=1;kase<=T;kase++)
    {
        if(kase==1)
        {
            N=2;
            a[0]=1;b[0]=256;
            a[1]=1;b[1]=390625;
        }
        else
        {
            N=1000;
            int p1=tot-1;
            int p2=tot-1-N;
            if(kase==2) p2=p1;
            if(kase==3) p2-=111;
            for(int i=0;i<N;i++)
            {
                a[i]=-1000000000+rand()%100000000;
                b[i]=a[i]-1+prime[p1-i]*prime[p2-i];
            }
            if(kase==4)
            {
                a[499]=a[999]=-1000000000;
                b[499]=a[499]-1+999999937;
                b[999]=a[999]-1+999999937*2;
            }
            if(kase==5)
            {
                a[499]=a[999]=-1000000000;
                b[499]=a[499]-1+1999999943;
                b[999]=a[999]-1+1999999973;
            }
            if(kase==6) b[999]=a[999]-1+prime[p1-998]*prime[p2-999];
            if(kase==7) b[233]=a[233]-1+prime[p1-699]*prime[p2-233];
        }
        printf("%d\n",N);
        for(int i=0;i<N;i++)
        {
            printf("%d %d\n",a[i],b[i]);
        }
    }

}

/***********************solve1***********************/

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int d[MAXN];

void solve1() ///O(n2*log(b-a))
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int st=clock();

    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            d[i]=b[i]-a[i]+1;
        }
        bool flag=true;
        for(int i=0;i<N;i++)
        {
            for(int j=i+1;j<N;j++)
            {
                if(gcd(d[i],d[j])!=1)
                {
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        if(!flag) printf("ongoing\n");
        else
        {
            long long ans=1;
            for(int i=0;i<N;i++)
            {
                ans=ans*d[i]%MOD;
            }
            ans=(ans-1+MOD)*10%MOD;
            printf("%08d\n",ans);
        }
    }

    int en=clock();
    freopen("/dev/tty","w",stdout);
    printf("time: %d ms\n",1000*(en-st)/CLOCKS_PER_SEC);
}

/***********************solve2***********************/

set<int> factor;

void solve2() ///O(n*sqrt(b-a))
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int st=clock();

    getprime(45000);
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        factor.clear();
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            d[i]=b[i]-a[i]+1;
        }
        bool flag=true;
        for(int i=0;i<N;i++)
        {
            int tmp=d[i];
            for(int j=0;prime[j]<=tmp/prime[j];j++)
            {
                if(tmp%prime[j]==0)
                {
                    if(factor.count(prime[j]))
                    {
                        flag=false;
                        break;
                    }
                    factor.insert(prime[j]);
                    while(tmp%prime[j]==0)
                    {
                        tmp/=prime[j];
                    }
                }
            }
            if(tmp!=1)
            {
                if(factor.count(tmp))
                {
                    flag=false;
                    break;
                }
                factor.insert(tmp);
            }
            if(!flag) break;
        }
        if(!flag) printf("ongoing\n");
        else
        {
            long long ans=1;
            for(int i=0;i<N;i++)
            {
                ans=ans*d[i]%MOD;
            }
            ans=(ans-1+MOD)*10%MOD;
            printf("%08d\n",ans);
        }
    }

    int en=clock();
    freopen("/dev/tty","w",stdout);
    printf("time: %d ms\n",1000*(en-st)/CLOCKS_PER_SEC);
}

int main()
{
    //getdata();
    solve1();
    solve2();
    return 0;
}
