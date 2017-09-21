//Problem.B Code By HYS.(Force)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
typedef unsigned long long u_t;
u_t a,t,o,p,ans=1;
inline bool judge(int i){
    return a*p%(u_t)pow(10,i)/(u_t)pow(10,i-1)==p%(u_t)pow(10,i)/(u_t)pow(10,i-1);
}
int main(){
    freopen("beta.in","r",stdin);
    freopen("beta.out","w",stdout);
    scanf("%llu%llu",&a,&t);
    if(a<(u_t)pow(10,t))goto tag;
    a%=(u_t)pow(10,t),p=o=a;
    for(int i=1;i<=t;i++){
        if(judge(i))continue;
        register int j;
        for(j=2;j<=10;j++){
            a=a*o%(u_t)pow(10,t);
            if(judge(i))break;
        }
        if(j>=11)goto tag;
        ans*=j,o=a;
    }
    printf("%llu\n",ans);
    if(false)
        tag:printf("-1\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}