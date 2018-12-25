#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,j,m=3,n;
	#ifdef LOCAL
	freopen("test.in_Cleaning Shifts.txt","w",stdout);	
	#endif
	while(m--){
		printf("25000 1000000\n");
		printf("1 500\n"); 
		for(i=0;i<24998;i++){
			printf("%d %d\n",(rand()%1000+1),(rand()%1000+1)*(rand()%1000+1));
		} 
		printf("500000 1000000\n");
	}
	return 0;
} 
