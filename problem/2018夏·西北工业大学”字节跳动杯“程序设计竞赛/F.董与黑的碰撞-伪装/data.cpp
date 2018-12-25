#include<bits/stdc++.h>
using namespace std;
#define T 5
#define N 499999
#define LEN 10
vector<string>vec;
int main()
{
    srand(time(NULL));
    FILE *in,*out;
    in=fopen("in.txt","w");
    out=fopen("out.txt","w");
    fprintf(in,"%d\n",T);
    int t=T;
    while(t--)
    {
        fprintf(in,"%d\n",2*N+1);
        int i;
        for(i=0;i<N;i++)
        {
            int len=rand()%LEN+1;
            string s;
            for(int j=0;j<len;j++)s+=rand()%95+33;
            vec.push_back(s);
            vec.push_back(s);
        }
        int len=rand()%LEN+1;
        string s;
        for(int j=0;j<len;j++)s+=rand()%95+33;
        vec.push_back(s);
        fprintf(out,"%s\n",s.c_str());
        random_shuffle(vec.begin(),vec.end());
        for(i=0;i<vec.size();i++)fprintf(in,"%s\n",vec[i].c_str());
        vec.clear();
    }
    return 0;
}
