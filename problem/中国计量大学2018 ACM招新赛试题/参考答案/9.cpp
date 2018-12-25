#include<cstdio>
#include<cstring>
int red[5],blue[5],red_count[5],blue_count[5];
char Red[5][10]={"iceman","lion","wolf","ninja","dragon"};
char Blue[5][10]={"lion","dragon","ninja","iceman","wolf"};
int initial,red_init,blue_init,dragon,ninja,iceman,lion,wolf;
void init(){
	scanf("%d",&initial);
	red_init=blue_init=initial;
	scanf("%d%d%d%d%d",&dragon,&ninja,&iceman,&lion,&wolf);
	red[4]=blue[1]=dragon;
	red[3]=blue[2]=ninja;
	red[0]=blue[3]=iceman;
	red[1]=blue[0]=lion;
	red[2]=blue[4]=wolf;
	memset(red_count,0,sizeof(red_count));
	memset(blue_count,0,sizeof(blue_count));
}
void print(){
	int i1,i2,flag,flag0,flag1,flag2,flaginit1,flaginit2,count1,count2,time1,time2;
	flag1=flag2=count1=count2=time1=time2=0;
	for(i1=0,i2=0,flaginit1=1,flaginit2=0;flag1<5||flag2<5;){
		if(i1==5) i1=0;
		if(i2==5) i2=0;
		if(flag1<5) flag=0;
		if(flag0||flaginit1){
			if(flaginit1) flaginit1=0;
			if(red_init>=red[i1]){
				flag1=0;
				red_init=red_init-red[i1];
				printf("%03d red %s %d born with strength %d,%d %s in red headquarter\n",time1++,Red[i1],++count1,red[i1],++red_count[i1],Red[i1]);
				flag=1;i1++;
			}
			else {flag1++;i1++;flaginit1=1;}
			if(flag1==5){
				printf("%03d red headquarter stops making warriors\n",time1++);
				flag=1;
			}
		}
		if(flag2<5) flag0=0;		
		if(flag||flaginit2){
			if(flaginit2) flaginit2=0;
			if(blue_init>=blue[i2]){
				flag2=0;
				blue_init=blue_init-blue[i2];
				printf("%03d blue %s %d born with strength %d,%d %s in blue headquarter\n",time2++,Blue[i2],++count2,blue[i2],++blue_count[i2],Blue[i2]);
				flag0=1;i2++;
			}
			else {flag2++;i2++;flaginit2=1;}
			if(flag2==5){
				printf("%03d blue headquarter stops making warriors\n",time2++);
				flag0=1;
			}
		}
	}
}
int main(){
	int count,t;
	while(scanf("%d",&t)!=EOF){
		count=0;
		while(t--){
			init();
			printf("Case:%d\n",++count);
			print();
		}
	}
	return 0;
} 
