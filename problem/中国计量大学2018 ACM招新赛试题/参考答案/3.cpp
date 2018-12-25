#include<cstdio>
int main(){
	int x,y,m,n,flag,ans1,ans2;
	while(scanf("%d%d%d",&x,&y,&n)!=EOF){
		flag=0;
		if(x%(n-1)!=0) flag=1;
		else m=x/(n-1);
		if(m*n-y<0||m*n-y>100) flag=1;
		else ans1=m*n-y;
		if(m-y<0||m-y>100) flag=1;
		else ans2=m-y;
		if(flag) printf("Impossible\n");
		else printf("%d %d\n",ans1,ans2);
	}
	return 0;
} 
