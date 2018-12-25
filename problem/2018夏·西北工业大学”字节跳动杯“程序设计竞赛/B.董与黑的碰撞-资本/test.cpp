#include<bits/stdc++.h>
using namespace std;

const int MAXN=100000+5;

int T,N;
int s[MAXN];

/**********************getdata***********************/

void getdata()
{
    freopen("in.txt","w",stdout);
    srand((unsigned)time(NULL));

    T=10;
    printf("%d\n",T);
    for(int kase=1;kase<=T;kase++)
    {
        if(kase<=3)
        {
            N=100000;
            for(int i=0;i<N;i++)
            {
                if(kase==1) s[i]=i+1;
                if(kase==2) s[i]=N-i;
                if(kase==3) s[i]=i%50000*2+1;
            }
        }
        else if(kase<=8)
        {
            N=100000;
            s[0]=50000;
            for(int i=1;i<N;i++)
            {
                s[i]=s[i-1]+rand()%101-50;
                if(s[i]<1) s[i]=s[i-1]+rand()%100;
                if(s[i]>100000) s[i]=s[i-1]-rand()%100;
            }
        }
        else
        {
            N=100000;
            for(int i=0;i<N;i++)
            {
                s[i]=rand()%99980+10;
            }
        }
        printf("%d\n",N);
        for(int i=0;i<N;i++)
        {
            if(i) printf(" ");
            printf("%d",s[i]);
        }
        printf("\n");
    }

}

/***********************solve************************/

int dp1[MAXN];//i及其左边的最小数
int dp2[MAXN];//i及其右边的最大数
double dp3[MAXN];//i及其左边的最大比值
double dp4[MAXN];//i及其右边的最大比值

void solve()
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
            scanf("%d",&s[i]);
        }
        for(int i=0;i<N;i++)
        {
            if(i==0) dp1[i]=s[i];
            else dp1[i]=min(dp1[i-1],s[i]);
        }
        for(int i=N-1;i>=0;i--)
        {
            if(i==N-1) dp2[i]=s[i];
            else dp2[i]=max(dp2[i+1],s[i]);
        }
        for(int i=0;i<N;i++)
        {
            if(i==0) dp3[i]=1;
            else dp3[i]=max(dp3[i-1],(double)s[i]/dp1[i]);
        }
        for(int i=N-1;i>=0;i--)
        {
            if(i==N-1) dp4[i]=1;
            else dp4[i]=max(dp4[i+1],(double)dp2[i]/s[i]);
        }
        double ans=1;
        for(int i=0;i<N;i++)
        {
            ans=max(ans,dp3[i]*dp4[i]);
        }
        printf("%.2f%%\n",(ans-1)*100);
    }

    int en=clock();
    freopen("/dev/tty","w",stdout);
    printf("time: %d ms\n",1000*(en-st)/CLOCKS_PER_SEC);
}

int main()
{
    //getdata();
    solve();
    return 0;
}
