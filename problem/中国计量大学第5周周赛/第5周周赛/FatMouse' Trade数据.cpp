#define LOCAL
#include<cstdio>
#include<cstdlib> 
int main(){
	int i,j,m=20,n;
	#ifdef LOCAL
	freopen("test.in_FatMouse' Trade.txt","w",stdout);	
	#endif
	while(m--){
		printf("%d 1000\n",rand()%10000);
		for(i=0;i<1000;i++){
			printf("%d %d",(rand()%5000+1),(rand()%500+1));
			printf("\n");
		} 
	}
	return 0;
}
