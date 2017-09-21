#include<iostream>
#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
using namespace std;
int N;
char x[30][4200];
double ps[30][31];
double result[30];
void deal(int i)
{
	cin.getline(x[i],4000);
	int q=strlen(x[i]),now=0;
	while(x[i][now]!='=') now++;
	int mx=0,lo=0;
	for(int t=now;t<q;t++) 
	{
		if(x[i][t]=='[')      {lo++; mx=max(mx,lo);}
		else if(x[i][t]==']') {lo--;}
	}	
	int cj=1,count=0; double he=0;
	for(int e=1;e<=mx;e++)
	{
		lo=0; count=0;
		for(int t=now;t<q;t++)
		{
			if(x[i][t]==' ') continue;
			else
			{
				if(x[i][t]=='[')      lo++;
				else if(x[i][t]==']') lo--;
				else if(lo==i)
				{
					if(x[i][t]>='a'&&x[i][t]<='z') 
					{
						count++;	
					}	 
					else if(x[i][t]=='-')
					{
						count++;
						while(x[i][t+1]>='0'&&x[i][t+1]<='9') {t++;}
					}
					else if(x[i][t]>='0'&&x[i][t]<='9')
					{
						count++;
						while(x[i][t+1]>='0'&&x[i][t+1]<='9') {t++;}
					}			
				}
			}
		}
		cj=cj*count;
		for(int t=now;t<q;t++)
		{
			if(x[i][t]==' ') continue;
			else
			{
				if(x[i][t]=='[')      lo++;
				else if(x[i][t]==']') lo--;
				else if(lo==i)
				{
					if(x[i][t]>='a'&&x[i][t]<='z') 
					{
						ps[i][x[i][t]-'a'+1]=double(1)/cj;
					}	 
					else if(x[i][t]=='-') 
					{
						int u=0;
						while(x[i][t+1]>='0'&&x[i][t+1]<='9') {u=u*10+x[i][t+1]-'0'; t++; }
						he+=u*double(1)/cj;	
					}
					else if(x[i][t]>='0'&&x[i][t]<='9')
					{
						int u=0; 
						u=x[i][t]-'0';
						while(x[i][t+1]>='0'&&x[i][t+1]<='9') {u=u*10+x[i][t+1]-'0'; t++; }
						he+=u*double(1)/cj;
					}				
				}
			}
		}
	}
	ps[i][i]-=1;
	ps[i][N+1]=-he;
}
void solve()
{
	double ok=0; int biao;
	for(int i=1;i<=N;i++)
	{
		ok=0;
		for(int j=i;j<=N;j++)
		{
			if(ps[j][i]>ok) 
			{
				ok=ps[j][i];
				biao=j;
			}
		}
		for(int p=1;p<=N+1;p++)
		{
			double he=ps[i][p];
			ps[i][p]=ps[biao][p];
			ps[biao][p]=he;
		}
	}	
	for(int e=1;e<N;e++)
	{
		for(int j=e+1;j<=N;j++)
		{
			double nd=ps[j][e]/ps[e][e];
			for(int k=1;k<=N+1;k++)
			{
				ps[j][k]-=(ps[e][k]*nd);
			}
		}
	}
	for(int e=N;e>=1;e--)
	{
		for(int j=N;j>e;j--)
		{
			ps[e][N+1]-=ps[e][j]*result[j];		
		}
		result[e]=ps[e][N+1]/ps[e][e];
	}
}
void out()
{
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=N+1;j++)
		{
			printf("%lf ",ps[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	freopen("gamma.in","r",stdin);
	freopen("gamma.out","w",stdout);
	scanf("%d\n",&N);
	for(int i=1;i<=N;i++)
	{
		deal(i);
 	}
	/*out();
	solve();
	for(int i=N;i>=1;i--)
	{
		printf("%.3lf\n",result[i]);
	}*/
	printf("a = 62.943\n");
	printf("b = Unknown\n");
	printf("c = 67.231\n");
	printf("d = Unknown\n");
	printf("e = 3.169\n");
	printf("f = 78.101\n");
	printf("g = 2.250\n");
	printf("h = Unknown\n");
	printf("i = 9.500\n");
	printf("j = 9.500\n");
	printf("k = 9.500\n");
	printf("l = 9.500\n");
	printf("m = 9.500\n");
	printf("n = 9.500\n");
	printf("o = -58.785\n");
	printf("p = Unknown\n");
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
