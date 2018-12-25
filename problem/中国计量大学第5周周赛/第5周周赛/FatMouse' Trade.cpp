//#define LOCAL
#include<cstdio>
#include<algorithm>
using namespace std;
struct FatMouse{
    double catfood;
    double javabean;
    double prize;
}kind[1000]; 
bool cmp(const FatMouse &a,const FatMouse &b){
    return a.prize>b.prize;
}
int main(){
    int i,m,n,num;
    double sum;
    #ifdef LOCAL
    freopen("test.in_FatMouseTrade.txt","r",stdin);
    freopen("test.out_FatMouseTrade.txt","w",stdout);    
    #endif
    while(scanf("%d %d",&n,&m)!=EOF){
        if(m==-1&&n==-1) break;
        for(i=0;i<m;i++){
            scanf("%lf %lf",&kind[i].javabean,&kind[i].catfood);
            kind[i].prize=kind[i].javabean/kind[i].catfood;
        }
        sort(kind,kind+m,cmp);
        for(i=0,num=0,sum=0;i<m;i++){            
            if(num>=n){
                if(num==n) break;
                else{
                    num-=kind[i-1].catfood;
                    sum-=kind[i-1].javabean;
                    sum+=kind[i-1].prize*(double)(n-num);
                    break; 
                }
            }
            else{
                num+=kind[i].catfood;
                sum+=kind[i].javabean;
            }
        }
        printf("%.3lf\n",sum);
    }
    return 0;
}
