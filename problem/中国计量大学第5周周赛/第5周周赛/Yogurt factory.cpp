#define LOCAL
#include<cstdio>
struct yogurt{
	int produce,client;
}day[50000];
int main(){
	int i,m,n,minnum;
	long long sum;
	#ifdef LOCAL
	freopen("test.in_Yogurt factory.txt","r",stdin);
	freopen("test.out_Yogurt factory.txt","w",stdout);	
	#endif
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=0,sum=0;i<n;i++){
			scanf("%d%d",&day[i].produce,&day[i].client);
			if(i==0) minnum=day[i].produce; 
			if(minnum+m*i<day[i].produce) day[i].produce=minnum+m*i;
			else minnum=day[i].produce-m*i;
			sum=sum+day[i].produce*day[i].client;
		}
		printf("%lld\n",sum);
	}
	return 0;
} 
