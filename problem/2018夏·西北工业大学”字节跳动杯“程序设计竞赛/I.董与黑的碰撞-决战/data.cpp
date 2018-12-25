#include<bits/stdc++.h>
using namespace std;
const int n=1000;
const int m=1000;
class node
{
public:
    string s;
    int c;
    vector<int>ve;
};
node out[n+5];
pair<int,vector<int> >pd[m+5];
int main()
{
    int i;
    FILE *fp;
    fp=fopen("maybeans.txt","w");
    int cnt=0;
    freopen("in.txt","w",stdout);
    srand((unsigned int)time(NULL));
    string now="aaaa";
    for(i=0;i<n;i++)
    {
        out[i].s=now;
        int j=3;
        while(now[j]=='z')j--;
        now[j]++;
        j++;
        while(j<=3)now[j++]='a';
        int c=rand()%(n/4)+n/4*3;
        out[i].c=c;
        cnt+=c;
        for(j=1;j<=c;j++)out[i].ve.push_back(rand()%20+1);
    }
    cout<<n<<" "<<m<<endl;
    for(i=0;i<n;i++)
    {
        cout<<out[i].s<<" ";
        cout<<out[i].c<<" ";
        for(int j=0;j<out[i].ve.size();j++)cout<<out[i].ve[j]<<" ";
        cout<<endl;
    }
    for(i=0;i<m-10;i++)
    {
        int select=rand()%n;
        int d=rand()%(out[select].c)*1/4+out[select].c*3/4+1;
        int begin;
        cnt+=d;
        if(d==out[select].c)begin=0;
        else begin=rand()%(out[select].c-d);
        fprintf(fp,"%s\n",out[select].s.c_str());
        pd[i].first=d;
        for(int j=begin;j<begin+d;j++)pd[i].second.push_back(out[select].ve[j]);
    }
    for(i=m-10;i<m;i++)
    {
        int d=rand()%n+1;
        pd[i].first=d;
        cnt+=d;
        fprintf(fp,"shenmegui\n");
        for(int j=0;j<d;j++)pd[i].second.push_back(rand()%20+1);
    }
    fprintf(fp,"%d\n",cnt);
    for(i=0;i<m;i++)
    {
        cout<<pd[i].first<<" ";
        for(int j=0;j<pd[i].second.size();j++)cout<<pd[i].second[j]<<" ";
        cout<<endl;
    }
    fclose(fp);
    return 0;
}