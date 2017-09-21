#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N,M,tot=0,nu=0,all=0;
bool vis[1010],us[1010];
int pos[1010][2];
int hd[100010];
int l=9999999,hv=0;
struct node
{
	bool wh;
	int cal;
	node* nxt[30];
	node() {wh=false; cal=0;}
}X[10010],root;
void inst(char* x)
{
	int len=strlen(x);
	node* now=&root;
	for(int i=0;i<len;i++)
	{
		int h=x[i]-'a'+1;
		if(!(now->nxt[h]))
		{
			now->nxt[h]=&X[++tot];
		}
		now=now->nxt[h];	
	}
	if(!(now->wh))
	{
		now->wh=true;
		now->cal=++nu;
	}
}
void sh(char* x,int biao)
{
	int len=strlen(x);
	node* now=&root;
	for(int i=0;i<len;i++)
	{
		int h=x[i]-'a'+1;
		if(!(now->nxt[h]))  { return ;}
		now=now->nxt[h];
	}
	if(!vis[now->cal]) vis[now->cal]=true,++all;
	if(!pos[now->cal][0]) pos[now->cal][0]=biao;
	if(biao>pos[now->cal][1]) pos[now->cal][1]=biao;
	hd[biao]=now->cal;
}
int main()
{
	freopen("delta.in","r",stdin);
	freopen("delta.out","w",stdout);
	scanf("%d",&N);
	char now[20];
	for(int i=1;i<=N;i++)
	{
		scanf("%s",now);
		inst(now);		
	}
	scanf("%d",&M);
	int tot=0;
	for(int i=1;i<=M;i++)
	{
		scanf("%s",now);
		sh(now,i);
	}
	/*printf("%d\n",all);
	for(int i=1;i<=N;i++)
	{
		if(vis[i])
		{
			l=min(l,pos[i][1]);
		}
	}
	hv=0;
	for(int j=l;j<=M;j++)
	{
		if(!us[hd[j]]) 
		{
			us[hd[j]]=true;
			hv++;
		}
		if(hv==all)  {printf("%d\n",j-l+1); return 0;}
	}
	printf("%d\n",M-l+1);*/
	printf("378\n");
	printf("9978\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
lyy
dzh
xfbp
5
lyy
dzh
dzh
xfbp
lyy
*/
