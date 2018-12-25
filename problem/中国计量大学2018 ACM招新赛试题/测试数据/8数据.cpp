#define LOCAL
#include<cstdio>
#include<cstdlib> 
int num[100][100];
char c[100][100];
int main(){
	int i,j;
	#ifdef LOCAL
	freopen("test.in_8-5.txt","w",stdout);	
	#endif
	printf("* 100\n");
	for(i=0;i<100;i++)
		for(j=0;j<100;j++){
			num[i][j]=rand()%2;
			if(num[i][j]) c[i][j]='@';
			else c[i][j]=' ';
		}
	for(i=0;i<100;i++){
		for(j=0;j<100;j++){
			printf("%c",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
