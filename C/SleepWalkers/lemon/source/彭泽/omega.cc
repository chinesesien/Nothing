#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define si scanf
#define so printf
#define N 1001000
#define M 
#define INF  
#define dt 500000
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

int n,k;
char in;
int a[N],b[N];
int f[N];
int ab(int num)
{
	if(num>=0)
		return num;
	return -num;
}
/*
	 ab(a[i]-a[j-1]-b[i]+b[j-1])
    =ab(a[i]-b[i]-(a[j-1]-b[j-1]))
    变成了只与a[i]-b[i]有关的东西，各个i可以分离看待
	每个i要么是A，要么是B，所以要么a[]++,要么b[]++，所以中心点对左右鬼畜的，每次挪动一个格 
*/
int ln[N];
int lst=0;
struct sta
{
	int v,po;
	sta(int value,int position)
	{
		v=value;
		po=position;
	}
	friend bool operator < (sta a,sta b)
	{
		return a.v>b.v;
	}
	friend bool operator > (sta a,sta b)
	{
		return a.v<b.v;
	}
};
priority_queue<sta> q;
long long ask(int mid)
{
	int po,v;
	if(mid==lst+1)//往右移了一格
	{
		q.push(sta(ln[mid+k],mid+k));
		while(1)
		{
			po=q.top().po;
			v=q.top().v;
			if(v!=ln[po])
			{
				q.pop();
				continue;
			}
			if(ab(mid-po)>k)
			{
				q.pop();
				continue;
			}
			break;
		}
	}
	else if(mid==lst-1)
	{
		q.push(sta(ln[mid-k],mid-k));
		while(1)
		{
			po=q.top().po;
			v=q.top().v;
			if(v!=ln[po])//不再是最新的 
			{
				q.pop();
				continue;
			}
			if(ab(mid-po)>k)//不在合法范围内 
			{
				q.pop();
				continue;
			}
			break;
		}
	}
	lst=mid;
	return q.top().v;
}
void push(int v,int po)
{
	if(v<ln[po])
	{
		q.push(sta(v,po));
		ln[po]=v;
	}
}
int main()
{
	freopen("omega.in","r",stdin);
	freopen("omega.out","w",stdout);
	rd(n),rd(k);
	for(int i=1;i<=n;i++)
	{
		si("%c\n",&in);
		a[i]=a[i-1];
		b[i]=b[i-1];
		if(in=='A')
			a[i]++;
		else if(in=='B')
			b[i]++;
	}
	memset(f,0x3f,sizeof(f));
	memset(ln,0x3f,sizeof(ln));
	f[0]=0;
	push(0,0+dt);
	for(int i=1;i<=n;i++)
	{
		f[i]=ask(a[i]-b[i]+dt)+1;
		push(f[i],a[i]-b[i]+dt);
	}
	so("%lld\n",f[n]);
	return 0;	
	
} 
