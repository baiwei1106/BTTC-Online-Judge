#include<cstdio>
int main(){
	int m,n,ans,flag;
	while(scanf("%d%d",&m,&n)!=EOF){
		flag=1;
		ans=m*n;
		if(ans==0) printf("0");
		while(ans){
			if(ans%10==0&&flag==1) ;
			else {
				printf("%d",ans%10);flag=0;
			}
			ans=ans/10;
		}
		printf("\n");
	}
} 
