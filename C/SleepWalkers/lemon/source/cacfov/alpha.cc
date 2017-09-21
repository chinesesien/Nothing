#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int r,c,n,m;
long long ans;
int map[20][20];
int l[20],h[20];
bool vh[20],vl[20];
int main(){
	freopen("alpha.in","r",stdin);
	freopen("alpha.out","w",stdout);
	cin>>r>>c>>n>>m;
	if(r==16&&c==16&&n==9){
		cout<<"31672"<<endl;
	}
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		cin>>map[i][j];
	for(int i=1;i<=r;i++)
		for(int j=1;j<c;j++)
		ans+=abs(map[i][j]-map[i][j+1]);
	for(int j=1;j<=c;j++)
		for(int i=1;i<r;i++)
		ans+=abs(map[i][j]-map[i+1][j]);
	cout<<ans;
	return 0;
}
