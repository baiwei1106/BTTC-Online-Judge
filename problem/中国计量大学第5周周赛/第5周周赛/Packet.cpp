#include<cstdio>
int Max(int m,int n){
	if(m>n) return m;
	else return n;
}
int main(){
	int a,b,c,d,e,f,count;
	while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)!=EOF){
		if(a==0&&b==0&&c==0&&d==0&&e==0&&f==0) break;
		count=0;
		count=count+f;
		count=count+e;
		a=Max(0,a-11*e);
		count=count+d;
		if(b<5*d) a=Max(0,a-(5*d-b)*4);
		b=Max(0,b-5*d);
		count=count+(c+3)/4;
		if(c%4>0){
			if(c%4==1){
				if(b<5) a=Max(0,a-(27-4*b));
				else a=Max(0,a-7);
				b=Max(0,b-5);
			}
			else if(c%4==2){
				if(b<3) a=Max(0,a-(18-4*b));
				else a=Max(0,a-6);
				b=Max(0,b-3);
			}
			else if(c%4==3){
				if(b<1) a=Max(0,a-(9-4*b));
				else a=Max(0,a-5);
				b=Max(0,b-1);
			}
		}
		count=count+(b+8)/9;
		if(b%9>0) a=Max(0,a-(36-(b%9)*4));
		count=count+(a+35)/36;
		printf("%d\n",count);
	}
	return 0;
}
