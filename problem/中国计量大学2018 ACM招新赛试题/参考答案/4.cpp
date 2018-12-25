#include<cstdio>
#include<cstring>
struct student{
	char name[20];
	int number;
	int num[15],flag[15];
}stu[10000];
int main(){
	int i,j,k,count1,count2,m,n;
	int forbid[10],flagstu[10000];
	while(scanf("%d%d",&m,&n)!=EOF){
		count1=count2=0;
		memset(flagstu,0,sizeof(flagstu));
		for(i=0;i<n;i++)
			scanf("%d",&forbid[i]);
		for(i=0;i<m;i++){
			scanf("%s %d",stu[i].name,&stu[i].number);
			for(j=0;j<stu[i].number;j++){
				scanf("%d",&stu[i].num[j]);
				for(k=0;k<n;k++){
					if(stu[i].num[j]==forbid[k]){
						if(!flagstu[i]) count1++;
						flagstu[i]=1;
						stu[i].flag[j]=1;
						count2++;
						break;
					}
					if(k==n-1){
						stu[i].flag[j]=0;
					}
				}
			}
		}
		for(i=0;i<m;i++){
			if(flagstu[i]){
				printf("%s:",stu[i].name);
				for(j=0;j<stu[i].number;j++){
					if(stu[i].flag[j])
						printf(" %05d",stu[i].num[j]);
				}
				printf("\n");
			}
		}
		printf("%d %d\n",count1,count2);
	}
	return 0;
} 
