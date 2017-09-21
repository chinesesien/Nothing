#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
int n,m,ans1=0;
short f[5010][310],head[5010][310],tail[5010][310];
string s,a[5010];
map<string,int>mm;
map<string,bool>nn;
int main(){
	freopen("delta.in","r",stdin);
	freopen("delta.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>s;
		mm[s]=1;
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>s; a[i]=s;
		if(mm[s]==1){
			ans1++; mm[s]=2;
			for(int j=1;j<=ans1;++j){
				if(j==1||i==1){
					f[i][j]=1; head[i][j]=i; tail[i][j]=i;
				}
				else{
					int A=f[i-1][j-1]+i-tail[i-1][j-1];
					if(f[i-1][j]!=0) f[i][j]=f[i-1][j]<A?f[i-1][j]:A;
					else f[i][j]=f[i-1][j-1]+i-tail[i-1][j-1];
					head[i][j]=head[i-1][j-1]; tail[i][j]=i;
				}
			}
		}
		else if(mm[s]==2){
			for(int j=1;j<=ans1;++j){
				if(j==1){
					f[i][j]=1; head[i][j]=i; tail[i][j]=i;
				}
				else{
					if(a[head[i-1][j]]==s){
						int tot=0,k;
						for(k=i; ;--k){
							if(mm[a[k]]==1||mm[a[k]]==2&&nn[a[k]]!=1){
								nn[a[k]]=1; tot++;
							}
							if(tot==f[i-1][j]) break;
						}
						int num=i-k+1;
						if(f[i-1][j]>num){
							f[i][j]=num; head[i][j]=k; tail[i][j]=i;
						}
						else{
							f[i][j]=f[i-1][j]; head[i][j]=f[i-1][j]; 
							tail[i][j]=tail[i-1][j];
						}
					}
					else{
						f[i][j]=f[i-1][j]; head[i][j]=f[i-1][j]; 
						tail[i][j]=tail[i-1][j];
					}
				} 
			}
		}
		else{
			for(int j=1;j<=ans1;++j){
				f[i][j]=f[i-1][j]; head[i][j]=head[i-1][j]; tail[i][j]=tail[i-1][j];
			}
		}
	}
	cout<<ans1<<' '<<f[m][ans1]<<endl;
	return 0;
}
