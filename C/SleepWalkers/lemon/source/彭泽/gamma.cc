#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
#define si scanf
#define so printf
#define N 
#define M 
#define INF  
template<typename TP>inline bool rd(TP& r)
{
	r=0;
	char tmp=getchar();
	while(tmp<'0'||tmp>'9')
	{
		if(tmp==EOF)
			return 0;
		tmp=getchar();
	}
	while('0'<=tmp&&tmp<='9')
	{
		r=(r<<3)+(r<<1)+tmp-'0';
		tmp=getchar();
	}
	return 1;
	
} 
int n;
long double mat[40][40];
char in;
string s[28];
int lth;
/*
	f[i]=sigma{p*f[j]}
*/

int stk[10000],tp;
int son,ko;
long double rt;
void read(int to,int l,int r,long double kk)
{
	son=0;
	ko=0;
	l++,r--;//去掉最外层的括号 
	int pst=1;
	for(int i=l;i<=r;i++)
	{
		if(s[to][i]=='[')
			ko++;
		else if(s[to][i]==']')
		{
			ko--;
			if(ko==0)
				son++;
		}
		else if(s[to][i]!=' '&&s[to][i]!='='&&ko==0)
		{
			son++;
			while(s[to][i]!=' '&&s[to][i]!=']')
				i++;
			i--;
		}
	}
	long double ks=1.0/(long double)son;
	for(int i=l;i<=r;i++)
	{
		if(s[to][i]=='-')
			pst*=-1;
		else if(s[to][i]=='[')
		{
			ko=1;
			for(int j=i+1;j<=r;j++)
			{
				if(s[to][j]=='[')
					ko++;
				else if(s[to][j]==']')
					ko--;
				if(ko==0)
				{
					read(to,i,j,kk*ks);
					i=j;
					break;
				}	
			}
		}
		else if(s[to][i]>='0'&&s[to][i]<='9')
		{
			rt=0;
			while(s[to][i]>='0'&&s[to][i]<='9')
			{
				rt=rt*10;
				rt=rt+s[to][i]-'0';
				i++;
			}
			mat[to][n+1]+=ks*rt*kk*(long double)pst;
			pst=1;
			i--;
		}
		else if(s[to][i]>='a'&&s[to][i]<='z')//字母 
		{
			mat[to][s[to][i]-'a'+1]-=ks*kk;
		}
	}
}
long double tmp[40];
void swp(int u,int v)
{
	memcpy(tmp,mat[u],sizeof(mat[u]));
	memcpy(mat[u],mat[v],sizeof(mat[v]));
	memcpy(mat[v],tmp,sizeof(tmp));
}
void print()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			so("%.3lf	",(double)mat[i][j]);
		so("|	%.3lf",(double)mat[i][n+1]);
		so("\n");
	}
	so("\n");
}
bool un[40];
void gaussian()
{
	long double q;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
			if(mat[j][i]!=0)
			{
				swp(i,j);
				break;
			}
		q=mat[i][i];
		for(int j=i;j<=n+1;j++)
			mat[i][j]/=q;
		for(int j=i+1;j<=n;j++)
			if(mat[j][i]!=0)
			{
				q=mat[j][i];
				for(int k=i;k<=n+1;k++)
					mat[j][k]-=mat[i][k]*q;
			}
	}
	for(int i=n;i;i--)
	{
		if(mat[i][i]!=1)
		{
			un[i]=1;
			continue;
		}
		for(int j=i+1;j<=n;j++)
			if(mat[i][j]!=0)
			{
				un[i]=1;
				break;
			}
		if(un[i])
			continue;
		for(int j=i-1;j;j--)
		{
			mat[j][n+1]-=mat[i][n+1]*mat[j][i];
			mat[j][i]=0;
		}
	} 
}

int main()
{
	freopen("gamma.in","r",stdin);
	freopen("gamma.out","w",stdout);
	rd(n);
	for(int i=1;i<=n;i++)
		getline(cin,s[i]);
	for(int i=1;i<=n;i++)
	{
		read(s[i][0]-'a'+1,4,s[i].length(),1);
		mat[i][i]+=1;
	}
	gaussian();
	double out;
	for(int i=1;i<=n;i++)
	{
		so("%c = ",s[i][0]);
		if(un[i])
			so("Unknown\n");
		else
		{
			out=mat[i][n+1];
			so("%.3lf\n",out);
		}
	}
	return 0;	
	
} 
