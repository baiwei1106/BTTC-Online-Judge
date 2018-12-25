#include<cstdio>
#include<cstring>
char c[1000][1000];
int a[1000][1000],b[1000][1000];
int main()
{
	int i,j,n,flag;
	char p;
	while(scanf("%c %d",&p,&n)!=EOF){
	getchar();
	flag=1;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,' ',sizeof(c));
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			c[i][j]=getchar();
			if(c[i][j]!=' ') a[i][j]=1;
			else a[i][j]=0;
		}
		getchar();
	}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			b[i][n-j-1]=a[i][j];
		}
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(a[i][j]!=b[i][j]){
				flag=0;break;
			}
	if(flag) printf("bu yao zhao le\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(b[i][j]) printf("%c",p);
			else printf(" ");
		}
		printf("\n");
	}
	}
	return 0;
}
