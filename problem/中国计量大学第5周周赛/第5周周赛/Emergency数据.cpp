#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,j,m=1,n;
	#ifdef LOCAL
	freopen("test.in_Emergency.txt","w",stdout);	
	#endif
	while(m--){
		printf("50 500 0 49\n");
		for(i=0;i<50;i++){
			printf("%d ",(rand()%50));
		}
		for(i=0;i<500;i++){
			printf("%d %d %d",(rand()%50),(rand()%50),(rand()%50));
			printf("\n");
		} 
	}
	return 0;
}
