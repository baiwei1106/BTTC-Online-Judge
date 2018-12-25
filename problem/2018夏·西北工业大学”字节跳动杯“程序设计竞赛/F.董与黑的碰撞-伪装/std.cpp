#include<bits/stdc++.h>
using namespace std;
#define LEN 10
int cnt[LEN][96];
int main()
{
    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    int i,j;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(cnt,0,sizeof(cnt));
        for(i=0;i<n;i++)
        {
            char s[LEN+2];
            scanf("%s",s);
            int len=strlen(s);
            for(j=0;j<len;j++)cnt[j][s[j]-33]++;
        }
        for(i=0;i<LEN;i++)
            for(j=0;j<95;j++)
                if(cnt[i][j]%2)printf("%c",j+33);
        printf("\n");
    }
}
