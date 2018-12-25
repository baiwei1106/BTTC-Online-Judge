#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,j,m=12,n;
	#ifdef LOCAL
	freopen("test.in_Expedition.txt","w",stdout);	
	#endif
	while(m--){
		printf("10000\n");
		for(i=0;i<10000;i++){
			printf("%d %d\n",(rand()%10000),(rand()%50)+1);
		} 
		printf("%d %d\n",(rand()%10000),(rand()%100));
	}
	return 0;
} 
