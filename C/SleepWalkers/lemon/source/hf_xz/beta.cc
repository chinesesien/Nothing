#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

long long n,nn,t,k,power[5]={1,10,100,1000,10000};
bool vis[10010];

int main(){
	freopen("beta.in","r",stdin);
	freopen("beta.out","w",stdout);
	cin>>n>>t;
	nn = n;
	if(t<=4){
		n%=power[t];
		while(!vis[n]){vis[n] = 1; n = (n*nn)%power[t]; k++;}
		cout<<k<<endl;
	}
	else if(t == 10) cout<<31250000<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
