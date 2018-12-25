#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,j,m=1,n;
	int count1=10000000,count2=10000001; 
	#ifdef LOCAL
	freopen("test.in_Muddy roads.txt","w",stdout);	
	#endif
	while(m--){
		printf("10000 1\n");
		for(i=0;i<10000;i++){
			printf("%d %d\n",++count1,++count2);
		}
		printf("10000 100\n");
		for(i=0;i<10000;i++){
			printf("%d %d\n",++count1,++count2);
		} 
		printf("10000 10000\n");
		for(i=0;i<10000;i++){
			printf("%d %d\n",++count1,++count2);
		}
		printf("10000 100000\n");
		for(i=0;i<10000;i++){
			printf("%d %d\n",++count1,++count2);
		}
		printf("10000 100000000\n");
		for(i=0;i<10000;i++){
			printf("%d %d\n",++count1,++count2);
		}
	}
	return 0;
} 
