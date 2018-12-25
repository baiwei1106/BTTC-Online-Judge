#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,n=1;
	#ifdef LOCAL
	freopen("test.in_10-5.txt","w",stdout);	
	#endif
	printf("1\n");
	while(n--){
		printf("100000\n");
		for(i=0;i<100000;i++)
			printf("%d ",rand()%2000000000+1);
	}
	return 0;
} 
