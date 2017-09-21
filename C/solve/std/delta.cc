//Problem.D Code By HYS.
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
map<string,int> ind,has;
int n,m,req,tmp,tot,vis[131072];
string b[131072],str;
int main(){
    freopen("delta.in","r",stdin);
    freopen("delta.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>str,ind[str]=++tot;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        cin>>str;
        if(ind.find(str)!=ind.end()){
        	b[i]=str;
			if(vis[ind[str]]==0)
            	req++,vis[ind[str]]=1;
        }
        else b[i]="0";
    }
    if(req==0)
        printf("0\n0\n");
    else{
        printf("%d\n",req);
        int p=req,l=1,r=1,ans=0x3f3f3f3f;
        while(true){
            if(p==0){
                while(b[l]=="0")l++;
                ans=min(ans,r-l);
                if(has[b[l]]<=1)p++;
                has[b[l]]--,l++;
            }
            else{
                if(r>m)break;
                if(ind[b[r]]!=0){
                    has[b[r]]++;
                    if(has[b[r]]==1)
                        p--;
                }
                r++;
            }
        }
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
