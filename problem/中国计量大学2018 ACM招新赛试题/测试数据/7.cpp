#define LOCAL 
#include<cstdio>
#include<algorithm>
using namespace std;
struct list{
	char c[1100];
	int n; 
}s[1100],w[1100],d[1100];
int main()
{
	int t,appetizer,course,dessert,i,j,k,sum;
	#ifdef LOCAL
	freopen("test.in_7-3.txt","r",stdin);
	freopen("test.out.txt","w",stdout);	
	#endif
	while(scanf("%d",&t)!=EOF){
		while(t--){		
			scanf("%d%d%d",&appetizer,&course,&dessert);
			for(i=0;i<appetizer;i++)
				scanf("%s %d",s[i].c,&s[i].n);
			for(j=0;j<course;j++)
				scanf("%s %d",w[j].c,&w[j].n);
			for(k=0;k<dessert;k++)
				scanf("%s %d",d[k].c,&d[k].n);
			for(i=0;i<appetizer;i++)
				for(j=0;j<appetizer-i-1;j++)
					if(s[j].n>s[j+1].n){
						swap(s[j].n,s[j+1].n);
						swap(s[j].c,s[j+1].c);
					} 
			for(i=0;i<course;i++)
				for(j=0;j<course-i-1;j++)
					if(w[j].n>w[j+1].n){
						swap(w[j].n,w[j+1].n);
						swap(w[j].c,w[j+1].c);
					}
			for(i=0;i<dessert;i++)
				for(j=0;j<dessert-i-1;j++)
					if(d[j].n>d[j+1].n){
						swap(d[j].n,d[j+1].n);
						swap(d[j].c,d[j+1].c);
					}
			sum=s[appetizer/2].n+w[course/2].n+d[dessert/2].n;
			printf("%d %s %s %s\n",sum,s[appetizer/2].c,w[course/2].c,d[dessert/2].c);
		} 
	}
	return 0;
}
