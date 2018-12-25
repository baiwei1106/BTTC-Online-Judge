#include<cstdio>
#include<algorithm>
using namespace std;
struct list{
	char c[110];
	int n; 
}s[110],w[110],d[110];
int comp(const list &a,const list &b){
	return a.n<b.n;
}
int main()
{
	int t,appetizer,course,dessert,i,j,k,sum;
	while(scanf("%d",&t)!=EOF){
		while(t--){		
			scanf("%d%d%d",&appetizer,&course,&dessert);
			for(i=0;i<appetizer;i++)
				scanf("%s %d",s[i].c,&s[i].n);
			for(j=0;j<course;j++)
				scanf("%s %d",w[j].c,&w[j].n);
			for(k=0;k<dessert;k++)
				scanf("%s %d",d[k].c,&d[k].n);
			sort(s,s+appetizer,comp);
			sort(w,w+course,comp);
			sort(d,d+dessert,comp);
			sum=s[appetizer/2].n+w[course/2].n+d[dessert/2].n;
			printf("%d %s %s %s\n",sum,s[appetizer/2].c,w[course/2].c,d[dessert/2].c);
		} 
	}
	return 0;
}
