#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,n=10;
	#ifdef LOCAL
	freopen("test.in_7-3.txt","w",stdout);	
	#endif
	printf("10\n");
	while(n--){
		printf("1000 1000 1000\n");
		for(i=0;i<1000;i++){
			printf("appetizers_%03d ",i);
			printf("%d\n",rand()%10000);
		}
		for(i=0;i<1000;i++){
			printf("main_courses_%03d ",i);
			printf("%d\n",rand()%10000);
		}
		for(i=0;i<1000;i++){
			printf("desserts_%03d ",i);
			printf("%d\n",rand()%10000);
		}
	}
	return 0;
}
