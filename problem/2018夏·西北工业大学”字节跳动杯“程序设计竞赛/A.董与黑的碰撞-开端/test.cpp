#include<bits/stdc++.h>
using namespace std;

void getdata()
{
    srand((unsigned)time(NULL));
    freopen("in.txt","w",stdout);
    int T=9;
    printf("%d\n",T);
    printf("dongxiansen\n");
    printf("Dongxiansen\n");
    printf("dongxianseN\n");
    printf("dongxianshen\n");
    printf("dongxianseng\n");
    printf("dongxiansheng\n");
    printf("dongxianse\n");
    printf("ongxiansen\n");
    printf("dongxiansen\n");
}

void solve()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int st=clock();
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        string s;
        cin>>s;
        if(s=="dongxiansen")
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
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
