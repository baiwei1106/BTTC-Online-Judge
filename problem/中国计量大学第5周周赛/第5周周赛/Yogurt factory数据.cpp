#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,j,m=9,n;
	#ifdef LOCAL
	freopen("test.in_Yogurt factory.txt","w",stdout);	
	#endif
	while(m--){
		printf("10000 500\n");
		for(i=0;i<10000;i++){
			printf("%d %d\n",(rand()%5000+1),(rand()%10000));
		} 
	}
	return 0;
} 
