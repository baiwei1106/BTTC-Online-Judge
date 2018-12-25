#include<cstdio>
#include<algorithm>
using namespace std;
int apple[100000];
int main()
{
	int i,t,n,sum,idea;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			for(i=0,sum=0;i<n;i++){
				scanf("%d%d",&apple[i],&idea);
				sum=sum+idea;
			}
			for(i=0;i<n;i++){
				if(i==0) printf("%d %d\n",apple[n-1],sum);
				else printf("%d %d\n",apple[i-1],sum);
			}
		}
	}
	return 0;
}
