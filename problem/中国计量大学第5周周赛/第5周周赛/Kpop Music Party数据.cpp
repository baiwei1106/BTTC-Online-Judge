#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,j,m=1000,n;
	#ifdef LOCAL
	freopen("test.in_Kpop Music Party.txt","w",stdout);	
	#endif
	printf("1000\n");
	while(m--){
		printf("10 1000000000 10\n");
		for(i=0;i<10;i++){
			printf("%d %d\n",(rand()%10000)*(rand()%10000)+1,(rand()%10000)*(rand()%10000)+900000001);
		} 
	}
	return 0;
} 
