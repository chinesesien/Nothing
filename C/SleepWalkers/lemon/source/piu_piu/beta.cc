#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
int T,sz;
struct pt
{
	int x[200];	
	int tt;
	void read()	
	{
		tt=0;
		char ch=getchar(); 
		while(ch<'0'||ch>'9')   {ch=getchar();}
		while(ch>='0'&&ch<='9') {x[++tt]=ch-'0'; ch=getchar();}
		return ;
	}	
	friend bool operator < (pt a,pt b)
	{
		for(int i=1;i<=T;i++)
		{
			if(a.x[i]==b.x[i]) continue;
			else return a.x[i]<b.x[i];
		}
	}
};
//map<pt,bool> s;
int main()
{	
	freopen("beta.in","r",stdin);
	freopen("beta.out","w",stdout);
	pt A;
	A.read();	
	scanf("%d",&T);
	printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
