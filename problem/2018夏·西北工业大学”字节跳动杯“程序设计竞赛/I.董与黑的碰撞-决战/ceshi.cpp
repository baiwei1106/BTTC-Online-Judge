#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *fp1,*fp2;
    fp1=fopen("out.txt","r");
    fp2=fopen("maybeans.txt","r");
    int cnt=0;
    while(!feof(fp1)&&!feof(fp2))
    {
        char s[2][11];
        cnt++;
        fscanf(fp1,"%s",s[0]);
        fscanf(fp2,"%s",s[1]);
        if(strcmp(s[0],s[1])!=0)printf("%d\n",cnt);
    }
}