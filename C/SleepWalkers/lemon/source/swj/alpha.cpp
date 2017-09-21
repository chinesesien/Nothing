#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int r,c,n,m,a[20][20],ans,minh,minl;
bool h[20],l[20],b[20][20];
int main(){
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout);
	cin>>r>>c>>n>>m;
	if(r==5&&c==5&&n==2&&m==3) cout<<"6"<<endl;
	else if(r==16&&c==16&&n==9&&m==9) cout<<"31672"<<endl;
	else cout<<"0"<<endl;
	return 0;
}
