#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,n=5;
	#ifdef LOCAL
	freopen("test.in_6-3.txt","w",stdout);	
	#endif
	printf("5\n");
	while(n--){
		printf("10000\n");
		for(i=0;i<10000;i++){
			printf("%d ",rand()%100);
			printf("%d\n",rand()%100);
		}
	}
	return 0;
}
