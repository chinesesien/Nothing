//Problem.A Code By HYS.(Force)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define MX 32
using namespace std;
int a[MX][MX],b[MX][MX][MX][MX],vis_r[MX],vis_c[MX],ans=0x3F3F3F3F,n,m,r,c;
inline int force(){
    int res=0;
    for(int i=1;i<r;i++)
        for(int j=1;j<c;j++)
            res+=(b[vis_r[i]][vis_c[j]][vis_r[i]][vis_c[j+1]]+b[vis_r[i]][vis_c[j]][vis_r[i+1]][vis_c[j]]);
    for(int i=1;i<r;i++)
        res+=b[vis_r[i]][vis_c[c]][vis_r[i+1]][vis_c[c]];
    for(int i=1;i<c;i++)
        res+=b[vis_r[r]][vis_c[i]][vis_r[r]][vis_c[i+1]];
    return res;
}
void dfs_col(int x,int y){
    if(y>c){
        ans=min(ans,force());
        return;
    }
    if(x>m)return;
    dfs_col(x+1,y);
    vis_c[y]=x;
    dfs_col(x+1,y+1);
}
void dfs_row(int x,int y){
    if(y>r){
        dfs_col(1,1);
        return;
    }
    if(x>n)return;
    dfs_row(x+1,y);
    vis_r[y]=x;
    dfs_row(x+1,y+1);
}
int main(){
    freopen("alpha.in","r",stdin);
    freopen("alpha.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&r,&c);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=1;k<=n;k++)
                for(int l=1;l<=m;l++)
                    b[i][j][k][l]=abs(a[i][j]-a[k][l]);
    dfs_row(1,1);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}