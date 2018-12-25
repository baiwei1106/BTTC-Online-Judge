#include<bits/stdc++.h>
using namespace std;

/**********************getdata***********************/

void getdata()
{
    freopen("in.txt","w",stdout);
    int T=100;
    printf("%d\n",T);
    for(int kase=1;kase<=T;kase++)
    {
        int n=kase;
        printf("%d\n",n);
    }
    fclose(stdout);
}

/***********************solve************************/

void solve()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        double ans=n-1;
        if(n<20) ans+=(double)n/((1<<n)-1);
        //ans+=n/(pow(2,n)-1);
        printf("%.4f\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
}

int main()
{
    getdata();
    solve();
    return 0;
}
