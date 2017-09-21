#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
double gs[30][30];
char c[30000];
int n;
int stt[10000];
int nd[10000];
int tot;
int num[10000];
void readin()
{
	cin>>n;
	char ch=' ';
	for(int i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		memset(num,0,sizeof(num));
		memset(stt,0,sizeof(stt));
		cin>>c[0];
		if(c[0]==10)continue;
		tot=0;
		int len=0;
		for(int j=1;;j++)
		{
			c[j]=getchar();
			if(c[j]==10)break;
			if(c[j]=='[')
			{
				tot++;
				stt[tot]=j;
			}
			len=j;
		}
		tot=0;
		for(int j=len;j>=0;j--)
		{
			if(c[j]==']')
			{
				tot++;
				nd[tot]=j;
			}
		}
		num[0]=1;
		for(int j=1;j<=tot;j++)
		{
			double ls[30];
			memset(ls,0,sizeof(ls));
			for(int k=stt[j]+1;k<nd[j];k++)
			{
				if((c[k]<='9'&&c[k]>='0')||c[k]=='-')
				{
					int x;
					bool f=0;
					if(c[k]=='-')
					{
						k++;
						f=1;
					}
					x=c[k]-'0';
					while(c[++k]<='9'&&c[k]>='0')
					{
						x=x*10+c[k]-'0';
					}
					num[j]++;
					if(!f)ls[0]+=x;
					else ls[0]-=x;
				}
				else if(c[k]<='z'&&c[k]>='a')
				{
					num[j]++;
					ls[c[k]-'a'+1]++;
				}
				else if(c[k]=='[')
				{
					for(int o=nd[j]-1;o>=k;o--)
					{
						if(c[o]==']')
						{
							k=o+1;
							break;
						}
					}
					num[j]++;
				}
			}
			num[j]*=num[j-1];
			for(int k=0;k<=n;k++)
			{
				gs[i][k]+=ls[k]/num[j];
			}
		}
		gs[i][i]--;
	}
}
bool z[30];
int main()
{
	freopen("gamma.in","r",stdin);
	freopen("gamma.out","w",stdout);
	readin();
	for(int i=1;i<=n;i++)
	{
		if(gs[i][i]==0)
		{
			z[i]=1;
			
			continue;
		}
		for(int j=1;j<i;j++)
		{
			double b=gs[j][i]/gs[i][i];
			for(int k=0;k<=n;k++)
			{
				gs[j][k]-=b*gs[i][k];
			}
		}
		for(int j=i+1;j<=n;j++)
		{
			double b=gs[j][i]/gs[i][i];
			for(int k=0;k<=n;k++)
			{
				gs[j][k]-=b*gs[i][k];
			}
		}	
	}

	for(int i=1;i<=n;i++)
	{
		printf("%c = ",i+'a'-1);
		if(z[i])cout<<"Unknown\n";
		else printf("%.3lf\n",-gs[i][0]/gs[i][i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
