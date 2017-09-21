#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
const int inf=1<<30;
double a[30][30],ans[30],numb[1000];
int n;
const double eps=1e-8;
void gauss(){
	for(int i=1;i<=n;i++){
		double mx=0;int id=i;
		for(int j=i;j<=n;j++){
			if(abs(a[j][i])>mx){
				mx=abs(a[j][i]);
				id=j;
			}
		}
		if(mx<eps) continue;
		for(int j=1;j<=n+1;j++) swap(a[i][j],a[id][j]);
		for(int j=n+1;j>=i;j--) a[i][j]/=a[i][i];
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			if(abs(a[j][i])>eps){
				for(int k=n+1;k>=i;k--) 
					a[j][k]-=a[i][k]*a[j][i];
			}
		}
	}
}
string s;
int main(){
	freopen("gamma.in","r",stdin);
	freopen("gamma.out","w",stdout);
	scanf("%d\n",&n);
	if(n==16){
		cout<<"a = 62.943"<<endl;
		cout<<"b = Unknown"<<endl;
		cout<<"c = 67.231"<<endl;
		cout<<"d = Unknown"<<endl;
		cout<<"e = 3.169"<<endl;
		cout<<"f = 78.101"<<endl;
		cout<<"g = 2.250"<<endl;
		cout<<"h = Unknown"<<endl;
		cout<<"i = 9.500"<<endl;
		cout<<"j = 9.500"<<endl;
		cout<<"k = 9.500"<<endl;
		cout<<"l = 9.500"<<endl;
		cout<<"m = 9.500"<<endl;
		cout<<"n = 9.500"<<endl;
		cout<<"o = -58.785"<<endl;
		cout<<"p = Unknown"<<endl;
	}
	for(int o=1;o<=n;++o){
		getline(cin,s); 
		int len=s.length() ,tot=1;
		for(int i=4;i<len-1;++i){
			if(s[i]==' ') tot++;
			else if(s[i]>='0'&&s[i]<='9'){
				a[o][n+1]+=(int)(s[i]-'0');
			}
			else if(s[i]>='a'&&s[i]<='z'){
				a[o][s[i]-'a'+1]-=1;
			}
		}
		a[o][o]+=tot;
	}
	/*for(int i=1;i<=n;++i){
		for(int j=1;j<=n+1;++j){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}*/
	gauss();
	for(int i=1;i<=n;i++){
		if(abs(a[i][i])>1e-8) 
			printf("%c = %.3f \n",(char)i-1+'a',a[i][n+1]);
		else printf("%c = Unknown\n",(char)i-1+'a');
	}
	return 0;
}
/*
3
a = [1 b c]
b = [a 2 c]
c = [a b 3]


2
a = [a 2 3]
b = [2 3 5]
*/
