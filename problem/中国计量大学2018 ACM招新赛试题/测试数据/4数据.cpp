#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,j;
	int m=1000,n=10;
	#ifdef LOCAL
	freopen("test.in_4-4.txt","w",stdout);	
	#endif
	printf("1000 10\n");
	for(i=0;i<n;i++)
		printf("%05d ",rand()%100000);
	printf("\n");
	for(i=0;i<m;i++){
		printf("test%03d ",i+1);
		printf("10 ",n);
		for(j=0;j<n;j++)
			printf("%05d ",rand()%100000);
		printf("\n");
	}
	return 0;
} 
